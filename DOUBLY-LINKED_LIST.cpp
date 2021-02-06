#include <iostream>
#include <stdlib.h>

using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root=NULL;
int len;

void append(void);
void addatbegin(void);
void addatpos(void);
int length(void);
void display(void);
void deletion(void);
void search(void);
int main()
{
	int ch;
	while(1)
	{
		
		cout<<"---------------------------\n";
		cout<<"1. Append\n";
		cout<<"2. Insert at begin\n";
		cout<<"3. Insert at postion\n";
		cout<<"4. Length\n";
		cout<<"5. Display\n";
		cout<<"6. Delete\n";
		cout<<"7. Search\n";
		cout<<"8. Quit\n";
		
		cout<<"Enter your choice : \n";
		cin>>ch;
		
		switch(ch)
		{
			case 1: append();
					break;
			case 2: addatbegin();
					break;
			case 3: addatpos();
					break;
			case 4: len=length();
					cout<<"Length is : \n"<<len<<endl;
					break;
			case 5: display();
					break;
			case 6: deletion();
					break;
			case 7: search();
					break;
			case 8: exit(1);
			default : 
					system("cls");
					cout<<"---------------------------\n";
					cout<<"Invalid input\n";
		}
	}
	return 0;
}


void append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter node data : \n";
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}


void addatbegin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter node data : \n";
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->right=root;
		root->left=temp;
		root=temp;
	}
}


void addatpos()
{
	struct node *temp,*p;
	int loc,i=1;
	cout<<"Enter location : \n";
	cin>>loc;
	if(loc>length())
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Invalid location... \n";
		cout<<"Currently list has "<<length()<<" nodes\n";
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
		cout<<"Enter node data : \n";
		cin>>temp->data;
		temp->left=NULL;
		temp->right=NULL;
		p=root;
		while(i<loc-1)
		{
			p=p->right;
			i++;
		}
		
		
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
	}
}

int length()
{
	int c=0;
	struct node* temp;
	temp=root;
	while(temp!=NULL)
	{
		c++;
		temp=temp->right;
	}
	return c;
}


void display()
{
	struct node* temp;
	temp=root;
	
	if(temp==NULL)
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"List is empty... \n";
	}
	else
	{
		system("cls");
		cout<<"Elements are : \n";
		while(temp!=NULL)
		{
			
			
			cout<<temp->data<<endl;
			temp=temp->right;
		}
	cout<<"\n";
	}
}

void deletion()
{
	struct node* temp;
	int loc;
	
	cout<<"Enter the location to delete : \n";
	cin>>loc;
	
	if(loc>length())
		cout<<"Invalid location...\n";
	else if(loc==1)
	{
		temp=root;
		root=temp->right;
		temp->right->left=NULL;
		temp->right=NULL;
		free(temp);
	}
	else
	{
		struct node*p=root,*q;
		int i=1;
		while(i<loc-1)
		{
			p=p->right;
			i++;
		}
		q=p->right;
		if(q->right==NULL)
		{
			p->right=NULL;
			q->left=NULL;
			free(q);
		}
		else
		{
			q=p->right;
			q->right->left=q->left;
			p->right=q->right;
			q->right=NULL;
			q->left=NULL;
			free(q);
		}
	}
}

void search()
{
	int ele,k=1;
	if(root==NULL)
	{
		cout<<"No elements to be searched...\n";
	}
	else
	{
		int count=0;
		cout<<"Enter element to be searched : \n";
		cin>>ele;
		struct node* temp;
		temp=root;
		while(temp!=NULL)
			{
				if(temp->data==ele)
				{
					cout<<"Element found at position "<<k<<endl;
					count++;
					break;
				}
				k++;
				temp=temp->right;
			}
		if(count==0)
		{
			cout<<"Element is not present...\n";
		}
	}
}
