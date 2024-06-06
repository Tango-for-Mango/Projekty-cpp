

#include "my_widget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>    
#include <QWheelEvent>  

float radius_factor = 1.0;  

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);  
}

 
void MyWidget::paintEvent([[maybe_unused]] QPaintEvent* event)
{
    QPainter painter(this);  

    painter.setRenderHint(QPainter::Antialiasing);                    
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkMagenta)));   
    auto r = this->rect();                                            
    painter.drawRect(r);                                             

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkYellow)));  
    for (const auto& circ : circles)                                 
    {
        QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());
        painter.drawEllipse(point, circ.radius, circ.radius);  
    }
}

 
void MyWidget::mousePressEvent(QMouseEvent* event)
{
    auto pos = event->localPos();            
    auto rec = rect();                      
    Circle c;                              
    c.radius = DEFAULT_RADIUS * radius_factor;  
    c.center.setX(pos.x() / rec.width());   // skladowa "x"  
    c.center.setY(pos.y() / rec.height());  // skladowa "y"  
    circles.push_back(c);                   // dodanie kolka 
    repaint();                             
}

void MyWidget::keyPressEvent(QKeyEvent* event)  
{
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_Z) //Ctrl + Z
    {
        if(!circles.empty())  
        {
            circles.pop_back();  
            repaint();  
        }
    }
}

void MyWidget::wheelEvent(QWheelEvent* event)  
{
    QPoint angleDelta = event->angleDelta() / 120;
    int numSteps = angleDelta.y();  
    // Zmiana promienia  
    if (numSteps > 0)
    {
        radius_factor *= 1.1; // wiecej promień o 10%
    }
    else if (numSteps < 0)
    {
        radius_factor *= 0.9; // mniej promień o 10%
    }
}

