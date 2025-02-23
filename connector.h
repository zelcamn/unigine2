#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QtNetwork/qtcpserver.h>
#include <QtNetwork/qtcpsocket.h>
#include <QObject>

#include "Game.h"

namespace web
{
    class Connector : public QObject
    {
        Q_OBJECT
    private:
        QTcpServer* server = nullptr;
        QTcpSocket* clientSocket = nullptr;

        QString peerIP;
        int PeerPort;

        bool isConnected = false;

        bool receivedIsReady = false;
        int receivedVariant = 0;

        void create_server(int listenPort);

    private slots:
        void new_connection();
        void data_received();

    public:
        void connect_to_server(QString peerIP, int peerPort);

        bool instatiate(int listenPort, QString peerIP, int peerPort);
        bool send_data(bool isReady, gamens::Variants variant);

        bool get_is_ready_received();
        gamens::Variants get_variant_received();

        bool get_isConnected();

        ~Connector();
    };
}

#endif // CONNECTOR_H
