#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    ui->horizontalSlider->setMaximum(100);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar_2, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
               ui->progressBar, SLOT(setValue(int)));
    disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
               ui->progressBar_2, SLOT(setValue(int)));
    delete ui;
}

