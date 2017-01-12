//Example 11-3,Log-Polar transform example
//Build Flags:
//g++ -Wall -g -o "example11_3" "example11_3.cpp" `pkg-config --cflags --libs opencv`
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;
int main(int argc, char **argv){
	 if(argc != 3){
	    cout << "Log Polar Usage:\n" << argv[0] << "<image name> <M Value>\n \t Defauly M value = 30 \n";
	    return -1;
	    }
	    
	Mat src = imread(argv[1],1);
	
	if(src.empty()){
		cout << "File not found, or un-readable" << argv[1] << "\n";
		return -1;
	} 
	    
	double M = atof(argv[2]);    //convert a string to a double 
	
	Mat dst(src.size(), src.type());
	Mat src2(src.size(), src.type());
	Point2f P(src.cols*0.5f,src.rows*0.5f); // loaction of point taken, 1,1 is lower right corner.
	logPolar(src, dst, P, M, INTER_LINEAR); // Broke this function up so I could undestand it, make it work.
	logPolar(dst, src2, P, M, WARP_INVERSE_MAP);
	
	//not in book, but makes looking at this easier for me.
	namedWindow("Source Image", WINDOW_AUTOSIZE);
	namedWindow("Log Polar", WINDOW_AUTOSIZE);
	namedWindow("Inverse Log Polar", WINDOW_AUTOSIZE);
	
	moveWindow("Source Image", 0, 0);
	moveWindow("Log Polar", 100, 100);
	moveWindow("Inverse Log Polar", 200, 200);
	
	imshow("Source Image", src);
	imshow("Log Polar", dst);
	imshow("Inverse Log Polar", src2);

	
	waitKey();
	    
	return 0;
	}
