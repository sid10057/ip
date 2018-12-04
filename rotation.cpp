#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
Mat img1=imread("lenna.jpg",1);
int diag=sqrt((img1.rows*img1.rows)+(img1.cols*img1.cols));
int x=img1.rows/2;
int y=img1.cols/2;
void call(int ang,void *c)
{
	Mat img2(diag,diag,CV_8UC3,Scalar(0,0,0));
    double angle=(double)(ang*3.14)/180;
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
			img2.at<Vec3b>((diag/2)-(j-y)*sin(angle)+(i-x)*cos(angle),(diag/2)+(j-y)*cos(angle)+(i-x)*sin(angle))=img1.at<Vec3b>(i,j);
		}
	}
	imshow("win",img2);
}
	
int main()
{
	int ang;
	/*cout<<"Enter the angle to be rotated(in degree)\n";
	cin>>ang;
	ang=(ang/180)*3.14;
	*/
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("Track","win",&ang,360,call);
	waitKey(0);
	return 0;
}
	
