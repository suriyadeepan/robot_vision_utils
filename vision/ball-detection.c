
#include <stdio.h>	// For printf()
#include <cv.h>		// Main OpenCV library.
#include <highgui.h>	// OpenCV functions for files and graphical windows.

void cvCreateShowWindow(char* name, IplImage *src)
{
	cvNamedWindow(name,CV_WINDOW_NORMAL);
	cvShowImage(name, src);
	
}

IplImage* hsvThreshold(IplImage* img,int* range)
{
	cvCvtColor ( img,img,CV_BGR2HSV );
	IplImage* hue = cvCreateImage ( cvGetSize(img), 8, 1 );
	cvSplit ( img, hue, NULL, NULL, NULL );
	printf ( "\nRange: %d %d\n",range[0],range[1] );
	cvInRangeS ( hue, cvScalar ( 0, 0, 0 ,0 ),
		     cvScalar ( 10, 255, 255,0 ),hue);
	return hue;
}

int main(int argc, char*  argv[])
 {
   if(argc < 2 ){
     printf (" no input image provided");
     exit(1);
   }

   cvStartWindowThread();
   
   IplImage* src = cvLoadImage(argv[1], CV_LOAD_IMAGE_UNCHANGED);
   IplImage* gray = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1); 
   cvCvtColor(src, gray, CV_BGR2GRAY);
   cvSmooth(gray, gray, CV_GAUSSIAN, 7, 7,0,0); 
   
   cvCreateShowWindow ( "Smoothed",gray );
   IplImage* cc_img = cvCreateImage(cvGetSize(gray), gray->depth, 3); 
   cvSetZero(cc_img);
   CvScalar(ext_color);

   //cvCreateShowWindow ( "cc_img",cc_img );  

   cvCanny(gray, gray, 10, 30, 3); 
   cvCreateShowWindow ( "canny_edge", gray ); 

   int mask_strength = 10 ;
   IplImage* temp = cvCreateImage(cvGetSize(gray), IPL_DEPTH_8U, 1); 
   cvMorphologyEx(gray,gray,temp,NULL,CV_MOP_TOPHAT,mask_strength);

   cvCreateShowWindow ( "morph", gray ); 

   CvMemStorage* storage = cvCreateMemStorage(0);
   CvSeq* circles = cvHoughCircles ( gray, storage, CV_HOUGH_GRADIENT,
				     1, src->height/6, 100, 50,0,0);
   cvCvtColor(gray, src, CV_GRAY2BGR);
   size_t i;
   for ( i = 0; i < circles->total; i++)  {   
     // round the floats to an int
     float* p = (float*)cvGetSeqElem(circles, i); 
     CvPoint center = cvPoint( cvRound(p[0]), cvRound(p[1]) );
     int radius = cvRound(p[2]);
     
     // draw the circle center
     //cvCircle(cc_img, center, 3, CV_RGB(0,255,0), -1, 8, 0 );

     // draw the circle outline
     cvCircle(cc_img, center, radius+1, CV_RGB(0,0,255), 2, 8, 0 );
     
     //printf("x: %d y: %d r: %d\n", center.x, center.y, radius);
   }   
   //cvCreateShowWindow ( "cc_img_contour",cc_img );  
   CvMemStorage *mem;
   mem = cvCreateMemStorage(0);
   CvSeq *contours = 0;
   cvCvtColor(cc_img, gray, CV_BGR2GRAY);
   // Use either this:
   /*int n = cvFindContours ( gray, mem, &contours, sizeof(CvContour),
     CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, cvPoint(0,0));*/
   // Or this:
   int n = cvFindContours ( gray, mem, &contours, sizeof(CvContour),
                              CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0)); 

   for (; contours != 0; contours = contours->h_next) {
     ext_color = CV_RGB( rand()&255, rand()&255, rand()&255 ); //randomly coloring different contours
     cvDrawContours(cc_img, contours, ext_color, CV_RGB(0,0,0), -1, CV_FILLED, 8, cvPoint(0,0));
   }
   cvCreateShowWindow ( "cc_img_final",cc_img );  
   cvSaveImage("out.png", cc_img,0);
   cvWaitKey(0);
   cvDestroyWindow("Smoothed");
   cvDestroyWindow("cc_img");
   cvDestroyWindow("cc_img_contour");
   cvDestroyWindow("cc_img_final");
 }
