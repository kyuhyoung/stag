#include "opencv2/opencv.hpp"
#include "Stag.h"


//void main()
int main(int argc, char **argv)
{
	//cv::Mat image = cv::imread("1.png", CV_LOAD_IMAGE_GRAYSCALE);
	//cv::Mat image = cv::imread("/mnt/d/data/stag_marker/21924.png", CV_LOAD_IMAGE_GRAYSCALE);
	cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	//Stag stag(15, 7, true);
	int libraryHD = atoi(argv[2]);
	Stag stag(libraryHD, 7, true);

	stag.detectMarkers(image);
	stag.logResults("log/");
}
