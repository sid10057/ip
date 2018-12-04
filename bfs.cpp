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
int c=0;
typedef struct P
{
	int i;
	int j;
}point;
queue<point> q;
int isvalid(int i,int j)
{
	if(i>=0&&j>=0&&i<img1.rows&&j<img1.cols)
		return 1;
	return 0;
}
void bfs(point a)
{
	c++;
	if(c%15==0)
	{
	namedWindow("win3",WINDOW_NORMAL);
	imshow("win3",img3);
	waitKey(1);
	}
	point b,c,d,e;
	b.i=a.i-1;
	b.j=a.j;
	c.i=a.i;
	c.j=a.j+1;
	d.i=a.i+1;
	d.j=a.j;
	e.i=a.i;
	e.j=a.j-1;
	if(isvalid(b.i,b.j))
	{
		if((img3.at<uchar>(b.i,b.j)==255)&&(img1.at<uchar>(b.i,b.j)==0))
			{
				if(img2.at<uchar>(b.i,b.j)!=0)
					{q.push(b);
				img2.at<uchar>(b.i,b.j)=0;}
			}
	}
	if(isvalid(c.i,c.j))
	{
		if((img3.at<uchar>(c.i,c.j)==255)&&(img1.at<uchar>(c.i,c.j)==0))
			{
				if(img2.at<uchar>(c.i,c.j)!=0)
					{q.push(c);
				img2.at<uchar>(c.i,c.j)=0;}
			}
	}
	if(isvalid(d.i,d.j))
	{
		if((img3.at<uchar>(d.i,d.j)==255)&&(img1.at<uchar>(d.i,d.j)==0))
			{
				if(img2.at<uchar>(d.i,d.j)!=0)
					{q.push(d);
				img2.at<uchar>(d.i,d.j)=0;}
			}
	}
	if(isvalid(e.i,e.j))
	{
		if((img3.at<uchar>(e.i,e.j)==255)&&(img1.at<uchar>(e.i,e.j)==0))
			{
				if(img2.at<uchar>(e.i,e.j)!=0)
					{q.push(e);
				img2.at<uchar>(e.i,e.j)=0;}
			}
	}
	point x=q.front();
	if(img1.at<uchar>(x.i,x.j)==0)
		img3.at<uchar>(x.i,x.j)=127;
	q.pop();
	
	if(q.empty())
	{
		return ;
	}
		bfs(q.front());
	return;
}	
int main()
{
	int num=0;
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
	for(int i=0;i<img1.rows;i++)
	{
		for(int j=0;j<img1.cols;j++)
		{
			if((img3.at<uchar>(i,j)==255));
			{
				if(img2.at<uchar>(i,j)!=0)
				{
				if(img1.at<uchar>(i,j)==0)
				{
				num++;
				point a={i,j};
				q.push(a);
				bfs(a);
				}
				}
			}
		}
	}
	cout<<num<<endl;
	waitKey(0);
	return 0;
	
}
	
