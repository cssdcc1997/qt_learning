#include "form2.h"

Form2::Form2(QWidget *parent) : QWidget(parent)
{
    resize(400,300);

    back_to_form1_btn = new QPushButton;
    present_form_label = new QLabel;

    back_to_form1_btn->setText(tr("跳转至界面1"));
    present_form_label->setText(tr("现在是界面2"));
    present_form_label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(present_form_label);
    layout->addWidget(back_to_form1_btn);

    setLayout(layout);

    connect(back_to_form1_btn, SIGNAL(clicked()), SLOT(on_back_to_form1()));

}

Form2::~Form2()
{

}

void Form2::on_back_to_form1()
{
    this->close();
}
