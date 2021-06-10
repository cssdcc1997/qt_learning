#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "form2.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *go_to_form2_btn;
    QLabel *present_form_label;

    Form2 *m_form2;

private slots:
    void on_go_to_form2();
};
#endif // MAINWINDOW_H
