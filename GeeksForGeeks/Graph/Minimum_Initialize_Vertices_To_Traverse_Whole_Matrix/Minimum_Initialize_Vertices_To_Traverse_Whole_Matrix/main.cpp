//
//  main.cpp
//  Minimum_Initialize_Vertices_To_Traverse_Whole_Matrix
//
//  Created by MURTUZA on 1/5/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100;



void printMinSources(int adj[][MAX], int N, int M)
{
    // Storing the cell value and cell indices
    // in a vector.
    vector<pair<long int, pair<int, int> > > x;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            x.push_back(make_pair(adj[i][j],
                                  make_pair(i, j)));
    

    
    cout<<x.size()<<endl;
    
}


int main(int argc, const char * argv[]) {
    
    int N = 2, M = 2;
    
    int adj[2][MAX] = {{3, 3},
        {1, 1}};
    
    printMinSources(adj, N, M);
    
    return 0;
}
