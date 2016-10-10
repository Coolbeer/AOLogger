#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

#include "t_parser.h"
#include "t_entities.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void on_pushButton_clicked();
        void updateCaption(void);

    private:
        Ui::MainWindow *ui;
        QFile inFile;
        t_parser theLogParser;
        t_entities entities;
};

#endif // MAINWINDOW_H
