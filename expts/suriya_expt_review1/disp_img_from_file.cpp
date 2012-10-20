#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>

int main()
{
	cv::Mat img=cv::imread("/home/rps/sample.png");

	cv::imshow("freaking_window_name",img);

	cv::waitKey(0);	

	return 0;
}
