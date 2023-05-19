#ifndef HACKBLOCKING_H
#define HACKBLOCKING_H

#include <QMainWindow>
#include <QHostInfo>
namespace Ui {
class  HackAddress;
}

class HackAddress : public QMainWindow
{
    Q_OBJECT

public:
    explicit  HackAddress(QWidget *parent = 0);
    ~ HackAddress();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_blockButton_clicked();
    void print(QHostInfo inf);

    void on_Hostline_textChanged(const QString &arg1);

private:
    Ui:: HackAddress *ui;
    QHostInfo *info;
};

#endif // HACKBLOCKING_H
