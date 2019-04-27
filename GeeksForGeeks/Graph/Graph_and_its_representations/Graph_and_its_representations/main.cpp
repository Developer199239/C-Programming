//
//  main.cpp
//  Graph_and_its_representations
//
//  Created by MURTUZA on 26/4/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void addEdge(vector<int>adj[],int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int>adj[],int vertices) {
    for(int v = 0; v<vertices; v++) {
        cout<<"Adjecenecy list of vertex "<<v<<endl;
        for(int i = 0; i<adj[v].size(); i++) {
            cout<<adj[v][i]<<" ";
        }
        cout<<endl;
    }
}


int main(int argc, const char * argv[]) {
    
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    
    printGraph(adj,V);
    
    return 0;
}
