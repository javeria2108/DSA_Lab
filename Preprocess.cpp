#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
class treeNode
{
public:
    treeNode * left;
    treeNode * right;
    string  data;
    treeNode* parent;
};
class BST
{
    
public:
    
    treeNode * root;
    
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
    treeNode* search(string s)
    {
        treeNode* t=root;
        while (t!=NULL){
			if(t->data.compare(s)==0){
			cout<<"found "<<s<<endl;
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
        void InorderTraverse(treeNode *n )
    {
        if (n!=NULL)
        {
            InorderTraverse(n->left);
            cout<<n->data<<" ";
            InorderTraverse(n->right);
        }
      
    }
    
};

class pp{
	public:
			string insertSpell(string s){
				int size=1;
				string arr[26]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
				string *matchingwords=new string[size];
				for (int i=0;i<=sizeof(arr);i++){
					s.append(arr[i]);
					for (int j=s.length();j>0;j--){
						char a=s[j];
						s[j]=s[j-1];
						s[j-1]=a;
						if (!dict.search(s).empty()){
							matchingwords[size-1]=s;
							size++;
						}
					}
					if(size==1){
						insertSpell(s);
					}
					
				}
			}

	
};
			
int main(){
pp p; 
	string s="binging";

	
}			
