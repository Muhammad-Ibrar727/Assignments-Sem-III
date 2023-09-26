#include<iostream>
using namespace std;


// Queue Using Array

const int MAX_SIZE=6;
int Queue[MAX_SIZE];

int front=-1,rear=-1;

void Enqueu(int value)
{
	if((front==0 && rear==MAX_SIZE-1) || (front==rear+1))
	{
		cout<<"Queue is full\n";
		return;
	}
	else if(front==-1)
	{
		rear=0;
		front=0;
		Queue[rear]=value;
	}
	else if(rear==MAX_SIZE)
	{
		rear=0;
	}
	else
	{
		rear++;
	}
	Queue[rear]=value;
}

void Dequeu()
{
	if(front==-1 )
	{
		cout<<"Your Queue is already Empty";
		return;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==MAX_SIZE)
	{
		front=0;
	}
	else
	{
		cout<<Queue[front]<<" Deleted from queue\n";
		front++;
	}
}

void Get_queue()
{
	int n;
	cout<<"How many elements you want to Enter in the Stack : ";
	cin>>n;
	
	if (n > MAX_SIZE) {
        cout << "Cannot insert more than " << MAX_SIZE << " elements." << endl;
        return;
    }
    
	for(int i=0; i<n; i++)
	{
		int element;
		cout<<"Enter the element  no "<<i+1<<" ";
		cin>>element;
		Enqueu(element);
	}
}

void Display()
{
	if(front==-1)
	{
		cout<<"Queue is Empty\n";
		return;
	}
	if(front<=rear)
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<Queue[i]<<",";
		}
	}
	else
	{
		for(int i=front;i<MAX_SIZE;i++)
		{
			cout<<Queue[i]<<",";
		}
		for(int i=0; i<=rear;i++)
		{
			cout<<Queue[i]<<",";
		}
	}
	cout<<endl;
}

//Queue Using the linkedlist

struct Qnode{
	int data;
	Qnode *next;
};
Qnode *Front=NULL;
Qnode*Rear=NULL;

void ENQ(int value)
{
	struct Qnode*Newnode=new Qnode;
	Newnode->data=value;
	Newnode->next=NULL;
	if(Front==NULL && Rear==NULL)
	{
		Front=Newnode;
		Rear=Newnode;
	}
	else
	{
		Rear->next=Newnode;
		Rear=Newnode;
	}
	
}

void DeQue()
{
	if(Front==NULL)
	{
		cout<<"Your Queue is Empty\n";
		return;
	}
	if(Front==Rear)
	{
		cout<<"Last Element of Queue has been Deleted\n";
		Front=NULL;
		Rear=NULL;
	}
	else
	{
		struct Qnode*temp=Front;
		Front=Front->next;
		delete temp;
		cout<<"Element on Front has been Deleted\n";
	}
}
void Get_Que()
{
	int n;
	cout<<"How many Elements You want to Enter in the Queue:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int element;
		cout<<"Enter the element no "<<i+1<<": ";
		cin>>element;
		ENQ(element);
	}
}

Display_Que()
{
	if(Front==NULL)
	{
		cout<<"Queue is Already Empty\n";
		return 0;
	}
	cout<<"[Front]-->";
	struct Qnode*temp=Front;
	while(temp!=NULL)
	{
		cout<<temp->data<<"-->";
		temp=temp->next;
	}
	cout<<"[Rear]\n";
}



//stack by using linked list



struct node{
	int data;
	node*next;
};

struct node*top=NULL;

void Push(int value)
{
	struct node*newnode=new node;
	newnode->data=value;
	newnode->next=top;
	top=newnode;
	
}

void Pop()
{
	if(top==NULL)
	{
		cout<<"Stack is Empty OR Underflow";
		return;
	}
	else
	{
		cout<<top->data<<" poped from the Stack";
		top=top->next;
	}
}
void Get_Stack()
{
	int n;
	cout<<"How many Elements you want to insert in the stack:";
	cin>>n;
	for(int i=0;i<n; i++)
	{
		int element;
		cout<<"Enter the element no "<<i+1<<" ";
		cin>>element;
		Push(element);
	}
}
void display()
{
	if(top==NULL)
	{
		cout<<"Stack is FULL";
		return;
	}
	else
	{
		cout<<"[TOP]\n";
		struct node*temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	
}

//Stack Using the Array
const int MAX=5;
int stack[MAX];
int Top1=-1;

void push(int value)
{
	if(Top1>MAX)
	{
		cout<<"OVER FLOW\n";
		return;
	}
	stack[++Top1]=value;
}

void pop()
{
	if(Top1>0)
	{
		cout<<stack[Top1]<<" poped from the stack\n";
		Top1--;
		
	}
	else
	{
		cout<<"UNDER FLOW\n";
		return;
	}
}

void Get_stack()
{
	int n;
	cout<<"How many Elements You want to Enter in the Stack: ";
	cin>>n;
	for(int i=0;i<n; i++)
	{
		int element;
		cout<<"Enter the element no "<<i+1<<": ";
		push(element);
	}
}
void Show()
{
	for(int i=0;i<Top1;i++)
	{
		cout<<stack[i]<<endl;
	}
}
