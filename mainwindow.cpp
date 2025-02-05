#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <curl/curl.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), curl(nullptr)
{
    ui->setupUi(this);

    // Initialize libcurl in the constructor
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Initialize curl member variable
    curl = curl_easy_init();

    // Perform libcurl operations
    performCurlOperations();
}

MainWindow::~MainWindow() //postman for apisss
{
    // Cleanup libcurl and curl instance in the destructor
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    delete ui;
}

void MainWindow::performCurlOperations()
{
    if (curl) {
        // Set the URL for the request
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts/1");

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
    }
}
