

#include "my_widget.h"

#include <QPainter>
#include <QRadialGradient>

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    //Jakosci obrazu
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor("#aeadac"))); //Tlo  podpunku 1
    auto r = this->rect();
    painter.drawRect(r);



    //painter.setBrush(QBrush(QColor(Qt::GlobalColor::magenta))); //Zmiana wartosci z "yellow" na "magenta"  podpunktu 1
    painter.translate(rect().width() / 2.0, rect().height() / 2.0);
    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);



    //3
    QPointF centrum = QPointF(20, 75);
    int promien = 25;
    QRadialGradient radialGrad(centrum ,promien);
    radialGrad.setColorAt(0, Qt::magenta);
    radialGrad.setColorAt(0.5, Qt::transparent);
    painter.setBrush(radialGrad);
    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            painter.drawEllipse(centrum.x()-promien/2, centrum.y()-promien/2, promien, promien);
            //painter.drawEllipse(-20, 60, 20, 20); //Dwie wartosci 40, 40 zostaly zmienione na 20, podpunktu 1
        }
        painter.rotate(360.0 / num_disks);
    }



    // Rysowanie krzyzyka
    painter.setBrush(Qt::NoBrush);  
    painter.setPen(QPen(Qt::black, 2)); //Grubosci 2
    int crossSize = 8; // Rozmiar krzyżyka
    painter.drawLine(-crossSize / 2, 0, crossSize / 2, 0); // Pozioma
    painter.drawLine(0, -crossSize / 2, 0, crossSize / 2); // Pionowa

}



void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}



void MyWidget::toggle_animation()
{
    if (timer.isActive())
        timer.stop();
    else
        timer.start(timer_interval);
}
