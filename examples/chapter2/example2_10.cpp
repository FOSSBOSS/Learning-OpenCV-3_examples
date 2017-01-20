//video: page 35,36
//its not streaming, I need to figure that out. 
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv; 
using namespace std;

int main(int argc, char ** argv){
namedWindow("Video", WINDOW_AUTOSIZE);
Mat frame;
VideoCapture cap(0);
if(argc==1){
	cap.open(0); // open /dev/video0
	}else{
		cap.open(string(argv[1])); //open the specified number somewhere in this book I saw a table for that.
		}
		
	if(!cap.isOpened()){ //videoCapture doesnt have an empty function
		cerr << "cannot capture video stream\n";
		return -1;
		}	
		
for(;;){
	cap >> frame;
	if(frame.empty()){
		break;
		}
		imshow("Video",frame);//I'm currious why openCV doesnt have a direct viewing function for Video Capture. 
		if(waitKey(33) >=0 ){
			break;
			}
	}


waitKey(0);
	return 0;  //not in book example, pg 34
	}
