#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"



using namespace cv;   //to avoid using this cv::imread(...) every line we use
using namespace std;   //to avoid using this std::cout  every line we use


void image_process(string image_path , string new_name)

    {
        Mat image = imread(image_path);

        // Check for failure
        if (image.empty()) 
            {
            cout << "Could not open or find the image" << endl;
            cin.get(); //wait for any key press

            }

        Mat output_image;

///////////////////////////////////////////////////////////////////////////////////////////////////////


        erode(image, output_image, getStructuringElement(MORPH_RECT, Size(5, 5)));



        image.convertTo(output_image, -1, 1, 100); //increase the brightness by 50

        image.convertTo(output_image, -1, 2, 0); //increase the contrast by *2


        //homogenius Blur the image with 3x3 kernel
        blur(image, output_image, Size(5, 5));


        //gaussian  Blur the image with 3x3 kernel , The standard deviation in the X direction and the Y direction of the Gaussian distribution will be calculated based on the size of the kernel.
        //GaussianBlur(image, output_image, Size(5, 5),0);



        //Erode the image with 3x3 kernel (each pixel value of the resultant image is calculated as the minimum value of the neighborhood)
        //erode(image, output_image, getStructuringElement(MORPH_RECT, Size(5, 5)));


        //dilate the image with 3x3 kernel (each pixel value of the resultant image is calculated as the max value of the neighborhood)
        //dilate(image, output_image,0,2) ;
  






/////////////////////////////////////////////////////////////////////////////////////////////////

        bool saved_processed = imwrite("D:/cpp_opencv_test/opencv_training/image_function.png", image);
 

    };







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


//////////////////////////////////////////////////////////////////////////
// equalizing  grey image histogram 
//change the color image to grayscale image

Mat image2;
cvtColor(image, image2, COLOR_BGR2GRAY);                            
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
                       
/////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////////


image_process("D:/cpp_opencv_test/opencv_training/osama.jpg","jiiiiiiiiiii");





/////////////////////////////////////////////////////////////////////////////////////////////////

// displaying image in a window

 namedWindow("The man", WINDOW_NORMAL); // Create a window
// imshow("The man", image); // Show our image inside the created window.



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

