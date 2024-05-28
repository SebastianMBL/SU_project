#ifndef QWIDGET_H
#define QWIDGET_H

#include <QWidget>

class QWidget : public QWidget
{
    Q_OBJECT

public:
    QWidget(QWidget *parent = nullptr);
    ~QWidget();
};
#endif // QWIDGET_H
