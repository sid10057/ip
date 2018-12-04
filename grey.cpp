#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace cv;
int ma(int a,int b,int c)
{
	int m=a;
	if(b>a)
		m=b;
	if(c>m)
		m=c;
	return m;
}
int mi(int a,int b,int c)
{
	int m=a;
	if(b<a)
		m=b;
	if(c<m)
		m=c;
	return m;
}
int main()
{
	Mat img1=imread("lenna.jpg",1);
	Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	Mat img3(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	Mat img4(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img2.rows;j++)
		{
			img2.at<uchar>(i,j)=(img1.at<Vec3b>(i,j)[0]+img1.at<Vec3b>(i,j)[1]+img1.at<Vec3b>(i,j)[2])/3;
			img3.at<uchar>(i,j)=(int)(0.07*img1.at<Vec3b>(i,j)[0]+0.72*img1.at<Vec3b>(i,j)[1]+0.21*img1.at<Vec3b>(i,j)[2]);
			img4.at<uchar>(i,j)=(ma(img1.at<Vec3b>(i,j)[0],img1.at<Vec3b>(i,j)[1],img1.at<Vec3b>(i,j)[2])+mi(img1.at<Vec3b>(i,j)[0],img1.at<Vec3b>(i,j)[1],img1.at<Vec3b>(i,j)[2]))/2;
		}
	}
	namedWindow("win1",WINDOW_NORMAL);
	imshow("win1",img2);
	namedWindow("win2",WINDOW_NORMAL);
	imshow("win2",img3);
	namedWindow("win3",WINDOW_NORMAL);
	imshow("win3",img4);
	waitKey(0);
	return 0;
}
