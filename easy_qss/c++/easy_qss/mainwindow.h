#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSound>
#include <QLineEdit>
#include <QComboBox>
#include <QPixmap>
#include <QFile>

//gpio control
//#include <wiringPi.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *personal_photo_label;
    QLabel *identify_result_label;
    QLabel *id_label;
    QLabel *name_label;
    QLabel *identify_type_label;
    QLineEdit *id_lineedit;
    QLineEdit *name_lineedit;
    QComboBox *identify_type_combobox;
    QPushButton *identify_succeed_btn;
    QPushButton *identify_waiting_btn;
    void door_control(bool open_or_not);

    void initUI();


private slots:
    void on_identify_succeed();
    void on_identify_waiting();
};
#endif // MAINWINDOW_H
