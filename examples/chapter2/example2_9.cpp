//Examples 2-8, 2-9,, are extended version of example 2.7

//Getting, and setting pixels 
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv; 
using namespace std;

int main(int argc, char ** argv){

Mat img_rgb, img_gray, img_cny, img_pyr0, img_pyr1;

img_rgb=imread(argv[1]);  //get an image

int x=16, y=32;
Vec3b intensity = img_rgb.at< Vec3b >(x,y); //set, but not used. page35
uchar blue=intensity[0];
uchar green=intensity[1];
uchar red =intensity[2];

namedWindow("Source", WINDOW_AUTOSIZE);	 
namedWindow("Gray", WINDOW_AUTOSIZE);	
namedWindow("Canny", WINDOW_AUTOSIZE);	

cvtColor(img_rgb, img_gray, COLOR_BGR2GRAY);
pyrDown(img_gray, img_pyr0); //produces an image half the x,y pixels of the first image.
pyrDown(img_pyr0, img_pyr1); //Half again
Canny(img_pyr1,img_cny,10,100,3,true);

cout << "At point (x,y) = (" << x << "," << y << ") blue, green, red = (" << (unsigned int)blue <<", " << (unsigned int)green <<", " << (unsigned int)red <<")\n "; 
cout << "The Gray pixel there is: " << (unsigned int)img_gray.at<uchar>(x,y) << "\n"; 
x/=4;
y/=4;
cout << "Pyramid pixel there is: " << (unsigned int)img_pyr1.at<uchar>(x,y) << "\n";

img_cny.at<uchar>(x,y) = 128; //set pixel at this location to 128


imshow("Source",img_rgb);
imshow("Gray",img_pyr1);
imshow("Canny",img_cny);

waitKey(0);
	return 0;  //not in book example, pg 34
	}
