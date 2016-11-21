#include "addtoondialog.h"
#include "ui_addtoondialog.h"

#include <QString>
#include <QFileDialog>
#include <QFileInfo>
#include <QStandardPaths>
#include <QMessageBox>
#include <iostream>

addToonDialog::addToonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addToonDialog)
{
    ui->setupUi(this);
}

addToonDialog::~addToonDialog()
{
    delete ui;
}

void addToonDialog::done(int r)
{
    if(QDialog::Accepted == r)  // ok was pressed
    {
        if(ui->toonName->text() == "")
        {
            std::cout << "Toon needs to have a valid name" << std::endl;
            return;
        }
        QFileInfo checkLogFile(ui->logPath->text());
        if(!checkLogFile.exists())
        {
            std::cout << "Log file not found" << std::endl;
            return;
        }

        this->toonName = ui->toonName->text();
        this->fileName = ui->logPath->text();
        QDialog::done(r);
        return;
    }
    else    // cancel, close or exc was pressed
    {
        QDialog::done(r);
        return;
    }
}

void addToonDialog::on_findLogFile_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Find log file", QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"\\..\\FunCom\\Anarchy Online", "Log.txt");
    if (file != "")
    {
        ui->logPath->setText(file);
    }
}

