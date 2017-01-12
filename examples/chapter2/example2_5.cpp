#include <opencv2/opencv.hpp>
using namespace cv;
void example2_5(cv::Mat & image){
	Mat out;
	namedWindow("input",WINDOW_AUTOSIZE);
	namedWindow("output",WINDOW_AUTOSIZE);
		
	imshow("input", image);
		
	GaussianBlur(image, out, Size(5,5) ,3, 3);
	GaussianBlur(  out, out, Size(5,5) ,3, 3);
	
	imshow("output",out);
	
	waitKey(0);
	}


int main(int argc, char **argv){
	Mat input;
	input = imread(argv[1]);
	example2_5(input);
	return 0;
	}
