#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<bits/stdc++.h>
using namespace cv;
using namespace std;
Mat img=imread("dfs_path.jpg",0);
Mat img1(img.rows,img.cols,CV_8UC1,Scalar(0));
Mat img2(img1.rows,img1.cols,CV_8UC1,Scalar(255));
Mat img3(img1.rows,img1.cols,CV_8UC1,Scalar(255));
int isvalid(int i,int j)
{
	if(i>=0&&j>=0&&i<img1.rows&&j<img1.cols)
		return 1;
	return 0;
}
int dfs(int i,int j,int prev)
{
	namedWindow("win2",WINDOW_NORMAL);
	imshow("win2",img2);
	waitKey(1);
	if(img1.at<uchar>(i,j)==255)
		img2.at<uchar>(i,j)=0;
	else
		return 0;
	if((i==img1.rows-1)&&(j==img1.cols-1))
	{
		return 1;
	}
	if(isvalid(i-1,j))
	{
		if((img1.at<uchar>(i-1,j)==255)&&(prev!=1))
		{
			if(dfs(i-1,j,3))
				return 1;
		}
	}
	if(isvalid(i,j+1))
	{
		if((img1.at<uchar>(i,j+1)==255)&&(prev!=2))
		{
			if(dfs(i,j+1,4))
				return 1;
		}
	}
	if(isvalid(i+1,j))
	{
		if((img1.at<uchar>(i+1,j)==255)&&(prev!=3))
		{
			if(dfs(i+1,j,1))
				return 1;
		}
	}
	if(isvalid(i,j-1))
	{
		if((img1.at<uchar>(i,j-1)==255)&&(prev!=4))
		{
			if(dfs(i,j-1,2))
			return 1;
		}
	}
	img2.at<uchar>(i,j)=255;
	return 0;
}
		
			
int main()
{
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
	    	if (img.at<uchar>(i,j)>127)
	    			img1.at<uchar>(i,j)=255;
	    	else
	    			img1.at<uchar>(i,j)=0;
	    }
	}
	if(dfs(0,0,0));
		cout<<"Path Found\n";
	waitKey(0);
}


	
	
