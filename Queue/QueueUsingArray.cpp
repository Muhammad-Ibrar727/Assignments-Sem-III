#include <iostream>
using namespace std;

const int MAX_SIZE = 6; // Define the maximum size of the queue

int rear = -1, front = -1;

void Enqueu(int Queue[], int value) {
	
	 if((front==0 && rear==MAX_SIZE-1) || (front==rear+1))
	 {
	 	cout<<"FUll\n";
	 	return;
	 }
	 else if(front==-1)
	 {
	 	front=0;
	 	rear=0;
	 	Queue[rear]=value;
	 }
	 else if (rear==MAX_SIZE-1)
	 {
		rear=0;
	 }
	 else
	 {
	 	rear=rear+1;
	 }
	 
	 	Queue[rear]=value;
}

void Dequeu(int Queue[]) {
    if (front == -1 ) {
        cout << "Underflow: Queue is empty" << endl;
        return;
    }
    if(front==rear)
    {
    	front=-1;
    	rear=-1;
	}
	else if(front==MAX_SIZE-1)
	{
		front=0;
	}
	else
	{
    cout << Queue[front] << " deleted from the list" << endl;
	front++;
	}

}

void display(int Queue[]) 
{
    if (front == -1) 
	{
        cout << "Your Queue is empty" << endl;
        return;
    } 
	else 
	{
        if (front <= rear) 
		{
            for (int i = front; i <= rear; i++)
			{
                cout << Queue[i] << ",";
            }
        }
		else 
		{
            for (int i = front; i < MAX_SIZE; i++) 
			{
                cout << Queue[i] << ",";
            }
            for (int i = 0; i <= rear; i++) 
			{
                cout << Queue[i] << ",";
            }
        }
        cout << endl;
    }
}

void Get_Queue(int Queue[]) {
    int n;
    cout << "How many elements you want to enter: ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Cannot insert more than " << MAX_SIZE << " elements." << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter the value no " << i + 1 << ": ";
        cin >> value;
        Enqueu(Queue, value);
    }
}

int main() {
    int Queue[MAX_SIZE];
	Get_Queue(Queue);
    display(Queue);
    while(true)
    {
    cout<<"choose the option\n";
    cout<<"1.For insertion\n";
    cout<<"2.for deletion\n";
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
    			Enqueu(Queue,val);
			}
    		break;
    	case 2:
    		Dequeu(Queue);
    		break;
    	case 3:
    		 display(Queue);
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

