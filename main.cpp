#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;   //to avoid using this cv::imread(...) every line we use
using namespace std;   //to avoid using this std::cout  every line we use

int main(int argc, char** argv)
{
 // Read the image file
 // this image will bw a Mat object .. and will be accept Mat operations
 // Mat image = imread("D:/cpp_opencv_test/opencv_training/lenna.png");

Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));

 // Check for failure
 if (image.empty()) 
 {
  cout << "Could not open or find the image" << endl;
  cin.get(); //wait for any key press
  return -1;
 }
 cout << "Chiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii" << endl;

////////////////////////////////////////////////////////////////////////
// saving image obj as a file

bool isSuccess = imwrite("D:/cpp_opencv_test/opencv_training/firstcv.png", image); //write the image to a file as JPEG 
//bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG
if (isSuccess == false)
{
 cout << "Failed to save the image" << endl;
 cin.get(); //wait for a key press
 return -1;
}

cout << "Image is succusfully saved to a file" << endl;

////////////////////////////////////////////////////////////////////
// modifiing image
Mat imageBrighnessHigh50;
image.convertTo(imageBrighnessHigh50, -1, 1, 100); //increase the brightness by 50

bool beSuccess = imwrite("D:/cpp_opencv_test/opencv_training/modified.png", imageBrighnessHigh100); //write the image to a file as JPEG 
//bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG





/////////////////////////////////////////////////////////
// displaying image in a window

 namedWindow("The girl"); // Create a window
 imshow("The girl", image); // Show our image inside the created window.




////////////////////////////////////////
 waitKey(0); // Wait for any keystroke in the window
 destroyWindow("The girl"); //destroy the created window

 return 0;
}

