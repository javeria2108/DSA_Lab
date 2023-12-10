#include <iostream>
using namespace std;
class dequeue{
	int A[5];
	int front;
	int rear;
	public:
		dequeue(){
			front=-1;
         	rear=5;
		}
		void enqueueFront(int d){
			if(!isFull()){
			
			A[++front]=d;}
			else{
				cout<<"dequeue is full"<<endl;
			}
		}
		void enqueueRear(int d){
			if (!isFull()){
			
			A[--rear]=d;}
			else{
				cout<<"dequeue is full"<<endl;
			}
		}
		int dequeueFront(){
			int d=A[0];
			
			for (int i=0;i<=front;i++){
				A[i-1]=A[i];
			}
			front--;
			return d;
		
		}
		int dequeueRear(){
			int d=A[4];
				for (int i=3;i>=rear;i--){
				A[i+1]=A[i];
			}
			rear++;
			return d;
		}
		bool isFull(){
			return (rear-front)==1;
		}
		bool isEmpty(){
			return (front==-1 && rear==5);
		}
	
};
int main(){
	dequeue dq;
	dq.enqueueFront(5);
	dq.enqueueFront(6);
	dq.enqueueFront(9);
	dq.enqueueRear(7);
	dq.enqueueRear(8);
	dq.enqueueRear(4);
	cout<<dq.dequeueFront()<<endl;
	cout<<dq.dequeueFront()<<endl;
	cout<<dq.dequeueRear()<<endl;
	cout<<dq.dequeueRear()<<endl;
}
