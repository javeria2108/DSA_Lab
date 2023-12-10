#include <iostream>
#define size 5

using namespace std;
class Queue{
	int front;
	int rear;
//	int size;
	int q[size];
public:
	Queue(){
		front=-1;
		rear=-1;
		
	}
	void enQueue(int a){
		if (!isFull()){
		rear=(rear+1)%size;
		q[rear]=a;
		cout<<a<<" is inserted in the queue\n";}
		else{
			cout<<"queue is full\n";
			
		}
	}
	int deQueue(){
		if (!isEmpty()){
			front=(front+1)%size;
			cout<<q[front]<<" is removed from queue";
			return q[front];
		}
		else{
			cout<<"queue is empty\n";
		}
	}
	
	bool isFull(){
		return ((front==-1&& rear==size-1)||(front==rear+1));
	}
	bool isEmpty(){
		return(front==rear);
	}
	void Display(){
		
	if (front<rear){
		cout<< "current queue is:\n";
		for(int i=(front+1)%size;i<size;i++){
			cout<<q[i];
			cout<<endl;
		}
	}
	else {
		cout<< "current queue is:\n";
		for (int i=rear;i<size;i++){
			cout<<q[i];
			cout<<endl;
		}
	}
		
		cout<< "current value of front is: "<<front<<endl;
		cout<< "current value of rear is: "<<rear<<endl;
		
	}
};
int main(){
	  Queue q;
  q.deQueue();
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);

  q.enQueue(6); 
  q.Display();
  q.deQueue();
  q.Display();
  q.enQueue(9);
  q.Display();
}
