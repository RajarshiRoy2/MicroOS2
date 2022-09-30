#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void Task0(void *p_arg);
    static void Task1(void *p_arg);

private:
    Ui::MainWindow *ui;
    QLabel *label;
    QHBoxLayout *layout;
};
#endif // MAINWINDOW_H
