#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTimer>
#include <QSettings>

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
        QSettings *configuration;
        QTimer *timer;

        void readConfig();

    public slots:
        void addEventToList(std::string);

    private slots:
        void on_startButton_clicked();
        void on_saveButton_clicked();
        void updateCaption(void);

        void on_findFile_clicked();

        void on_addToon_clicked();

private:
        Ui::MainWindow *ui;
        QFile inFile;
        t_parser theLogParser;
        t_entities entities;
};

#endif // MAINWINDOW_H
