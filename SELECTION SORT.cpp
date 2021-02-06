//selection sort
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
		int imin=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[imin])
			{
				imin=j;
			}
		}
		int temp=arr[i];
		arr[i]=arr[imin];
		arr[imin]=temp;
	}
	cout<<"---------------------------\n";
	cout<<"sorted array is : \n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<endl;
	}
	return 0;
	
}

