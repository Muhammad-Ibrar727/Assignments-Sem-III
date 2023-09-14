#include <iostream>
using namespace std;

// Define your own stack data structure
const int MAX_SIZE = 100;
class MyStack {
private:
    char data[MAX_SIZE];
    int top;
public:
    MyStack() : top(-1) {}

    void push(char c) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return data[top--];
    }

    char peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return data[top];
    } 	

    bool isEmpty() {
        return top == -1;
    }


};

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

void infixToPostfix(string s) {
    MyStack st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            // If operand found
            result += c;
        }
        
		//if found the '(' bracket then push
		else if (c == '(') 
		{
            st.push('(');
        }
        
		//if found the ')' then pop untill found the starting braces
		 else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop();
            }
            st.pop(); // Pop the '('
        } 
		
		//if we found the operator then pop operator untill get the small precide
		else {
            while (!st.isEmpty() && prec(c) <= prec(st.peek())) {
                result += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        result += st.pop();
    }
    cout << result << endl;
}

int main() {
//    string exp = "a+b*(c^d-e)^(f+g*h)";
    string exp = "a*(c-d*d-e)^(f/g*h)-v";
    infixToPostfix(exp);
    return 0;
}

