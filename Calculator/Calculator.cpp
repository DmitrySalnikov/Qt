#include "Calculator.h"

Calculator::Calculator(QWidget *parent) : QWidget(parent) {
    m_plcd = new QLCDNumber(12);
    m_plcd->setSegmentStyle(QLCDNumber::Flat);
    m_plcd->setMinimumSize(150, 50);

    QChar aButtons[4][4] = {{'7', '8', '9', '/'},
                            {'4', '5', '6', '*'},
                            {'1', '2', '3', '-'},
                            {'0', '.', '=', '+'}};

    QGridLayout * ptopLayout = new QGridLayout;
    ptopLayout->addWidget(m_plcd, 0, 0, 1, 4);
    ptopLayout->addWidget(createButton("CE"), 1, 3);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            ptopLayout->addWidget(createButton(aButtons[i][j]), i + 2, j);

    setLayout(ptopLayout);
}

QPushButton * Calculator::createButton(QString const & str) {
    QPushButton * pcmd = new QPushButton(str);
    pcmd->setMaximumSize(40, 40);
    connect(pcmd, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return pcmd;
}

void Calculator::calculate() {
    double dOperand2 = m_stk.pop().toDouble();
    char strOperation = m_stk.pop().at(0).toLatin1();
    double dOperand1 = m_stk.pop().toDouble();
    double dResult = 0.;

    switch (strOperation) {
    case '/' : dResult = dOperand1 / dOperand2;
        break;
    case '*' : dResult = dOperand1 * dOperand2;
        break;
    case '-': dResult = dOperand1 - dOperand2;
        break;
    case '+' : dResult = dOperand1 + dOperand2;
    }

    m_plcd->display(dResult);
}

void Calculator::slotButtonClicked() {
    QString str = ((QPushButton *)sender())->text();

    if (str == "CE") {
        m_stk.clear();
        m_strDisplay = "";
        m_plcd->display("0");
        return;
    }
    if (str.contains(QRegExp("[0-9]"))) {
        if (m_strDisplay.size() < 11) {
            m_strDisplay += str;
            m_plcd->display(m_strDisplay);
        }
    } else if (str == ".") {
        if (!m_strDisplay.contains('.')) {
            if (m_strDisplay.isEmpty()) {
                m_strDisplay = "0.";
            } else if (m_strDisplay.size() < 11) {
                m_strDisplay += str;
            }
            m_plcd->display(m_strDisplay);
        }
    } else {
        if (m_stk.count() >= 2) {
            m_stk.push(QString().setNum(m_plcd->value()));
            calculate();
            m_stk.clear();
            m_stk.push(QString().setNum(m_plcd->value()));
            m_strDisplay = "";
            if (str != "=") {
                m_stk.push(str);
            }
        } else {
            if (str != "=") {
                m_stk.push(QString().setNum(m_plcd->value()));
                m_stk.push(str);
            }
            m_strDisplay = "";
        }
    }
}
