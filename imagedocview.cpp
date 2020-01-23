#include "imagedocview.h"
#include "ui_imagedocview.h"

ImageDocView::ImageDocView(QWidget *parent, const QString &filename) :
    QMdiSubWindow(parent),
    ui(new Ui::ImageDocView),
    filename(filename)
{
    ui->setupUi(this);
    this->setWindowTitle(filename);
}

ImageDocView::~ImageDocView()
{
    delete ui;
}
