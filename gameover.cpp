#include "gameover.h"
#include "ui_gameover.h"

gameover::gameover(int a,QWidget *parent) :
    score(a),
    QWidget(parent),
    ui(new Ui::gameover)
{
    ui->setupUi(this);
    ui->score->setNum(score);
}

gameover::~gameover()
{
    delete ui;
}

void gameover::on_OK_clicked()
{
    emit closeGame();
    close();
}
