#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
//trackbar highgui
using namespace std;
using namespace cv;

//g_ is a global
int g_slider_postition = 0;
int g_run = 1, g_dontset =0;
VideoCapture g_cap;

void onTrackbarSlide(int pos, void *){
	g_cap.set( CAP_PROP_POS_FRAMES, pos );
	
	if(!g_dontset){
		g_run =1;
		g_dontset =0;
		}
	}


int main(int argc, char ** argv){
	namedWindow("Example2_4", WINDOW_AUTOSIZE);
	g_cap.open(string(argv[1]));
	int frames = (int) g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmpw = (int) g_cap.get(CAP_PROP_FRAME_WIDTH);
	int tmph = (int) g_cap.get(CAP_PROP_FRAME_HEIGHT);
	cout << "This Video has " << frames<< " Frames of dimensions: " << tmpw << ", " << tmph << "\n";

createTrackbar("Position", "Example2_4", &g_slider_postition, frames, onTrackbarSlide);

Mat frame;	
while(1){

if(g_run !=0){
   g_cap >> frame;
   if(frame.empty())
		break;
		
	int current_pos  = (int) g_cap.get(CAP_PROP_POS_FRAMES);
	imshow("Example2_4", frame);	
    g_dontset =1;
    
    setTrackbarPos("Position", "Example2_4",current_pos);
    imshow("Example2_4", frame);
    
    g_run -=1;
   }
	char c = (char) waitKey(10);
	if (c == 's'){
		g_run =1;
		cout << "Single step: Run = "<<g_run<<"\n";
	}
	if (c=='r'){
		g_run = -1;
		cout << "Run Mode: Run = "<<g_run<<"\n";
		}
	if(c==27)
	break;	
	}
	
	return 0;
	}
