#include "imagedocview.h"
#include "ui_imagedocview.h"

#include <QLabel>
#include <QPicture>
#include <QPixmap>

ImageDocView::ImageDocView(QWidget *parent, const QString &filename) :
    QWidget(parent),
    ui(new Ui::ImageDocView),
    filename(filename)
{
    ui->setupUi(this);
    this->setWindowTitle(filename);

    QImage image(filename);
    auto label = new QLabel(ui->scrollArea);

    label->setPixmap(QPixmap::fromImage(image));

    ui->scrollArea->setWidget(label);
}

ImageDocView::~ImageDocView()
{
    delete ui;
}
