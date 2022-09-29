#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;   //to avoid using this cv::imread(...) every line we use
using namespace std;   //to avoid using this std::cout  every line we use

int main(int argc, char** argv)
{
 // Read the image file
 // this image will bw a Mat object .. and will be accept Mat operations
 Mat image = imread("D:/cpp_opencv_test/opencv_training/lenna.png");



 // Check for failure
 if (image.empty()) 
 {
  cout << "Could not open or find the image" << endl;
  cin.get(); //wait for any key press
  return -1;
 }
 cout << "Chiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii" << endl;





 String windowName = "The Guitar"; //Name of the window

 namedWindow(windowName); // Create a window

 imshow(windowName, image); // Show our image inside the created window.

 waitKey(0); // Wait for any keystroke in the window

 destroyWindow(windowName); //destroy the created window

 return 0;
}

