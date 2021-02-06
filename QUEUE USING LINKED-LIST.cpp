/*Queue - Linked List implementation*/

#include<iostream>
#include<stdlib.h>

using namespace std;
struct Node 
{
	int data;
	struct Node* next;
};

// Two glboal variables to store address of front and rear nodes. 

struct Node* front = NULL;
struct Node* rear = NULL;

// To Enqueue an integer

void Enqueue()
{	
	int x;
	cout<<"Enter the element...\n";
	cin>>x;
	
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data =x; 
	temp->next = NULL;
	
	if(front == NULL && rear == NULL)
	{
		front = rear = temp;
	}
	else
	{
		
	rear->next = temp;
	rear = temp;
	}
	cout<<"Element inserted...\n";
	
}

// To Dequeue an integer.
void Dequeue() 
{
	struct Node* temp = front;
	
	if(front == NULL) {
		printf("Queue is Empty...\n");
		return;
	}
	else if(front == rear)
	 {
	 	cout<<"---------------------------\n";
		cout<<"Deleted item is : "<<front->data<<endl;
		front = rear = NULL;
	}
	else
	 {
	 	cout<<"---------------------------\n";
		cout<<"Deleted item is : "<<front->data<<endl;
		front = front->next;
	}
	free(temp);
}



void Print() 
{
	system("cls");
	cout<<"---------------------------\n";
	cout<<"Queue elements are : \n";
	struct Node* temp = front;
	while(temp != NULL) {
		printf("%d \n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int ch;
	while(1)
    {        
    	cout<<"---------------------------\n";
		cout<<"1. Enqueue\n";
		cout<<"2. Dequeue\n";
		cout<<"3. Traverse\n";
		cout<<"4. Quit\n";
	
		cout<<"Enter your choice :\n";
    	cin>>ch;
    	
    	switch(ch)
        {
            case 1: Enqueue();
                    break;
            case 2: Dequeue();
                    break;        
            case 3: Print();
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
