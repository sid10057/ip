#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
Mat img1=imread("jopening.PNG",0);
Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
Mat img3(img1.rows,img1.cols,CV_8UC1,Scalar(0));
Mat img4(img1.rows,img1.cols,CV_8UC1,Scalar(0));
int isvalid(int i,int j)
{
	if(i>=0&&j>=0&&i<img1.rows&&j<img1.cols)
		return 1;
	return 0;
}
void opening()
{
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
		    int arr[10];
			int sum=0;
			int count=0;
			int ans;
			for(int x=0;x<3;x++)
			{
				for(int y=0;y<3;y++)
				{
					if(isvalid(i-1+x,j-1+y))
					{
						arr[count]=img2.at<uchar>(i-1+x,j-1+y);
						count++;
					}
				}
			}
			ans=arr[0];
			for(int x=1;x<count;x++)
			{
				if(arr[x]<ans)
					ans=arr[x];
			}	
			img3.at<uchar>(i,j)=ans;
		}
	}
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
		    int arr[10];
			int sum=0;
			int count=0;
			int ans;
			for(int x=0;x<3;x++)
			{
				for(int y=0;y<3;y++)
				{
					if(isvalid(i-1+x,j-1+y))
					{
						arr[count]=img3.at<uchar>(i-1+x,j-1+y);
						count++;
					}
				}
			}
			ans=arr[0];
			for(int x=1;x<count;x++)
			{
				if(arr[x]>ans)
					ans=arr[x];
			}	
			img4.at<uchar>(i,j)=ans;
		}
	}
}
int main()
{
   int arr[10];
   for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
	    	if (img1.at<uchar>(i,j)>127)
	    			img2.at<uchar>(i,j)=255;
	    	else
	    			img2.at<uchar>(i,j)=0;
	    }
	}
	opening();
	namedWindow("win1",WINDOW_NORMAL);	
	imshow("win1",img1);
	namedWindow("win1",WINDOW_NORMAL);	
	imshow("win2",img2);
	namedWindow("win1",WINDOW_NORMAL);	
	imshow("win3",img3);
	namedWindow("win1",WINDOW_NORMAL);	
	imshow("win4",img4);
	waitKey(0);
	return 0;
}
	
