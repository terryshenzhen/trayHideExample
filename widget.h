#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


//-------------trayHide
#include <QSystemTrayIcon>  //t托盘类
#include <QDesktopServices> //桌面事件类



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void trayHideInit();

     void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_hide_clicked();

    //-------------trayHide
    void trayActivatedSlot(QSystemTrayIcon::ActivationReason ireason);


private:
    Ui::Widget *ui;

    //-------------trayHide
    QMenu *trayMenu;//托盘菜单
    QSystemTrayIcon *apptray;//托盘图标添加成员



};
#endif // WIDGET_H
