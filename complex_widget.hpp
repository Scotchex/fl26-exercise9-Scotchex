////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#ifndef COMPLEX_WIDGET_H
#define COMPLEX_WIDGET_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QPushButton;

class ComplexWidget : public QWidget
{
    Q_OBJECT

public:
    // this is the top level widget so no need for a parent
    explicit ComplexWidget(QWidget *parent = nullptr);

    double getRealPart();
    double getImaginaryPart();
    double getMagnitude();
    double getPhase();

private slots:
    void updateDisplay();

private:
    QLineEdit *realPart;
    QLineEdit *imaginaryPart;

    QLabel *showMagnitude;
    QLabel *showPhase;

    QPushButton *updateButton;
};

#endif
