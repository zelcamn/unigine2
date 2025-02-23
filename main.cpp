#include "paperrockscissors.h"
#include "Game.h"
#include "connector.h"

#include <QApplication>
#include <QDebug>
#include <QTimer>

int main(int argc, char *argv[])
{
    qRegisterMetaType<gamens::Variants>("gamens::Variants");

    QApplication app (argc, argv);
    PaperRockScissors w;

    gamens::Game game;
    web::Connector connector;


    QObject::connect(w.getRockBtn(), &QPushButton::clicked, &game, [&game](){
        game.set_chosenVariant(gamens::Variants::Rock);
        qDebug() << game.get_chosenVariant();
    });

    QObject::connect(w.getPaperBtn(), &QPushButton::clicked, &game, [&game](){
        game.set_chosenVariant(gamens::Variants::Paper);
        qDebug() << game.get_chosenVariant();
    });

    QObject::connect(w.getScissorsBtn(), &QPushButton::clicked, &game, [&game](){
        game.set_chosenVariant(gamens::Variants::Scissors);
        qDebug() << game.get_chosenVariant();
    });

    QObject::connect(w.getReadyBtn(), &QPushButton::clicked, &game, [&game, &w, &connector](){
        game.set_is_ready(true);
        if (connector.get_isConnected())
        {
            connector.send_data(game.get_is_ready(), game.get_chosenVariant());
        }
    });


    QObject::connect(w.getConnectBtn(), &QPushButton::clicked, &connector, [&connector, &w]() {
        connector.instatiate((int) w.getLocalPortSpinBox()->value(),
                             w.getPeerIPLnEdit()->text(),
                             w.getPeerPortSpinBox()->value());
    });

    QTimer timer;

    QObject::connect(&timer, &QTimer::timeout, &game, [&game, &w, &connector]() {

    if (game.get_is_ready())
    {
        w.getReadyBtn()->setStyleSheet("background-color: green; color: white;");
    }
    else
    {
        w.getReadyBtn()->setStyleSheet("background-color: gray; color: white;");
    }

    if (connector.get_isConnected())
    {
        w.getConnectBtn()->setStyleSheet("background-color: green; color: white;");
    }
    else
    {
        w.getConnectBtn()->setStyleSheet("background-color: gray; color: white;");
    }

    QMetaObject::invokeMethod(&game, "proceed_game",  Qt::QueuedConnection,
                              Q_ARG(bool, connector.get_is_ready_received()),
                              Q_ARG(int, (int)connector.get_variant_received()));

    QMetaObject::invokeMethod(w.getWinLoseLbl(), "setText",  Qt::QueuedConnection,
                              Q_ARG(QString, game.get_resultText()));}
    );

      timer.start(16);

    w.show();
    return app.exec();
}
