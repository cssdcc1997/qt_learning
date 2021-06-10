#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QSound>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *present_status_label;
    QPushButton *identify_succeed_btn;
    QPushButton *identify_waiting_btn;


private slots:
    void on_identify_succeed();
    void on_identify_waiting();
};
#endif // MAINWINDOW_H
