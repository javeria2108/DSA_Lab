#include <iostream>
using namespace std;
class Queue{
	int top;
	int A[5];
	public:
		Queue(){
			top=-1;
		}
	void enqueue(int d){
		if(top<=sizeof(A)-1){
			top++;
			A[top]=d;
			cout<<"were here"<<endl;
		}
	}
	int dequeue(){
		
			int d=A[0];
			top--;
			for (int i=0;i<=top;i++){
				A[i-1]=A[i];
			}
			return d;
		
		}
	int gettop(){
		return top;
	}
	bool isFull(){
		return top==sizeof(A);
	}
	bool isEmpty(){
		return top==-1;
	}
	
};
class Stack{
	Queue q1;
	Queue q2;
	public:
	void push(int d){
		if (!q1.isFull()){
		
		q1.enqueue(d);
	}
	else{
		cout<<"stack is full"<<endl;
	}
	
}
	int pop(){
		if(!isEmpty()){
		
		for(int i=0;i<q1.gettop();i++){
			q2.enqueue(q1.dequeue());
		}
		int d= q1.dequeue();
		Queue q3;
		q3=q2;
		q2=q1;
		q1=q3;
		return d;
	}
	    else{
	    	cout<<"stack is empty"<<endl;
	    	return 0;
		}
	}
	bool isFull(){
		return q1.isFull();}
	bool isEmpty(){
		return q1.isEmpty();
	}	
};
int main(){
	Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack"<<endl;
    cout << s.pop() << " Popped from stack"<<endl;
    cout << s.pop() << " Popped from stack"<<endl;
    cout << s.pop() << " Popped from stack"<<endl;
}
