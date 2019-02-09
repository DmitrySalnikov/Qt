#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {
    QHBoxLayout * mainLayout = new QHBoxLayout(this);
    QVBoxLayout * leftLayout = new QVBoxLayout();
    QVBoxLayout * rightLayout = new QVBoxLayout();
    QPushButton * addOne = new QPushButton();
    QPushButton * Reset = new QPushButton();
    QLCDNumber * arrLen = new QLCDNumber();
    QScrollArea * len = new QScrollArea();
    QWidget * graph = new QWidget();
    leftLayout->addWidget(addOne);
    leftLayout->addWidget(Reset);
    leftLayout->addWidget(len);
    rightLayout->addWidget(graph);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
}

Widget::~Widget() {
}
