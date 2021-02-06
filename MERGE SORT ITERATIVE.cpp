//merge sort iterative
#include <iostream>
#include <stdlib.h>

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
	L[i] = arr[low + i];
	
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];
		i = 0;
		j = 0;
		k = low;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
	}
	else
	{
		arr[k] = R[j];
		j++;
	}
	k++;
	}
	
	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	}
	void mergeSort(int arr[], int low, int high)
	{
		if (low < high) {
		int mid = low + (high - low) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
	}
	void printArray(int A[], int size)
	{
		int i;
		for (i = 0; i < size; i++)
		printf("%d \n", A[i]);
		
	}
	int main()
	{
		
		int n;
		cout<<"Enter the number of elements you want to enter : \n";
		cin>>n;
		int arr[n];
	    cout<<"Enter the elements\n";
	    for(int i=0;i<n;i++)
	    {
	    	cin>>arr[i];
		}
		mergeSort(arr, 0, n - 1);
		printf("\nSorted array is :\n");
		printArray(arr, n);
		return 0;
}
