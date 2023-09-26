#include<iostream>
#include"Assignment4Functions.h"
using namespace std;
int main()
{
	while(true)
	{
	cout<<"__________________________________________\n";
	cout<<"\nChoose the correct options:\n";
	cout<<"1.For the Queue\n";
	cout<<"2.For the Stack\n";
	cout<<"3.Exit\n";
	int choice;
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			while(true)
			{
			cout<<"\n ------Queue-----\n";
			cout<<"Enter the choice:\n";
			cout<<"1.For the Queue using array\n";
			cout<<"2.For the Queue Using Linkedlist\n";
			cout<<"3.Back to the main Menu\n";
			int choice2;
			cin>>choice2;
			switch(choice2)
			{
				case 1:
					
					cout<<"\nQueue Using Array\n";
					Get_queue();
					Display();
					while(true)
					{
						cout<<"\t\t\t\t*****Select the option*****\n";
						cout<<"1.Enqueu the element in the Queue\n";
						cout<<"2.Deqeue the element from the Queue\n";
						cout<<"3.Back to the main menu\n";
						int ch;
						cin>>ch;
						switch(ch)
						{
							case 1:
								{
								int element;
								cout<<"Enter the new element: ";
								cin>>element;
							 	Enqueu(element);
								Display();
								}
								break;
							case 2:
								Dequeu();
								Display();
								break;
							case 3:
								break;
							default:
								cout<<"Enter the correct option\n";
						}//End of switch of queue using array
						if(ch==3)
						{
							break;
						}
					}//End of while loop of Queue using array
					break;
				case 2:
					{
						cout<<"\n*****Queue Using LinkedList****\n";
						Get_Que();
						Display_Que();
						while(true)
						{
							cout<<"******Choose the Option******\n";
							cout<<"1.For Enqueu the element\n";
							cout<<"2.For Dequeu the element\n";
							cout<<"3.For Exit\n";
							int ch2;
							cin>>ch2;
							switch(ch2)
							{
								case 1:
									{
									int NewElement;
									cout<<"Enter the new Element:";
									cin>>NewElement;
									ENQ(NewElement);
									Display_Que();
									}
									break;
								case 2:
									DeQue();
									Display_Que();
									break;
								case 3:
									break;
								default:
									cout<<"Enter the correct Option\n";
							}//End of switch
							if(ch2==3)
							{
								break;
							}
						}
					}
					break;
				case 3:
					break;
				default:
					cout<<"Enter the correct Choice\n";
			}
			if(choice2==3)
			{
				break;
			}
			}
			break;
		case 2:
			while(true)
			{
			cout<<"\n ------Stack-----\n";
			cout<<"Enter the choice:\n";
			cout<<"1.For the Stack using array\n";
			cout<<"2.For the Stack Using Linkedlist\n";
			cout<<"3.Back to the main Menu\n";
			int choice3;
			cin>>choice3;
			switch(choice3)
			{
				case 1:
					{
					cout<<"\nStack Using Array\n";
					Get_stack();
					Show();
					while(true)
						{
							cout<<"\n***choose the option***\n";
							cout<<"1.For Inserting New Element in Stack\n";
							cout<<"2.For Deleting the Element from Stack\n";
							cout<<"3.For Back to the main menu\n";
							int ch3;
							switch(ch3)
							{
								case 1:
									int n;
									cout<<"Enter the new element";
									cin>>n;
									push(n);
									Show();
									break;
								case 2:
									pop();
									Show();
									break;
								case 3:
									break;	
								default:
									cout<<"Enter the correct option\n";
							}
							if(ch3==3)
							{
								break;
								}	
						}
					}
					
					break;
				case 2:
					{
						cout<<"\n Stack By Using Linkedlist\n";
						Get_Stack();
						display();
						
						while(true)
							{
								cout<<"*****Choose the Option*****\n";
								cout<<"1.For the Inserting new element\n";
								cout<<"2.For the Deleting element\n";
								cout<<"3.For Back to the main Menu\n";
								
								int ch4;
								cin>>ch4;
								switch(ch4)
								{
									case 1:
										{
											int element;
											cout<<"Enter the new element:";
											cin>>element;
											Push(element);
											display();
										}
										break;
									case 2:
										Pop();
										display();
										break;
									case 3:
										break;
									default:
										cout<<"Enter the correct Option\n";
								}
								if(ch4==3)
								{
									break;
								}
							}//End of while
					}
					break;
				case 3:
					break;
				default:
					cout<<"Enter the correct Choice\n";
			}
			if(choice3==3)
			{
				break;
			}
			}
			break;
		case 3:
			break;
		default:
			cout<<"Enter the correct option\n";
	}
	if(choice==3)
		{
			break;
		}
	}
}
