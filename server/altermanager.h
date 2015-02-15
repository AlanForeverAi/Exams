#ifndef ALTERMANAGER_H
#define ALTERMANAGER_H

#include <QDialog>
#include "data.h"
#include "ui_altermanager.h"

class AlterManager : public QDialog, public Ui::alterManager
{
    Q_OBJECT

public:
    explicit AlterManager();
    ~AlterManager();

signals:
    void updateManager(User *);

private slots:
    void showManager(User *);

    void on_pushButton_Save_clicked();
    void on_pushButton_Cancel_clicked();
};

#endif // ALTERMANAGER_H
