#include<iostream>
#include<string>
#include"Functios_App_Of_stack.h"
using namespace std;

int main() {
	
    string exp; //it stores the infix expression
    string expp;// it stores the postfix

    while (true) {
        cout << "\n\t\t\tChoose the correct option\n";
        cout<<"\t\t____________________________________\n";
        cout <<	"\n1.Enter the Expression\n";
        cout << "2.Check Expression\n";
        cout << "3.Convert it into postfix\n";
        cout << "4.Evaluation of Expression\n";
        cout << "5.Quick Sort\n";
        cout << "6.Exit\n";

        int choice;
        cin >> choice;
        switch (choice) {
        	case 1:
        		{
        			cout << "Enter an expression: ";
    				cin >> exp;
    				cout<<"\n Your Expression in [infix] : ";
    				cout<<exp;
    				cout<<endl;
				}
				break;
            case 2:
                check_exp(exp);
                break;
            case 3:
            	{
            	expp=infix_to_postfix(exp);
            	cout<<expp;
				}
                break;
            case 4:
            	{
            	int result=Evaluate(expp);
            	cout<<"result="<<result;
				}
                break;
            case 5:
            	{
            		cout<<"\n\t\t\t***Quick Sort****\n";
            		int n;
					cout<<"How many elements you want to eneter in the array: ";
					cin>>n;
					int arr[n];
					cout<<"Enter the "<<n<<" numbers in the array\n";
					
					for(int i=0;i<n;i++)
					{
						cin>>arr[i];
					}
					
					cout<<"Your Erray is : ";
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<",";
					}
					cout<<endl;
					QuickSort(arr,0,n-1);
					
					cout<<"Your array after the sorting :";
					for(int i=0;i<n;i++)
					{
						cout<<arr[i]<<",";
					}
				}
				
                break;
            case 6:
                return 0;
            default:
                cout << "Enter the correct option\n";
        }
    }
    return 0;
}
        
