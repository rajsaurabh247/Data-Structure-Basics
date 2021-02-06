//bubble sort
#include<iostream>
#include<stdlib.h>
int main()
{
	using namespace std;
	int n,i;
	cout<<"Enter the number of elements you want to enter : \n";
	cin>>n;
	int arr[n];
    	cout<<"Enter the elements\n";
    	for(i=0;i<n;i++)
   	 {
    		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"---------------------------\n";
	cout<<"sorted array is : \n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<endl;
	}
	return 0;
	
}

