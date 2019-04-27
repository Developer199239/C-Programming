//
//  main.cpp
//  Find_maxsum_tations_array_O(n)
//
//  Created by MURTUZA on 29/3/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int maxSum(int arr[],int n) {
    int arrsum = 0;
    int currVal = 0;
    for(int i = 0; i<n; i++) {
        arrsum = arrsum + arr[i];
        currVal = currVal + (i*arr[i]);
    }
    
    int maxVal = currVal;
    
    for(int j = 1; j<n; j++) {
        currVal = currVal + arrsum - n * arr[n-j];
        if(currVal > maxVal) {
            maxVal = currVal;
        }
    }
    return maxVal;
}


int main(int argc, const char * argv[]) {
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\nMax sum is " << maxSum(arr, n)<<endl;
    return 0;
}
