#include <iostream>
#include <cstring>
using namespace std;

class node{
	public:
		int data;
		node *next;
};
class LL{

	node *head;
	public:
		
		LL(){
			head=NULL;
		}
		insertH(int d){
			node *n=new node();
			n -> data=d;
		//	n -> next=NULL;
			n->next=head;
			head=n;
		}
		void deleteH(){
			if(head!=NULL){
			
			node *n=head;
			head=head->next;
			delete[] n;}
			else{
				cout<<"linked list is empty"<<endl;
			}
		}
		void insertT(int d){
			node *nptr=new node();
			nptr->data=d;
			nptr->next=NULL;
			node *end=head;
			if (head!=NULL){
				while (end->next!=NULL){
					end=end->next;
				}
	            end->next=nptr;

			}
			else{
				head=nptr;
			}
		}
		
		void deleteT(){
			node *pptr=NULL;
			node *tptr=head;
			while(tptr->next!=NULL){
			pptr=tptr;
			tptr=tptr->next;
			}
			pptr->next=NULL;
			delete tptr;
		
			
		}
		  void insertAfter(int y,int pos)
        {
        	int count=0;
        	node *nptr=new node();
        	nptr->data=y;
        	nptr->next=NULL;
        	node *tptr=head;
        	node *pptr=NULL;
        	if(head!=NULL){
			
        	while(count!=pos){
        		pptr=tptr;
        		tptr=tptr->next;
        		count++;
			}
			pptr->next=nptr;
			nptr->next=tptr;}
        }
		void deleted(int d){
			node *pptr=NULL;
			node *tptr=head;
			while(tptr!=NULL){
				if (tptr->data==d){
					if (tptr==head){
						head=head->next;
						tptr=head;
					}
					else {
						pptr->next=tptr->next;
						tptr=pptr->next;
					}
				}
				else{
					pptr=tptr;
					tptr=tptr->next;
				}
			}
		}
		int search(int y) {
			int count=0;
			node *end=head;
			if (head!=NULL){
				while(end->data!=y){
					if(end->next!=NULL){
					
					end=end->next;
					count++;}
					else{
						cout<<" not found in list "<<endl;
						return 0;
					}
					
				}
			}
		
     
        return count;
        }
		void print()
       {
        node * tptr=head;
        while(tptr!=NULL)
        {
            cout<<tptr->data<<" -> ";
            tptr=tptr->next;
           // break;
        }
        cout<<"NULL\n"    ;
        }
};
int main(){
	 LL ll;
    
    ll.insertT(1);
    cout<<endl;
    ll.print();
    
    ll.insertH(3);
    cout<<endl;
    ll.print();
    
    ll.insertH(5);
    cout<<endl;
    ll.print();
    ll.insertH(7);
    ll.insertH(6);
    cout<<endl;
    ll.print();
    ll.insertAfter(3,1);
    cout<<endl;
    ll.print();
    cout<<"index: ";
	cout<<ll.search(7);
    ll.deleteH();
    cout<<endl;
    ll.print();
      cout<<"index: ";
	cout<<ll.search(7);
    ll.deleteT();
  // ll.deleted(5);
    cout<<endl;
    ll.print();
    
    
}
