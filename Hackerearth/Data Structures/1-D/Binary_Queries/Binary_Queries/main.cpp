//
//  main.cpp
//  Binary_Queries
//
//  Created by Zeeshan Khan on 1/15/19.
//  Copyright © 2019 Murtuza. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,q;
    cin>>n>>q;
    int ar[n];
    for(int i = 0; i<n; i++) {
        cin>>ar[i];
    }
    int status,l,r,index;
    for(int i = 0; i<q; i++) {
        cin>>status;
        if(status == 1) {
            cin>>index;
            index--;
            if(ar[index] == 0) {
                ar[index] = 1;
            } else {
                ar[index] = 0;
            }
        } else {
            cin>>l>>r;
            l--;
            r--;
            
        }
    }
    
    return 0;
}
