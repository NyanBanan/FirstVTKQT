//
// Created by nyanbanan on 18.02.24.
//

#ifndef FIRSTVTKQT_DICOMWIDGET_HPP
#define FIRSTVTKQT_DICOMWIDGET_HPP
//Qt
#include <QDir>
//VTK
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkDICOMImageReader.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkImageData.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
//QtVTK
#include <QVTKOpenGLNativeWidget.h>

class DICOMWidget : public QVTKOpenGLNativeWidget{
public:
    DICOMWidget(QDir source_dir, QWidget* parent = nullptr);
};

#endif    //FIRSTVTKQT_DICOMWIDGET_HPP
