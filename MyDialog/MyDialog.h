#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class MyDialog : public QDialog {
  Q_OBJECT

  public:
    MyDialog(QWidget * parent = 0) : QDialog(parent) { 
      QDialog * dialog = new QDialog(parent);
      QVBoxLayout * layout = new QVBoxLayout(this);
      QPushButton * button = new QPushButton(this);
      button->setText("Close");
      QLabel * label = new QLabel(this);
      label->setText("<font color = red>Hello!</font>");
      layout->addWidget(label);
      layout->addWidget(button);
      connect(button, SIGNAL(clicked()), this, SLOT(close()));
    }
}
