



#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <vector>

class MyWidget : public QWidget
{
    Q_OBJECT
  public:
    constexpr static double DEFAULT_RADIUS = 75.0;  // Promien kolek, w pikselach

    explicit MyWidget(QWidget *parent = nullptr);       
    void paintEvent(QPaintEvent *event) override;       
    void mousePressEvent(QMouseEvent *event) override;   //  myszy
    void keyPressEvent(QKeyEvent *event) override;      //  klawiatury 
    void wheelEvent(QWheelEvent *event) override;       // kola na myszy 

    struct Circle
    {
        QPointF center;   
        double radius;
    };

  signals:    

  private:
    std::vector<Circle> circles;   
};

#endif  
