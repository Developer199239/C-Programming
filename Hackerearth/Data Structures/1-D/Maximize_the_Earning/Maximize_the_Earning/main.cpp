//
//  main.cpp
//  Maximize_the_Earning
//
//  Created by Zeeshan Khan on 1/31/19.
//  Copyright © 2019 Murtuza. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(;n>0;n--) {
        int long n,r,maxLen = 0,maxNumber = -1,s;
        cin>>n;
        cin>>r;
        for(int i = 0; i<n; i++) {
            cin>>s;
            if(s>maxNumber) {
                maxLen++;
                maxNumber = s;
            }
        }
        cout<<(maxLen*r)<<endl;
    }
    return 0;
}
