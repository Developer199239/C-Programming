//
//  main.cpp
//  Monk_in_the_real_estate
//
//  Created by MURTUZA on 12/1/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int test;
    cin>>test;
    while(test--) {
        set<int>road;
        int e;
        cin>>e;
        int x,y;
        for(int i = 0; i<e; i++) {
            cin>>x>>y;
            road.insert(x);
            road.insert(y);
        }
        
        cout<<road.size()<<endl;
    }
    return 0;
}
