#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "managefile.h"
#include "logic.h"
#include "entrypoint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadData();
    void openWindowFile();
    void Calculate();

private:
    Ui::MainWindow *ui;
    Data data;

    char* QstringToCharArray(QString qstr);
    QStringList ConvertRowToQTFormat(char **row, size_t size);
    void showData(Data* data);
    void showErrorWindow(char* nameError);

};
#endif // MAINWINDOW_H
