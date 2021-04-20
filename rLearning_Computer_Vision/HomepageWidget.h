#ifndef HOMEPAGEWIDGET_H
#define HOMEPAGEWIDGET_H

#include <QWidget>

namespace Ui {
class HomepageWidget;
}

class HomepageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomepageWidget(QWidget *parent = 0);
    ~HomepageWidget();

signals:
    void Signal_Get_Started(void);

private slots:
    void on_m_btn_Get_Started_clicked();

private:
    Ui::HomepageWidget *ui;
};

#endif // HOMEPAGEWIDGET_H
