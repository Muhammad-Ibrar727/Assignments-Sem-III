//Muhammad Ibrar
//Roll NUmber: F22-019


#include<iostream>
#include"Assignment3Functions.h"
using namespace std;
int main()
{
    while(true)
    {
        cout<<"\n____________Choose the options_________________\n";
        cout<<"1.Binary Search on array\n";
        cout<<"2.Insertion sort on the linked list\n";
        cout<<"3.Priority Queue on  the linked list\n";
        cout<<"4. For Exit\n";
        
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            cout<<"---Binary Search---\n";
           	Get_Array_for_search();
        break;
        }//End of the case 1
        
        case 2:
        	{
			
            cout<<"\n---Insertion Sort On Linked List---\n";
            
            struct node*head=NULL;
            Get_List(head);
            cout<<"Linked list without sorting: ";
            Display(head);
            cout<<endl;
            cout<<"\nLinked list after the sorting:";
            insertion_sort(head);
            Display(head);
            cout<<endl;
            break;
        }
        case 3:
            {
            cout<<"\n---priority Queue---\n";
            Get_Queue();
            cout<<endl;
            Display_Queue();
            cout<<endl;
			}
            break;
        case 4:
        cout<<"Program Terminated\n";
            break;       
        default:
            break;
        }
        if(choice==4)
        {
            break;
        }
    }

    return 0;
}
