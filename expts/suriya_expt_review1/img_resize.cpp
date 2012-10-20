#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>


int main()
{

	//cv::Mat img=cv::imread("/home/suriyadeepan/Documents/Pictures/sins.jpg",CV_LOAD_IMAGE_COLOR);
	cv::Mat img=cv::imread("sins.jpg",CV_LOAD_IMAGE_COLOR);

	cv::Mat img1(cv::Size(320,240),CV_8UC3);


	cv::resize(img,img1,img1.size(),0,0,CV_INTER_CUBIC);


	cv::imshow("Original image",img);
	cv::imshow("Cropped image",img1);


	cv::waitKey(0);

	return 0;


}
