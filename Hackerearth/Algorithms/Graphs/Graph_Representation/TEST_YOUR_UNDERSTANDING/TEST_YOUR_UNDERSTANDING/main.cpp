//
//  main.cpp
//  TEST_YOUR_UNDERSTANDING
//
//  Created by MURTUZA on 12/1/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool ar[1000][1000];


void initializer(int node) {
    for(int i = 1; i<=node; i++) {
        for(int j =1; j<=node; j++) {
            ar[i][j] = false;
        }
    }
}
                    
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    initializer(n);
    int a,b;
    for(int i = 0; i<m; i++) {
        cin>>a>>b;
        ar[a][b] = true;
        ar[b][a] = true;
    }
    
    int q;
    cin>>q;
    for(int i = 0; i<q; i++) {
        cin>>a>>b;
        if(ar[a][b] == true) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
