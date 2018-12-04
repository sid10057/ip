#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace cv;
void call(int t,void *c)
{
	Mat *p=(Mat *)c;
	Mat img3(img1.rows,img1.cols,CV_8UC1,Scalar(0)
	for(int i=0;i<img2.rows;i++)
	{
		for(int j=0;j<img2.cols;j++)
		{
	    	if (img2.at<uchar>(i,j)>t)
	    			img3.at<uchar>(i,j)=255;
	    	else
	    			img3.at<uchar>(i,j)=0;
	    }
	}
	imshow("win",img3);
}	
	
int main()
{
    int threshold;
    int *ptr;
    ptr=&threshold;
    Mat img1=imread("lenna.jpg",1);
    Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<img2.rows;i++)
	{
		for(int j=0;j<img2.rows;j++)
		{
			img2.at<uchar>(i,j)=(int)(0.07*img1.at<Vec3b>(i,j)[0]+0.72*img1.at<Vec3b>(i,j)[1]+0.21*img1.at<Vec3b>(i,j)[2]);
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("Trackbar","win",ptr,255,call);
	waitKey(0);
	return 0;
}
	
	
	
	
