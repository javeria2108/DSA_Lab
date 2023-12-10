#include <string>
#include <fstream>
#include "linklist.h"
#include <queue>
#include <iostream>
#include "object.h"
#include <map>
using namespace::std;

using namespace std;
      
      class Neighbour:public object
      {
         public:
               string name;
               float distance;    
               Neighbour()
               {
                          }
               Neighbour(string d,float w)
               {
                  name=d;
                  distance=w;          
               }
               
               void input()
               {
               
               }
               
               void print()
               {
                  cout<<" "<<name<<"  "<<distance<<"  ";  
                }
            };
      
      class Vertix:public object
      {
       
              
              

         public:  
		   bool status;  
		    string name;
               LL neighbourList;           
               Vertix()
               {  status=false;}
               
               Vertix(string n)
               {
                 name=n;
                 status=false;
               }
               
               void addNeighbour(string d, float weight)
               {
                    Neighbour* n=new Neighbour(d,weight); 
                    neighbourList.insert(n);                    
                }
               void input()
               { }
               
               void print()
               {
                  cout<<" "<<name<<"  ";
                  neighbourList.print();  
                }
                
               string getName()
               {
                 return name;
               }

            };
            
            
            
      class Edge: public object
      {
            private:
            	int weight;
            	string v1;
            	string v2;
            public:
            	Edge(string s1, string s2, float w){
            		 v1 = s1;
                     v2 = s2;
                    weight = w;
				}
            
            };
            
            
            
      class Graph
      {
         LL AdjList;   
         public:
               void buildGraph(string filename)
               {
                    ifstream in;
                    in.open("PTA.txt");    //graph file name
                    
                    string vertexis;
                    // reading vertixes
                    getline(in,vertexis);
		   cout<<vertexis;

                    while(vertexis.length()>0)
//for(int i=0;i<11;i++)
                    {   Vertix * v;
                        int sep=vertexis.find(' ');

		       if(sep!=-1)
                        {v=new Vertix(vertexis.substr(0,sep));
                         vertexis=vertexis.substr(sep+1,vertexis.length());}
		       else
		       {v=new Vertix(vertexis);
		       vertexis=vertexis.substr(0,0);}
			//cout<<v->getName()<<endl;

                        AdjList.insert(v);
			
		}
             //reading edges
AdjList.print();

                  //  while(!in.eof())
for(int i=0;i<10;i++)
                    {

                        string s,d;
                        int weight;  // comment if unweighted graph

                        in>>s>>d>>weight;

cout<<s<<" "<<d<<" "<<weight<<endl;
//int I;
//cin>>I;
                        int loc =searchInAdjList(s);
//cout<<" "<<loc<<" "<<((Vertix*)AdjList.get(loc))->getName()<<endl;
                        ((Vertix*)AdjList.get(loc))->addNeighbour(d,weight); 
  
                        loc =searchInAdjList(d);       // for undirected graphs 
//cout<<" "<<loc<<" "<<((Vertix*)AdjList.get(loc))->getName()<<endl;
                        ((Vertix*)AdjList.get(loc))->addNeighbour(s,weight);
           AdjList.print();

                    }

                }
                
                              
        
                // just finding appropriate node to build the neighbour list
                int searchInAdjList(string node)
                {
                    for(int i=0;i<AdjList.getLength()-1;i++)
                       {
                            Vertix * v=(Vertix*)AdjList.get(i);
                            if(v->getName().compare(node)==0)
                                 return i; 
                        }
                }
                  void OptimalPath(string v1, string v2) {
    	 queue<Vertix*> que;
        int sindex = searchInAdjList(v1);
        int dindex = searchInAdjList(v2);
        
        Vertix* sourceVertix = ((Vertix*)AdjList.get(sindex));
        sourceVertix->status = true;
        que.push(sourceVertix);
        map<string, string> parentMap;
        parentMap[v1] = "";

        while (!que.empty()) {
            Vertix* frontVertix = que.front();
            que.pop();

            for (int i = 0; i < frontVertix->neighbourList.getLength(); i++) {
                Neighbour* neighbour = ((Neighbour*)frontVertix->neighbourList.get(i));
                Vertix* neighbourVertix = ((Vertix*)AdjList.get(searchInAdjList(neighbour->name)));
                if (!neighbourVertix->status) {
                    neighbourVertix->status = true;
                    que.push(neighbourVertix);
                    parentMap[neighbour->name] = frontVertix->name;
                }
            }
        }

     
        if (parentMap.find(v2) == parentMap.end()) {
            cout << "Did not find any path" << endl;
        } else {
            string d = v2;
            cout << d;
            while (d != v1) {
                d = parentMap[d];
                cout << " -- " << d;
            }
            cout << endl;
        }   
		for (int i = 0; i < AdjList.getLength(); i++) {
        Vertix* v = (Vertix*)AdjList.get(i);
        v->status = false;
    }
}
                
                void print()
                {
                     for(int i=0;i<AdjList.getLength()-1;i++)
                       {
                            Vertix * v=(Vertix*)AdjList.get(i);
                            v->print();
                        }
                 }
                 
            };
      
      
      int main()
      {
          Graph G;
G.buildGraph("");
          G.print();
           string v1;
    cout << "Give source vertex name: ";
    cin >> v1;
    string v2;
    cout << "Give destination vertex name:: ";
    cin >> v2;
    G.OptimalPath(v1,v2);
          
      }
