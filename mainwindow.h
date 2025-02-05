#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <curl/curl.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CURL* curl; // Declare a CURL* member variable

    // Function to perform libcurl operations
    void performCurlOperations();
};
#endif // MAINWINDOW_H
