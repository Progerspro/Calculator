#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QStack>
#include <QLabel>
class Calculator : public QWidget
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = 0);
    QStack<QString> stack;
    QString* test;
    QLCDNumber* lcd;
    QPushButton* Create_Button(QString name);
    QString input;
    void solve();
public slots:
void button_clicked();
};

#endif // CALCULATOR_H
