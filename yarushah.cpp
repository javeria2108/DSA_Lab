#include<iostream>
#include <stack>
using namespace std;
	bool isValid(string s) {
		int n=s.size();
		stack<char> st;
		bool answer=true;
	
//	 bool push(int x)
//    {
//        if (top >= (MAX - 1)) {
//            cout << "Stack Full"<<endl;
//            return false;
//        }
//        else {
//            a[++top] = x;
//            cout << x << " pushed into stack"<<endl;
//            return true;
//        }
//    }
	
		for(int i=0; i<n; i++){
			if(s[i]=='{' || s[i]=='[' || s[i]=='('){
		
		
				st.push(s[i]);
			}
		else if(s[i]==')'){
			if(!st.empty() && st.top()=='('){
				st.pop();
		
		
			}
			else{
				answer= false;
				break;
			}
		}
		
		
			else if(s[i]==']'){
				
				
			if(!st.empty() && st.top()=='['){
				st.pop();
		
		
		
			}
			else{
				answer= false;
				break;
		
		
		
			}
		}
		
		
		
		
		
			else if(s[i]=='}'){
			if(!st.empty() && st.top()=='{'){
				st.pop();
			}
			else{
				answer= false;
				break;
			}
		}
	
	}
	    
//    bool isEmpty()
//    {
//        return (top < 0);
//    }
//    bool isFull()
//    {
//        return (top == MAX);
//    }
//};
	
			if(!st.empty()){
			return false;
		}
		
		
		
			return answer;
			
		}
	
		
		
	
int main(){
	 string s;
	 cout<<"Enter the expression"<<endl;
	 cin>>s;
	 
	
	

	if (isValid(s)){
		cout<<"The expression is valid"<<endl;
	}
	else {
		cout<<"The expression is invalid"<<endl;
	}
	
	return 0;
}
