#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ucos_ii.h"

#define  TASK0_STK_SIZE                         250u
static  CPU_STK  Task0Stk[TASK0_STK_SIZE];
static  CPU_STK  Task1Stk[TASK0_STK_SIZE];
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //label = new QLabel(this);
    //layout = new QHBoxLayout();



    OSInit();
    //OSTaskCreate(Task1, (void *)0, &Task1Stk[TASK0_STK_SIZE - 1], 0);
    OSTaskCreate(Task0, (void *)0, &Task0Stk[TASK0_STK_SIZE - 1], 0);


    OSStart();

    //label->setText( QString::number(OSTimeGet()));
    //layout->addWidget(label);
    //setLayout(layout);

}

void MainWindow::Task0 (void *p_arg)
{
    qDebug()<<"Started MicrOS system with timer...";
    while(1)
    {
        int milli_seconds = 1000;

        // Storing start time
        clock_t start_time = clock();

        // looping till required time is not achieved
        while (clock() < start_time + milli_seconds);
        qDebug()<< OSTimeGet();

    }


}

void MainWindow::Task1 (void *p_arg)
{
    qDebug()<<"Task 1...";
}


MainWindow::~MainWindow()
{
    delete ui;
}

