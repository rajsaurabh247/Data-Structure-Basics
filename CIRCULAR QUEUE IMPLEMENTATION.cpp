/* implementing circular queue */

#include<iostream>
#include <stdlib.h>


using namespace std;

void insert();
void deletion();
void display();

int *cqueue;
int n;
int front=-1,rear=-1;

int main()
{
	int ch;
	
	cout<<"---------CREATE A CIRCULAR QUEUE FIRST--------\n";
    cout<<"Enter the size of the circular queue\n";
    cin>>n;
    cqueue=(int *) malloc( n * sizeof(int) );
    cout<<"Circular Queue with size "<<n<<" is created...\n";
    
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
	if(front==rear+1 || (rear==n-1 && front==0))
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Circular Queue is full...\n";
	}
	else if(front==-1 && rear==-1)
	{
		cout<<"---------------------------\n";
		int ele;
		cout<<"Enter the element to insert : \n";
		cin>>ele;
		front=0;
		rear=0;
		cqueue[rear]=ele;
	}
	else if(rear==n-1)
	{
		cout<<"---------------------------\n";
		int ele;
		cout<<"Enter the element to insert : \n";
		cin>>ele;
		rear=0;
		cqueue[rear]=ele;
	}
	else
	{
		cout<<"---------------------------\n";
		int ele;
		cout<<"Enter the element to insert : \n";
		cin>>ele;
		rear++;
		cqueue[rear]=ele;
	}
}

void deletion()
{
	if(front==-1 && rear==-1)
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"No item to delete...\n";
	}
	else if(front==rear)
	{
		system("cls");
		cout<<"Deleted item is : "<<cqueue[front]<<endl;
		front=-1;
		rear=-1;
	}
	else if(front==n-1)
	{
		system("cls");
		cout<<"Deleted item is : "<<cqueue[front]<<endl;
		front=0;
	}
	else
	{
		system("cls");
		cout<<"Deleted item is : "<<cqueue[front]<<endl;
		front++;
	}
}



void display()
{
	system("cls");
    if(front == -1 && rear == -1)
    {
        system("cls");
		cout<<"---------------------------\n";
		cout<<"No item to display...\n";
    }
    else if(rear >= front)
    {
        cout<<"Elements in the Circular queue are :\n";
        for(int i = front;i<=rear;i++)
        {
            cout<<cqueue[i]<<endl;
        }
    }
    else
    {
        cout<<"Elements in the circular queue are :\n";
        for(int j = front;j<=n-1;j++)
        {
            cout<<cqueue[j]<<endl;
        }
        for(int k = 0;k<=rear;k++)
        {
            cout<<cqueue[k]<<endl;
        }
    }

}
