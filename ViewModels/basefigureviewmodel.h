
#ifndef BASEFIGUREVIEWMODEL_H
#define BASEFIGUREVIEWMODEL_H

#include "Models/basefiguremodel.h"

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDoubleValidator>

class FigureViewModelSettings{
public:

    QString imagePath = nullptr;
    QString squareFormula = nullptr;

    FigureViewModelSettings(const QString& imagePath, const QString& squareFormula){
        this->imagePath = imagePath;
        this->squareFormula = squareFormula;
    }
};

class BaseFigureViewModel : public QWidget
{
    Q_OBJECT
public:
    explicit BaseFigureViewModel(QWidget *parent = nullptr);
    ~BaseFigureViewModel();
    virtual void ClearInputForms() = 0;

protected:
    virtual void LoadImage(const QString& imagePath);
    virtual void SetImageSize();
    virtual void SetupImage();
    virtual void SetupInputForms() = 0;
    virtual void SetupCalculateButton();
    virtual void SetupFormula(const QString& squareFormula);

    void Setup(const FigureViewModelSettings& setupSettings);

    void ShowCalcResults(BaseFigureModel* figure, const QString& messageHeader, const QString& messageBody);

protected:
    // ставим валидацию на форме
    QDoubleValidator *validator = nullptr;

    QLabel *image = nullptr;
    QPixmap* pixmap = nullptr;
    QVBoxLayout* layout = nullptr;

private:
    void SetupValidator();

    size_t imageWidthPx;
    size_t imageHeightPx;

protected slots:
    virtual void ProvideCalculateLogicFromModel() = 0;
};

#endif // BASEFIGUREVIEWMODEL_H
