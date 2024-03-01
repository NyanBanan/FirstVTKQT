//
// Created by nyanbanan on 18.02.24.
//

#include "DicomWidget.hpp"

DICOMWidget::DICOMWidget(QDir source_dir, QWidget* parent) : QVTKOpenGLNativeWidget(parent) {
    auto window = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    setRenderWindow(window);

    auto vtk_ren = vtk::MakeSmartPointer(vtkRenderer::New());

    auto dicom_reader = vtkSmartPointer<vtkDICOMImageReader>::New();
    dicom_reader->SetDirectoryName(source_dir.path().toStdString().c_str());
    dicom_reader->SetDataScalarTypeToUnsignedShort();
    dicom_reader->UpdateWholeExtent();
    dicom_reader->Update();

    auto data = vtkSmartPointer<vtkImageData>::New();
    data->ShallowCopy(dicom_reader->GetOutput());

    auto volume_mapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
    volume_mapper->SetBlendModeToComposite();
    volume_mapper->SetRequestedRenderModeToGPU();
    volume_mapper->SetInputData(data);

    auto volume_property = vtkSmartPointer<vtkVolumeProperty>::New();
    volume_property->SetInterpolationTypeToLinear();
    volume_property->ShadeOn();
    volume_property->SetAmbient(0.1);
    volume_property->SetDiffuse(0.9);
    volume_property->SetSpecular(0.2);
    volume_property->SetSpecularPower(10.0);

    auto gradient_opacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
    gradient_opacity->AddPoint(0.0, 0.0);
    gradient_opacity->AddPoint(2000.0, 1.0);

    volume_property->SetGradientOpacity(gradient_opacity);

    auto scalar_opacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
    scalar_opacity->AddPoint(-800.0, 0.0);
    scalar_opacity->AddPoint(-750.0, 1.0);
    scalar_opacity->AddPoint(-350.0, 1.0);
    scalar_opacity->AddPoint(-300.0, 0.0);
    scalar_opacity->AddPoint(-200.0, 0.0);
    scalar_opacity->AddPoint(-100.0, 1.0);
    scalar_opacity->AddPoint(1000.0, 0.0);
    scalar_opacity->AddPoint(2750.0, 0.0);
    scalar_opacity->AddPoint(2976.0, 1.0);
    scalar_opacity->AddPoint(3000.0, 1.0);

    volume_property->SetScalarOpacity(scalar_opacity);

    auto color = vtkSmartPointer<vtkColorTransferFunction>::New();
    color->AddRGBPoint(-750.0, 0.08, 0.05, 0.03);
    color->AddRGBPoint(-350.0, 0.39, 0.25, 0.16);
    color->AddRGBPoint(-200.0, 0.80, 0.80, 0.80);
    color->AddRGBPoint(2750.0, 0.70, 0.70, 0.70);
    color->AddRGBPoint(3000.0, 0.35, 0.35, 0.35);

    volume_property->SetColor(color);

    auto volume = vtkSmartPointer<vtkVolume>::New();
    volume->SetMapper(volume_mapper);
    volume->SetProperty(volume_property);

    vtk_ren->SetBackground(0.2, 0.2, 0.2);
    vtk_ren->AddVolume(volume);
    vtk_ren->ResetCamera();

    renderWindow()->AddRenderer(vtk_ren);
}
