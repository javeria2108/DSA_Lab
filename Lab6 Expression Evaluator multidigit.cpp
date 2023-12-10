#include <iostream>
using namespace std;
#include <stack>
#include <string>
#include <sstream>
class ExpressionEvaluator{
	stack<char> st;
	public:
	string InfixToPostfix(string s){
		string postfix;
		for(int i=0;i<s.length();i++){
			
			if (s[i]=='('){
				st.push(s[i]);
			}
			else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'){
				
		
				if (!st.empty()){
						if(CheckPrecedence(s[i],st.top())){
						st.push(s[i]);
					}
					else{
						postfix+=st.top();
						st.pop();
						st.push(s[i]);
					}
				}
				else{
						st.push(s[i]);
				}
			
			}
			else if((s[i]>='0'&&s[i]<='9' )){
				if (s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='/'||s[i+1]=='*' || s[i+1]=='('||s[i+1]==')'){
				
				postfix+=s[i];
				postfix+=" ";}
				else{
					postfix+=s[i];
					postfix+=s[i+1];
				//	postfix+=" ";
					i++;
				}
			}
			else if(s[i]==')'){
				while(!st.empty()&&st.top()!='('){
					postfix+=st.top();
					postfix+=" ";	
					st.pop();
			}
			}
			
		}
		while(!st.empty()){
			if(st.top()!='('){
			    postfix+=st.top();
				postfix+=" ";
			}
			st.pop();
		}
		cout<<postfix<<endl;
		return postfix;
	}
	bool CheckPrecedence(char a,char b)//returns true if current op is of greater precendence
	{
		char op[4]={'-','+','*','/'};
		int prec_a=-1;
		int prec_b=-1;
		for (int i=0;i<sizeof(op);i++){
			if (a==op[i]){
				prec_a=i;
			}
			else if(b==op[i]){
				prec_b=i;
			}
		}
		return (prec_a>prec_b);
	}
	int evaluate(string s){
		stack<int> ev;
		int result;
		int a=0;
		int b=0;
		for(int i=0;i<s.length();i++){
			cout<<"im here1";
			if(s[i]>='0' && s[i]<='9' ){
				if(s[i+1]>='0' && s[i+1]<='9' &&s[i+2==" "]){
					stringstream stream;
   			        stream << ev.top();
   					string op;
                    stream >> op;
                    op+=s[i+1];
                    stringstream ss;
   					ss << op;
    				ss>>a;
    				cout<<a;
    				ev.pop();
    				i+=2;
    					if(s[i]>='0' && s[i]<='9' && (s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='/'||s[i+1]=='*' || s[i+1]=='('||s[i+1]==')'||s[i+1]==' ')){
    						 b=s[i]-'0';
    						 cout<<b;
    						
						}
						else{
								stringstream stream;
   			        			stream << ev.top();
   					  			string op2;
                   				 stream >> op2;
                   				 op2+=s[i+1];
                    		 stringstream ss;
   								 ss << op2;
    							ss>>b;
    							i++;	}}
    						
				else{
				
				ev.push(s[i]-'0');}}
			
			
		
			else{
				cout<<" I'm here2 ";
				if(a==0){
				
				a=ev.top();
				cout<<a;
				ev.pop();}
				if (b==0){
				
				b=ev.top();
				cout<<b;
				ev.pop();}
				if (s[i]=='+'){
					cout<<a;
					cout<<b;
					result=b+a;
				}
				else if(s[i]=='-'){
					result=b-a;
				}
				else if(s[i]=='/'){
					result=b/a;
				}
				else if(s[i]=='*'){
					result=b*a;
				}
				ev.push(result);
			}
			
			
		}
		return result;}
	
};
int main(){
	ExpressionEvaluator e;
	string s;
	cout<<"enter expression:";
	cin>>s;
    cout<<e.evaluate(e.InfixToPostfix("2+(5/3)*2"));
   
    
}     
