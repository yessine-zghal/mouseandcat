#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

namespace Ui {
class gameover;
}

class gameover : public QWidget
{
    Q_OBJECT

public:
    explicit gameover(int a,QWidget *parent = nullptr);
    ~gameover();

signals:
    void closeGame();

private slots:
    void on_OK_clicked();

private:
    int score;
    Ui::gameover *ui;
};

#endif // GAMEOVER_H
