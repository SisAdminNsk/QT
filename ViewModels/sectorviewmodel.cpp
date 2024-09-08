
#include "sectorviewmodel.h"

SectorViewModel::SectorViewModel(QWidget *parent) : BaseFigureViewModel(parent)
{
    this->sectorModel = new SectorModel();

    auto settings = FigureViewModelSettings(
        QString::fromStdString(":/resource/Images/sector.png"),
        QString::fromStdString("S = (PI * R^2 * ALPHA / 360)"));

    this->Setup(settings);
}

SectorViewModel::~SectorViewModel(){
    delete this->sectorModel;
    delete inputAlphaForm;
    delete inputRadiousForm;
}

void SectorViewModel::SetupInputForms(){

    inputAlphaForm = new QLineEdit(this);
    inputAlphaForm->setPlaceholderText("Введите значение для угла сектора:");
    inputAlphaForm->setValidator(validator);
    layout->addWidget(inputAlphaForm);

    inputRadiousForm = new QLineEdit(this);
    inputRadiousForm->setPlaceholderText("Введите значение для радиуса сектора:");
    inputRadiousForm->setValidator(validator);
    layout->addWidget(inputRadiousForm);
}

void SectorViewModel::ProvideCalculateLogicFromModel(){

    bool ok;
    auto inputRadious = inputRadiousForm->text();
    auto inputAlpha = inputAlphaForm->text();

    auto radious = inputRadious.toDouble(&ok);
    auto alpha = inputAlpha.toDouble(&ok);

    if(ok){
        this->sectorModel->alpha = alpha;
        this->sectorModel->radious = radious;
        ShowCalcResults(sectorModel, QString::fromStdString("Результат"), QString::fromStdString("Площадь сектора: "));
    }
}

