#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->configuration = new QSettings(QSettings::IniFormat, QSettings::UserScope, "PWAN", "AOLogger");

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));

    timer->start(1000);

    ui->logPath->setText(this->configuration->value("player/logPath", "%LOCALAPPDATA%\\Funcom\\Anarchy Online").toString());
    ui->playerName->setText(this->configuration->value("player/name", "Playername").toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCaption(void)
{

 if(!inFile.isOpen())
    {
        ui->label->setText("Not Open");
        return;
    }
    ui->label->setText("Open");

    while(!inFile.atEnd())
    {
        QString hopp = inFile.readLine();
        if(hopp.isEmpty())
            return;
        t_event *returnEvent = theLogParser.parseLine(hopp.simplified().toStdString());
        if(returnEvent->type() != k_event::error)
            entities.addEvent(returnEvent);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(inFile.isOpen())
        inFile.close();

    inFile.setFileName(ui->logPath->text());
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    inFile.seek(inFile.size());
    entities.setPlayerName(ui->playerName->text().toStdString());
}

void MainWindow::on_pushButton_2_clicked()
{
    this->configuration->setValue("player/logPath", ui->logPath->text());
    this->configuration->setValue("player/name", ui->playerName->text());
    this->configuration->sync();
    std::cout << "Settings saved" << std::endl;
}
