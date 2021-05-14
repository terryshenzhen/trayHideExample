#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    trayHideInit();

}

Widget::~Widget()
{
    delete ui;
}

#include<QMenu>

void Widget::trayHideInit()
{

//***托盘***
    apptray= new QSystemTrayIcon(this);//初始化托盘对象tray
    apptray->setIcon(QIcon(QPixmap(":/image/image/icon.png")));//设定托盘图标，引号内是自定义的png图片路径
    apptray->setToolTip("My helper"); //提示文字


    QString title="APP Message";
    QString text="My helper start up";
    apptray->show();//让托盘图标显示在系统托盘上
    apptray->showMessage(title,text,QSystemTrayIcon::Information,3000); //最后一个参数为提示时长，默认10000，即10s


    //创建菜单项动作
//    QAction *minimizeAction = new QAction("MinWin", this);
//    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    QAction *maximizeAction = new QAction("MaxWin", this);
    connect(maximizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));

    QAction *restoreAction = new QAction("restore", this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

// 需要退出可以将下面的打开
//    QAction *quitAction = new QAction("exit", this);
//    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit())); //关闭应用

    //创建托盘菜单
    QMenu *trayMenu = new QMenu(this);
    //trayMenu->addAction(minimizeAction);
    trayMenu->addAction(maximizeAction);
    trayMenu->addAction(restoreAction);
    trayMenu->addSeparator();
    //trayMenu->addAction(quitAction);
    apptray->setContextMenu(trayMenu);

 connect(apptray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(trayActivatedSlot(QSystemTrayIcon::ActivationReason)));


}



void Widget::trayActivatedSlot(QSystemTrayIcon::ActivationReason ireason)
{
    switch (ireason)
    {
    case QSystemTrayIcon::Trigger:
        this->showNormal();
        break;
    case QSystemTrayIcon::DoubleClick:
        this->showNormal();
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    default:
        break;
    }

}




#include<QCloseEvent>
void Widget::closeEvent(QCloseEvent *event)
{

        if(apptray->isVisible())
        {
            hide(); //隐藏窗口
            event->ignore(); //忽略事件
        }
}




void Widget::on_pushButton_hide_clicked()
{



}
