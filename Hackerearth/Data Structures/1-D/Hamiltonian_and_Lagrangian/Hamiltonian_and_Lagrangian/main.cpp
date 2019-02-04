//
//  main.cpp
//  Hamiltonian_and_Lagrangian
//
//  Created by Zeeshan Khan on 1/31/19.
//  Copyright © 2019 Murtuza. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
#include <stdio.h>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int minValue = 10001;
    int arr[n];
    set<int>myset;
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        if(arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    
    int tempArra[n],j = 0;
    
    for(int i = n-1; i>=0;i--) {
        if(arr[i] > minValue) {
            minValue = arr[i];
            tempArra[j++] = minValue;
        } else if(arr[i] == minValue) {
           tempArra[j++] = minValue;
        }
    }
    
    
    for(int i = j - 1; i>=0; i--) {
        cout<<tempArra[i]<<" ";
    }
    
    
    return 0;
}
