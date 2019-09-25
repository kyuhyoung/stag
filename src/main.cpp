#include "opencv2/opencv.hpp"
#include "Stag.h"

using namespace std;
using namespace cv;


bool is_only_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(), 
	        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}


//------------ Check if the string is camera index --------------  
//	cout << is_this_camera_index("04");
//	=> true
bool is_this_camera_index(const std::string& strin)
{
	return 2 >= strin.size() && is_only_number(strin); 	
}

void detect_marker_cam(Stag& stag, int idxCam)
{
	Mat im_bgr;

	//비디오 캡쳐 초기화
	VideoCapture cap(idxCam);
	if (!cap.isOpened()) {
		cerr << "에러 - 카메라를 열 수 없습니다.\n";	exit(0);
	}
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	while(1)
	{
		// 카메라로부터 캡쳐한 영상을 frame에 저장합니다.
		cap.read(im_bgr);
		if(im_bgr.empty()) {
			cerr << "빈 영상이 캡쳐되었습니다.\n";	break;
		}
		// 영상을 화면에 보여줍니다.
        Mat im_gray;
        cvtColor(im_bgr, im_gray, CV_BGR2GRAY);
		stag.detectMarkers(im_gray);
		imshow("marker detection", stag.drawMarkers(im_bgr));
		/*
        im_bgr = stag.drawMarkers(im_bgr);
		imshow("marker detection", im_bgr);
		*/
        // ESC 키를 입력하면 루프가 종료됩니다. 
		char ch = waitKey(1);
		if (27 == ch) break;
	}
}

//void main()
int main(int argc, char **argv)
{
	if(argc < 4) 
	{
		cout << "Usage : Stag [libraryHD] [errorCorrection] [cameraID or path to image]" << endl;	exit(0);
	}		
	int libraryHD = atoi(argv[1]), errorCorrection = atoi(argv[2]);
	Stag stag(libraryHD, errorCorrection, true);

	//cv::Mat image = cv::imread("1.png", CV_LOAD_IMAGE_GRAYSCALE);
	//cv::Mat image = cv::imread("/mnt/d/data/stag_marker/21924.png", CV_LOAD_IMAGE_GRAYSCALE);
	if(is_this_camera_index(argv[3]))
	{
		detect_marker_cam(stag, atoi(argv[3]));
	}
	else
	{
		cv::Mat image = cv::imread(argv[3], CV_LOAD_IMAGE_GRAYSCALE);
	//Stag stag(15, 7, true);
		stag.detectMarkers(image);
		stag.logResults("log/");
	}		
}
