#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
Mat img1=imread("veg.jpg",0);
int isvalid(int i,int j)
{
	if(i>=0&&j>=0&&i<img1.rows&&j<img1.cols)
		return 1;
	return 0;
}		
int main()
{ 	
    Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(0));
    for(int i=0;i<img2.rows;i++)
	{
		for(int j=0;j<img2.cols;j++)
		{
			img2.at<uchar>(i,j)=img1.at<uchar>(i,j);		/*This program very effectively erases salt-pepper noise*/
		}
	}
  	for(int i=0;i<img2.rows;i++)
	{
		for(int j=0;j<img2.cols;j++)
		{
			int arr[10];
			int sum=0;
			int count=0;
			for(int x=0;x<3;x++)						/*Here 3 is the size of kernel*/
			{
				for(int y=0;y<3;y++)
				{
					if(isvalid(i-1+x,j-1+y))
					{
						arr[count]=img1.at<uchar>(i-1+x,j-1+y);
						count++;
					}
				}
			}		
			sort(arr,arr+count);					//inbuilt function of opencv
			if(count%2==1)
				img2.at<uchar>(i,j)=arr[count/2];
			else
				img2.at<uchar>(i,j)=(arr[count/2]+arr[(count/2)-1])/2;
		}
	}
	namedWindow("win1",WINDOW_NORMAL);	
	imshow("win1",img1);
	namedWindow("win",WINDOW_NORMAL);	
	imshow("win",img2);
	waitKey(0);
	return 0;
}
