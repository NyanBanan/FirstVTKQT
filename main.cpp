#include <QtCore>
#include <QMainWindow>
#include <QMdiArea>
#include <QMenuBar>
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    window.setWindowTitle("Тестируем чтение DICOM");
    window.resize(1200, 800);

    QMdiArea mdi;
    window.setCentralWidget(&mdi);

    return app.exec();
}
