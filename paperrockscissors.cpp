#include "paperrockscissors.h"
#include "./ui_paperrockscissors.h"

PaperRockScissors::PaperRockScissors(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PaperRockScissors)
{
    ui->setupUi(this);
}

PaperRockScissors::~PaperRockScissors()
{
    delete ui;
}

QPushButton* PaperRockScissors::getRockBtn() {return ui->RockBtn;};
QPushButton* PaperRockScissors::getPaperBtn() {return ui->PaperBtn;};
QPushButton* PaperRockScissors::getScissorsBtn() {return ui->ScissorsBtn;};
QPushButton* PaperRockScissors::getReadyBtn() {return ui->ReadyBtn;};
QPushButton* PaperRockScissors::getConnectBtn() {return ui->ConnectBtn;};

QLabel* PaperRockScissors::getWinLoseLbl() {return ui->WinLoseLbl;};

QLineEdit* PaperRockScissors::getPeerIPLnEdit() {return ui->PeerIPLblEdit;};

QSpinBox* PaperRockScissors::getLocalPortSpinBox() {return ui->LocalPortSpinBox;};
QSpinBox* PaperRockScissors::getPeerPortSpinBox() {return ui->PeerPortSpinBox;};
