#include "gameend.h"
#include "ui_gameend.h"

GameEnd::GameEnd(int point, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameEnd)
{
    ui->setupUi(this);
    ui->congraduation_2->setText("CONGRADUATION");
    ui->label_2->setText("Your score is : ");
    ui->score->setNum(point);

}

GameEnd::~GameEnd()
{
    delete ui;
}

void GameEnd::on_pushButton_clicked()
{
    emit closeGame();
    close();
}
