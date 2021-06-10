#include "mainwindow.h"

//

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400,300);

    present_status_label = new QLabel(tr("等待识别"));
    present_status_label->setAlignment(Qt::AlignCenter);

    identify_succeed_btn = new QPushButton(tr("识别成功"));
    identify_waiting_btn = new QPushButton(tr("识别等待"));
    identify_succeed_btn->setEnabled(true);
    identify_waiting_btn->setEnabled(false);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(present_status_label);
    layout->addWidget(identify_succeed_btn);
    layout->addWidget(identify_waiting_btn);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);

    connect(identify_succeed_btn, SIGNAL(clicked()), SLOT(on_identify_succeed()));
    connect(identify_waiting_btn, SIGNAL(clicked()), SLOT(on_identify_waiting()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_identify_succeed()
{
    QSound::play(":/Sounds/sbcg.wav");
    identify_succeed_btn->setEnabled(false);
    identify_waiting_btn->setEnabled(true);
    present_status_label->setText(tr("识别成功"));
}

void MainWindow::on_identify_waiting()
{
    QSound::play(":/Sounds/kssb.wav");
    identify_succeed_btn->setEnabled(true);
    identify_waiting_btn->setEnabled(false);
    present_status_label->setText(tr("等待识别"));
}

