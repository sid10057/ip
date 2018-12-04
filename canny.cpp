#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;
Mat img1=imread("rubik.jpg",1);
Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
Mat img3(img2.rows,img2.cols,CV_8UC1,Scalar(0));		
/*void call(int t,void *c)
{
	for(int i=1;i<img1.rows-1;i++)
	{
		for(int j=1;j<img1.cols-1;j++)
		{
			if(sqrt(gx[i][j]*gx[i][j]+gy[i][j]*gy[i][j])>t)
				img3.at<uchar>(i,j)=0;
			else 
				img3.at<uchar>(i,j)=255;
		}
	}
	namedWindow("win3",WINDOW_NORMAL);	
	imshow("win3",img3);
}*/
void call(int t,void *c)
{
	Canny(img2,img3,t,3*t,3);
	imshow("win3",img3);
}
int main()
{
	int t;
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
			img2.at<uchar>(i,j)=(int)(0.07*img1.at<Vec3b>(i,j)[0]+0.72*img1.at<Vec3b>(i,j)[1]+0.21*img1.at<Vec3b>(i,j)[2]);
		}
	}
	namedWindow("win3",WINDOW_NORMAL);
	createTrackbar("Track","win3",&t,100,call);
	waitKey(0);
	return 0;
}
	
