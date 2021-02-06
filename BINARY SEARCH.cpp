//binary search
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
	
    int i,n,num;
    int *arr;
    cout<<"---------CREATE AN ARRAY FIRST--------\n";
    cout<<"Enter the size of the array\n";
    cin>>n;
    arr=(int *) malloc( n * sizeof(int) );
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
			cout<<"Enter the no. to be searched :\n";
			cin>>num;
			
			int low=0,high=n-1;
			int mid;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(arr[mid]<num)
				{
					low=mid+1;
				}
				else if(arr[mid]==num)
				{
					cout<<"Element "<<num<<" found at position "<<mid+1;
					break;
				}
				else
				{
					high=mid-1;
				}
				
			}
			if(low>high)
			{
				cout<<"Element"<<num<<"not found";
			}
			return 0;	
			}
