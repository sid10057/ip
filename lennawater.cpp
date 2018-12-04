#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace cv;
int main()
{
	Mat img1=imread("lenna.jpg",1);
	Mat img2((img1.rows)*2,img1.cols,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
			img2.at<Vec3b>(i,j)=img1.at<Vec3b>(i,j);
		}
	}
	for(int i=img1.rows;i<img2.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
			img2.at<Vec3b>(i,j)=img1.at<Vec3b>(img2.rows-i-1,j);
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img2);
	waitKey(0);
	return 0;
}
