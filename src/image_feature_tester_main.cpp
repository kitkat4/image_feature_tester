#include <QtWidgets>
#include <opencv2/opencv.hpp>

/* #include <QHBoxLayout>
#include <QGraphicsView>
 */
int main(int argc, char** argv){

    QApplication app(argc, argv);

    QWidget window;

    QGraphicsView* graphics_view_1 = new QGraphicsView;
    QGraphicsView* graphics_view_2 = new QGraphicsView;
    
    QHBoxLayout* layout = new QHBoxLayout;

    window.resize(250, 150);
    window.setWindowTitle("Image Feature Tester");
    window.show();

    QString file_name = QFileDialog::getOpenFileName(&window, "ファイル選択画面");

    cv::Mat img = cv::imread(file_name.toStdString(), cv::IMREAD_COLOR);
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    QImage qimg((uchar*)img.data, img.cols, img.rows, 
                img.step, QImage::Format_RGB888);

    QGraphicsPixmapItem* pixmap_item = 
        new QGraphicsPixmapItem(QPixmap::fromImage(qimg));

    QGraphicsScene* scene = new QGraphicsScene;
    scene->addItem(pixmap_item);

    graphics_view_1->setScene(scene);

    QPushButton* button = new QPushButton("test button");
    
    layout->addWidget(graphics_view_1);
    layout->addWidget(graphics_view_2);
    layout->addWidget(button);

    window.setLayout(layout);

    return app.exec();
}
