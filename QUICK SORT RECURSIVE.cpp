//quick sort recursive
#include <iostream>
using namespace std;
int partition(int *A,int start,int end)
{
	int pivot=A[end];
	int partitionIndex=start;	//set partition index as start initially
	for(int i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(A[i],A[partitionIndex]);	//swap if element is lesser than pivot
			partitionIndex++;
		}
	}
	swap(A[partitionIndex],A[end]);		//swap pivot with element at partition index
	return partitionIndex;
}

void Quicksort(int *A,int start,int end)
{
	if(start<end)
	{
		int partitionIndex = partition(A,start,end);	//calling partition
		Quicksort(A,start,partitionIndex-1);
		Quicksort(A,partitionIndex+1,end);
	}
}
int main() 
{
	int n,i;
	cout<<"Enter the number of elements you want to enter : \n";
	cin>>n;
	int arr[n];
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
   	{
    	cin>>arr[i];
	}
	
	Quicksort(arr,0,n-1);
	
	cout<<"---------------------------\n";
	cout<<"sorted array is : \n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<endl;
	}
	return 0;
}
