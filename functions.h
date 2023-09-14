#include<iostream>
using namespace std;

void mainMenu()
{
		cout << "\n\t\t\t\t\t\t 1. Singly Linked List\n\n";
		cout << "\t\t\t\t\t\t 2. Doubly Linked List\n\n";
		cout << "\t\t\t\t\t\t 3. Singly Circular Linked List\n\n";
		cout << "\t\t\t\t\t\t 4. Doubly Circular Linked List\n\n";
		cout << "\t\t\t\t\t\t 5. Exit\n";
		cout << "[COMPILER] : Enter Your Choice\n";
		cout << "\n[USER] : ";

}
void Submenu()
{
	cout << "\n\t\t\t\t\t--------------------------------------------\n";
				cout << "\n\t\t\t\t\t\t*Select Operations*\n";
				cout << "\n\t\t\t\t\t\t1. Insertion Operation\n";
				cout << "\n\t\t\t\t\t\t2. Deletion operation\n";
				cout << "\n\t\t\t\t\t\t3. Searching Operation\n";
				cout << "\n\t\t\t\t\t\t4. Sorting Linkedlist\n";
				cout << "\n\t\t\t\t\t\t5. Back To Main Menu\n";

				cout << "[COMPILER] : Enter your choice\n";
				cout << "\n[USER]: ";
}

//for insertion
void Submenu2()
{
	cout << "\n\t\t\t\t\t--------------------------------------------\n";
						cout << "\n\t\t\t\t\t\t*Select Operations*\n";
						cout << "\n\t\t\t\t\t\t1. Insert A Node In The Beginning\n";
						cout << "\n\t\t\t\t\t\t2. Insert A Node In The Last\n";
						cout << "\n\t\t\t\t\t\t3. Insert At Location\n";
						cout << "\n\t\t\t\t\t\t4. show LinkedList\n";

						cout << "\n\t\t\t\t\t\t5. Back To Main Menu\n";

						cout << "\n[COMPILER] : Enter your choice\n";
						cout << "\n[USER]: ";
}
//for deletion
Submenu3()
{
	cout << "\n\t\t\t\t\t--------------------------------------------\n";
						cout << "\n\t\t\t\t\t\t*Select Operations*\n";
						cout << "\n\t\t\t\t\t\t1. Delete A Node In The Beginning\n";
						cout << "\n\t\t\t\t\t\t2. Delete A Node In The Last\n";
						cout << "\n\t\t\t\t\t\t3. Delete At Location\n";
						cout << "\n\t\t\t\t\t\t4. show LinkedList\n";

						cout << "\n\t\t\t\t\t\t5. Back To Main Menu\n";

						cout << "\n[COMPILER] : Enter your choice\n";
						cout << "\n[USER]: ";
}
// For the singly linked list
struct node
{
	int data;
	struct node *next;
};

//For the singly Circular
struct Snode
{
	int data;
	Snode* next;
};

//For Doubly LinkedList
struct Dnode
{
	int data;
	struct Dnode*prev;
	struct Dnode*next;
};

// for Doubly Circular linked list
struct DSnode{
	int data;
	struct DSnode *prev;
	struct DSnode *next;
};

// Function to push a node to the beginning of the singly linked list
void push(struct node *&head, int nodedata)
{
	struct node *newnode = new node;
	newnode->data = nodedata;
	newnode->next = head;
	head = newnode;
}

// Function to display the singly linked list
void displayList(struct node *head)
{
	cout << "\n\t\t\t\t\t--------------------------------------------\n";
	cout << "\n\t\t\t\t\t\t ******Your Linked List****** \n";
	cout << "\t\t\t\t\t\t";
	while (head != NULL)
	{
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

// Function to insert a node at the end of the singly linked list
void insert_at_end(struct node *&head, int nodedata)
{
	struct node *newnode = new node;
	newnode->data = nodedata;
	newnode->next = NULL;

	if (head == NULL)// if linked list is empty
	{
		head = newnode;
	}
	else
	{
		struct node *current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newnode;
	}
}

void insert_at_position(struct node *&head, int nodedata, int position)
{
	struct node *newnode = new node;
	newnode->data = nodedata;
	newnode->next = NULL;

	if (position <= 0)
	{
		cout << "\n[COMPILER] : Invalid position. Position should be a positive integer." << endl;
		return;
	}

	if (position == 1)
	{
		newnode->next = head;
		head = newnode;
		return;
	}

	struct node *current = head;
	int current_position = 1;

	while (current != NULL && current_position < position - 1)
	{
		current = current->next;
		current_position++;
	}

	if (current == NULL)
	{
		cout << "\n[COMPILER] : Position exceeds the length of the list. Node not inserted." << endl;
		return;
	}

	newnode->next = current->next;
	current->next = newnode;
}

//deleting functions start from here 
void del_at_beginning(struct node*&head)
{
	if(head==NULL)
	{
		cout<<"\n[COMPILER] : Linked list is already empty";
	}
	else
	{
		struct node*temp = head;
		head = head->next;
		delete temp;
	}
}
void del_at_end(struct node*&head)
{
	if(head==NULL)
	{
		cout<<"\n[COMPILER] : Linked list is already is empty";
	}
	else if(head->next==NULL)
	{
		//if we have only one node in the linkedList
		delete head;
		head=NULL;
	}
	else
	{
		struct node*current=head;
		while(current->next->next!=NULL)
		{
			current=current->next;
		}
		delete current->next;
		current->next=NULL;
	}
}

void del_at_pos(struct node* &head, int pos)
{
    if (head == NULL)
    {
        cout << "\n[COMPILER] : Your Linked List is Empty";
        return;
    }
    if (pos <= 0)
    {
        cout << "\n[COMPILER] : Invalid position";
        return;
    }
    if (pos == 1)
    {
        del_at_beginning(head);
        return;
    }

    struct node* current = head;
    struct node* prev = NULL;
    int current_position = 1;

    while (current != NULL && current_position < pos)
    {
        prev = current;
        current = current->next;
        current_position++;
    }

    if (current == NULL)
    {
        cout << "\n[COMPILER] : Position exceeds the length of the list. Node cannot deleted." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}

// Function to get a linked list from [USER] input
void get_linkedlist(struct node *&head)
{
	int n;
	cout << "\n[COMPILER] : Enter the number of elements you want to add\n ";
	cout<<"\n[USER] : "; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int element;
		cout << "[COMPILER] : Enter element " << i + 1 << ": ";
		cin >> element;
		insert_at_end(head, element);
	}
}

void Sort_SL(node* &head) {
    if (head == NULL || head->next == NULL) {
        return; // Empty list or single element, no need to sort
    }

    node* current = head;
    while (current) {
        node* minNode = current;
        node* temp = current->next;

        while (temp) {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }

        // Swap data of current and minNode
        int tempData = current->data;
        current->data = minNode->data;
        minNode->data = tempData;

        current = current->next;
    }
}

void search(struct node*head,int search_el)
{
	if(head==NULL)
	{
		cout<<"\n[COMPILER] : Your Linked list is Already Empty";
		return;
	}
	int count=1;
	node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==search_el)
		{
			cout<<"[COMPILER] : ";cout<<search_el<<" found at location "<<count;
			count++;
			return;
		}
		else
		{
		count++;
		temp=temp->next;
		}
	}
	cout<<"\n[COMPILER] : NOT FOUND IN LINKED LIST";
}


/////////////////////////////////////////   DOUBLY LINKED LIST //////////////////////////////////////////////////////

////////////////////////insetion functios////////////////////////////////////

void insert_At_Last(struct Dnode*& head, int data)
{
    struct Dnode* newnode = new Dnode;
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct Dnode* current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->prev = current;
    }
}
void Push(struct Dnode*&head,int nodedata)
{
	struct Dnode*newnode=new Dnode;
	newnode->data=nodedata;
	newnode->next=head;
	head=newnode;

}

void insert_At_Start(struct Dnode * &head,int nodedata)
{
	struct Dnode *newnode = new Dnode;
	if(head==NULL)
	{
		newnode->next=NULL;
		newnode->prev=NULL;
		newnode->data=nodedata;
		head=newnode;
	}
	else
	{
		newnode->data=nodedata;
		newnode->prev=NULL;
		newnode->next=head;
		head=newnode;
	}

} 

void get_DList(struct Dnode *&head)

{
	int n;
	cout << "\n[COMPILER] : Enter the number of elements you want to add\n ";
	cout<<"\n[USER] : "; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int element;
		cout << "[COMPILER] : Enter element " << i + 1 << ": ";
		cin >> element;
		insert_At_Last(head,element);
	}
}

void Display_DList(struct Dnode *head)

{
    cout << "\n\t\t\t\t\t--------------------------------------------\n";
	cout << "\n\t\t\t\t\t\t ******Your Linked List****** \n";
	cout << "\t\t\t\t\t\t";
	if(head==NULL)
	{
		cout << "\n[COMPILER] : Your Linked List is already [Empty]'n";
		return;
	}

	while(head!=NULL)
	{
		cout<<head->data<<"-->";
		head=head->next;
	}
}
void search2(struct Dnode*head,int search_el)
{
		if(head==NULL)
	{
		cout<<"\n[COMPILER] : Your Linked list is Already Empty";
		return;
	}
	int count=1;
	Dnode *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==search_el)
		{
			cout<<"\n[COMPILER] : "<<search_el<<" found at location "<<count;
			count++;
			return;
		}
		else
		{
		count++;
		temp=temp->next;
		}
	}
	cout<<"\n[COMPILER] : NOT FOUND IN LINKED LIST";
}

void insert_At_Position(struct Dnode*& head, int data, int pos) {
    if (pos == 0) {
        cout << "\n[COMPILER] : Invalid position!";
        return;
    }

    struct Dnode* newnode = new Dnode;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (pos == 1) {
        insert_At_Start(head,data);
        return;
    }

    struct Dnode* current = head;
    int position = 1;

    while (position < pos - 1 && current!=NULL) {
        current = current->next;
        position++;
    }

    if (current==NULL) {
        cout << "\n[COMPILER] : Position exceeds the list length." << endl;
        delete newnode;
        return;
    }

    // Inserting after the current node
    newnode->next = current->next;
    newnode->prev = current;
    current->next = newnode;
}


/////////////Deletion functions of Doubly linkedlist//////////////

void del_At_Start(struct Dnode* &head)
{
	if(head==NULL)
	{
		cout<<"Your linkedlist is already Empty";
		return;
	}
	
	
	struct Dnode *temp=head;
	head=head->next;

	if(head->prev!=NULL)
		{
			head->prev=NULL;
		}
	delete temp;
	
}

void del_At_Last(struct Dnode*&head)
{
	
	if(head==NULL)
	{
		cout<<"\n[COMPILER] : Your Linked list is already Empty";
		return;
	}
	
	struct Dnode *ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}

    //last node
	if(ptr->prev!=NULL)
	{
		ptr->prev->next=NULL;
	}
	else
	{
        //IF we have only one node
		head=NULL;
	}

	delete ptr;
}

void del_At_Position(struct Dnode* &head,int pos)
{
	if(pos<=0)
	{
		cout<<"\n[COMPILER] : Invalid Position !";
		return;
	}

	if(pos==1)
	{
		del_At_Start(head);
		return;
	}

	Dnode *current=head;
	int currentPos=1;

	while(currentPos < pos && current!=NULL)
	{
		current=current->next;
		currentPos++;
	}
	if(current==NULL)
	{
		cout<<"\n[COMPILER] : Position Exceeds from list";
		return;
	}

    current->prev->next=current->next;
    current->next->prev=current->prev;
	delete current;
	cout<<"\n[COMPILER] : Node deleted at no "<<pos<<endl;
}

void Sort_DL(struct Dnode * &head)
{
    if(head == NULL || head->next==NULL)
    {
        cout<<"[COMPILER] : your linked list is empty";
        return;
    }
   
    Dnode *current=head;
    while(current)
    {
        
        Dnode* min_node=current;
        Dnode* temp=current->next;

        while(temp)
        {
            if(temp->data < min_node->data)
            {
                min_node=temp;
            }
            temp=temp->next;
           
        }

        //swape data  current with min node

        int tempData= current->data;
        current->data=min_node->data;
        min_node->data=tempData;
        
        current=current->next;
    }
}
///////////////////////////Singly circular's functions start from here//////////////////////////////////////////



void insert_at_start(struct Snode*&head,int nodedata)
{
	struct Snode * newnode=new Snode;
	newnode->data=nodedata;
	
	if( head==NULL)
	{
		newnode->next=newnode;
		head=newnode;
		return;
	}
	
	Snode *ptr=head;
	while(ptr->next!=head)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=head;
	head=newnode;
}

void insert_at_last(struct Snode* &head, int data)
{
    struct Snode* newnode = new Snode;
    newnode->data = data;
    newnode->next = NULL; // Initialize the new node's next pointer to NULL

    if (head == NULL)
    {
        // If the list is empty, make the new node point to itself
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        // Traverse the list to find the last node
        Snode* ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }

        // Insert the new node at the end
        ptr->next = newnode;
        newnode->next = head;
    }
}

void insert_at_pos(struct Snode*& head, int data, int pos) {
    if (pos <= 0) {
        cout << "\n[COMPILER] : Invalid position";
        return;
    }

    struct Snode* newnode = new Snode;
    newnode->data = data;
    newnode->next = NULL;

    if (pos == 1) {
        insert_at_start(head,data);
        return;
    }

    struct Snode* current = head;
    int position = 1;

    while (position < pos - 1 && current->next != head) {
        current = current->next;
        position++;
    }

    if (position < pos - 1) 
    {
        cout << "\n[COMPILER] : Position exceeds the list length." << endl;
        delete newnode;
        return;
    }

    // Inserting after the current node
    newnode->next = current->next;
    current->next = newnode;
}



void get_SC_list(struct Snode* &head)
{
	 int n;
	cout << "\n[COMPILER] : Enter the number of elements you want to add\n ";
	cout<<"\n[USER] : "; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int element;
		cout << "[COMPILER] : Enter element " << i + 1 << ": ";
		cin >> element;
		insert_at_last(head, element);
	}	
}

void Display_SClist(struct Snode*head)
{
    cout << "\n\t\t\t\t\t--------------------------------------------\n";
	cout << "\n\t\t\t\t\t\t ******Your Linked List****** \n";
	cout << "\t\t\t\t\t\t";
	if (head == NULL) 
	{
        cout << "\n[COMPILER] : Your linked list is empty";
        return;
    }
	 else 
	 {
        Snode* temp = head;
        do {
            cout << temp->data << "-->";
            temp = temp->next;
        	} 
			while (temp !=head);
    }
    cout<<"head";
    cout << endl;
}


//Deletion in Singly Circular linked list
void Del_at_start(Snode* &head)
{
    if (head == NULL)
	{
		cout<<"\n[COMPILER] : your linked list is Empty";
        return;
	}

    Snode* temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    if (temp == head) // If there's only one node
    {
        delete head;
        head = NULL;
    }
    else
    {
        Snode* todelete = head;
        temp->next = head->next;
        head = head->next;
        delete todelete;
    }
}


void Del_at_position(struct Snode* &head, int pos)
{
    if (head == NULL)
    {
        cout << "\n[COMPILER] : Your Linked List is Empty";
        return;
    }
    if (pos <= 0)
    {
        cout << "\n[COMPILER] : Invalid position";
        return;
    }
    
    // Special case: Deleting the head node.
    if (pos == 1)
    {
        //deletion at start function called
		Del_at_start(head);
        return;
    }

    struct Snode* current = head;
    struct Snode* prev = NULL;
    int current_position = 1;

    while (current->next != head && current_position < pos)
    {
        prev = current;
        current = current->next;
        current_position++;
    }

    if (current_position < pos)
    {
        cout << "\n[COMPILER] : Position exceeds the length of the list. Node cannot be deleted." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}


void del_at_last(struct Snode *head)
{
	if(head==NULL)
	{
		cout<<"\n[COMILER] : Your linked list is already Empty";
		return;
	}
	
	Snode *ptr=head;
	
	while(ptr->next->next!=head)
	{
		ptr=ptr->next;
	}

	ptr->next=head;
	cout<<"\n[COMPILER] : last node deleted in singly circular\n";

}

void search_SC(struct Snode* head, int search_el)
{
    if (head == NULL)
    {
        cout << "\n[COMPILER] : Linked List is Empty" << endl;
        return;
    }

    int count = 1;
    Snode* temp = head;

    do
    {
        if (temp->data == search_el)
        {
            cout << "\n[COMPILER] : " << search_el << " found at location " << count << endl;
            return;
        }

        count++;
        temp = temp->next;

    } while (temp != head);

    cout << "\n[COMPILER] : " << search_el << " NOT FOUND IN LINKED LIST" << endl;
}


void Sort_SingleCircularList(Snode* &head) {
    if (head == NULL || head->next == head) {
        return; // Empty list or single element, no need to sort
    }

    Snode* current = head;
    do {
        Snode* minNode = current;
        Snode* temp = current->next;

        do {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        } while (temp != head);

        // Swap data of current and minNode
        int tempData = current->data;
        current->data = minNode->data;
        minNode->data = tempData;

        current = current->next;
    } while (current != head);
}



///////////////////////////////DOUBLY CIRCULAR Linked list///////////////////////////////////
void Insert_At_Beginning(struct DSnode* &head,int data)

{
	struct DSnode *newnode=new DSnode;
	newnode->data=data;
	if(head==NULL)
	{
		newnode->next = newnode; // Circular link to itself
        newnode->prev = newnode; // Circular link to itself
        head = newnode; // Set the new node as the head
	}
	else{
		newnode->next = head;
        newnode->prev = head->prev;
        head->prev->next = newnode;
        head->prev = newnode;
        head = newnode; // Update the head to the new node
	}
}

void Insert_At_End(struct DSnode * &head,int nodedata )
{
	
	//if we have no node at start
	if(head==NULL)
	{
		Insert_At_Beginning(head,nodedata);
		return;
	}
	
	struct DSnode *newnode=new DSnode;
	newnode->data=nodedata;
	struct DSnode *ptr=head;
	while(ptr->next!=head)
	{
		ptr=ptr->next;
	}
	newnode->next=head;
	newnode->prev=ptr;
	ptr->next=newnode;
	head->prev=newnode;
}

void Insert_At_Pos(struct DSnode*& head, int data, int pos) {
    if (pos <= 0) {
        cout << "\n[COMPILER]: Invalid position";
        return;
    }

    struct DSnode* newnode = new DSnode;
    newnode->data = data;


    if (pos == 1) {
        
        Insert_At_Beginning(head,data);
		return;
    }

    struct DSnode* current = head;
    int position = 1;

    while (position < pos - 1) {
        current = current->next;
        position++;
        if (current == head) {
            cout << "\n[COMPILER] : Position exceeds the length of the list." << endl;
            delete newnode;
            return;
        }
    }

    // Inserting after the current node
    newnode->next = current->next;
    newnode->prev = current;
    current->next->prev = newnode;
    current->next = newnode;
}


void get_DSlist(struct DSnode * &head)
{
 int n;
 cout<<"\n[COMPILER] : How many elements you want to Insert:";
 cout<<"\n[USER] : ";cin>>n;
 for(int i=0;i<n;i++)
 {
	int element;
	cout<<"[COMPILER] : Enter the element no "<<i+1<<" ";
	cin>>element;
	Insert_At_End(head,element);
 }
}
void Display_DClist(struct DSnode* head) {
    cout << "\n\t\t\t\t\t--------------------------------------------\n";
	cout << "\n\t\t\t\t\t\t ******Your Linked List****** \n";
	cout << "\t\t\t\t\t\t";
    if (head == NULL) {
        cout << "Your LinkedList is empty" << endl;
        return;
    } else {
        struct DSnode* current = head;
        do {
            cout << current->data << "-->";
            current = current->next;
        } while (current != head);
        cout << endl;  // Print a newline to separate the lists if needed
    }
}

void Del_At_Start(struct DSnode *&head)
{
	if(head==NULL)
	{
		cout<<"\n[COMPILER] : Your linked list is already Empty";
		return;
	}
    struct DSnode*ptr=head;

    //if we have only one node in the linked list
	if(ptr->next==head)
	{
		delete ptr;
		head=NULL;
		return;
	}

	while(ptr->next!=head)
	{
		ptr=ptr->next;
	}

	ptr->next=head->next;
	head->next->prev=ptr;
	head=head->next;
	
	
}

void Del_At_End(struct DSnode*&head)
{
	if(head==NULL)
	{
		cout<<"\n[COMPILER] : Your Linkedlist is already Empty";
		return;
	}
	if(head->next=head)
	{
		Del_At_Start(head);
		return;
	}

	struct DSnode *ptr=head;

	while(ptr->next->next!=head)
	{
		ptr=ptr->next;
	}
	ptr->next=head;
	head->prev=ptr;
	ptr->next->prev=NULL;

}

void Search_DS(struct DSnode* head, int search_el)
{
		if(head==NULL)
	{
		cout<<"\n[COMPILER] : Your Linked list is Already Empty";
		return;
	}
    int count = 1;
    DSnode* temp = head;

    if (temp == NULL)
    {
        cout << "[COMPILER] : Linked List is Empty" << endl;
        return;
    }

    do
    {
        if (temp->data == search_el)
        {
            cout << "[COMPILER] : " << search_el << " found at location " << count << endl;
            return;
        }
        else
        {
            count++;
            temp = temp->next;
        }
    } while (temp != head);

    cout << "[COMPILER] : " << search_el << " NOT FOUND IN LINKED LIST" << endl;
}


void Del_at_position(struct DSnode* &head, int pos)
{
    if (head == NULL)
    {
        cout << "[COMPILER] : Your Doubly Circular Linked List is Empty";
        return;
    }
    if (pos <= 0)
    {
        cout << "[COMPILER] : Invalid position";
        return;
    }

    // Special case: Deleting the head node.
    if (pos == 1)
    {
        Del_At_Start(head);
        return;
    }

    struct DSnode* current = head;
    int current_position = 1;

    do
    {
        current = current->next;
        current_position++;
        if (current == head && current_position != pos)
        {
            cout << "\n[COMPILER] : Position exceeds the length of the list. Node cannot be deleted." << endl;
            return;
        }
    } while (current != head && current_position < pos);

    if (current == head)
    {
        cout << "[COMPILER] : Position exceeds the length of the list. Node cannot be deleted." << endl;
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

//sorting of the doubly circular linked list
void Sort_DoublyCircularList(DSnode* &head) {
    if (head == NULL || head->next == head) {
        return; // Empty list or single element, no need to sort
    }

    DSnode* current = head;
    DSnode* tail = head->prev; // Tail node points to the last node

    bool swapped;

    do {
        swapped = false;
        DSnode* temp = head;

        while (temp->next != head) {
            if (temp->data > temp->next->data) {
                // Swap data values
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);

    // After sorting, head may have changed, so update head to the minimum element
    head = current;
}
