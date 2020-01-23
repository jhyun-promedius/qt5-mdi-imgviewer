#include <QFileDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "imagedocview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_Quit_triggered()
{
    this->close();
}

void MainWindow::on_action_Open_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
            this,
            "Open File",
            "",
            tr("PNG (*.png);;JPEG (*.jpg *.jpeg);;TIFF (*.tif);;All files (*.*)" ));
    // QMessageBox::information(this, "Selected:", QString("Selected filename = [%1]").arg(filename));
    if (filename.isEmpty()) {
        return; // Cancelled, Do nothing.
    }
    //
    ui->mdiArea->hide();
    auto imageDocView = new ImageDocView(ui->mdiArea, filename);
    QMdiSubWindow *window = ui->mdiArea->addSubWindow(imageDocView);
    window->setAttribute(Qt::WA_DeleteOnClose);
    ui->mdiArea->show();
}

void MainWindow::on_mdiArea_subWindowActivated(QMdiSubWindow *mdiSubWindow)
{
    if (!mdiSubWindow) return;
    auto imageDocView = qobject_cast<ImageDocView *>(mdiSubWindow->widget());
    if (imageDocView) {
        this->statusBar()->showMessage(QString("Selected: %1").arg(imageDocView->getFilename()));
    }
}
