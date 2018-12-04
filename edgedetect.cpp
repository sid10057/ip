#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
#include<stdlib.h>
using namespace cv;
using namespace std;

void call(int t,void *c)
{
	Mat img1=imread("rubik.jpg",1);
Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
Mat img3(img2.rows,img2.cols,CV_8UC1,Scalar(0));
    int **gx,**gy;
	gx=(int **)malloc(img2.rows*sizeof(int *));
	gy=(int **)malloc(img2.rows*sizeof(int *));
	for(int i=0;i<img2.rows;i++)
		gx[i]=(int *)malloc(img2.cols*sizeof(int));
	for(int i=0;i<img2.rows;i++)
		gy[i]=(int *)malloc(img2.cols*sizeof(int));
    int xk[3][3];
	int yk[3][3];
	xk[0][0]=-1;xk[0][1]=-2;xk[0][2]=-1;
	xk[1][0]=0;xk[1][1]=0;xk[1][2]=0;
	xk[2][0]=1;xk[2][1]=2;xk[2][2]=1;
	yk[0][0]=-1;yk[0][1]=0;yk[0][2]=1;
	yk[1][0]=-2;yk[1][1]=0;yk[1][2]=2;
	yk[2][0]=-1;yk[2][1]=0;yk[2][2]=1;	
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
			img2.at<uchar>(i,j)=(int)(0.07*img1.at<Vec3b>(i,j)[0]+0.72*img1.at<Vec3b>(i,j)[1]+0.21*img1.at<Vec3b>(i,j)[2]);
		}
	}
	for(int i=1;i<img2.rows-1;i++)
	{
		for(int j=1;j<img2.cols-1;j++)
		{
			int sum=0;
			int ans;
			for(int x=0;x<3;x++)
			{
				for(int y=0;y<3;y++)
				{					
						sum=sum+(img2.at<uchar>(i-1+x,j-1+y))*xk[x][y];
				}
			}
			ans=sum/8;
			gx[i][j]=ans;
		}
	}
	for(int i=1;i<img2.rows-1;i++)
	{
		for(int j=1;j<img2.cols-1;j++)
		{
			int sum=0;
			int ans;
			for(int x=0;x<3;x++)
			{
				for(int y=0;y<3;y++)
				{					
						sum=sum+(img2.at<uchar>(i-1+x,j-1+y))*yk[x][y];
				}
			}
			ans=sum/8;
			gy[i][j]=ans;
		}
	}	
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
}
int main()
{
	
	
		
    int t;
	
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("Track","win",&t,100,call);
	/*for(int i=1;i<img1.rows-1;i++)
	{
		for(int j=1;j<img1.cols-1;j++)
		{
			if(sqrt(gx[i][j]*gx[i][j]+gy[i][j]*gy[i][j])>4)
				img3.at<uchar>(i,j)=0;
			else 
				img3.at<uchar>(i,j)=255;
		}
	}
	namedWindow("win3",WINDOW_NORMAL);	
	imshow("win3",img3);*/
	waitKey(0);
	return 0;
}
	
	
