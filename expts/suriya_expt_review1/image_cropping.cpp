#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>


int main()
{

	cv::Mat img=cv::imread("sins.jpg",CV_LOAD_IMAGE_COLOR);

	cv::Rect my_rect(50,50,300,300);

	cv::Mat img1=img(my_rect);

	cv::imshow("Original image",img);
	cv::imshow("Cropped image",img1);


	cv::waitKey(0);

	return 0;


}
