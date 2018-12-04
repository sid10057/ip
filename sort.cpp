#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/core/core.hpp"
#include<iostream>
#include<math.h>
using namespace cv;
using namespace std;
void sortarr(int arr[],int count)
{
	for(int i=0;i<count-1;i++)
	{
		int low=arr[i];
		int lowindex=i;
		for(int j=i+1;j<count;j++)
		{
			if(arr[j]<low)
				{low=arr[j];
				 lowindex=j;}
		}
		int temp=arr[i];
		arr[i]=low;
		arr[lowindex]=arr[i];
	}
}
int main()
{
	int arr[10];
	for(int i=0;i<9;i++)
		cin>>arr[i];
	sort(arr,arr+9);	
	//sortarr(arr,9);
	for(int i=0;i<9;i++)
		cout<<arr[i]<<" ";
	return 0;
}
	
