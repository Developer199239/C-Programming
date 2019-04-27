//
//  main.cpp
//  BFS
//
//  Created by MURTUZA on 26/4/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <list>
using namespace std;

class Graph{
    int vertices;
    list<int> *adj;
    
    
public:
    Graph(int vertices);
    
    void addEdge(int v,int w);
    
    void BFS(int s);
    
};

Graph:: Graph(int v) {
    this->vertices = v;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    bool *visited = new bool[vertices];
    for(int i = 0; i<vertices; i++) {
        visited[i] = false;
    }
    
    list<int>queue;
}




int main(int argc, const char * argv[]) {
    
    return 0;
}
