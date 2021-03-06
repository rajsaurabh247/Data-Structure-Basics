#include<iostream>
#include <stdlib.h>


using namespace std;

void push();
int isfull();
void pop();
int isempty();
void peek();
void display();

int *stack;
int n,top=-1;
int item;

int main()
{
	int ch;
	
	cout<<"---------CREATE A STACK FIRST--------\n";
    cout<<"Enter the size of the stack\n";
    cin>>n;
    stack=(int *) malloc( n * sizeof(int) );
    cout<<"Stack with size "<<n<<" is created...\n";
    
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
	
	if(isfull())
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Stack Overflow...\n";
	}
	else
	{
		
		cout<<"---------------------------\n";
		cout<<"Enter element to push :\n";
		cin>>item;
		stack[++top]=item;
		cout<<"Element pushed...\n";
	}
	
}

int isfull()
{
	if(top==n-1)
		return 1;
	else
		return 0;
}

void pop()
{
	if(isempty())
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Stack Underflow...\n";
	}
	else
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Popped item is : "<<stack[top--]<<endl;
	}
}

int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void peek()
{
	if(isempty())
	{
		system("cls");
		cout<<"Stack Underflow...\n";
	}
	else
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Peeked item is : "<<stack[top]<<endl;
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
		for(int i=top;i>=0;i--)
		{
			cout<<stack[i]<<endl;
		}
	}
}

