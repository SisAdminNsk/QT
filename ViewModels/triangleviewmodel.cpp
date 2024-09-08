
#include "triangleviewmodel.h"
#include <QMessageBox>

TriangleViewModel::TriangleViewModel(QWidget *parent) : BaseFigureViewModel(parent)
{
    this->triangleModel = new TriangleModel();

    auto settings = FigureViewModelSettings(
        QString::fromStdString(":/resource/Images/triangle.png"),
        QString::fromStdString("S = (A * H / 2"));

    this->Setup(settings);
}

TriangleViewModel::~TriangleViewModel(){
    delete this->triangleModel;
    delete inputTriangleBaseField;
    delete inputTriangleHeightField;
}

void TriangleViewModel::ClearInputForms(){
    this->inputTriangleBaseField->clear();
    this->inputTriangleHeightField->clear();
}

void TriangleViewModel::SetupInputForms(){

    inputTriangleBaseField = new QLineEdit(this);
    inputTriangleBaseField->setPlaceholderText("Введите значение для основания треугольника:");
    inputTriangleBaseField->setValidator(validator);
    layout->addWidget(inputTriangleBaseField);

    inputTriangleHeightField = new QLineEdit(this);
    inputTriangleHeightField->setPlaceholderText("Введите значение для высоты треугольника:");
    inputTriangleHeightField->setValidator(validator);
    layout->addWidget(inputTriangleHeightField);
}

void TriangleViewModel::ProvideCalculateLogicFromModel(){

    bool ok;
    auto inputBaseText = inputTriangleBaseField->text();
    auto inputHeightText = inputTriangleHeightField->text();

    auto triangleBaseSight = inputBaseText.toDouble(&ok);
    auto triangleHeightSight = inputHeightText.toDouble(&ok);

    if(ok){
        this->triangleModel->base = triangleBaseSight;
        this->triangleModel->height = triangleHeightSight;

        ShowCalcResults(triangleModel, QString::fromStdString("Результат"),QString::fromStdString("Плошадь треугольника: "));
    }
}
