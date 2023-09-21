#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
	int priority;
};

node * front=NULL;
node * rear=NULL;
void Enqueue(int data, int pr) {
    struct node* newnode = new node;
    newnode->data = data;
    newnode->priority = pr;
    newnode->next = NULL;

    if (front == NULL || front->priority > pr) {
        newnode->next = front;
        front = newnode;
    } else {
        struct node* temp = front;
        while (temp->next != NULL && temp->next->priority <= pr) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    if (rear == NULL) {
        rear = newnode;
    }
}

void Dequeue()
{
	if(front==NULL)
	{
		cout<<"Your Queue is empty";
		return;
	}
	struct node*temp=front;
	front=front->next;
	delete temp;
}
void get_Que()
	{
	int n;
	cout<<"how many nodes you want to ente in the Queue";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int element;
		int priority;
		cout<<"enter the element no"<<i+1;
		cin>>element;
		cout<<"Enter the priority of element no "<<i+1<<" ";
		cin>>priority;
		Enqueue(element,priority);
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
			cout<<temp->data<<"("<<temp->priority<<")"<<" --> ";
			temp=temp->next;
		}
	}
}

int main()
{
	get_Que();
	cout<<endl;
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
    switch(c)
    {
    	case 1:
    		{
    			int val;
    			cout<<"Enter the new value";
    			cin>>val;
    			int p;
    			cout<<"Enter the priority";
    			cin>>p;
    			Enqueue(val,p);
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
