#include <iostream>
#include <stdlib.h>

using namespace std;
struct node
{
	int data;
	struct node* link;
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
void reverse(void);
void Sort(struct node *) ;
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
		cout<<"8. Reverse\n";
		cout<<"9. Sort\n";
		cout<<"10. Quit\n";
		
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
			case 8: reverse();
					break;
			case 9: Sort(root);
					break;
			case 10: exit(1);
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
	temp->link=NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}


void addatbegin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter node data : \n";
	cin>>temp->data;
	temp->link=NULL;
	
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}


void addatpos()
{
	struct node *temp,*p;
	int loc,i=1;
	cout<<"Enter location : \n";
	cin>>loc;
	if(loc>length()+1)
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"Invalid location... \n";
		cout<<"Currently list has "<<length()<<" nodes\n";
	}
	else
	{
		p=root;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		temp=(struct node*)malloc(sizeof(struct node));
		cout<<"Enter node data : \n";
		cin>>temp->data;
		temp->link=NULL;
		
		temp->link=p->link;
		p->link=temp;
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
		temp=temp->link;
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
			temp=temp->link;
		}
	cout<<"\n";
	}
}

void deletion()
{
	if(root==NULL)
	{
		cout<<"No elements to be deleted...\n";
	}
	else
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
			root=temp->link;
			temp->link=NULL;
			free(temp);
		}
		else
		{
			struct node*p=root,*q;
			int i=1;
			while(i<loc-1)
			{
				p=p->link;
				i++;
			}
			q=p->link;
			p->link=q->link;
			q->link=NULL;
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
				temp=temp->link;
			}
		if(count==0)
		{
			cout<<"Element is not present...\n";
		}
	}
}

void reverse()
{
	if(root==NULL)
	{
		system("cls");
		cout<<"---------------------------\n";
		cout<<"List is empty... \n";
	}
	else
	{
		system("cls");
		int i=0,j,len,k,tempvar;
		struct node *p,*q;
		len=length();
		j=len-1;
		p=q=root;
		while(i<j)
		{
			k=0;
			while(k<j)
		{
				q=q->link;
				k++;
			}
			tempvar=p->data;
			p->data=q->data;
			q->data=tempvar;
			i++;
			j--;
			p=p->link;
			q=root;
		}
		display();
	}
}




void Sort(struct node *start) 
{ 
    struct node *temp1,*temp2;
    int k;
    /* Checking for empty list */
    if (start == NULL) 
        cout<<"Nothing to sort...\n"; 
  
    else
    {
  
        for(int i=length()-2;i>=0;i--)
		{
			temp1=start;
			temp2=temp1->link;
			for(int j=0;j<=i;j++)
			{
				if(temp1->data > temp2->data)
				{
					k=temp1->data;
					temp1->data=temp2->data;
					temp2->data=k;
				}
				temp1=temp2;
				temp2=temp2->link;
			}
		}
         
	} 
} 

