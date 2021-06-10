#include "mainwindow.h"

//

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    initUI();

    //init gpio
    //wiringPiSetupSys();
}

MainWindow::~MainWindow()
{
    //wiringPiTerminateSys();
}

void MainWindow::on_identify_succeed()
{
    QSound::play(":sounds/sbcg.wav");
    identify_succeed_btn->setEnabled(false);
    identify_waiting_btn->setEnabled(true);
    door_control(true);
}

void MainWindow::on_identify_waiting()
{
    QSound::play(":sounds/ksdl.wav");
    identify_succeed_btn->setEnabled(true);
    identify_waiting_btn->setEnabled(false);
    door_control(false);
}

void MainWindow::door_control(bool open_or_not)
{
//    //pinmode, which pin,input or output
//    pinMode(7, OUTPUT);
//    //set value, high or low
//    if(open_or_not){
//       digitalWrite(7, HIGH);
//    }else{
//       digitalWrite(7, LOW);
//    }
}

void MainWindow::initUI()
{
    resize(400,700);

    personal_photo_label = new QLabel;
    personal_photo_label->setObjectName("personal_photo_label");
    personal_photo_label->setFixedSize(300,400);
    QPixmap photo_pixmap = QPixmap(":/image/personal_photo.jpg").scaledToWidth(personal_photo_label->width(), Qt::SmoothTransformation);
    personal_photo_label->setPixmap(photo_pixmap);

    id_label = new QLabel(tr("ID ："));
    id_lineedit = new QLineEdit;
    name_label = new QLabel(tr("姓名 ："));
    name_lineedit = new QLineEdit;
    identify_type_label = new QLabel(tr("识别方式 ："));
    identify_type_combobox = new QComboBox;
    identify_type_combobox->addItem("虹膜识别");
    identify_type_combobox->addItem("密码识别");
    identify_type_combobox->addItem("指纹识别");

    identify_succeed_btn = new QPushButton(tr("识别成功"));
    identify_waiting_btn = new QPushButton(tr("识别等待"));
    identify_succeed_btn->setEnabled(true);
    identify_waiting_btn->setEnabled(false);

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(personal_photo_label);
    hlayout->setMargin(20);

    QGridLayout *gridlayout = new QGridLayout;
    gridlayout->addWidget(id_label,0,0,1,1);
    gridlayout->addWidget(id_lineedit,0,1,1,3);
    gridlayout->addWidget(name_label,1,0,1,1);
    gridlayout->addWidget(name_lineedit,1,1,1,3);
    gridlayout->addWidget(identify_type_label,2,0,1,1);
    gridlayout->addWidget(identify_type_combobox,2,1,1,3);
    gridlayout->addWidget(identify_succeed_btn,3,0,2,2);
    gridlayout->addWidget(identify_waiting_btn,3,2,2,2);
    gridlayout->setSpacing(20);


    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(hlayout);
    vlayout->addLayout(gridlayout);
    vlayout->setMargin(20);

    frame = new QFrame;
    frame->setObjectName("frame");
    frame->setLayout(vlayout);

    QVBoxLayout *frame_vlayout = new QVBoxLayout;
    frame_vlayout->addWidget(frame);
    frame_vlayout->setMargin(30);

    centralWidget = new QWidget(this);
    centralWidget->setObjectName("centralWidget");
    centralWidget->setLayout(frame_vlayout);

    setCentralWidget(centralWidget);

    connect(identify_succeed_btn, SIGNAL(clicked()), SLOT(on_identify_succeed()));
    connect(identify_waiting_btn, SIGNAL(clicked()), SLOT(on_identify_waiting()));


    QFile file(":/qss/mainwindow.qss");
    if (file.open(QFile::ReadOnly)) {
        QString stylesheet = QLatin1String(file.readAll());
        setStyleSheet(stylesheet);
        file.close();
    }
}
