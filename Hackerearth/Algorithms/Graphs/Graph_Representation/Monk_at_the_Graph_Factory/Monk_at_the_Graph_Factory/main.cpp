//
//  main.cpp
//  Monk_at_the_Graph_Factory
//
//  Created by MURTUZA on 12/1/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int sum = 0;
    int de;
    for(int i = 0; i<n; i++) {
        cin>>de;
        sum = sum + de;
    }
    
    if(sum == (2*(n-1))) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    return 0;
}
