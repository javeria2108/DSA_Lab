#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class HT{
	private:
    int length;   // will increase with increase in inserted element
    int HTableSize;
    string *key_arr;// Will hold Names in an array of size 10
    int *status_arr; // Will hold (0 for Empty, 1 for there is data, -1 for deleted)
    int totalProbes;           // will count total number of probes for all inserted elements
    int numFailures;           // will update if unable to find any empty slot
    void updateProbes(int probes)
    {
        // Add the number of probes, for one insert operation to the tally.
        totalProbes += probes;
        length += 1;
    }
    
    
 
    int hFQuad1(string key)
    {   int ascii_value=0;
        for (int i=0;i<key.length();i++){
        	ascii_value+=int(key[i]);
		}
        return ascii_value;
    }
    public:
    HT(int Size) // bcz the words in wordlist are 85760 something
    {
  
        key_arr = new string[Size];
        status_arr = new int[Size];
        HTableSize = Size;
        for (int i = 0; i < Size; i++)
            status_arr[i] = 0;
    }
    void printStats() {
        cout << "Average probes/insert = " <<
        probeRate() << " = " <<
        totalProbes << "/" << length;
        cout <<", size = "<< length;
        cout <<", failures = " << numFailures << endl;
    }
    
    float probeRate() {
        if ( length == 0 ) return 0;
        return (float)totalProbes / (float)length;
    }
    
    void print() {
        // Print the content of the hash table.
        
        for (int i=0; i<length; i++) {
            cout<<"["<<i<<"] ";
            cout << key_arr[i];
            cout << endl;
        }
    }
     int getSize() {
        return HTableSize;
    }
    
     int qAdd(string key) {
     //	cout<<"IM here"<<endl;
        // Insert k in the hash table.
        // Use open addressing with quadratic probing and hash(k) 
       // cout<<key<<endl;
        int size=90000;
        int coll=0;
        int x=hFQuad1(key)%size;
        if (key_arr[x].empty()){
        	key_arr[x]=key;
        //	cout<<"if"<<endl;
        	updateProbes(1);
        	return coll;
        	
		}
		else {
		//	cout<<"else"<<endl;
			while(coll<size){
				x=(hFQuad1(key)+coll)%size;
				if (key_arr[x].empty()){
					key_arr[x]=key;
					updateProbes(coll);
					return coll;
				}
				
				coll++;
				
			}
			
        // so if it gets here, it didn't find an EMPTY slot
        numFailures += 1;
        cout << "Warning: qinsert(" << key << ") found no EMPTY slot, so no insert was done." << endl;
        return -1;}
      
			
		}
		
		bool qExists(string key)
    {
    	int size=90000;
    	int x=hFQuad1(key)%size;
    	int i=0;
    	if (key_arr[x].compare(key)==0){
    		cout<<"found "<<key<<" without collisions"<<endl;
    		return true;
		}
		else{
			while(i<size && !key_arr[x].empty()){
				x=(hFQuad1(key)+i)%size;
				if(key_arr[x].compare(key)==0){
					return true;
					cout<<"found "<<key<<" after "<<i<<" collisions "<<endl;
				}	
			}
			    cout<<"Did not find "<<key<<endl;
				return false;
		}
         // using quadratic probing for item searching returns -1 if not found and number of probes incase of found successfully.
        return -1;
    }
};
int main(){
	 HT htQ(90000);
	 // htQ.printStats(); 
	    //htQ.print(); 
	    string word;

	 ifstream inputFile("file.txt");
	 string str;
	 while (getline(inputFile, str)){
     // cout << str << std::endl;}
      htQ.qAdd(str); }
      
      htQ.print();  
	  htQ.printStats(); 
             
	
	cout<<"Enter the word to find";
cin>>word;
cout<<htQ.qExists(word);
	
}
