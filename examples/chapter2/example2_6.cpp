#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char ** argv){
	Mat img1, img2;
	int variables =0;
	int war =0;
	//war !=variables;
	namedWindow("e1",WINDOW_AUTOSIZE);
	namedWindow("e2",WINDOW_AUTOSIZE);
	img1 = imread(argv[1]);
	imshow("e1",img1); //show input image
	
	pyrDown(img1,img2); // produces an image half the x,y pixels of the first image.
	imshow("e2", img2);
	waitKey(0);
	cout << variables << " " << war << endl;
	return 0;
	}
