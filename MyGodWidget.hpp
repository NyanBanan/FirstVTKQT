//
// Created by nyanbanan on 17.02.24.
//

#ifndef FIRSTVTKQT_MYGODWIDGET_HPP
#define FIRSTVTKQT_MYGODWIDGET_HPP

#include <QDir>
#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenuBar>
#include <QVTKInteractor.h>
#include <QVTKOpenGLNativeWidget.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowCollection.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageData.h>
#include <vtkPiecewiseFunction.h>
#include <vtkVolumeMapper.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>

#include "DicomWidget.hpp"

class MyGodWidget : public QMainWindow {
    Q_OBJECT
public:
    explicit MyGodWidget(QWidget* parent = nullptr);
    ~MyGodWidget() override = default;

private slots:
    void openFile();
    void vtk(QDir dir);
    void addDataSet(QDir dir);

private:
    void initMenu();
    void initTool();
    void initDocker();

    int _count{0};
    QFrame _frame{};
    QMdiArea _mdi{};
    QGridLayout _grid_layout{};
    QLabel _file_loc{};
    QLabel _location{};

    vtkSmartPointer<vtkRenderer> _vtk_ren;
    vtkSmartPointer<vtkImageData> _data{vtkImageData::New()};
};

#endif    //FIRSTVTKQT_MYGODWIDGET_HPP
