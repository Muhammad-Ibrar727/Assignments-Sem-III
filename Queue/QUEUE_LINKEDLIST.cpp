#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};

node* front=NULL;
node* rear=NULL;

void Enqueue(int value)
{
	struct node*newnode=new node;
	newnode->data=value;
	newnode->next=NULL;
	if(front==NULL && rear== NULL)
	{
		front=newnode;
		rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}

void Dequeue()
{
	if(front==NULL)
	{
		cout<<"Your linked list is empty\n";
		return;
	}
	if(front==rear)
	{
		cout<<"last element dequeued\n";
		front=NULL;
		rear=NULL;
	}
	else
	{
		struct node*temp=front;
		front=front->next;
		delete temp;
		cout<<"front deleted";
	}
}

void display()
{
	if(front==NULL)
	{
		cout<<"Queue list is empty\n";
		
	}
	else
	{
		struct node*temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<"-->";
			temp=temp->next;
		}
	}
}
void get_Que()
{
	int n;
	cout<<"how many nodes you want to ente in the Queue";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int element;
		cout<<"enter the element no"<<i+1;
		cin>>element;
		Enqueue(element);
	}
}
int main()
{
	get_Que();
	display();
	cout<<endl;
	 while(true)
    {
    cout<<"\nchoose the option\n";
    cout<<"1.For Enqueue\n";
    cout<<"2.for Deque\n";
    cout<<"3. for display\n";
    cout<<"4. for exit\n";
    int c; 
    cin>>c;
//    system("cls");
    switch(c)
    {
    	case 1:
    		{
    			int val;
    			cout<<"Enter the new value";
    			cin>>val;
    			Enqueue(val);
			}
    		break;
    	case 2:
    		Dequeue();
    		break;
    	case 3:
    		 display();
    		break;
    	case 4:
    		break;
    	default :
    		cout<<"Enter the correct option";
	}
	if (c==4)
	{
		break;
	}
}
return 0;
}
