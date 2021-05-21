#ifndef GAMEEND_H
#define GAMEEND_H

#include <QWidget>

namespace Ui {
class GameEnd;
}

class GameEnd : public QWidget
{
    Q_OBJECT

public:
    explicit GameEnd(int point, QWidget *parent = nullptr);
    ~GameEnd();

private slots:
    void on_pushButton_clicked();
signals:
    void closeGame();

private:
    Ui::GameEnd *ui;
};

#endif // GAMEEND_H
