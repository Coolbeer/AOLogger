#ifndef ADDTOONDIALOG_H
#define ADDTOONDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class addToonDialog;
}

class addToonDialog : public QDialog
{
    Q_OBJECT

public:
    QString toonName;
    QString fileName;

    explicit addToonDialog(QWidget *parent = 0);
    ~addToonDialog();

private slots:
    void done(int);
    void on_findLogFile_clicked();

private:
    Ui::addToonDialog *ui;
};

#endif // ADDTOONDIALOG_H
