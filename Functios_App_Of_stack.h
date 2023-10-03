#include<iostream>
#include<stack>
using namespace std;

const int max_size = 50;


//Stack class for the basic functions of stack
class MyStack {

private:
    char data[max_size];


public:
	int top;
	
    MyStack() : top(-1) {
    }

    void push(char c) {
        if (top == max_size - 1) {
            cout << "Stack is full\n";
            return;
        }
        data[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Your Infix is not valid\n";
            return '\0';
        }
       return data[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    char peek() {
        if (top == -1) {
            cout << "Your Infix is not valid" << endl;
            return '\0';
        }
        return data[top];
    }
};

//Function to check the expression validity 

void check_exp(string s) {
	
    MyStack s1;		//creating the object of the class MyStack to access the functions 

    for (int i = 0; i < s.length(); i++) 
	{
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') 
		{
            s1.push(c);
        } 
		else if (c == ')' || c == '}' || c == ']') 
			{
	            if (s1.isEmpty()) 
				{
	                cout << "[ Not Valid ]\n";
	                return;
	            }
	
	            char top = s1.peek();
	            if ((c == ')' && top == '(') ||
	                (c == '}' && top == '{') ||
	                (c == ']' && top == '[')) {
	                s1.pop();
	            } 
	            
				else {
	                cout << "[ Not Valid ]\n";
	                return;
	            }
        }
    }

    if (s1.isEmpty()) {
        cout << "[ Valid Expression ]\n";
    } else {
        cout << "[ Not Valid ]\n";
    }
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}


string infix_to_postfix(string s)
{
	MyStack s2;
	
	string result;		// it will store the postfix expression 
	
	for(int i=0; i<s.length();i++)
	{
		char c=s[i];
		
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            // If operand found
            result += c;
        }
        
    	else if(c=='(' || c=='{' || c=='[')
    	{
    		s2.push(c);
		}
		else if(c==')' || c=='}' || c==']')
		{
			while (!s2.isEmpty() && s2.peek() != '(' && s2.peek() != '{' && s2.peek() != '[')
			 {
                result += s2.pop();
            }
            s2.pop(); 
		}
		//if number or oprand is found
		else
		{
            while (!s2.isEmpty() && prec(c) <= prec(s2.peek())) {
                result += s2.pop();
            }
            s2.push(c);
        }
	}
	
	
	while (!s2.isEmpty()) 
	{
        result += s2.pop();
    }
    
   return result;
}

//Evaluation of the expression and applly all the operations on the expression

int Evaluate(string exp)
{
    // Create a stack of capacity equal to expression size
    stack<int> st;
 
    // Scan all characters one by one
    for (int i = 0; i < exp.size(); ++i) 
	{
         
        // If the scanned character is an operand
        // (number here), push it to the stack.
        if (isdigit(exp[i]))
            st.push(exp[i] - '0');
 
        // If the scanned character is an operator,
        // pop two elements from stack apply the operator
        else 
		{
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            
            switch (exp[i]) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            case '%':
            	st.push(val2%val1);
            	break;
            }
        }
    }
    return st.top();
}

// Functions of the quick sort

int Partition(int arr[],int low,int high)
{
	int Pivot=arr[high];
	int i=low-1;
	
	for(int j=low;j<=high-1;j++ )
	{
		if(arr[j]<Pivot)
		{
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	i++;
	int temp=arr[i];
	arr[i]=Pivot;
	arr[high]=temp;
	return i;
}
void QuickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pivot=Partition(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}