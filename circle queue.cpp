#include <iostream>
using namespace std;

class CirQueue{
	//int size=5;
	int A[5];
	int front;
	int rear;
public:
	CirQueue(){
	
	
	
	
	front=-1;
	rear=-1;
	//cout<<"constructor";
	
	}

	
	bool isempty(){
		if(front==-1 && rear==-1){
		
		return true;}
		else
		return false;
		
	}
	void enqueue(int value){
		if((front==-1 && rear==4)||(front==rear+1)){
			cout<<"Queue is full \n";
		}
		else
		{
			rear=(rear+1)%5;
			A[rear]=value;
			cout<<value<<" is added \n";
	
		}
	
	}
	void dequeue(){
		if(isempty()){
			cout<<"Queue is empty\n";
		}
		else{
			if(front==rear){
				front=rear=-1;
			}
				else{
			front=(front+1)%5;
		}
		
		}
	
	}
	void showfront(){
		if(isempty()){
			cout<<"Queue is empty\n";
		}
		else{
			cout<<"ELement at front is: "<<A[front];
		}
	}
	void display(){
		if(isempty()){
			cout<<"Queue is empty\n";
			
		}
		else {
			int i;
			if(front<rear){
				for(i=(front+1)%5;i<=rear;i++){
					cout<<A[i]<<" ";
					
				}
			}
			else{
				i=front;
				while(i<5){
					cout<<A[i]<<" ";
					i++;
				}
				i=0;
				while(i<=rear){
					cout<<A[i]<<" ";
					i++;
				}
			
				
			}
		}
		
	}
	
};
int main()
    { 
	CirQueue q;
	q.dequeue();
	q.enqueue(6);
	q.enqueue(8);
	q.enqueue(7);
	
	

    q.enqueue(5);
    q.display();
    q.enqueue(8);
    q.enqueue(4);
    q.dequeue();
    q.display();
//    q.enqueue(10);
//    q.display();
//    q.dequeue();

    




 return 0;}

