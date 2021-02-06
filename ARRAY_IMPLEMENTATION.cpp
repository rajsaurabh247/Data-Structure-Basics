#include <iostream>
#include <stdlib.h>

using namespace std;

void append();
void insertatbegin();
void insertatpos();
void length();
void display();
void deletion();
void search();
void sort();

int n;
int* arr;

int main()
{
    int ch,i;
    cout<<"---------CREATE AN ARRAY FIRST--------\n\n";
    cout<<"Enter the size of the array\n";
    cin>>n;
    arr=(int *) malloc( n * sizeof(int) );
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
    {
    	cin>>arr[i];
	}
    while(1)
    {        
    	cout<<"---------------------------\n";
        cout<<"1. Append\n";
        cout<<"2. Insert at begin\n";
        cout<<"3. Insert at position\n";
        cout<<"4. Length\n";
        cout<<"5. Display\n";
        cout<<"6. Delete\n";
        cout<<"7. Searching\n";
        cout<<"8. Sorting\n";
        cout<<"9. Exit\n";

        cout<<"Enter your choice :\n";
        cin>>ch;
        switch(ch)
        {
            case 1: append();
                    break;
            case 2: insertatbegin();
                    break;        
            case 3: insertatpos();
                    break;  
            case 4: length();
                    break;  
            case 5: display();
                    break;
            case 6: deletion();
                    break;
            case 7: search();
                    break;
			case 8: sort();
                    break;        
            case 9: exit(1);
            default : 
            		system("cls");
					cout<<"---------------------------\n";
					cout<<" Invalid input\n" ;   
        }
    }
    return 0;
}

void append()
{
	
	arr=(int *) realloc( arr,n * sizeof(int) + sizeof(int) );
	cout<<"---------------------------\n";	
	cout<<"Enter the element\n";
	cin>>arr[n];
	n++;
}

void insertatbegin()
{
	arr=(int *) realloc( arr,n * sizeof(int) + sizeof(int) );
	for(int i=0;i<n;i++)
    {
    	arr[n-i]=arr[n-i-1];
	}
	
	cout<<"---------------------------\n";
	cout<<"Enter the element\n";
	cin>>arr[0];
	n++;
}

void insertatpos()
{
	int pos;
	system("cls");	
	cout<<"---------------------------\n";
	cout<<"Enter the position\n";
	cin>>pos;
	if(pos==1)
	{
		insertatbegin();	
	}
	else if(pos==n+1)
	{
		append();
	}
	else
	{
		arr=(int *) realloc( arr,n * sizeof(int) + sizeof(int) );
		for(int i=0;i<n-pos+1;i++)
    	{
    		arr[n-i]=arr[n-i-1];
		}
		cout<<"Enter the element\n";
		cin>>arr[pos-1];
		n++;
	}
	
}


void length()
{
	system("cls");
	cout<<"---------------------------\n";
	cout<<"Length of array is : \n"<<n<<endl;
}

void display()
{
	system("cls");
	cout<<"---------------------------\n";
	for(int i=0;i<n;i++)
    {
    	cout<<arr[i]<<endl;
	}
	
}

void deletion()
{
	int pos;	
	system("cls");
	cout<<"---------------------------\n";
	cout<<"Enter the position\n";
	cin>>pos;
	for(int i=pos;i<n;i++)
    {
    	arr[i-1]=arr[i];
	}
	n--;
	
}

void search()
{
	int num;
	system("cls");
	cout<<"---------------------------\n";
	cout<<"Enter the no. to be searched :\n";
	cin>>num;
	int count=0;
	for(int i=0;i<n;i++)
	{									//linear search is implemented here
		if(arr[i]==num)
		{
			cout<<"---------------------------\n";
			cout<<"Element "<<num<<" found at position "<<i+1<<endl;
			count++;
			break;
		}
	}
	if(count==0)
	{
		cout<<"---------------------------\n";
		cout<<"Element not found \n";
	}
}

void sort()
{										//bubble sort is implemented here
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
	system("cls");
	cout<<"---------------------------\n";
	cout<<"sorted array is : \n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i]<<endl;
	}
	
}


