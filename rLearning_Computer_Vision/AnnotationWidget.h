#ifndef ANNOTATIONWIDGET_H
#define ANNOTATIONWIDGET_H

#include <QWidget>

namespace Ui {
class AnnotationWidget;
}

class AnnotationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AnnotationWidget(QWidget *parent = 0);
    ~AnnotationWidget();

private:
    Ui::AnnotationWidget *ui;
};

#endif // ANNOTATIONWIDGET_H
