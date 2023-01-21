#include <bits/stdc++.h>
using namespace std;

int precedence(char ch){
	switch(ch){
		case '-':
		case '+':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return -1;
	}
}
bool isOperand(char ch){
	return (ch>='a' && ch<='z') || (ch>='A' && ch <='Z');
}

string infixToPostfix(string infix){
	int n=infix.size();
	stack<char> st;
	string postfix;
	for(int i=0;i<n;i++){
		if(isOperand(infix[i])){
			//step 2
			postfix.push_back(infix[i]);
		}
		else if(infix[i] == '('){
			//step 3
			st.push('(');
		}
		else if(infix[i] == ')'){
			//step 4
			while( st.top() != '(' ){
				postfix.push_back(st.top());
				st.pop();
			}
			st.pop();
			
		}
		else{
			//step 5
			while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(infix[i])){
				postfix.push_back(st.top());
				st.pop();
			}
			st.push(infix[i]);
		}
	}
	
	while(!st.empty()){
		postfix.push_back(st.top());
		st.pop();
	}
	return postfix;
}

int main() {
	// your code goes here
	precedence('+');
	isOperand('b');
	string infix="a*(b+c+d)";
	string postfix=infixToPostfix(infix);
	cout<<"Infix expression : "<<infix<<endl; 
	cout<<"Postfix expression : "<<postfix<<endl;
	return 0;
}