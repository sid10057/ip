#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
using namespace cv;
using namespace std;
Mat img1=imread("image.jpeg",1);
Mat img2=imread("image1.jpeg",1);
Mat img3(img1.rows,img1.cols,CV_8UC3,Scalar(0,0,0));
void call(int k,void *c)
{
	for(int i=0;i<img3.rows;i++)
	{
		for(int j=0;j<img3.cols;j++)
		{
			img3.at<Vec3b>(i,j)[0]=(k*img1.at<Vec3b>(i,j)[0]+(100-k)*img2.at<Vec3b>(i,j)[0])/100;
			img3.at<Vec3b>(i,j)[1]=(k*img1.at<Vec3b>(i,j)[1]+(100-k)*img2.at<Vec3b>(i,j)[1])/100;
			img3.at<Vec3b>(i,j)[2]=(k*img1.at<Vec3b>(i,j)[2]+(100-k)*img2.at<Vec3b>(i,j)[2])/100;
		}
	}
	imshow("win",img3);
}		
	
int main()
{
    int t=0;
    cout<<img2.rows<<img2.cols;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("Track","win",&t,100,call);
	waitKey(0);
	return 0;
}
