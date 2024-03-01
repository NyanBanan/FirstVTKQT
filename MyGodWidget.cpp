//
// Created by nyanbanan on 17.02.24.
//

#include "MyGodWidget.hpp"

#include <vtkSmartVolumeMapper.h>

MyGodWidget::MyGodWidget(QWidget* parent) : QMainWindow(parent) {
    setWindowIcon(QIcon("icons/schwi_icon.png"));
    setWindowTitle("Тестируем чтение DICOM");
    resize(1200, 800);

    setCentralWidget(&_mdi);

    initMenu();
    initTool();
    initDocker();
}

void MyGodWidget::initMenu() {
    auto menu = this->menuBar();
    auto file = menu->addMenu("File");

    auto new_action = file->addAction(QIcon("icons/plus_icon.png"), "Новый", QKeySequence("Ctrl+N"));
    QWidget::connect(new_action, SIGNAL(triggered()), this, SLOT(openFile()));
}

void MyGodWidget::openFile() {
    ++_count;
    QDir dir = QFileDialog::getExistingDirectory(this, "Выберите папку");
    if (dir.exists()) {
        vtk(dir);
    }
}

void MyGodWidget::vtk(QDir dir) {
    //    addDataSet(dir);

    auto sub = new QMdiSubWindow{&_mdi};
    sub->setWindowTitle(QString("Dataset %1").arg(_count));

    auto dicom = new DICOMWidget{dir, sub};
    sub->setWidget(dicom);

    _mdi.addSubWindow(sub);
    sub->resize(100,100);
    sub->show();
}

void MyGodWidget::addDataSet(QDir dir) {
    auto file_loc = new QLabel(QString("File location %1:").arg(_count));
    auto location = new QLabel(dir.path());

    _grid_layout.addWidget(file_loc, _count, 0);
    _grid_layout.addWidget(location, _count, 1);
}

void MyGodWidget::initTool() {}

void MyGodWidget::initDocker() {}
