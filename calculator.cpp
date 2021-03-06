#include "calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent)
{
    what = new QLabel;
    lcd = new QLCDNumber(12);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setMinimumSize(150,50);
    QGridLayout* grid = new QGridLayout;
    QVBoxLayout* vert = new QVBoxLayout;
    QChar butt[5][5] =
    {
        {' ',' ',' ',' ',' '},
        {' ','1','2','3','C'},
        {' ','4','5','6','.'},
        {' ','7','8','9','='},
        {' ','+','-','*','/'},
    };
    grid->addWidget(lcd,1,1,1,4);
    vert->addWidget(what);
    for(int f = 1; f < 5;f++)
        for(int s = 1; s < 5;s++)
        {
            grid->addWidget(Create_Button(butt[f][s]),f + 1,s);
        }
    grid->addLayout(vert,0,1);
    setLayout(grid);
}


QPushButton* Calculator::Create_Button(QString name)
{
    QPushButton* button = new QPushButton(name);
    button->setMinimumSize(30,30);
    QObject::connect(button,SIGNAL(clicked()),SLOT(button_clicked()));
            return button;
}
//Solve:
void Calculator::solve()
{
    int first = stack.pop().toInt();
    char* ch = stack.pop().toAscii().data();
    int second = stack.pop().toInt();
    int result;
    switch(*ch)
    {
    case '+':
        result = first + second;
        break;
    case '-':
        result = first - second;
        break;
    case '*':
        result = first * second;
        break;
    case '/':
        result = first / second;
        break;
    }
    lcd->display(result);
}

void Calculator::button_clicked()
{
    QString str = ((QPushButton*)sender())->text();

    if(str == "C")
    {
        input = "";
        stack.clear();
        lcd->display("C");
    }
    else if(str.contains(QRegExp("[0-9]")))
    {
            input += str;
            lcd->display(input);
    }
    else if(str == "A")
    {
        //TODO:ADD ABOUT PAGE!
    }
    //TODO:Change this algorithm!
    //Warning! Bad algorithm, not working whell!
    else if(stack.count() >= 2)
    {
        stack.push(QString().setNum(lcd->value()));
        solve();
        stack.clear();
        stack.push(QString().setNum(lcd->value()));
        input = "";
        if(str != "=")
        {
            stack.push(str);
        }
        else if(str == "=")
        {
            stack.clear();
        }
    }
    else
    {
        stack.push(QString().setNum(lcd->value()));
        stack.push(str);
        what->setText("You choose = " "\""+str+"\"");
        input = "";
        lcd->display("0");

}
}
