//display a picture
//page:23
#include <opencv2/opencv.hpp>
//using namespace cv; 
//made tedious on purpose
int main(int argc, char ** argv){
	cv::Mat img = cv::imread(argv[1],-1);
	if(img.empty()){
		return -1;
		}
		cv::namedWindow("Example1",cv::WINDOW_AUTOSIZE);
		cv::imshow("Example1", img);
		cv::waitKey(0);
		cv::destroyWindow("Example1");  //openCV3 handles this for you but we're doing it anyway
		
	return 0;
	}
