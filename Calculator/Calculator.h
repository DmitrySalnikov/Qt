#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtWidgets>

class Calculator : public QWidget {
    Q_OBJECT

private:
    QLCDNumber * m_plcd;
    QStack<QString> m_stk;
    QString m_strDisplay;

public:
    Calculator(QWidget *parent = 0);
    ~Calculator() {}
    QPushButton * createButton(QString const & str);
    void calculate();

public slots:
    void slotButtonClicked();
};

#endif // CALCULATOR_H
