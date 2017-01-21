//page 26
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string.h>
#include <fstream>
//trackbar highgui
using namespace std;
using namespace cv;

int main(int, char**)
{
    Mat frame;
    //string N = "0";
    VideoCapture cap(0);
    if (!cap.isOpened()) {
		cout << "ERRROR!";
		return 1;
		}
    while(1)    {
        cap >> frame;
        if(frame.empty()) {
			cout << "ERRROR!";
			return 1;
			}
        imshow ("Live",frame);
        if (waitKey(5)>0) break;
    }
    return 0;
}
//jim nelson, monday, 10am securitas, EMMC Hospital
