// Binary Search Tree - Implemenation in C++

#include<iostream>
#include <stdlib.h>
#include<queue>

using namespace std;
struct node
{
	int data; 
	node* left;
	node* right;
};

struct node* root=NULL;

void insert() 
{
	struct node *temp, *parent;
	temp=(struct node*)malloc(sizeof(struct node));
	cout<<"Enter node data : \n";
	cin>>temp->data;
	temp->left=temp->right=NULL;
	
	parent=root;
	if(root == NULL) 
	{ 
		root=temp;
	}
	 
	else 
	{
		struct node *curr;
		curr=root;
		while(curr)
		{
			parent=curr;
			if(temp->data>curr->data)
			{
				curr=curr->right;
			}
			else
			{
				curr=curr->left;
			}
		}
		if(temp->data>parent->data)
		{
			parent->right=temp;
		}
		else
		{
			parent->left=temp;
		}
	}
}

void search()
{ 
	if(root == NULL)
	{
		cout<<"Nothing to be searched..."<<endl;
	}
	else
	{
		int n;
		cout<<"Enter number be searched...\n";
		cin>>n;
		int c=0;
		struct node *t;
		t=root;
		while(t!=NULL)
		{
			if(n<t->data)
			{
				t=t->left;
			}
			else if(n>t->data)
			{
				t=t->right;
			}
			else
			{
				c++;
				break;
			}
		}
		if(c==0)
		{
			cout<<"Not Found...\n";
		}
		else
		{
			cout<<"Found...\n";
		}
	}
}

void findmax(struct node*root)
{
	struct node *t;
	t=root;
	if(root==NULL)
	{
		cout<<"No elements present in the tree...\n";
	}
	else
	{
		while(t->right!=NULL)
		{
			t=t->right;
		}
		cout<<"Maximum element is : "<<t->data<<endl;
	}
}

void findmin(struct node* root)
{
	struct node *t;
	t=root;
	if(root==NULL)
	{
		cout<<"No elements present in the tree...\n";
	}
	else
	{
		while(t->left!=NULL)
		{
			t=t->left;
		}
		cout<<"Minimum element is : "<<t->data<<endl;
	}
}

int findheight(struct node *root)
{
	int lht,rht;
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		lht=findheight(root->left);
		rht=findheight(root->right);
		int max=(lht>rht)?lht:rht;
		return max+1;
	}
	
	
}

void LevelOrder(struct node *root) 
{
	if(root == NULL) 
		return;
	else
	{
		queue<node*> Q;
		Q.push(root);  
		//while there is at least one discovered node
		while(!Q.empty()) 
		{
			node* current = Q.front();
			Q.pop(); // removing the element at front
			cout<<current->data<<endl;
			if(current->left != NULL) 
				Q.push(current->left);
			if(current->right != NULL) 
				Q.push(current->right);
		}	
	}
}

void preorder(struct node *root) 
{
	if(root == NULL) 
		return;
	else
	{	
		cout<<root->data<<endl; 
		preorder(root->left);     
		preorder(root->right);    
	}
}

void inorder(struct node *root) 
{
	if(root == NULL) 
		return;
	else
	{	
		inorder(root->left);  
		cout<<root->data<<endl;    
		inorder(root->right);    
	}
}

void postorder(struct node *root) 
{
	if(root == NULL) 
		return;
	else
	{	
		postorder(root->left);     
		postorder(root->right); 
		cout<<root->data<<endl;    
	}
}

void traverse(struct node *root)
{
	if(root==NULL)
	{
		cout<<"No elements present in the tree...\n";
	}
	int choice;
	cout<<"---------------------------\n";
	cout<<"Enter your choice : "<<endl;
	cout<<"1. Level Order Traversal\n";
	cout<<"2. Pre-Order Traversal\n";
	cout<<"3. In-Order Traversal\n";
	cout<<"4. Post-Order Traversal\n";
	
	cout<<"Enter your choice : \n";
	cin>>choice;
		
	switch(choice)
	{
		case 1: LevelOrder(root);
				break;
		case 2: preorder(root);
				break;
		case 3: inorder(root);
				break;
		case 4: postorder(root);
				break;
		default : 
				system("cls");
				cout<<"---------------------------\n";
				cout<<"Invalid input\n";
	}
}

int totalnodes(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return(totalnodes(root->left)+totalnodes(root->right)+1);
	}
}

node* FindMin(node* root)
{
	while(root->left != NULL) 
		root = root->left;
	return root;
}

struct node* deletion(struct node *root, int data) {
	if(root == NULL) 
		return root; 
	else if(data < root->data) 
		root->left = deletion(root->left,data);
	else if (data > root->data) 
		root->right = deletion(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = deletion(root->right,temp->data);
		}
	}
	return root;
}

int main() 
{
	int ch,max,min,ht,total;
	while(1)
	{
		
		cout<<"---------------------------\n";
		cout<<"1. Insert an element\n";
		cout<<"2. Search\n";
		cout<<"3. Find Maximum Element\n";
		cout<<"4. Find Minimum Element\n";
		cout<<"5. Height of tree\n";
		cout<<"6. Total nodes in the tree\n";
		cout<<"7. Traverse\n";
		cout<<"8. Delete\n";
		cout<<"9. Quit\n";
		
		cout<<"Enter your choice : \n";
		cin>>ch;
		
		switch(ch)
		{
			case 1: insert();
					break;
			case 2: search();
					break;
			case 3: findmax(root);
					break;
			case 4: findmin(root);
					break;
			case 5: ht=findheight(root);
					cout<<"Height of tree is : "<<ht<<endl;
					break;
			case 6: total=totalnodes(root);
					cout<<"Total Nodes : "<<total<<endl;
					break;
			case 7: traverse(root);
					break;
			case 8: cout<<"Enter data to be deleted... : \n";
					int d;
					cin>>d;
			root=deletion(root,d);
			cout<<"Deleted...\n";
					break;
			case 9: exit(1);
			default : 
					system("cls");
					cout<<"---------------------------\n";
					cout<<"Invalid input\n";
		}
	}
	return 0;
}
