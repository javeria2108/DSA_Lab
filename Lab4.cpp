#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000
class BracketChecker{
	int top;
	string error_type="";
	int error_index;
    char a[MAX];
    int s;
    int x=0;
    public: 
    
	    BracketChecker(){
	    	top=-1;
		}
		char CheckType(){
			char type;
		//	cout<<a[top];
				if (a[top]=='('){type=')';	}
				else if(a[top]=='['){type=']';
				}
				else if (a[top]=='{'){type='}';
				}
				return type;
				
			
		}
		void CheckExpression(char arr[],int size){
			s=size;
		
			for (int i=0;i<=size-1;i++){
			
			    if (arr[i]=='('|| arr[i]=='{'|| arr[i]=='[' ) {
					push(arr[i]);
					
				}
				else if ((arr[i]==')'|| arr[i]==']'|| arr[i]=='}')&&arr[i]==CheckType()){
				
				//	cout<<"type "<<CheckType()<<endl;
				//	cout<<"array: "<<arr[i];
				
					
					pop();}
				else  {
			           	x=1;
						error_type="misplaced brackets";
						error_index=i;
					    break;
				}	
			}
			if(isEmpty()&& x==0){
						cout<<"Expression is balanced"<<endl;
					}
			else {
				
				if (error_type==""){
					error_type="missed brackets";
					error_index=s-1;
				}
						cout<<"Expression is unbalanced"<<endl;
						cout<<"Error at index "<<error_index<<" of expression."<<endl;
						cout<<"Error type: "<<error_type<<endl;
					
					}
			
		}
		bool push(char x){
				top++;
				a[top]=x;
			
		}
		bool isEmpty(){
			return (top==-1);
		}
		bool isFull(){
			return (top==s-1);
		}
		char pop(){
					
					top--;
			
		}
		
};
int main(){
	BracketChecker bcheck;
	cout<<"enter the expression: ";
	string expression; 
	cin>>expression;
	char arr[expression.length()+1];
	strcpy(arr,expression.c_str());
//	for (int i=0; i<expression.length();i++){
//		cout<<arr[i];
//	}
	int size=expression.length();
//	cout<<size;
    bcheck.CheckExpression(arr,size);  
	return 0;   
	
}
