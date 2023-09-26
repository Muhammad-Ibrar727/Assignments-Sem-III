#include<iostream>
using namespace std;


int Binary_search(int arr[], int lb, int ub,int item,int loc)
{
	int beg,end,mid;
	beg=lb;
	end=ub;
	mid=int((beg+end)/2);
	
	while(beg<=end && arr[mid]!=item)
	{
		if(item<arr[mid])
		{
			end=mid-1;
		}
		else
		{
			beg=mid+1;
		}
		
		mid=int((beg+end)/2);
	}
	
	if(arr[mid]==item)
		return loc=mid;
	else
		return loc=-1;
}

void Get_Array_for_search()
{
	int n;
	cout<<"How many elements you want to enter in the array : ";
            cin>>n;
            int arr[n];
            cout<<"\n\t\t\t\t[NOTE]: Enter the elements in sorted form\n";
            cout<<"Enter the "<<n <<" elements\n";
            for(int i=0;i<n;i++)
            {
                cout<<"Enter the element no "<<i+1<<" ";
                cin>>arr[i];
            }
            
            cout<<"Array :";

            // displayig arrray
            for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<",";
            }
            
            //Binary search
            cout<<endl;
            int element;
            cout<<"Enter the element you want to search in the array :";
            cin >> element;
             int loc=Binary_search(arr,1,n,element,0);
            if(loc==-1)
            {
                cout<<"Not found !";
                
            }
            else
            {
            cout<<"element found at loc "<<loc+1;
            }
}

// for the insertion sort on linkedlist
struct node{
	int data;
	node*next;
};

void insert(struct node*&head,int nodedata)
{
	struct node*newnode=new node;
	newnode->data=nodedata;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		
	}
	else
	{
		struct node*temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp->next=newnode;
	}
}

// geting the linked list from the user
void Get_List(struct node*&head)
{
	int n;
	cout<<"How many elements you want to enter? : ";
	cin>>n;
	for(int i=0; i<n;i++)
	{
		int element;
		cout<<"Enter the element no "<<i+1<<": ";
		cin>>element;
		insert(head,element);
	}
}

void Display(struct node*head)
{
	if(head==NULL)
	{
		cout<<"LInked list is Empty";
		return;
	}
	else
	{
		struct node*temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"-->";
			temp=temp->next;
		}
	}
}

void insertion_sort(struct node*head)
{
	if(head==NULL)
	{
		cout<<"\nYour linked list is Empty\n";
		return;
	}
	else if(head->next==NULL)
	{
	cout<<"\nYour linked list has only 1 node\n";
	return;
	}
	struct node*current=head;
	
	while(current!=NULL)
	{
		struct node*current2=head;
		while(current!=current2)
		{
			if(current->data < current2->data)
			{
				int temp=current2->data;
				current2->data=current->data;
				current->data=temp;
			}
			current2=current2->next;
		}
		
		
		current=current->next;
		
	}
	
}

// Functions for the priority queue

struct Node{
int data;
int priority;
Node *next;
};
 Node*front=NULL;
 Node*rear=NULL;

void Enqeue(int data,int pr)
{
	struct Node*newnode=new Node;
	newnode->data=data;
	newnode->priority=pr;
	newnode->next=NULL;
	
	if(front==NULL || front->priority > pr)
	{
		newnode->next=front;
		front =newnode;
	}
	else
	{
		struct Node*temp= front;
		while(temp->next!=NULL && temp->next->priority <= pr)
		{
			temp=temp->next;
		}
		
		newnode->next=temp->next;
		temp->next=newnode;
	}
	if(rear==NULL)
	{
		rear=newnode;
	}
 }
void Get_Queue()
{
	int n;
	cout<<"How many elements you Enter in the queue";
	cin>>n;
	cout<<"Enter the "<<n<<" elements \n";
	for(int i=0;i<n;i++)
	{
		int element,pr;
		cout<<"Enter the element no"<<i+1<<" : ";
		cin>>element;
		cout<<"Enter the priority of element no "<<i+1<<" :";
		cin>>pr;
	 	Enqeue(element,pr);
	}
}

void Display_Queue()
{
	if(front==NULL && rear==NULL)
	{
		cout<<"Queue is Empty";
		return;
	}
	else
	{
		struct Node*temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<"("<<temp->priority<<")"<<" --> ";
			temp=temp->next;
		}
	}
}
