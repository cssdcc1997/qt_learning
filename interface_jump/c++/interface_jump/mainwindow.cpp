#include "mainwindow.h"

//
//
// from mainwindow jump to form2, and then jump back

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(400,300);

    m_form2 = new Form2;

    go_to_form2_btn = new QPushButton;
    present_form_label = new QLabel;

    go_to_form2_btn->setText(tr("跳转至界面2"));
    present_form_label->setText(tr("现在是界面1"));
    present_form_label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(present_form_label);
    layout->addWidget(go_to_form2_btn);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);

    connect(go_to_form2_btn, SIGNAL(clicked()), SLOT(on_go_to_form2()));
}

MainWindow::~MainWindow()
{
    delete m_form2;
}

void MainWindow::on_go_to_form2()
{
    m_form2->show();
}

