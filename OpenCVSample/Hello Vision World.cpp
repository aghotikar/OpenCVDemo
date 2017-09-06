// Hello Vision World.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace cv;
using namespace std;

void performImageOperations(Mat img, int scalar) {
  Mat add_img;
  Mat subtract_img;
  Mat multiply_img;
  Mat divide_img;
  Mat resize_img;

  // Add a scalar to the image
  add_img = img + scalar;
  namedWindow("Added image window", WINDOW_NORMAL);
  imshow("Added image window", add_img);
  waitKey(0);

  // Subtract a scalar from the image
  subtract_img = img - scalar;
  namedWindow("Subtracted image window", WINDOW_NORMAL);
  imshow("Subtracted image window", subtract_img);
  waitKey(0);

  // Multiply the image with a scalar
  multiply_img = img * scalar;
  namedWindow("Multiplied image window", WINDOW_NORMAL);
  imshow("Multiplied image window", multiply_img);
  waitKey(0);

  // Divide the image with a scalar
  divide_img = img / scalar;
  namedWindow("Divided image window", WINDOW_NORMAL);
  imshow("Divided image window", divide_img);
  waitKey(0);

  // resize the image
  resize(img, resize_img, Size(), 0.5, 0.5, CV_INTER_AREA);
  namedWindow("Display resized window", WINDOW_NORMAL);
  imshow("Display resized window", resize_img);
  waitKey(0);
}

int main() {

  string filePath = "";
  int scalar;
  Mat img;

  // Read the file path as input
  cout << "Enter the file path:" << std::endl;
  cin >> filePath;

  // Read the image from the specified file
  img = imread(filePath, IMREAD_COLOR);

  // Create a frame in which the image will be displayed
  namedWindow("Display window", WINDOW_NORMAL);

  // Check if the image is valid
  if (!img.data) {
    cout << "The image cannot be opened/found." << std::endl;
    waitKey(0);
    return -1;
  } else {
    imshow("Display window", img);
    waitKey(0);
    destroyAllWindows();

    // Read the scalar as input
    cout << "Enter the scalar to [add,subtract,multiply,divide] to the image:";
    cin >> scalar;
    performImageOperations(img, scalar);

    return 0;
  }
}
