//
//  main.cpp
//  GraphRepresentation
//
//  Created by MURTUZA on 12/1/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool a[10][10];

void initialize() {
    for(int i = 0; i<10; i++) {
        for(int j = 0; j<10; j++) {
            a[i][j] = false;
        }
    }
}

vector<int>adj[10];

int main(int argc, const char * argv[]) {
    //===== adjaceny matrix====
    /*int x,y,nodes,edges;
    initialize();
    cin>>nodes;
    cin>>edges;
    for(int i = 0; i<edges; i++) {
        cin>>x>>y;
        a[x][y] = true;
    }
    
    if(a[3][4] == true) {
        cout<<"There is an edge between 3 and 4"<<endl;
    } else {
        cout<<"There is no edge between 3 and 4"<<endl;
    }*/
    
    
    //===== adjaceny list====
    int x,y,nodes,edges;
    cin>>nodes;
    cin>>edges;
    
    for(int i = 0; i<edges; i++) {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    
    for(int i = 1; i<=nodes; i++) {
        cout<<"Adjacency list of node "<<i<<" : ";
        
        for(int j = 0; j<adj[i].size(); ++j) {
            if(j == adj[i].size() - 1) {
                cout<<adj[i][j] <<endl;
            } else {
                cout<<adj[i][j]<<" -->";
            }
        }
    }
    
    
    return 0;
}
