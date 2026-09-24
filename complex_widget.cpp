////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#include "complex_widget.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#include <cmath>

ComplexWidget::ComplexWidget(QWidget *parent) : QWidget(parent)
{
    realPart = new QLineEdit("0.0", this);
    imaginaryPart = new QLineEdit("0.0", this);

    showMagnitude = new QLabel("0.0", this);
    showPhase = new QLabel("0.0", this);

    updateButton = new QPushButton("Update", this);

    auto *layout = new QGridLayout(this);

    layout->addWidget(new QLabel("Real part:"), 0, 0);
    layout->addWidget(new QLabel("Imaginary part:"), 0, 2);
    layout->addWidget(new QLabel("Magnitude:"), 1, 0);
    layout->addWidget(new QLabel("Phase:"), 1, 2);
    layout->addWidget(realPart, 0, 1);
    layout->addWidget(imaginaryPart, 0, 3);
    layout->addWidget(showMagnitude, 1, 1);
    layout->addWidget(showPhase, 1, 3);
    layout->addWidget(updateButton, 3, 2);

    connect(updateButton, &QPushButton::clicked, this, &ComplexWidget::updateDisplay);
}

double ComplexWidget::getRealPart()
{
    return realPart->text().toDouble();
}

double ComplexWidget::getImaginaryPart()
{
    return imaginaryPart->text().toDouble();
}

double ComplexWidget::getMagnitude()
{
    return std::hypot(getRealPart(), getImaginaryPart());
}

double ComplexWidget::getPhase()
{
    return std::atan2(getImaginaryPart(), getRealPart());
}

void ComplexWidget::updateDisplay()
{
    showMagnitude->setText(QString::number(getMagnitude()));
    showPhase->setText(QString::number(getPhase()));
}