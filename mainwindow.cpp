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

    while(!inFile.atEnd())
    {
        QString hopp = inFile.readLine();
        if(hopp.isEmpty())
            return;
        t_event *returnEvent = theLogParser.parseLine(hopp.toStdString());
        if(returnEvent->type() != k_event::error)
            entities.addEvent(returnEvent);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(inFile.isOpen())
        inFile.close();

    inFile.setFileName(ui->lineEdit->text());
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    inFile.seek(inFile.size());
}
