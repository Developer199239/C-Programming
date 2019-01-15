//
//  main.cpp
//  Monk_and_Welcome_Problem
//
//  Created by Zeeshan Khan on 1/15/19.
//  Copyright © 2019 Murtuza. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int ar[n];
    for(int i = 0; i<n; i++) {
        cin>>ar[i];
    }
    int b;
    for(int i = 0; i<n; i++) {
        cin>>b;
        ar[i]+=b;
    }
    
    for(int i = 0; i<n; i++) {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    return 0;
}
