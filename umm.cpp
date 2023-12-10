#include <iostream>
#include <string>
#include <fstream>


using namespace std;
class treeNode
{
public:
    treeNode * left;
    treeNode * right;
    string  data;
    treeNode* parent;
    string status="unused";
};
class BST
{
    
public:
    
    treeNode * root;
    string arr[16347];
    BST()
    {
        root=NULL;
    }
     void insert( string m)
    {
        treeNode *z=new treeNode();
        z->data=m;
        z->left=NULL;
        z->right=NULL;
        
        treeNode *y=NULL;
        treeNode *x=root;
        
        while(x!=NULL)
        {
            
            y=x;
            if(x->data.compare(z->data)>0)
                x=x->left;
            else
                x=x->right;
            
        }
        
        z->parent=y;
        if(root==NULL)
            root=z;
        else if(y->data.compare(z->data)<0)
            y->right=z;
        else
            y->left=z;
    }
    string search(string s)
    {
        treeNode* t=root;
        int i=0;
        while (t!=NULL){
			if(t->data.compare(s)==0){
				i=1;
			cout<<"found "<<s<<endl;
			
		}
			if (t->data.compare(s)>0){
				t=t->left;
			}
			else{
				t=t->right;
			}
		}
		if(i==0){
			return "sfr";
		}
		else{
			return s;
		}
		
      }
       treeNode* searcht(string s)
    {
        treeNode* t=root;
        while (t!=NULL){
			if(t->data.compare(s)==0){
			//cout<<"found "<<s<<endl;
			return t;
		}
			if (t->data.compare(s)>0){
				t=t->left;
			}
			else{
				t=t->right;
			}
		}
		return t;
      }   
        string TreeMin(treeNode* x=NULL)
    {
        if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        if(x->left !=NULL)
            x=x->left;
        return x->data;
    }
    
    ////////// Max Tree

    string  TreeMax(treeNode* x=NULL)
    {  
    	 if (x==NULL)         //  to make function usable for both kind of function calls use in this code
            x=root;
        if(x->right !=NULL)
            x=x->right;
        return x->data;
 
        
    }
	  treeNode* Predecessor(string x)
    {
        treeNode * c=searcht(x);
        treeNode* p =c->parent;
        if(c->left!=NULL)
        {
            string val=TreeMax(c->left);
            return searcht(val);
            // TreeMin will return the minimum value not node containing that value, but this function has to return the node. How to handle it without changing TreeMin
            
            
        }
        else
        {
           while (p->data.compare(c->data)>0 && p!=NULL){
           	p=p->parent;
		   }
		   return p;
       }
        
     
    }
    
    
    ////////// Successor of x
   
    treeNode* Successor(string x)
    {
    	treeNode* c= searcht(x);
    	treeNode* p=c->parent;
    	if (c->right!=NULL){
    		string val=TreeMin(c->right);
    		return searcht(val);
		}
		else {
			while(p->data.compare(c->data)<0 && p!=NULL){
				p=p->parent;
			}
			return p;
		}
        
    }
      
    
        string* InorderTraverse(treeNode *n )
        
    {
    
    	int index=0;
        static string arr[16347];
        if (n!=NULL)
        {
            InorderTraverse(n->left);
           // cout<<n->data<<" ";
             arr[index]=n->data;
            index++;
            InorderTraverse(n->right);
           
        }
     return arr;
    }
    
};

class SpellChecker{
		BST dict;
		public:
			void Dictionary(){
				 ifstream read;
   				 read.open("Dict.txt");
   				 if(read){
    				while(!read.eof()){
    				string word;
    				read>>word;
    				dict.insert(word);
					}
				read.close();
				}
		//	cout<<dict.search("eat");
			//	dict.InorderTraverse(dict.root);
			}
			void writeInFile(string s){
				ofstream fout;
				fout.open("CorrectFile.txt",ios::app);
				fout<<s<<" "<<endl;
				fout.close();
			}
			void checkSpell(string s){
				
				if (!dict.search(s).empty()){
				
				
					writeInFile(s);
				}
				else{
					string basew=Preprocessing(s);
					if(!basew.empty()){
						writeInFile(s);
					}
					else{
						cout<<"did not find "<<s;
						SpellCorrector(s);
					}
					
				}
			}
			string Preprocessing(string n){
				int last=n.length()-1;
				string s=n;
				if (s.at(last)=='g'&& s.at(last-1)=='n'&& s.at(last-2)=='i'){
					cout<<"ing";
				    s.erase(last-2,last);
				    cout<<s;
					if(!dict.search(s).empty()){ 
					cout<<"going well";
						return s;
					}
					else{
						s.append("e");
				     	return dict.search(s);
				}}
					else if(s.at(last)=='s'&& s.at(last-1)=='e'&& s.at(last-2)=='i'){
					s.erase(last-2,last);
					s.append("y");
				    if(!dict.search(s).empty()){
				    	cout<<"ies";
						return n;
					}
				}
				else if ((s.at(last)=='s'&& s.at(last-1)=='e') || (s.at(last)=='y'&& s.at(last-1)=='l') || (s.at(last)=='d'&& s.at(last-1)=='e') ){
					s.erase(last-1,last);
					if(!dict.search(s).empty()){
						return n;
					}
					else{
				     n.erase(last);
				     return dict.search(n);
					}
				}
					else if(s.at(last)=='s'){
					s.erase(last);
					if(!dict.search(s).empty()){
						return n;
					}
				}
				return dict.search(s);
			}
			void SpellCorrector(string s1){
				int words=1;
				string matchingWords[10];
				int i=0;
				int distance=1;
			   
			    		similar(s1,dict,distance,matchingWords[i]);
			    	
			    	
				string correct;
				cin>>correct;
			}
			int min(int a,int b,int c){
				if(a<=b && b<=c){
					return a;
				}
				else if(b<=a && a<=c){
					return b;
				}
				else return c;
			}
			int distance(string s1,string s2){
				int x=s1.length();
				int y=s2.length();
				int ed[x+1][y+1]; //2D array containing lengths of both strings
				for (int i=0;i<=x;i++){
					for (int j=0;j<=y;j++){
						if(i==0){
							ed[i][j]=j; //operations to convert an empty string to s2 uptil index j
						}
						else if(j==0){
							ed[i][j]=i; //operations to convert empty s2 to s1 uptil index i
						}
						else if(s1[i-1]==s2[j-1]){
						//same characters
						ed[i][j]=ed[i-1][j-1];
				    	}
				    	else{
				    		ed[i][j]=min(ed[i-1][j-1],ed[i][j-1],ed[i-1][j])+1;
						}
			     	}
				}
				return ed[x][y];
				
			
			
			
			
			}
//				string original=s;
//				int size=1;
//				string arr[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
//				string *matchingwords=new string[size];
//				for (int i=0;i<26;i++){
//		//	cout<<arr[i]<<endl;
//		         	string m=arr[i];
//					s=s+m;
//					if (!dict.search(s).empty()){
//							matchingwords[size-1]=s;
//							size++;
//						}
//					cout<<"s after appending "<<s<<endl;
//					for (int j=s.length()-1;j>0;j--){
//			
//			//	cout<<s[j];
//						char a=s[j];
//						s[j]=s[j-1];
//						s[j-1]=a;
//						cout<<"s after replacing "<<s<<endl;
//						string p=s;
//						cout<<"after search: ";
//						cout<<dict.search(p)<<endl;
//						if (dict.search(p)!=""){
//						//	cout<<"im here in array"<<endl;
//							matchingwords[0]=s;
//						//	cout<<"array0"<<matchingwords[0];
//							size++;
//						}
//					}
//					s=original;
//					
//				}
////					if(size<5){
////						insertSpell(s);
////					}
//				for (int n=0;n<sizeof(matchingwords);n++){
//					cout<<matchingwords[n];
//				}
//			}
 void similar(string s,BST bst,int dis, string st){
 int words=0;
 treeNode* t;
       if (st.empty()){
    	t=bst.root;
	}
	else
      {t =bst.searcht(st);
	   } 
        int i=0;
        cout<<"did you mean: "<<endl;
        while (words<10){
			if(distance(s,t->data)<=dis ){
				if(t->status=="unused"){
					t->status="used";
				 cout<< t->data;
				 words++;
				}
				else if(bst.Predecessor(t->data)->status=="unused"){
					bst.Predecessor(t->data)->status="used";
					string s1=bst.Predecessor(t->data)->data;
				 cout<< t->data;
				 words++;
				}
				else if(bst.Successor(t->data)->status=="unused"){
					bst.Successor(t->data)->status="used";
					string s2=bst.Successor(t->data)->data;
				 cout<< t->data;
				 words++;
				}
			     
			
		}
			if (t->data.compare(s)>0){
				t=t->left;
			}
			else{
				t=t->right;
			}
		}

		}
		


	
};
int main(){

   
	SpellChecker sc;
	sc.Dictionary();
   cout<< sc.distance("halew","hello");
   sc.SpellCorrector("hatr");


//	ifstream fin;
//
//	fin.open("input.txt");
//	 if(fin){
//                while (!fin.eof()) {
//                    string word;
//                    fin>>word;
//                    sc.checkSpell(word);   
//                }
//                fin.close();
//            }
}
