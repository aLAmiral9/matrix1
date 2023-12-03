#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // Baca gambar dari file
    cv::Mat image = cv::imread("Chris_Hemsworth.jpg");

    if (image.empty()) {
        std::cerr << "Error: Unable to read the image!" << std::endl;
        return -1;
    }

    // Ubah gambar menjadi efek matriks sederhana
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            cv::Vec3b& pixel = image.at<cv::Vec3b>(i, j);
            pixel[0] = 255 - pixel[0]; // Mengubah warna biru
            pixel[1] = 255 - pixel[1]; // Mengubah warna hijau
            pixel[2] = 255 - pixel[2]; // Mengubah warna merah
        }
    }

    // Tampilkan gambar efek matriks
    cv::imshow("Matrix Effect", image);
    cv::waitKey(0);

    return 0;
}
