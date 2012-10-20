#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

int main()
{

	cv::Mat img=cv::imread("/home/rps/sample.png",CV_LOAD_IMAGE_COLOR);
	cv::Mat img_smooth=cv::smooth(img);
	
	imshow("cv_window",img);

	cv::waitKey(0);



	return 0;


}
