#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Quit_triggered();

    void on_action_Open_triggered();

    void on_mdiArea_subWindowActivated(QMdiSubWindow *);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
