#include<iostream>
#include<stack>
//#include<>
using namespace std;
int prec(char c)
{
	if(c=='^')
	return 3;
	else if (c=='/' ||c=='*')
	return 2;
	else if(c=='+' || c=='-')
	return 1;
	else
	return -1;
}
void infixToPostfix(string s)
{

	stack<char> st;
	string result;
	
	for(int i=0;i<s.length();i++)
	{
		char c= s[i];
		
		
		if ((c>= 'a' && c<='z') || (c >='A' && c<='Z') || (c>= '0' && c<='9'))//if operand found
		{
		
		result +=c;
		}
		//if the scanned charcter is an '(' push it to the stack.
		else if(c=='(')
		{
			st.push('(');
		}
		
		//
		else if(c==')')
		{
			while(st.top()!='(')
			{
				result+=st.top();
				st.pop();
			}
			st.pop();
		}
		
//		if operator is found
		else
		{
			
			while(!st.empty() && prec(c)<= prec(st.top()))
			{
				result+=st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	
	//pop allll the remaing elemens from the stack
	while(!st.empty())
	{
		result+=st.top();
		st.pop();
	}
	cout<<result<<endl;
}
int main()
{
	string exp="a+b(c^d-e)^(f+g*h)";
	infixToPostfix(exp);
	return 0;
}
