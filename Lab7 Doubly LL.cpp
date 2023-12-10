#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node* prev;
		node(int d){
			data=d;
			next=NULL;
			prev=NULL;
		}
		
};
class doublyLL{
		node *start;
		node*last;
		public:
			doublyLL(){
				start=NULL;
				last=NULL;
			}
			void insert(int b){
					node*n=new node(b);
				if (start==NULL){
					start=last=n;
					n->next=n;
					n->prev=n;
				}
				else{
				n->next=start;
				start->prev=n;
				start=n;
				start->prev=last;
				last->next=start;
			}
			}
			void del(){

                if (start!=NULL){
                	node*t=start;
                	start=start->next;
                	last->next=start;
                	start->prev=last;
                	delete t;
				}

			
			}
			void deleteAt(int i){
				if(i==0){
					del();
				}
				else{
					int pos=0;
				node*t=start;
				node*tp=t->prev;
				while(pos!=i){
					tp=t;
					t=t->next;
					pos++;
				}
			     node*tn=t->next;
			     tp->next=tn;
			     tn->prev=tp;
			     delete t;
				}
				
			}
			void insertAt(int d,int i){
				if (i==0){
					insert(d);
				}
				else{
				int pos=0;
				node*n=new node(d);
				node*t=start;
				node*tp=t->prev;
				while(pos!=i){
					tp=t;
					t=t->next;
					pos++;
				}
		       	tp->next=n;
		       	n->prev=tp;
		       	n->next=t;
		       	t->prev=n;
			
				
				}
			
			}
			int search(int a){
				if (start==NULL){
					return -1;
				}
				else{
					int index=0;
					node* t=start;
					while(t->data!=a &&t->next!=start){
						t=t->next;
						index++;
					}
					return index;
				}
				return -1;
			}
			void print(){
				node* t=start;
				while(t->next!=start){
					cout<<t->data<<" -> ";
					t->prev=t;
					t=t->next;	
				}cout<<t->data;
			}
};
int main(){
	doublyLL dl;
	dl.insert(7);
	dl.insert(6);
	dl.insert(4);
	dl.insert(3);
	dl.insert(5);
	dl.print();
	cout<<endl;
	dl.del();
	dl.print();
	cout<<endl;
	dl.deleteAt(2);
	dl.print();
	cout<<endl;
	dl.insertAt(5,2);
	dl.print();
	cout<<endl;
	dl.insertAt(7,3);
	dl.print();
	cout<<endl;
	cout<<"index is "<<dl.search(4);
//	
	
	
}
