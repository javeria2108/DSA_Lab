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
		int* GetPointer(){
			return y;
		}		
			void insert (int a,int i){
				top++;
			if((((top/size))<0.7) && i<=size-1){
				
			*(y+i)=a;
			*(y-i); //resetting pointer
			
			cout<<a<<" inserted in array at index "<<i<<endl;
			
	}
		    else {
		    	cout<<"Array is filled upto 70%"<<endl;
			resize();
			}
			
		}
		void resize(){
			size=size*2;
			int *arr =new int[size];
				y=arr;
				for (int i=0;i<=size-1;i++){
					arr[i]=array[i];
				}
			
			delete [] array;
		}
		void remove(int a){
			for (int i=0;i<size;i++){
				if (array[i]==a){
					array[i]=0;
					top--;
					cout<<a<<" is removed from array "<<endl;
				}
			}
		}
		void display(){
			 y=array;
			for (int i=0;i<=size-1;i++){      
	        cout<<*y++<<endl;
        }
       

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
