#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())//isopened检查是否正确开启正常开启返回1
	{
		std::cout << "不能打开视频文件" << std::endl;
		return -1;
	}

	double fps = cap.get(CAP_PROP_FPS);//get函数获得视频的fps
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		bool rSucess = cap.read(frame);//获取视频的当前帧
		if (!rSucess) 
		{
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{
			cv::imshow("frame", frame);//显示当前帧
		}
		waitKey(30);
	}
	

}