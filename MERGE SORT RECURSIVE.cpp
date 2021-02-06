//merge sort recursive
#include<iostream>
#include<stdlib.h>
using namespace std; 

void Merge(int *A,int *L,int leftCount,int *R,int rightCount)
{
	int i=0,j=0,k=0;

	while(i<leftCount && j< rightCount)
	{
		if(L[i]  < R[j]) 
			A[k++] = L[i++];
		else 
			A[k++] = R[j++];
	}
	while(i < leftCount)
		 A[k++] = L[i++];
	while(j < rightCount)
		 A[k++] = R[j++];
}

void MergeSort(int *A,int n)
{
	int mid, *L, *R;
	if(n < 2) 
		return;

	mid = n/2;
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(int i = 0;i<mid;i++)
	{ 
		L[i] = A[i]; // creating left subarray
	}
	for(int j = mid;j<n;j++)
	{	
		R[j-mid] = A[j]; // creating right subarray
	}

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);
	  // Merging L and R into A as sorted list.
        free(L);
        free(R);
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
	
	MergeSort(arr,n);
	
	cout<<"---------------------------\n";
	cout<<"sorted array is : \n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<endl;
	}
	return 0;
}
