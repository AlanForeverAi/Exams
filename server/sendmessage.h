#ifndef SENDMESSAGE_H
#define SENDMESSAGE_H

#include <QDialog>
#include <QMessageBox>
#include "ui_sendmessage.h"
#include "data.h"

class SendMessage : public QDialog, public Ui::SendMessage
{
    Q_OBJECT
public:
    SendMessage();
    ~SendMessage();

signals:
    void sendMessage(QString);

private slots:
    void on_pushButton_Confirm_clicked();
    void on_pushButton_Cancel_clicked();
};

#endif // SENDMESSAGE_H
