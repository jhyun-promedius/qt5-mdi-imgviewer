#ifndef IMAGEDOCVIEW_H
#define IMAGEDOCVIEW_H

#include <QWidget>

namespace Ui {
class ImageDocView;
}

class ImageDocView : public QWidget
{
    Q_OBJECT

public:
    explicit ImageDocView(QWidget *parent, const QString &filename);
    ~ImageDocView();

    const QString &getFilename() const {
        return this->filename;
    }

private:
    Ui::ImageDocView *ui;

    QString filename;
};

#endif // IMAGEDOCVIEW_H
