#ifndef FORM2_H
#define FORM2_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class Form2 : public QWidget
{
    Q_OBJECT
public:
    Form2(QWidget *parent = nullptr);
    ~Form2();

private:
    QPushButton *back_to_form1_btn;
    QLabel *present_form_label;

private slots:
    void on_back_to_form1();
};

#endif // FORM2_H
