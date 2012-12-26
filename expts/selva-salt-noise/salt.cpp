
#include<stdio.h>
#include<stdlib.h>
#include <cv.h>
#include <highgui.h>

void salt (cv::Mat &image, int n ) {
  for ( int k=0 ; k<n; k++ ) {
    // rand() is the MFC random number generator
    // try qrand() with Qt
    int i= rand () % image .cols;
    int j= rand () % image .rows;

    if ( image .channels () == 1 ) { // gray-level image
      
      image .at<uchar> (j, i) = 255;
    
    }
    else if ( image .channels () == 3 ) { // color image
    
      image .at <cv::Vec3b> (j, i)[ 0 ]= 255;
      image .at <cv::Vec3b> (j, i)[ 1 ]= 255;
      image .at <cv::Vec3b> (j, i)[ 2 ]= 255;
    
    }                                                                       
  }
}

int main()
{
  char *home = getenv ( "HOME" ) ;
  char dir [128] ;
  strcpy ( dir, home );
  strcat ( dir , "/repo/athena/expts/images/" );

  printf ( "\n Path to dir %s ", dir );

  // open the image
  char img[128];
  strcpy ( img, dir ) ;
  strcat (img, "01.jpg" );
  printf ( "\n Path to img %s ", img );

  cv::Mat image= cv::imread(img);
  // call function to add noise
  salt(image,3000);
  // display image
  cv::namedWindow("Image");
  cv::imshow("Image",image);

}
