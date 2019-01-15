//
//  main.cpp
//  Micro_and_Array_Update
//
//  Created by Zeeshan Khan on 1/15/19.
//  Copyright © 2019 Murtuza. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int test;
    cin>>test;
    for(; test; test--) {
        int n,k;
        cin>>n>>k;
        int min = 1000007;
        int element;
        for(int i = 0; i<n; i++) {
            cin>>element;
            if(element<min) {
                min = element;
            }
        }
        
        int cnt = k - min;
        if(cnt > 0) {
            cout<<cnt<<endl;
        } else {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
