#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class HT
{
private:
    int length;   // will increase with increase in inserted element
    int HTableSize;
    string *key_arr; // Will hold Names in an array of size 10
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
    int hFQuad2(string key, int i)
    {    int k=hFQuad1(key);
    int h2=1+(k%(i-1));
        // complete
        return h2;
    }

public:
    HT(int Size=86000) // bcz the words in wordlist are 85760 something
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
    int getInserts(){
        return length;
    }
    int getFailures(){
        return numFailures;
    }
    int getProbes(){
        return totalProbes;
    }
    
    
  
    
    int qExists(string key)
    {
    		int size=6000;
    	int x=hFQuad1(key)%size;
    	int i=1;
    	if (key_arr[x].compare(key)==0){
    		cout<<"found "<<key<<" without collisions"<<endl;
    		return true;
		}
		else{
			while(i<size && status_arr[x]==1){
				x=(hFQuad1(key)+(i*i))%size;
				if(key_arr[x].compare(key)==0){
					return true;
					cout<<"found "<<key<<" after "<<i<<" collisions "<<endl;
				}	
				if(i>(size/2)){
					x=(hFQuad1(key)+(3*hFQuad2(key,i))+(i*i))%size;
				    if(key_arr[x].compare(key)==0){
					return true;
					cout<<"found "<<key<<" after "<<i<<" collisions "<<endl;
				}
			}
			  }  cout<<"Did not find "<<key<<endl;
				return false;
		}
         // using quadratic probing for item searching returns -1 if not found and number of probes incase of found successfully.
        return -1;
        
    }

    int qAdd(string key) {
        // Insert k in the hash table.
        // Use open addressing with quadratic probing and hash(k) 
        int size=6000;
        int x=hFQuad1(key)%size;
        int inserted=0;
        if (status_arr[x]==0){
        	key_arr[x]=key;
        	status_arr[x]=1;
        	inserted=1;
        
		}
		else {
			int coll=1;
			while(coll<size){
				x=(hFQuad1(key)+(coll*coll))%size;
				if (status_arr[x]==0){
					key_arr[x]==key;
					updateProbes(coll-1);
						status_arr[x]=1;
                     	inserted=1;
                     	
					return coll;
				}
				if(coll>(size/2)){
					x=(hFQuad1(key)+(3*hFQuad2(key,coll))+(coll*coll))%size;
					if (status_arr[x]==0){
					key_arr[x]==key;
					updateProbes(coll-1);
						status_arr[x]=1;
                     	inserted=1; 
						
					return coll-1;
				}
				}
				
				coll++;
				
			}
		}
      if(inserted==0)	{
        // so if it gets here, it didn't find an EMPTY slot
        numFailures += 1;
      //  cout << "Warning: qinsert(" << key << ") found no EMPTY slot, so no insert was done." << endl;
        return -1;}
        if (inserted==1){
        	cout<<key<< " inserted"<<endl;
		}
			
		}
        // Tips:
        // - Look at the lecture slides if you don't remember how to implement these.
        // - You need to prevent against infinite loops. You should limit the number
        // of times you probe and print an error message upon exceeding this limit.
        // - You're welcome to add new declarations add to the constructor,
        // - You're also welcome to modify the main() method to automate your testing.
        // In fact, you should!
        
        // ************* ADD YOUR CODE HERE *******************
        int coll=0; // track collisions mentioned in textbook as i increases on every collision
        //Your method should return with no of probes, after it stores the value in an EMPTY slot
        // and calls updateProbes

       

       
    
 

    
};


int main()
{
        
            
            // declare hashtable
            HT htQ(6000);   //adjust size acording to load factor
            // read data from file
            
            ofstream fout;
            ifstream fin;
            
            fin.open("file.txt");  // can change of file 
            fout.open("status.txt",ios::app);
            
            // Execute a loop If file successfully opened
            if(fin){
                while (!fin.eof()) {
                    /// read wordlist
                    // insert each word in hashtable
                    // report the number of collisions for each word by writting it in another file (so you need two files one in reading mode i.e wordlist and other in write mode i.e status file, telling the collision per word containing <word, probe count> pairs)
                    

                    string word;
                    fin>>word;
                    int col=htQ.qAdd(word);

                    fout<<word<<" "<<col<<endl;
                   
                }
                
                fin.close();
                fout.close();
                
            }
            // report total stats of the process
             //  htQ.print();
              
              htQ.printStats();


// checking search 
string word;
cout<<"Enter the word to find";
cin>>word;
cout<<htQ.qExists(word);

            // ask the user to find any particular word and report number of collisions to find that number is it the same as number of probes occurred at the time of insertion (you can check from the status file)
            
      

    
    
    
}
