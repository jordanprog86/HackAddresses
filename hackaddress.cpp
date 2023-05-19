#include "hackaddress.h"
#include "ui_hackaddress.h"
#include <QHostInfo>
#include <QHostAddress>
 HackAddress:: HackAddress(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui:: HackAddress)
{
    ui->setupUi(this);
    info = new QHostInfo;

    setCentralWidget(ui->report);
    ui->toolBar->addWidget(ui->Hostline);
    ui->toolBar->addWidget(ui->blockButton);
    ui->blockButton->setEnabled(!ui->Hostline->text().isEmpty());



}

 HackAddress::~ HackAddress()
{
    delete ui;
}

void  HackAddress::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void  HackAddress::on_blockButton_clicked()
{
info->fromName("qt-project.org");
info->lookupHost(ui->Hostline->text(), this, SLOT(print(QHostInfo)));

}
void  HackAddress::print(QHostInfo inf)
{
    ui->report->clear();

    if(inf.error())
    {
        ui->report->append("<b> Lookup failed -></b>" +ui->Hostline->text() + ":" + inf.errorString());
    }
    else
    {
 for(int i = 0; i <inf.addresses().count(); i++)
 {
 QHostAddress address = inf.addresses().at(i);
  ui->report->append("<b>Adresses </b>"+QString::number(i) + ": " +address.toString());

 }

 ui->report->append("<b>host Name: </b>"+inf.hostName());
 ui->report->append("<b>localDomainName: </b>" +inf.localDomainName());
 ui->report->append("<b>localHostName: </b>"+inf.localHostName());
}
}

void  HackAddress::on_Hostline_textChanged(const QString &arg1)
{
      ui->blockButton->setEnabled(!arg1.isEmpty());
}
