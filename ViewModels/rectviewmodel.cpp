
#include <QMessageBox>
#include "Models/rectmodel.h"
#include "rectviewmodel.h"

RectViewModel::RectViewModel(QWidget *parent) : BaseFigureViewModel(parent)
{
    this->rectModel = new RectModel();

    auto settings = FigureViewModelSettings(
        QString::fromStdString(":/resource/Images/rect.png"),
        QString::fromStdString("S=(A*B)"));

    this->Setup(settings);
}

RectViewModel::~RectViewModel(){
    delete this->rectModel;
    delete this->inputRectSightA;
    delete this->inputRectSightB;
}

void RectViewModel::SetupInputForms(){

    inputRectSightA = new QLineEdit(this);
    inputRectSightB = new QLineEdit(this);

    inputRectSightA->setPlaceholderText("Введите значение для стороны A:");
    inputRectSightB->setPlaceholderText("Введите значение для стороны B");

    inputRectSightA->setValidator(validator);
    inputRectSightB->setValidator(validator);

    layout->addWidget(inputRectSightA);
    layout->addWidget(inputRectSightB);
}

void RectViewModel::ProvideCalculateLogicFromModel(){

    bool ok;
    auto inputTextASight = inputRectSightA->text();
    auto inputTextBSight = inputRectSightB->text();

    auto aSight = inputTextASight.toDouble(&ok);
    auto bSight = inputTextBSight.toDouble(&ok);

    if(ok){
        this->rectModel->sightA = aSight;
        this->rectModel->sightB = bSight;

        ShowCalcResults(rectModel, QString::fromStdString("Результат"), QString::fromStdString("Плошадь прямоугольника: "));
    }
}
