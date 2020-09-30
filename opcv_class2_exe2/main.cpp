#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())//isopened����Ƿ���ȷ����������������1
	{
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);//get���������Ƶ��fps
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		bool rSucess = cap.read(frame);//��ȡ��Ƶ�ĵ�ǰ֡
		if (!rSucess) 
		{
			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			cv::imshow("frame", frame);//��ʾ��ǰ֡
		}
		waitKey(30);
	}
	

}