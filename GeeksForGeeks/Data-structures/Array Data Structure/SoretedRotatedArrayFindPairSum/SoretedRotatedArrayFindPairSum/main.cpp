//
//  main.cpp
//  SoretedRotatedArrayFindPairSum
//
//  Created by MURTUZA on 28/3/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool pairInSortedRotated(int arr[], int n, int x) {
    int i;
    for(i = 0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            break;
        }
    }
    
    int l  = (i+1) % n;
    int r = i;
    
    while(l != r) {
        if(arr[l] + arr[r] == x) {
            return true;
        }
        
        if(arr[l] + arr[r] < x) {
            l = (l+1) % n;
        } else {
            r = (n + r - l) % n;
        }
    }
    
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {1,2,3,4,5};
    int sum = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bool isPair = pairInSortedRotated(arr, n, sum);
    if(isPair) {
        cout<<"Has pair elements with the sum "<<sum<<endl;
    } else {
        cout<<"Doesn't have pair elements with the sum "<<sum<<endl;
    }
    
    return 0;
}
