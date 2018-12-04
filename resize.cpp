#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img1=imread("lenna.jpg",1);
	Mat img2(img1.rows/3,img1.cols/3,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<img2.rows;i++)
	{
		for(int j=0;j<img2.cols;j++)
		{
			int sum1=0;
			int sum2=0;
			int sum3=0;
			for(int k=0;k<3;k++)
			{
				for(int l=0;l<3;l++)
				{
					sum1=sum1+(img1.at<Vec3b>(3*i+k,3*j+l)[0])/9;
					sum2=sum2+(img1.at<Vec3b>(3*i+k,3*j+l)[1])/9;
					sum3=sum3+(img1.at<Vec3b>(3*i+k,3*j+l)[2])/9;
				}
			}
			img2.at<Vec3b>(i,j)[0]=sum1;
			img2.at<Vec3b>(i,j)[1]=sum2 ;
			img2.at<Vec3b>(i,j)[2]=sum3;
		}
	}
	namedWindow("win1",WINDOW_AUTOSIZE);
	imshow("win1",img1);
	namedWindow("win2",WINDOW_AUTOSIZE);
	imshow("win2",img2);
	waitKey(0);
	return 0;
}
	
