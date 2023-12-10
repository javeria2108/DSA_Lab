//
//  main.cpp
//  BST
//
//  Created by Hina Khalid  on 17/06/2020.
//  Updated on 28/03/2022
//  Copyright © 2022 Hina Khalid . All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/////////////////BST

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
    
    ////////// Inorder Traversal
    
    void InorderTraverse(treeNode *n )
    {
        if (n!=NULL)
        {
            InorderTraverse(n->left);
            cout<<n->data<<" ";
            InorderTraverse(n->right);
        }
      
    }
    
    ////////// Postorder Traversal
    
    void PostorderTraverse(treeNode *n )
    {
        if(n!=NULL){
        	PostorderTraverse(n->left);
        	PostorderTraverse(n->right);
        	cout<<n->data<<" ";
        	
		}

        
        
        
        
        
    }
    
    ////////// Preorder Traversal
    
    void PreorderTraverse(treeNode *n)
    {
        
          if(n!=NULL){
          	cout<<n->data<<" ";
        	PreorderTraverse(n->left);
        	PreorderTraverse(n->right);
        	
        	
		}
        
        
        
    }
    
    ////////// Insert in Tree
    
    
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
    
    ////////// Min Tree
    
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
    
    /////////// Tree Search
   
    treeNode* searcht(string s)
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
    
    
   
    ////////// Predecessor of x
    
    
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
			return "";
		}
		else{
			return s;
		}
		
      }
    
    ////////// Delete from tree
    
   void deleted( string x)
    {
    	treeNode* d=searcht(x);
    	treeNode* p=d->parent;
    	if (d->data.compare(p->data)>0){
    		if(d->left==NULL && d->right==NULL)
    		  p->right=NULL;
    		else{
    			treeNode* rc=d->right;
    			treeNode* lc=d->left;
    			 p->right=NULL;
    			 
    		
			}  
		}
		else { 
		if(d->left==NULL && d->right==NULL)
		      p->left=NULL;	
		else{
			treeNode* lc=d->left;
			d=d->right;
			d->left=lc;
		}      
		}
        
        
    }
  
};

//int main()
//{
//    BST St;
//    St.insert("pat");
//    St.insert("use");
//    St.insert("zoo");
//    St.insert("try");
//    St.insert("bat");
//    St.insert("hay");
//    St.insert("key");
//    St.insert("jig");
//    
//    
//    St.InorderTraverse(St.root);
//    cout<<endl;
//     St.PreorderTraverse(St.root);
//    cout<<endl;
//    St.PostorderTraverse(St.root);
//    cout<<endl;
//    
//    
//    cout<<St.TreeMin()<<endl;
//   cout<<St.TreeMax()<<endl;
//   cout<<St.search("key")<<endl;
//    
//    treeNode* scNode=St.Successor("key");
//    cout<<scNode->data<<endl;
//    treeNode* PsNode=St.Predecessor("key");
//    cout<<PsNode->data<<endl;
//   
//    
//    
//    
//   
//    /*
//    treeNode* sNode=St.search("");
//    if(sNode!=NULL)
//        cout<<sNode->data<<endl;
//    else
//        cout<<"Data not found"<<endl;
//   */ 
//    St.deleted("jig");
//    St.InorderTraverse(St.root);
//    cout<<endl;
//    
//    St.deleted("bat");
//    St.InorderTraverse(St.root);
//    cout<<endl;
//    
//    St.deleted("use");
//    St.InorderTraverse(St.root);
//    cout<<endl;
// 
//    
//}
//

