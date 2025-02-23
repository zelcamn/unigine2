#include "connector.h"

namespace web
{

bool Connector::instatiate(int listenPort, QString peerIP, int peerPort)
{
    try
    {
        create_server(listenPort);
        connect_to_server(peerIP, peerPort);
    }
    catch (std::runtime_error)
    {
        return false;
    }
    return true;
};

void Connector::create_server(int listenPort)
{
    if (server != nullptr)
    {
        delete server;
    }

    server = new QTcpServer(this);

    connect(server, &QTcpServer::newConnection, this, &Connector::new_connection);
    if (server->listen(QHostAddress::Any, listenPort)) {
        qDebug() << "Сервер слушает порт" << listenPort;
    } else {
        qDebug() << "Ошибка запуска сервера!";
        throw std::runtime_error("Ошибка запуска сервера!");
    }
}

void Connector::connect_to_server(QString peerIP, int peerPort)
{
    if (clientSocket != nullptr)
    {
        delete clientSocket;
    }

    clientSocket = new QTcpSocket(this);

    connect(clientSocket, &QTcpSocket::readyRead, this, &Connector::data_received);

    connect(clientSocket, &QTcpSocket::connected, this, []() {
        qDebug() << "Подключено к удаленному узлу!";
    });
    clientSocket->connectToHost(peerIP, peerPort);
}

void Connector::new_connection()
{
    QTcpSocket *newSocket = server->nextPendingConnection();
    connect(newSocket, &QTcpSocket::readyRead, this, [newSocket]() {
        QByteArray data = newSocket->readAll();
        qDebug() << "Получено:" << data;
    });
    connect(newSocket, &QTcpSocket::disconnected, newSocket, &QTcpSocket::deleteLater);
    qDebug() << "Новое соединение установлено!";
}

void Connector::data_received()
{
    QByteArray data = clientSocket->readAll();
    QDataStream stream(&data, QIODevice::ReadOnly);

    stream >> receivedIsReady >> receivedVariant;

    qDebug() << "Ответ от узла: bool =" << receivedIsReady << ", enum =" << receivedVariant;
}

bool Connector::send_data(bool isReady, gamens::Variants variant)
{
    if (clientSocket->state() == QAbstractSocket::ConnectedState) {
        QByteArray buffer;
        QDataStream stream(&buffer, QIODevice::WriteOnly);
        stream << isReady << static_cast<int>(variant); // Кодируем bool и enum
        clientSocket->write(buffer);
        clientSocket->flush();
        qDebug() << "Отправлено: bool =" << isReady << ", enum =" << variant;
        isConnected = true;
        return true;
    } else {
        qDebug() << "Нет соединения с узлом!";
        isConnected = false;
        return false;
    }
}

bool Connector::get_is_ready_received()
{
    return receivedIsReady;
}

gamens::Variants Connector::get_variant_received()
{
    if (receivedVariant < 0 or receivedVariant > 2)
    {
        return gamens::Variants::Rock;
    }
    return (gamens::Variants) receivedVariant;
}

bool Connector::get_isConnected()
{
    return isConnected;
}

Connector::~Connector()
{
    if (server != nullptr)
    {
        delete server;
    }

    if (clientSocket != nullptr)
    {
        delete clientSocket;
    }
}

}
