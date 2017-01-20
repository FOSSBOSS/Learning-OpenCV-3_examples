//Examples 2-8, 2-9, are extended version of example 2.7
#include <opencv2/opencv.hpp>
using namespace cv; 

int main(int argc, char ** argv){

Mat img_rgb, img_gray, img_cny, img_pyr0, img_pyr1;

img_rgb=imread(argv[1]);  //get an image thats right baby, no error checking

namedWindow("Source", WINDOW_AUTOSIZE);	 
namedWindow("Gray", WINDOW_AUTOSIZE);	
namedWindow("Canny", WINDOW_AUTOSIZE);	

cvtColor(img_rgb, img_gray, COLOR_BGR2GRAY);
pyrDown(img_gray, img_pyr0); //produces an image half the x,y pixels of the first image.
pyrDown(img_pyr0, img_pyr1); //Half again
Canny(img_pyr1,img_cny,10,100,3,true);

imshow("Source",img_rgb);
imshow("Gray",img_pyr1);
imshow("Canny",img_cny);

waitKey(0);
	return 0;  //not in book example, pg 34
	}
