#include <iostream>
using namespace std;
class TREE_CLASS
{
	private:
		typedef struct bin
		{
			char data[50];
			struct bin *left;
			struct bin *right;
		}node;
		
	public:
		node *New,*root;
		TREE_CLASS();
		void create();
		void insert(node *,node *);
		void rec_inorder(node *);
		void printLevelOrder(node* root);
		void printLevel(node* root,int level);
		int height(node *node);
};

TREE_CLASS::TREE_CLASS()
{
	root = NULL;
}

void TREE_CLASS::create()
{
	char ans='y';
	do
	{
		New = new node;
		cout<<"\n Enter The Element : ";
		cin>>New->data;
		New->left = NULL;
		New->right = NULL;
		if(root==NULL)
		{
			root=New;
		}
		else
		{
			insert(root,New);
		}
		cout<<"\n Do You Want To Enter More Elements?(y/n) : ";
		cin>>ans;
	}while (ans == 'y' || ans=='Y');
}

void TREE_CLASS::insert(node *root,node *New)
{
	char ch;
	cout<<"\n Where to Insert left/right of "<<root->data<<" : ";
	cin>>ch;
	if((ch=='r')||(ch=='R'))
	{
		if(root->right == NULL)
		{
			root->right=New;
		}
		else
		{
			insert(root->right,New);
		}
	}
	else
	{
		if(root->left == NULL)
		{
			root->left=New;
		}
		else
		{
			insert(root->left,New);
		}
	}
}


void TREE_CLASS::rec_inorder(node *root)
{
	if(root!=NULL)
	{
		rec_inorder(root->left);
		cout<<" "<<root->data;
		rec_inorder(root->right);
	}
}

void TREE_CLASS::printLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for(i=1;i<=h;i++)
	{
		cout<<"\n";
		printLevel(root,i);
	}
}


void TREE_CLASS::printLevel(node* root,int level)
{
	if(root==NULL)
	{
		return;
	}
	if(level==1)
	{
		cout<<""<<root->data;
	}
	else if(level>1)
	{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
}


int TREE_CLASS::height(node* node)
{
	if(node==NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);
		
		if(lheight>rheight)
		{
			return(lheight + 1);
		}
		else
		{
			return(rheight + 1);
		}
	}
}


int main()
{
	int choice;
	TREE_CLASS obj;
	do
	{
		cout<<"\n\t\t MAIN MENU";
		cout<<"\n 1] CREATE";
		cout<<"\n 2] DISPLAY";
		cout<<"\n 3] EXIT";
		cout<<"\n\t Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:obj.create();
				   break;
			case 2:if(obj.root==NULL)
				   {
				   		cout<<"Tree is not Created!";
				   }
				   else
				   {
				   		obj.printLevelOrder(obj.root);
				   }
				   break;
		}
	}while(choice<=2);
}
