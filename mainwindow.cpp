#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a QLabel to display the image
    imageLabel = new QLabel(this);

    // Specify the path to your image file
    QString imagePath = ":/World_Map.jpg";

    // Load the image into a QPixmap
    QPixmap pixmap(imagePath);

    // Check if the image was loaded successfully
    if (!pixmap.isNull())
    {
        // Set the pixmap to the QLabel
        imageLabel->setPixmap(pixmap);

        // Optionally, scale the image to fit the QLabel
        imageLabel->setScaledContents(true);
    }
    else
    {
        // Handle the error if the image couldn't be loaded
        qDebug() << "Image not found at path:" << imagePath;
    }

    // Optionally, set the QLabel's position and size
    imageLabel->setGeometry(10, 10, 1900, 990); // Adjust size as needed
}

MainWindow::~MainWindow()
{
    delete ui;
}
