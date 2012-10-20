#include<opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>


int main()
{

	cv::Mat img=cv::imread("/home/rps/sample.png",CV_LOAD_IMAGE_COLOR);

	cv::Mat img1;

	cv::blur(img,img1,cv::Size(5,5));

	imshow("cv_test",img1);


	cv::waitKey(0);

	return 0;


}
