#include "imagedocview.h"
#include "ui_imagedocview.h"

#include <QScrollArea>

ImageDocView::ImageDocView(QWidget *parent, const QString &filename) :
    QWidget(parent),
    ui(new Ui::ImageDocView),
    filename(filename)
{
    ui->setupUi(this);
    this->setWindowTitle(filename);
    //
    auto scrollArea = new QScrollArea(this);
    ui->gridLayout->addWidget(scrollArea);
}

ImageDocView::~ImageDocView()
{
    delete ui;
}
