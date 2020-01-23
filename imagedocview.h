#ifndef IMAGEDOCVIEW_H
#define IMAGEDOCVIEW_H

#include <QMdiSubWindow>

namespace Ui {
class ImageDocView;
}

class ImageDocView : public QMdiSubWindow
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
