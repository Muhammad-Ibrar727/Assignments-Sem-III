#include<iostream>
using namespace std;

int Binary_search(int arr[], int lb, int ub,int item,int loc)
{
	int beg,end,mid;
	beg=lb;
	end=ub;
	mid=int((beg+end)/2);
	
	while(beg<=end && arr[mid]!=item)
	{
		if(item<arr[mid])
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
		
		mid=int((beg+end)/2);
	}
	
	if(arr[mid]==item)
		return loc=mid;
	else
		return loc=-1;
}
int main()
{
	int arr[]={1,2,3,5,7,8,9,11};
	cout<<"Array after the sorting\n";
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<",";
	}
	cout<<endl;
	int element;
	cout<<"Enter the element you want to search in the array :";
	cin >> element;
	int loc=Binary_search(arr,1,8,element,0);
	if(loc==-1)
	{
		cout<<"Not found !";
		
	}
	else
	{
	cout<<"element found at loc "<<loc+1;
	}
	return 0;
}
