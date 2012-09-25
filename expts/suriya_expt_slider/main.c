// example 2-3

#include<opencv2/highgui/highgui.hpp>

int g_slider_position=0;
CvCapture* g_capture=NULL;

void onSlide(int);

int main(int argc, char **argv)
{
	cvNamedWindow("Player_with_slider",CV_WINDOW_AUTOSIZE);

	g_capture=cvCreateFileCapture("/home/suriyadeepan/Videos/Sample.avi");

	// get total no. of frames in the video...
	int frame_count=(int)cvGetCaptureProperty(g_capture,CV_CAP_PROP_FRAME_COUNT);

	if(frame_count!=0)
	{
		cvCreateTrackbar("Slider","Player_with_slider",(int)g_slider_position,frame_count,onSlide);

	}

	IplImage* frame;

	while(1)
	{
		frame=cvQueryFrame(g_capture);
		if(!frame)break;



		cvShowImage("Player_with_slider",frame);



		//cvSetTrackbarPos("Slider","Player_with_slider",++g_slider_position);

		char response=cvWaitKey(33);

		if(response==27)
			break;

	}

	cvReleaseCapture(&g_capture);

	cvDestroyWindow("Player_with_slider");

}

void onSlide(int pos)
{

	cvSetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES,pos);

}


