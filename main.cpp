////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//

#include "complex_widget.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ComplexWidget widget;
    widget.setWindowTitle("Exercise 9");
    widget.show();

    return app.exec();
}
