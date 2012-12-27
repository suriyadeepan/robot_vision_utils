/* 
Expt01 by Selvakumar - 24/09/2012
  Loads a image and perform blur operation over the image and saves it in blurred.jpg file.
  This program is taken from a website. it had two errors since the cvSmooth and cvSaveImage had too few arguments and I corrected it the value '11' in cvSmooth signifies the amount of blur. sucess fully compiled and executed  */

#include <stdio.h>	// For printf()
#include <cv.h>		// Main OpenCV library.
#include <highgui.h>	// OpenCV functions for files and graphical windows.

int main(int argc, char* argv[])
{
	// Open the file "lena.jpg".
	IplImage* img = cvLoadImage("lena.jpg", CV_LOAD_IMAGE_UNCHANGED);
	if (!img) {
		printf("Error: Could not open the image file! \n");
		exit(1);
	}

	// Blur the image.
	cvSmooth(img, img, CV_GAUSSIAN,11,0,0,0);

	// Save the blurred image to a file.
	cvSaveImage("blurred.jpg", img,0);

	// Show the blurred image on the screen.
	cvNamedWindow("Blurred", CV_WINDOW_AUTOSIZE);
	cvShowImage("Blurred", img);

	// Wait for the user to press something on the graphical window.
	// Note: cvWaitKey() is needed for time to draw on the screen.
	cvWaitKey(0);

	// Free the resources.
	cvDestroyWindow("Blurred");
	cvReleaseImage( &img );

	return 0;
}
