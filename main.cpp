#include "calculator.h"
#include "QApplication"
int main(int argc,char* argv[])
{
    QApplication a(argc,argv);
    Calculator calc;
    calc.setWindowTitle("Calculator ALPHA 0.1");
    calc.resize(200,200);
    calc.show();
    return a.exec();
}

