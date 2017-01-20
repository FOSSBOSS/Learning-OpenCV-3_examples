//display a picture
//page:23
#include <opencv2/opencv.hpp>
using namespace cv; 

int main(int argc, char ** argv){
	Mat img = imread(argv[1],-1);
	if(img.empty()){
		return -1;
		}
		namedWindow("Example1",WINDOW_AUTOSIZE);
		imshow("Example1", img);
		waitKey(0);
		destroyWindow("Example1");  //openCV3 handles this for you but we're doing it anyway
		
	return 0;
	}
