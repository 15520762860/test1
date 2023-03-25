#ifndef CUSTOM_PLOT_H
#define CUSTOM_PLOT_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class custom_plot;
}

class custom_plot : public QWidget
{
    Q_OBJECT

public:
    explicit custom_plot(QWidget *parent = nullptr);
    ~custom_plot();

private:
    Ui::custom_plot *ui;
};

#endif // CUSTOM_PLOT_H
