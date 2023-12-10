#include<iostream>
using namespace std;
class Array
{   int *y;
    int top=0;
    int size;
   int *array;
    

	public:
		
		
		Array(int s){
			size=s;
		array=new int[size];
			y=array;
		}
//		int* GetPointer(){
//			return y;
//		}		
			void insert (int a,int i){
			top++;
			if(((((top+1)/size))<0.7) && i<=size-1){
				
			y[i]=a;
			 //resetting pointer
			
			cout<<a<<" inserted in array at index "<<i<<endl;
		
			
	}
		    else {
		    	cout<<"Array is filled upto 70%"<<endl;
		    	cout<<"Array is resized "<<endl;
			resize();
			}
			
		}
		void resize(){
			
			int *arr =new int[size*2];
				y=arr;
				for (int i=0;i<=size-1;i++){
					arr[i]=array[i];
				}
			
			delete [] array;
			size=size*2;
		}
		void remove(int a){
			for (int i=0;i<size;i++){
				if (y[i]==a){
					y[i]=0;
					top--;
					cout<<a<<" is removed from array "<<endl;
				}
			}
		}
		void display(){
			 
			for (int i=0;i<=size-1;i++){      
	        cout<<y[i]<<" ";
        }
        cout<<endl;
       

		}		
	
};
int main(){
	
int s;
	cout<<"Enter size of Array";
		cin>>s;
		Array A(s);
	
A.insert(1,0);
A.insert(5,4);
A.insert(2,3);
A.insert(6,2);
A.insert(3,1);
A.display();	
A.remove(5);
A.remove(6);
A.display();			
	
	
}
