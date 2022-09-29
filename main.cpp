#include <opencv2/opencv.hpp>
#include <iostream>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"



using namespace cv;   //to avoid using this cv::imread(...) every line we use
using namespace std;   //to avoid using this std::cout  every line we use

int main(int argc, char** argv)
{
 // Read the image file
 // this image will bw a Mat object .. and will be accept Mat operations

Mat image = imread("D:/cpp_opencv_test/opencv_training/osama.jpg");

//Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30)); // to make an image yourself

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

bool isSuccess = imwrite("D:/cpp_opencv_test/opencv_training/firstcv.png", image); //write the image to a file as png
//bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG
if (isSuccess == false)
{
 cout << "Failed to save the image" << endl;
 cin.get(); //wait for a key press
 return -1;
}

cout << "Image is succusfully saved to a file" << endl;

////////////////////////////////////////////////////////////////////////////
// modifiing image brightness... pixel + n
Mat imageBrighnessHigh50;
image.convertTo(imageBrighnessHigh50, -1, 1, 100); //increase the brightness by 50
bool bright = imwrite("D:/cpp_opencv_test/opencv_training/modifiedBraightness.png", imageBrighnessHigh50); //write the image to a file as JPEG 



// modifiing image contrast.... pixel x n

Mat imagecontrastx2;
image.convertTo(imagecontrastx2, -1, 2, 0); //increase the contrast by *2
bool contrast = imwrite("D:/cpp_opencv_test/opencv_training/modifiedcontrast.png", imagecontrastx2); //write the image to a file as JPEG 


//////////////////////////////////////////////////////////////////////////
// equalizing  grey image histogram 
//change the color image to grayscale image

Mat image2;

cvtColor(image, image2, COLOR_BGR2GRAY); 


imwrite("D:/cpp_opencv_test/opencv_training/before_modify_histogram_grey.png", image2); //write the image to a file as JPEG                             


//equalize the histogram
Mat hist_equalized_image;
equalizeHist(image2, hist_equalized_image); 

bool hist_bool = imwrite("D:/cpp_opencv_test/opencv_training/modified_grey_histogram.png", hist_equalized_image); //write the image to a file as JPEG                             


////////////////////////////////////////////////////////////////////////////////////


//Convert the image from BGR to YCrCb color space 
//In this color space, Y channel only contains intensity information while Cr and Cb channels contain color information. 
//Therefore only the Y channel needs to be processed in order to equalize the histogram.
Mat hist_color_equalized_image;
cvtColor(image, hist_color_equalized_image, COLOR_BGR2YCrCb);


//Split the image into 3 channels; Y, Cr and Cb channels respectively and store it in a std::vector
vector<Mat> vec_channels;
split(hist_color_equalized_image, vec_channels); 


//Equalize the histogram of only the Y channel 
equalizeHist(vec_channels[0], vec_channels[0]);


//Merge 3 channels in the vector to form the color image in YCrCB color space.
merge(vec_channels, hist_color_equalized_image); 
    

//Convert the histogram equalized image from YCrCb to BGR color space again
cvtColor(hist_color_equalized_image, hist_color_equalized_image, COLOR_YCrCb2BGR);

bool hist_color_bool = imwrite("D:/cpp_opencv_test/opencv_training/modified_color_histogram.png", hist_color_equalized_image); //write the image to a file as JPEG                             
/////////////////////////////////////////////////////////////////////////


//homogenius Blur the image with 3x3 kernel
Mat image_blurred_with_3x3_kernel;
blur(image, image_blurred_with_3x3_kernel, Size(5, 5));

bool blurred_bool = imwrite("D:/cpp_opencv_test/opencv_training/image_blurred_with_3x3_kernel.png", image_blurred_with_3x3_kernel); 


//gaussian  Blur the image with 3x3 kernel , The standard deviation in the X direction and the Y direction of the Gaussian distribution will be calculated based on the size of the kernel.
Mat gaussian_blurred_with_3x3_kernel;
GaussianBlur(image, gaussian_blurred_with_3x3_kernel, Size(5, 5),0);

bool gaussian_blurred_bool = imwrite("D:/cpp_opencv_test/opencv_training/gaussian_blurred_with_3x3_kernel.png", gaussian_blurred_with_3x3_kernel); 

///////////////////////////////////////////////////////////////////////////////////////

//Erode the image with 3x3 kernel (each pixel value of the resultant image is calculated as the minimum value of the neighborhood)
Mat image_eroded_with_3x3_kernel;
erode(image, image_eroded_with_3x3_kernel, getStructuringElement(MORPH_RECT, Size(5, 5)));

bool image_eroded_with = imwrite("D:/cpp_opencv_test/opencv_training/image_eroded_with_3x3_kernel.png", image_eroded_with_3x3_kernel); 


//dilate the image with 3x3 kernel (each pixel value of the resultant image is calculated as the max value of the neighborhood)
//Mat image_dilated_with_3x3_kernel;
//dilate(image, image_dilated_with_3x3_kernel,0,2) ;
//bool image_dilated_with = imwrite("D:/cpp_opencv_test/opencv_training/image_dilated_with_3x3_kernel.png", image_dilated_with_3x3_kernel); 

/////////////////////////////////////////////////////////////////////////////////////////////////

// displaying image in a window

 namedWindow("The man", WINDOW_NORMAL); // Create a window
 imshow("The man", image); // Show our image inside the created window.



///////////////////////////////////////////////////////////////////////////////////////////
// creating track bar



//Create track bar to change brightness
int iSliderValue1 = 50;
createTrackbar("Brightness", "The man", &iSliderValue1, 100);

//Create track bar to change contrast
int iSliderValue2 = 50;
createTrackbar("Contrast", "The man", &iSliderValue2, 100);

while (true)
{
    //Change the brightness and contrast of the image 
    
    Mat dst;
    int iBrightness  = iSliderValue1 - 50;
    double dContrast = iSliderValue2 / 50.0;
    image.convertTo(dst, -1, dContrast, iBrightness); 

    //show the brightness and contrast adjusted image
    imshow("The man", dst);

    // Wait until user press some key for 50ms
    int iKey = waitKey(50);

    //if user press 'ESC' key
    if (iKey == 27)
    {
        break;
    }
}









////////////////////////////////////////
waitKey(0); // Wait for any keystroke in the window
destroyAllWindows(); //Destroy all opened windows

 return 0;
}

