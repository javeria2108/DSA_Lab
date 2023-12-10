#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include "linklist.h"
#include "object.h"

using namespace std;

class Neighbour : public object {
public:
    string name;
    float distance;

    Neighbour() {}
    Neighbour(string d, float w) {
        name = d;
        distance = w;
    }

    void input() {
        cout << "Enter neighbour name: ";
        cin >> name;
        cout << "Enter distance: ";
        cin >> distance;
    }

    void print() {
        cout << " " << name << " " << distance << " ";
    }
};

class Vertix : public object {
public:
    string name;
    LL neighbourList;
    bool visited;

    Vertix() { 
        visited = false; 
    }

    Vertix(string n) {
        name = n;
        visited = false;
    }

    void addNeighbour(string d, float weight) {
        Neighbour* n = new Neighbour(d, weight);
        neighbourList.insert(n);
    }

    void input() {
        cout << "Enter vertex name: ";
        cin >> name;

        int numNeighbours;
        cout << "Enter number of neighbours: ";
        cin >> numNeighbours;

        for (int i = 0; i < numNeighbours; i++) {
            cout << "Enter neighbour #" << i + 1 << " details:" << endl;
            string neighbourName;
            float distance;

            cout << "Enter neighbour name: ";
            cin >> neighbourName;

            cout << "Enter distance: ";
            cin >> distance;

            addNeighbour(neighbourName, distance);
        }
    }

    void print() {
        cout << " " << name << " ";
        neighbourList.print();
    }

    string getName() {
        return name;
    }
};

class Edge : public object {
public:
    string source;
    string destination;
    float weight;

    Edge() {}

    Edge(string s, string d, float w) {
        source = s;
        destination = d;
        weight = w;
    }

    void input() {}

    void print() {
        cout << " " << source << " " << destination << " " << weight << " ";
    }
};

class Graph {
    LL AdjList;
    LL EdgeList;

public:
    void buildGraph(string filename) {
        ifstream in;
        in.open("PTA.txt");

        // Read vertices and create vertex objects
        string vertices;
        getline(in, vertices);
        cout << vertices;

        while (vertices.length() > 0) {
            Vertix* v;
            int sep = vertices.find(' ');

            if (sep != -1) {
                v = new Vertix(vertices.substr(0, sep));
                vertices = vertices.substr(sep + 1, vertices.length());
            } else {
                v = new Vertix(vertices);
                vertices = vertices.substr(0, 0);
            }

            AdjList.insert(v);
        }

        // Read edges and add neighbours to vertex objects
        while (!in.eof()) {
            string s, d;
            float weight;

            in >> s >> d >> weight;
            cout << s << " " << d << " " << weight << endl;

            int loc = searchInAdjList(s);
            ((Vertix*)AdjList.get(loc))->addNeighbour(d, weight);

            loc = searchInAdjList(d);
            ((Vertix*)AdjList.get(loc))->addNeighbour(s, weight);

            AdjList.print();
        }
    }
    
    int searchInAdjList(string node) {
        for (int i = 0; i < AdjList.getLength(); i++) {
            Vertix* v = static_cast<Vertix*>(AdjList.get(i));
            if (v->getName() == node) {
                return i;
            }
        }
        return -1; // Return -1 if the node is not found
    }

    void print() {
        for (int i = 0; i < AdjList.getLength(); i++) {
            Vertix* v = static_cast<Vertix*>(AdjList.get(i));
            v->print();
        }
    }

    void OptimalPath(string v1, string v2) {
    	 queue<Vertix*> que;
        int sindex = searchInAdjList(v1);
        int dindex = searchInAdjList(v2);
        
        Vertix* sourceVertix = ((Vertix*)AdjList.get(sindex));
        sourceVertix->visited = true;
        que.push(sourceVertix);
        map<string, string> parentMap;
        parentMap[v1] = "";

        while (!que.empty()) {
            Vertix* frontVertix = que.front();
            que.pop();

            for (int i = 0; i < frontVertix->neighbourList.getLength(); i++) {
                Neighbour* neighbour = ((Neighbour*)frontVertix->neighbourList.get(i));
                Vertix* neighbourVertix = ((Vertix*)AdjList.get(searchInAdjList(neighbour->name)));
                if (!neighbourVertix->visited) {
                    neighbourVertix->visited = true;
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
                cout << " <- " << d;
            }
            cout << endl;
        }   
		for (int i = 0; i < AdjList.getLength(); i++) {
        Vertix* v = (Vertix*)AdjList.get(i);
        v->visited = false;
    }
}
};


int main() {
    Graph g;

    // Build the graph from the file "GraphMaze.txt"
    g.buildGraph(" ");

    // Print the graph to verify it was read correctly
    cout << "The graph is: " << endl;
    g.print();

    // Find the shortest path between two vertices using BFS
    string v1;
    cout << "Give source vertex name: ";
    cin >> v1;
    string v2;
    cout << "Give destination vertex name:: ";
    cin >> v2;
    g.OptimalPath(v1,v2);


    return 0;
}

