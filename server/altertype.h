#ifndef ALTERTYPE_H
#define ALTERTYPE_H

#include <QMessageBox>
#include <QDialog>
#include "data.h"
#include "ui_altertype.h"

class AlterType : public QDialog, public Ui::alterType
{
    Q_OBJECT

public:
    explicit AlterType();
    ~AlterType();

signals:
    void updateType(int, QString);

private slots:
    void showType(int, QString);
    void on_pushButton_Save_clicked();
    void on_pushButton_Cancel_clicked();
};

#endif // ALTERTYPE_H
