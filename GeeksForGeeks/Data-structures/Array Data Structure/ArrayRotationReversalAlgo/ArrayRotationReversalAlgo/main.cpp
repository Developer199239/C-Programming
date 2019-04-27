//
//  main.cpp
//  ArrayRotationReversalAlgo
//
//  Created by MURTUZA on 25/3/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


void rotateArray(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5,6,7};
    int d = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    rotateArray(arr, 0, d-1);
    rotateArray(arr, d, n-1);
    rotateArray(arr, 0, n-1);
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
