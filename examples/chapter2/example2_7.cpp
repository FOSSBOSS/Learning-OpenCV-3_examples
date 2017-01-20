#include <opencv2/opencv.hpp>
using namespace cv; 

int main(int argc, char ** argv){
	
Mat img_rgb, img_gray, img_cny;

img_rgb=imread(argv[1]);  //get an image

namedWindow("Source", WINDOW_AUTOSIZE);	 // I'd call it src.
namedWindow("Gray", WINDOW_AUTOSIZE);	
namedWindow("Canny", WINDOW_AUTOSIZE);	



cvtColor(img_rgb, img_gray, COLOR_BGR2GRAY);
Canny(img_gray, img_cny,10,100,3,true);

imshow("Source",img_rgb);
imshow("Gray",img_gray);
imshow("Canny",img_cny);
waitKey(0);
	return 0;  //not in book example, pg 34
	}
