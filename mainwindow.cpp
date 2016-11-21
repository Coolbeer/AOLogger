#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtoondialog.h"

#include <iostream>
#include <QFileDialog>
#include <QStandardPaths>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readConfig();

    this->timer = new QTimer();
    timer->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readConfig()
{
    this->configuration = new QSettings(QSettings::IniFormat, QSettings::UserScope, "PWAN", "AOLogger");
    ui->logPath->setText(this->configuration->value("player/logPath", "%LOCALAPPDATA%\\Funcom\\Anarchy Online").toString());
    ui->playerName->setText(this->configuration->value("player/name", "Playername").toString());

    configuration->beginGroup("toons");
    QStringList toons = configuration->childGroups();
    ui->toonSelector->addItem("Select toon from list");
    foreach (QString toon, toons)
    {
        ui->toonSelector->addItem(toon);
    }
}

void MainWindow::updateCaption(void)
{

 if(!inFile.isOpen())
    {
        ui->eventList->addItem("File no longer open!!");
        disconnect(this->timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
        return;
    }

    while(!inFile.atEnd())
    {
        QString hopp = inFile.readLine();
        if(hopp.isEmpty())
            return;
        t_event *returnEvent = theLogParser.parseLine(hopp.simplified().toStdString());

        //Add event to the log
        ui->eventList->addItem(QString::fromStdString(returnEvent->getMessage()));
        ui->eventList->scrollToBottom();

        if(returnEvent->type() != k_event::error)
        {
            entities.addEvent(returnEvent);
        }
    }
}

void MainWindow::addEventToList(std::string)
{

}

void MainWindow::on_startButton_clicked()
{
    if(inFile.isOpen())
        inFile.close();

    inFile.setFileName(ui->logPath->text());
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->eventList->addItem("Unable to open file!");
        return;
    }

//    inFile.seek(inFile.size());
    entities.setPlayerName(ui->playerName->text().toStdString());
    connect(this->timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
    ui->eventList->addItem("File Opened");
}

void MainWindow::on_saveButton_clicked()
{
    this->configuration->setValue("player/logPath", ui->logPath->text());
    this->configuration->setValue("player/name", ui->playerName->text());
    this->configuration->sync();
    std::cout << "Settings saved" << std::endl;
}

void MainWindow::on_findFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Find log file", QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation)+"\\..\\FunCom\\Anarchy Online", "Log.txt");
    if (fileName != "")
        ui->logPath->setText(fileName);
}

void MainWindow::on_addToon_clicked()
{
    addToonDialog dialog(this);
    if(dialog.exec())
    {
        this->configuration->beginGroup("toons");
        this->configuration->beginGroup(dialog.toonName);
        this->configuration->setValue("logPath", dialog.fileName);
        this->configuration->endGroup();
        this->configuration->endGroup();
        std::cout << dialog.fileName.toStdString() << std::endl;
        std::cout << dialog.toonName.toStdString() << std::endl;
        ui->toonSelector->addItem(dialog.toonName);
    }
}

void MainWindow::on_toonSelector_currentIndexChanged(const QString &arg1)
{
    if(arg1 != "Select toon from list")
    {
        this->configuration = new QSettings(QSettings::IniFormat, QSettings::UserScope, "PWAN", "AOLogger");
    //    this->configuration->beginGroup("toons");
    //    this->configuration->beginGroup(arg1);
        ui->logPath->setText(this->configuration->value("toons/"+arg1+"/logPath").toString());
    //    this->configuration->endGroup();
    //    this->configuration->endGroup();
    }
}
