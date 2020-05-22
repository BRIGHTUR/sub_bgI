#include<iostream>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat frame;
	Mat bgMat;
	Mat subMat;
	Mat bny_subMat;
	VideoCapture cap;
	int cnt = 0;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return -1;
	}
	while (1)
	{
		cap >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		if (cnt == 0) {
			frame.copyTo(bgMat);
		}
		else {
			absdiff(frame, bgMat, subMat);
			threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);
			imshow("b_submat", bny_subMat);
			imshow("subMat", subMat);
			waitKey(30);
		}
		cnt++;

	}

}