/* implementing queue */

#include<iostream>
#include <stdlib.h>


using namespace std;

void insert();
void deletion();
void display();

int *queue;
int n;
int front=0,rear=0;

int main()
{
	int ch;
	
	cout<<"---------CREATE A QUEUE FIRST--------\n";
    cout<<"Enter the size of the queue\n";
    cin>>n;
    queue=(int *) malloc( n * sizeof(int) );
    cout<<"Queue with size "<<n<<" is created...\n";
    
	while(1)
    {        
    	cout<<"---------------------------\n";
		cout<<"1. Insert\n";
		cout<<"2. Delete\n";
		cout<<"3. Traverse\n";
		cout<<"4. Quit\n";
	
		cout<<"Enter your choice :\n";
    	cin>>ch;
    	
    	switch(ch)
        {
            case 1: insert();
                    break;
            case 2: deletion();
                    break;        
            case 3: display();
                    break;       
            case 4: exit(1);
            default : 
					system("cls");
					cout<<"---------------------------\n";
					cout<<" Invalid input\n" ;   
        }
}
return 0;
}

void insert()
{
	if(n==rear)
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Queue is full...\n";
	}
	else
	{
		cout<<"---------------------------\n";
		int ele;
		cout<<"Enter the element to insert : \n";
		cin>>ele;
		queue[rear]=ele;
		rear++;
	}
}

void deletion()
{
	if(front==rear)
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Queue is empty...\n";
	}
	else
	{
		cout<<"---------------------------\n";
		cout<<"Deleted item is : "<<queue[front]<<endl;
		for(int i=0;i<rear-1;i++)
		{
			queue[i]=queue[i+1];
		}
		rear--;
	}
}

void display()
{
	if(front==rear)
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Queue is empty...\n";
	}
	else
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Queue elements are : \n";
		for(int i=front;i<rear;i++)
		{
			cout<<queue[i]<<endl;
		}
	}
}
