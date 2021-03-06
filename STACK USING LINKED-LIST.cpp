#include<iostream>
#include <stdlib.h>


using namespace std;

void push();
int isfull();
void pop();
int isempty();
void peek();
void display();

int last=-1;

struct node
{
	int data;
	struct node *link;
};
struct node *top=NULL;

int main()
{
	int ch;
    
	while(1)
    {        
    	cout<<"---------------------------\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Peek\n";
		cout<<"4. Traverse\n";
		cout<<"5. Quit\n";
	
		cout<<"Enter your choice :\n";
    	cin>>ch;
    	
    	switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;        
            case 3: peek();
                    break;  
            case 4: display();
                    break;         
            case 5: exit(1);
            default : 
					system("cls");
					cout<<"---------------------------\n";
					cout<<" Invalid input\n" ;   
        }
}
return 0;
}
void push()
{
	
		cout<<"---------------------------\n";
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		cout<<"Enter element to push :\n";
		cin>>temp->data;
		temp->link=top;
		top=temp;
		last++;
		cout<<"Element pushed...\n";
		
	}
	



void pop()
{
	if(isempty())
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"No elements to pop...\n";
	}
	else
	{
		system("cls");
		cout<<"---------------------------\n";
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp=top;
		cout<<"Popped item is : "<<(temp->data)<<endl;
		top=top->link;
		temp->link=NULL;
		free(temp);
	}
}

int isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

void peek()
{
	if(isempty())
	{
		system("cls");
		cout<<"No elements to peek...\n";
	}
	else
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Popped item is : "<<(top->data)<<endl;
		
	}
}

void display()
{
	if(isempty())
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Stack is empty...\n";
	}
	else
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Elements of stack are : \n";
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->link;
		}
	}
}

