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
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int minValue = 10001;
    int arr[n],tempArr[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
        if(arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    int j = 0;
    tempArr[j++] = minValue;
    for(int i = n-1; i>=0;i--) {
        if(arr[i] > minValue) {
            minValue = arr[i];
            tempArr[j++] = minValue;
        }
    }
    
    for(int i = j - 1; i>=0; i--) {
        cout<<tempArr[i]<<" ";
    }
    
    return 0;
}
