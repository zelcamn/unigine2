#ifndef PAPERROCKSCISSORS_H
#define PAPERROCKSCISSORS_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class PaperRockScissors;
}
QT_END_NAMESPACE

// класс главного окна
class PaperRockScissors : public QMainWindow
{
    Q_OBJECT

public:
    PaperRockScissors(QWidget *parent = nullptr);
    ~PaperRockScissors();

    // методы для получения указателей на кнопки
    QPushButton *getRockBtn();
    QPushButton *getPaperBtn();
    QPushButton *getScissorsBtn();
    QPushButton *getReadyBtn();
    QPushButton *getConnectBtn();

    // метод для получения указателя на строку результатов
    QLabel *getWinLoseLbl();

    // метод для получения указателя на строку ввода IP другого игрока
    QLineEdit *getPeerIPLnEdit();

    // методы для получения указателей на спинбоксы портов игроков
    QSpinBox *getLocalPortSpinBox();
    QSpinBox *getPeerPortSpinBox();

private:
    Ui::PaperRockScissors *ui;
};
#endif // PAPERROCKSCISSORS_H
