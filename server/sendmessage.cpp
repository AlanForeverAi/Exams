#include "sendmessage.h"

SendMessage::SendMessage()
{
    setupUi(this);
}

SendMessage::~SendMessage()
{

}


void SendMessage::on_pushButton_Confirm_clicked()
{
    if(textEdit_Message->toPlainText() == ""){
        QMessageBox::about(this, "msg", QStringLiteral("信息为空！！"));
        return ;
    }
    emit this->sendMessage(textEdit_Message->toPlainText());
    this->close();
}

void SendMessage::on_pushButton_Cancel_clicked()
{
    this->close();
}
