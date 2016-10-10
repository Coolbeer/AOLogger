#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
    timer->start(1000);
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

//    QString hopp = inFile.readLine();
//    if(!hopp.isEmpty())
//        theLogParser.parseLine(hopp.toStdString());
//    ui->label->setText(ui->label->text() + hopp);
}

void MainWindow::on_pushButton_clicked()
{
    theLogParser.parseLine("[\"#000000004200000a#\",\"Other hit by other\",\"\",1475957541]Zagam hit Corrupted Hiisi Berserker for 2298 points of energy damage.");
    theLogParser.parseLine("[\"#0000000042000008#\",\"You hit other\",\"\",1475957540]You hit The Beast for 4274 points of poison damage. Critical hit!");
/*
    if(inFile.isOpen())
        inFile.close();

    inFile.setFileName(ui->lineEdit->text());
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    inFile.seek(inFile.size());
*/
}
