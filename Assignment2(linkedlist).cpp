//Assignment no 2 *LINKED LIST*
//Submitted By Muhummad Ibrar
//Roll Number F22- 019

#include<iostream>
#include<windows.h>
#include"functions.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	while (true)
	{
		cout << "\n------------------------------------------------------Main Menu--------------------------------------------------------\n";
		mainMenu();
		char choice;
		cin >> choice;

		cout << "\n\t\t\t_______________________________________________________________________\n";
		switch (choice)
		{
		case '1':
		{
			cout << "\n\t\t\t\t\t\t****SINGLY LINKED_LIST****";
			cout << "\n\t\t\t_______________________________________________________________________\n";
			struct node *head = NULL;
			get_linkedlist(head);
			displayList(head);

			while (true)
			{
				Submenu();
				char opt;
				cin >> opt;
				switch (opt)
				{
				case '1':
					while (true)
					{
						Submenu2();//CALL THE MENU FOR INSERTION
						int choice2;
						cin >> choice2;

						switch (choice2)
						{
						case 1:
						{
							int data;
							cout << "\n[COMPILER] : Enter the data to insert at the beginning: ";
							cout<<"\n[USER]: ";cin >> data;
							push(head, data);
							cout << "\n[COMPILER] : Node with data " << data << " inserted at the beginning." << endl;
							break;
						}
						case 2:
						{
							int data;
							cout << "\n[COMPILER] : Enter the data to insert at the end: ";
							cout<<"\n[USER]: ";cin >> data;
							insert_at_end(head, data);
							cout << "\n[COMPILER] : Node with data " << data << " inserted at the end." << endl;
							break;
						}
						case 3:
						{
							int data, pos;
							cout << "\n[COMPILER] : Enter the position where you want to enter the data:";
							cout<<"\n[USER]: ";cin >> pos;
							cout << "\n[COMPILER] : Enter the data :";
							cin >> data;
							insert_at_position(head, data, pos);
							break;
						}

						case 4:
						{
							cout << "\t\t\t\t\t\t";
							displayList(head);
						}
						case 5:
							break;
						default:
							cout << "\n[COMPILER] : Enter the Valid choice\n";
						}
						if (choice2 == 5)
						{
							break;
						}
					} // End of while loop of the insertion operation
					break;

				// Deletion Operatio in the singly linked list
				case '2':
					while (true)
					{
						Submenu3();
						int choice2;
						cin >> choice2;

						switch (choice2)
						{
						case 1:
						{
							// cout << "Deletion at start";
							del_at_beginning(head);
							cout<<"\n[COMPILER] : First item is deleted from singly linked list";
							break;
						}
						case 2:
						{
							// cout << "Deletion at End\n";
							del_at_end(head);
							cout<<"\n[COMPILER] : last Element of singly linked list is deleted\n";
							break;
						}
						case 3:
						{
							int pos;
							cout << "\n[COMPILER] : Enter the position where you want to Delete the data:";
							cout<<"\n[USER] : ";	 cin>>pos;
							del_at_pos(head,pos);
							break;
						}

						case 4:
						{
							cout << "\t\t\t\t\t\t";
							displayList(head);
						}
						case 5:
							break;
						default:
							cout << "\n[COMPILER] : Enter the Valid choice\n";
						}
						if (choice2 == 5)
						{
							break;
						}
					} // End of the while loop of deletion process
					break;

				case '3':
					cout << "\n\t\t\t\t\t\t**Searching Element**\n";
					int element;
					cout<<"\n[COMPILER] : ";cout<<"Enter the element you want to search in the linked_list:";
					cin>>element;
					search(head,element);
					break;
				case '4':
					cout << "\n\t\t\t\t\t\t**Sorting of the Linkedlist**";
					Sort_SL(head);
					displayList(head);
					break;
				case '5':
					break;

				default:
					cout << "\n[COMPILER] : Enter the valid option";
				}

				if (opt == '5')
				{
					break;
				}

			} // End of while loop of main operations of the singly linked list

			break;
		}
			// End of case 1 singly linked list

		// Doubly Linked List
		case '2':
		{
			cout << "\n\t\t\t\t\t\t****DOUBLY LINKED_LIST****\n";
            cout << "\n\t\t\t_______________________________________________________________________\n";
			struct Dnode *head = NULL;
			get_DList(head);
           
			Display_DList(head);
            

			while (true)
			{
				//submenu of doubly linked list
                Submenu();
				char opt;
				cin >> opt;
				switch (opt)
				{
				case '1':
					while (true)
					{
						//menu for insertion in the doubly linked list
						Submenu2();

						int choice2;
						cin >> choice2;

						switch (choice2)
						{
						case 1:
						{
							int data;
							cout << "\n[COMPILER] : Enter the data to insert at the beginning: ";
							cin >> data;
							insert_At_Start(head,data);
							cout << "\n[COMPILER] : Node with data " << data << " inserted at the beginning." << endl;
							break;
						}
						case 2:
						{
							int data;
							cout << "\n[COMPILER] : Enter the data to insert at the end: ";
							cout<<"\n[USER]: ";cin >> data;
							insert_At_Last(head, data);
							cout << "\n[COMPILER] : Node with data " << data << " inserted at the end." << endl;
							break;
						}
						case 3:
						{
							int data, pos;
							cout << "\n[COMPILER] : Enter the position where you want to enter the data:";
							cout<<"\n[USER]: ";cin >> pos;
							cout << "\n[COMPILER] : Enter the data :";
							cout<<"\n[USER]: ";cin >> data;
							insert_At_Position(head, data, pos);
							break;
						}

						case 4:
						{
							cout << "\t\t\t\t\t\t";
							Display_DList(head);
						}
						case 5:
							break;
						default:
							cout << "\n[COMPILER] : Enter the Valid choice\n";
						}
						if (choice2 == 5)
						{
							break;
						}
					} // End of while loop of the insertion operation of DOUBLY LINKEDLIST
					break;

				// Deletion Operatio in the DOUBLY LINKEDLIST
				case '2':
					while (true)
					{
						//submenu 3 for the deletion in linked list
						Submenu3();
						int choice2;
						cin >> choice2;

						switch (choice2)
						{
						case 1:
						{
						
							del_At_Start(head);
							cout<<"\n[COMPILER] : First Element of linked list is [DELETED]\n";
							break;
						}
						case 2:
						{
							
							del_At_Last(head);
							cout<<"\n[COMPILER] : Last Node of linked list is [DELETED]\n";
							
							break;
						}
						case 3:
						{
							
							int pos;
							cout << "\n[COMPILER] : Enter the position where you want to Delete the data:";
							cout<<"\n[USER]: ";cin>>pos;
							del_At_Position(head,pos);
							break;
						}

						case 4:
						{
							cout << "\t\t\t\t\t\t";
							Display_DList(head);
						}
						case 5:
							break;
						default:
							cout << "\n[COMPILER] : Enter the Valid choice\n";
						}
						if (choice2 == 5)
						{
							break;
						}
					} // End of the while loop of deletion process of DOUBLY LINKED LIST
					break;
				case '3':

					cout << "\n\t\t\t\t\t\t****Searching of the element****\n";
					int element;
					cout<<"\n[COMPILER] : Enter the [Element] you want to Search in the D_list:\n";
					cout<<"\n[USER] : ";cin>>element;
					search2(head,element);
					break;
				case '4':
					cout << "\n\t\t\t\t\t\t*****Sorting of the Linkedlist****\n";
                   Sort_DL(head);
                   cout<<"\n\t\t\t\t\t\t";
                    Display_DList(head);
					break;
				case '5':
					break;

				default:
					cout << "\n[COMPILER] : Enter the valid option";
				}

				if (opt == '5')
				{
					break;
				}

			} // End of while loop of main operations of the DOUBLY LINKEDLIST

			break;
		}
		break;
			//END OF THE DOUBLY LINKEDLIST

			       case '3':
				   {
			           cout << "\n\t\t\t\t\t\t****[Singly Circular LinkedList]****\n";
						 cout << "\n\t\t\t_______________________________________________________________________\n";
			           struct Snode* head = NULL;
			           get_SC_list(head);
					   Display_SClist(head);
			
			           while(true)
			           {
							//Submenu for the singly circular linked list
							Submenu();
			               char opt;
			               cin>>opt;
			               switch(opt)
							{
								case '1':
				 while (true)
			           		{
					            	Submenu2();
			
					                int choice2;
					                cin >> choice2;
			
					                switch (choice2)
					                {
					                case 1:
					                {
					                    int data;
					                    cout << "\n[COMPILER] : Enter the data to insert at the beginning: ";
					                	cout<<"\n[USER]: ";cin >> data;
					                    insert_at_start(head,data);
					                    cout << "\n[COMPILER] : Node with data " << data << " inserted at the beginning." << endl;
					                    break;
					                }
					                case 2:
					                {
					                    int data;
					                    cout << "\n[COMPILER] : Enter the data to insert at the end: ";
					                    cout<<"\n[USER]: ";cin >> data;
					                    insert_at_last(head, data);
					                    cout << "\n[COMPILER] : Node with data " << data << " inserted at the end." << endl;
					                    break;
					                }
					                case 3:
					                {
					                    int data,pos;
					                    cout<<"\n[COMPILER] : Enter the position where you want to enter the data:";
					                    cout<<"\n[USER]: ";cin>>pos;
					                    cout<<"\n[COMPILER] : Enter the data :";
					                    cout<<"\n[USER]: ";cin>>data;
					                    insert_at_pos(head,data,pos);
					                    break;
					                }
			
					                case 4:
					                	{
					                		cout<<"\t\t\t\t\t\t";
					                		Display_SClist(head);
										}
					                case 5:
					                    break;
					                default:
					                    cout << "\n[COMPILER] : Enter the Valid choice\n";
					                }
					                if (choice2 == 5)
					                {
					                    break;
					                }
			           }//End of while loop of the insertion operation
						break;
			
								// Deletion Operatio in the singly circular linked list
								case '2':
										 while (true)
			           		{
					            	Submenu3();
			
					                int choice2;
					                cin >> choice2;
			
					                switch (choice2)
					                {
					                case 1:
					                {
					                	Del_at_start(head);
										cout<<"\n[COMPILER] : First Node of linked list is [DELETED]\n";
					                    break;
					                }
					                case 2:
					                {
					                   
										del_at_last(head);
										cout<<"\n[COMPILER] : Last Node of linked list is [DELETED]\n";
					                    break;
					                }
					                case 3:
					                {
					                    int pos;
					                    cout<<"\n[COMPILER] : Enter the position where you want to Delete the data:";
					                    cout<<"\n[USER]: ";cin>>pos;
                                        Del_at_position(head,pos);
			
					                    break;
					                }
			
					                case 4:
					                	{
					                		cout<<"\t\t\t\t\t\t";
					                		Display_SClist(head);
										}
					                case 5:
					                    break;
					                default:
					                    cout << "\n[COMPILER] : Enter the Valid choice\n";
					                }
					                if (choice2 == 5)
					                {
					                    break;
					                }
			           }// End of the while loop of deletion process
						break;
								case '3':
									{
									cout << "\n\t\t\t\t\t\t**Searching Element**\n";
									int element;
									cout<<"\n[COMPILER] : ";cout<<"Enter the element you want to search in the linked_list:";
									cin>>element;
									search_SC(head,element);
									}
									break;
								case '4':
									cout<<"\n\t\t\t\t\t\t**Sorting of the Linkedlist**\n";
									Sort_SingleCircularList(head);
									Display_SClist(head);
									break;
								case '5':
									break;
			
								default:
										cout<<"\n[COMPILER] : Enter the valid option";
							}
			
							if (opt=='5')
							{
								break;
							}
			
			}//End of while loop of main operations of the singly CIRCULAR linked list
			    break;
			}//END OF DOUBLY CIRCULAR LINKED LIST

		case '4':

			// Code for Doubly Circular Linked List can be added here
			{
				cout << "\n\t\t\t\t\t\t****Doubly Circular LinkedList****\n";
				 cout << "\n\t\t\t_______________________________________________________________________\n";
				struct DSnode *head = NULL;
				get_DSlist(head);
				Display_DClist(head);

				while (true)
				{
					Submenu();

					char opt;
					cin >> opt;
					switch (opt)
					{
					case '1':
						while (true)
						{
							//submenu for the insertion of doubly circular 
							Submenu2();
							int choice2;
							cin >> choice2;

							switch (choice2)
							{
							case 1:
							{
								int data;
								cout << "\n[COMPILER] : Enter the data to insert at the beginning: ";
								cout<<"\n[USER]: ";cin >> data;
								Insert_At_Beginning(head, data);
								cout << "\n[COMPILER] : Node with data " << data << " inserted at the beginning." << endl;
								break;
							}
							case 2:
							{
								int data;
								cout << "\n[COMPILER] : Enter the data to insert at the end: ";
								cout<<"\n[USER]: ";cin >> data;
								Insert_At_End(head, data);
								cout << "\n[COMPILER] : Node with data " << data << " inserted at the end." << endl;
								break;
							}
							case 3:
							{
								int data, pos;
								cout << "\n[COMPILER] : Enter the position where you want to enter the data:";
								cout<<"[USER] : "; cin >> pos;
								cout << "\nComiler : Enter the data :";
								cout<<"[USER] : "; cin >> data;
								Insert_At_Pos(head, data, pos);
								break;
							}

							case 4:
							{
								cout << "\t\t\t\t\t\t";
								Display_DClist(head);
							}
							case 5:
								break;
							default:
								cout << "\n[COMPILER] : Enter the Valid choice\n";
							}
							if (choice2 == 5)
							{
								break;
							}
						} // End of while loop of the insertion operation
						break;

					// Deletion Operatio in the singly linked list
					case '2':
						while (true)
						{
							Submenu3();
							int choice2;
							cin >> choice2;

							switch (choice2)
							{
							case 1:
							{
								Del_At_Start(head);
								cout<<"\n[COMPILER] : First Node of linked list is [DELETED]\n";
								break;
							}
							case 2:
							{
								Del_At_End(head);
								cout<<"\n[COMPILER] : Last Node of linked list is [DELETED]\n";
								break;
							}
							case 3:
							{
								int pos;
								cout << "[COMPILER] : Enter the position where you want to Delete the data:\n";
								cout<<"\n [USER]:";cin>>pos;
								Del_at_position(head,pos);
								break;
							}

							case 4:
							{
								cout << "\t\t\t\t\t\t";
								Display_DClist(head);
							}
							case 5:
								break;
							default:
								cout << "\n[COMPILER] : Enter the Valid choice\n";
							}
							if (choice2 == 5)
							{
								break;
							}
						} // End of the while loop of deletion process
						break;
					case '3':
						cout << "\n\t\t\t\t\t\t**Searching of the element**\n";
						int node;
						cout<<"\n[COMILER] : Enter the Node you want to search in the linked list\n";
						cout<<"[user] : ";cin>>node;
						Search_DS(head,node);
						break;
					case '4':
						cout << "\n\t\t\t\t\t\t**Sorting of the Linkedlist**\n";
						Sort_DoublyCircularList(head);
						cout<<"\n[COMPILER] : after sorting the linked list\n";
						Display_DClist(head);
						break;
					case '5':
						break;

					default:
						cout << "\n[COMPILER] : Enter the valid option";
					}

					if (opt == '5')
					{
						break;
					}

				} // End of while loop of main operations of the singly linked list
			}
			break;
		case '5':
			exit(0);
		default:
			cout << "\n[COMPILER] : Enter the Valid Option\n";
		}

		if (choice == '5')
		{
			break;
		}
	}//End of while loop of main menu

	// Reset the console color
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	return 0;
}
