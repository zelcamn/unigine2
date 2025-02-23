#ifndef PAPERROCKSCISSORS_H
#define PAPERROCKSCISSORS_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class PaperRockScissors;
}
QT_END_NAMESPACE

class PaperRockScissors : public QMainWindow
{
    Q_OBJECT

public:
    PaperRockScissors(QWidget *parent = nullptr);
    ~PaperRockScissors();

    QPushButton* getRockBtn();
    QPushButton* getPaperBtn();
    QPushButton* getScissorsBtn();
    QPushButton* getReadyBtn();
    QPushButton* getConnectBtn();

    QLabel* getWinLoseLbl();

    QLineEdit* getPeerIPLnEdit();

    QSpinBox* getLocalPortSpinBox();
    QSpinBox* getPeerPortSpinBox();

private:
    Ui::PaperRockScissors *ui;
};
#endif // PAPERROCKSCISSORS_H
