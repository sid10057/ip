#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img1=imread("lenna.jpg",1);
	Mat img2(3*img1.rows,3*img1.cols,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<img2.rows;i++)
	{
		for(int j=0;j<img2.cols;j++)
		{
			img2.at<Vec3b>(i,j)=img1.at<Vec3b>(i/3,j/3);
		}
	}
	namedWindow("win1",WINDOW_AUTOSIZE);
	imshow("win1",img1);
	namedWindow("win2",WINDOW_AUTOSIZE);
	imshow("win2",img2);
	return 0;
}
	
