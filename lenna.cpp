#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img1=imread("lenna.jpg",1);
	Mat img2(img1.rows,(img1.cols)*2,CV_8UC3,Scalar(0,0,0));
	cout<<"No. of rows and col "<<img1.rows<<" "<<img1.cols;
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
			img2.at<Vec3b>(i,j)=img1.at<Vec3b>(i,j);
		}
	}
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=img1.cols;j<img2.cols;j++)
		{
			img2.at<Vec3b>(i,j)=img1.at<Vec3b>(i,img2.cols-j-1);
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img2);
	waitKey(0);
	return 0;
}
