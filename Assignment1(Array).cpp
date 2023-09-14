#include <iostream>
#include<windows.h>
using namespace std;
const int size = 20;

void display_arr(int arr[],int sz)
{
	cout<<"Your Array: ";
	for(int i=0;i<sz;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<"\n_________________________________________\n";
}
void insert_at_begining(int arr[], int &sz, int element)
{
	if (sz > size)
	{
		cout << "Size is full , cannot insert the new element:\n";
		return;
	}
	else
	{
		for (int i = sz; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = element;
		sz++;
	}
	
}

void insert_at_end(int arr[], int &sz, int element)
{
	if (sz >= size)
	{
		cout << "array is full , cannot insert element";
		return;
	}
	else
	{
		arr[sz] = element;
		sz++;
	}

}

void insert_at_pos(int arr[], int &sz, int element, int pos)
{
	if (sz >= size)
	{
		cout << "Array is full , cannot insert the element";
		return;
	}

	if (sz < pos - 1 || pos - 1 < 0)
	{
		cout << "invalid position for entering the number";
		return;
	}

	// inserting the element at the pos
	for (int i = sz; i > pos - 1; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos - 1] = element;
	sz++;

	
}

void Del_first_element(int arr[], int &sz)
{
	if(sz==0)
	{
		cout<<"your array is empty";
		return;
	}
	
	for (int i = 0; i < sz; i++)
	{
		arr[i] = arr[i + 1];
	}
	sz--;
		cout << "First Element is Deleted\n";

}

void Del_last_element(int arr[], int &sz)
{
	sz--;
	if(sz==0 || sz<0)
	{
		cout<<"your array is empty";
		return;
	}
	cout<<"Last Element Deleted\n";
}

void Del_at_pos(int arr[], int &sz, int pos)
{
	if (pos - 1 < 0 || pos - 1 >= sz)
	{
		cout << "Invalid position for deletion." << endl;
		return;
	}

	for (int i = pos - 1; i < sz; i++)
	{
		arr[i] = arr[i + 1];
	}
	sz--;
}

// Sorting of arrays
void Insertion_sort(int arr2[],int n)
{
	for(int j=1; j<n; j++)
	{
		int key=arr2[j];
		int i=j-1;
		while(i>=0 && arr2[i]>key)
		{
			arr2[i+1]=arr2[i];
			i=i-1;
		}
		arr2[i+1]=key;
	}
	
}

//searching the element in array
void search(int arr[], int n, int s)
{
    bool found = false; 
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            cout << s << " found at the position no " << i + 1;
            found = true; 
            break;
        }
    }

    if (!found)
    {
        cout << s << " not found in the array";
    }
}

void selection_sort(int arr[],int size)

{
	int temp;
	int i=0,j=0,k=0;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			}
			
		}
	}
}
void bubble_sort(int arr[],int n)
{
		
	 for (int i = 0; i < n - 1; i++) 
		{
			for (int j = 0; j < n - i - 1; j++) 
				{ 
				// Fix the termination condition
					    if (arr[j] > arr[j + 1])
								{
					                swap(arr[j], arr[j + 1]);
					            }
				}
		}
	
}

int main()
{
	 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	    int arr[size];
		cout << "How many elements you want to Enter\n(For Insertion, Deletion & searching):";
				int sz;
			
				cin >> sz;
		
				cout << "Enter the " << sz << " elements:" << endl;
				
				for (int i = 0; i < sz; i++)
				{
					cin >> arr[i];
				}
				cout << endl;
			
				
				display_arr(arr,sz);

				
		while (true)
		{

	
			cout << endl;
			cout << "*****************************" << endl;
			cout << "Choose the option:\n";
			cout << "1.Insertion of Elements:\n";
			cout << "2.Deletion of Elements:\n";
			cout << "3.Sorting of Array:\n";
			cout << "4.Searching of Elements:\n";
			cout << "5.Exit:\n";
			char choice;
			cin >> choice;
		
		
			switch (choice)
			{
				case '1':
					cout << "****Insertion of Element****" << endl;
				
					while(true)
					{
							
						char choice2;
						cout << "\n*****Select Operations:*****\n";
						cout << "1.Insertion of Element at Beginnig\n";
						cout << "2.Insertion of Element at End\n";
						cout << "3.Insertion of Element at Specific Location\n";
						cout << "4.Back to the menu\n";
						
						cin >> choice2;
						int element;
		
						switch (choice2)
						{
						case '1':
			
							cout << "Enter the elements you want insert:";
							cin >> element;
							insert_at_begining(arr, sz, element);
							display_arr(arr,sz);
							break;
			
						case '2':
							cout << "Enter the element you want to insert at end:";
							cin >> element;
							insert_at_end(arr, sz, element);
							display_arr(arr,sz);
							break;
						case '3':
							cout << "Enter the element you want to insert at specific location:";
							cin >> element;
							cout << "\nEnter the position where you want to insert:";
							int pos;
							cin >> pos;
							insert_at_pos(arr, sz, element, pos);
							display_arr(arr,sz);
							break;
						case '4':
							break;
						default:
							cout << "Enter the valid choice:";
						}
						if(choice2=='4')
						{
							break;
					}
		
		}//Here while loop is terminating
		break;
		
		while(true)
	{
		
		case '2':
			cout << "\n****Deletion of Elements****" << endl;

			cout << "\n*****Select Operations:*****\n";
			cout << "1.Deletion of Element at Beginnig\n";
			cout << "2.Deletion of Element at End\n";
			cout << "3.Deletion of Element at Specific Location\n";
			cout << "4.Back to the main menu\n";
			char choice3;

			cin >> choice3;
			
			switch (choice3)
			{
				case '1':
				
					Del_first_element(arr, sz);
					display_arr(arr,sz);
					break;
				case '2':
					
					Del_last_element(arr, sz);
					display_arr(arr,sz);
					break;
				case '3':
					cout << "Deleting the element at specific location" << endl;
					int pos2;
					cout << "Enter the position ";
					cin >> pos2;
					Del_at_pos(arr, sz, pos2);
					display_arr(arr,sz);
					break;
				case '4':
					break;
				default:
					cout << "Invalid choice";
				}
	
				if(choice3=='4')
				{
					break;
				}
	}//End of while loop
	break;
	
	while(true)
	{
		
		
		case '3':
			cout << "\n****Sorting of Array****" << endl;
			int n;
			cout<<"How many Elements you want to enter for sorting:";
			int arr2[n];
			cin>>n;
			cout<<"Enter the "<<n<<" elements\n";
			for(int i=0;i<n;i++)
			{
				cin>>arr2[i];
			}
			cout<<"Your array for the sorting is :\n";
			display_arr(arr2,n);
		
				while(true)
				{
				
					cout<<"\n***Select the Operation***\n";
					cout<<"1.insertion sort\n";
					cout<<"2.Selection sort\n";
					cout<<"3.Bubble  sort\n";
					cout<<"4.Exit\n";
					char choice4;
					cin>>choice4;
				
				switch(choice4)
				{
					case '1':
						//insertion sort
						 Insertion_sort(arr2,n);
						 display_arr(arr2,n);
							break;
					case '2':
							selection_sort(arr2,n);
							display_arr(arr2,n);
							break;
					case '3':
							bubble_sort(arr2,n);
					    	// Displaying the sorted array
					    	display_arr(arr2,n);
							break;
					case '4':
							break;
					default:
							cout<<"Enter the valid Options";
				}
				
				if(choice4=='4')
				{
					break;
				}
		    }
	    	break;
	    }//End of while loop for case 3
	    
	    break;
    
		case '4':
		
			cout << "****Searching of Element****" << endl;
			cout<<"Enter the number you want to search in array:";
			int search_element;
			cin>>search_element;
			search(arr,sz,search_element);
			break;
		case '5':
			cout<<"Program terminated";
			break;
		default:
			cout << "Choose the correct options:";
		}
		if(choice=='5')
		{
			break;
		}
	}//End of the main while loop
}
