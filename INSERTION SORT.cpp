//insertion sort
#include<iostream>
#include<stdlib.h>
int main()
{
	using namespace std;
	int n;
	cout<<"Enter the number of elements you want to enter : \n";
	cin>>n;
	
	int arr[n];
    cout<<"\nEnter the elements\n";
    for(int i=0;i<n;i++)
   	{
    	cin>>arr[i];
	}
	
	for(int i=1;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
	arr[j+1]=key;
	}
	cout<<"---------------------------\n";
	cout<<"Sorted array is : \n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<endl;
	}
	return 0;
	
}

