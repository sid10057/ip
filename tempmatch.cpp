#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<math.h>
#include<bits/stdc++.h>
using namespace cv;
using namespace std;
Mat img=imread("coins.jpeg",1);
Mat img1=imread("temp.jpeg",1);
int main()
{
	Mat img2(img.rows-img1.rows+1,img.cols-img1.cols+1,CV_32FC1,Scalar(0));
	matchTemplate(img,img1,img2,5);
	namedWindow("win1",WINDOW_NORMAL);
	imshow("win1",img2);
	waitKey(0);
	return 0;
}
