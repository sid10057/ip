#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
using namespace cv;
int main()
{
	Mat img(100,100,CV_8UC3,Scalar(0,0,0));
	namedWindow("win",WINDOW_NORMAL);
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			if(i+j<img.rows)
				img.at<Vec3b>(i,j)[2]=255;
			else
				{img.at<Vec3b>(i,j)[1]=255;
				  img.at<Vec3b>(i,j)[2]=255;
				}
		}
	}
	imshow("win",img);
	waitKey(0);
	return 0;
}

