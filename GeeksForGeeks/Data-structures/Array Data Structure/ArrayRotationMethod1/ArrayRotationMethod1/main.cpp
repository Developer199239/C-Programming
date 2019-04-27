//
//  main.cpp
//  ArrayRotationMethod1
//
//  Created by MURTUZA on 25/3/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include<stdio.h>
#include <algorithm>
using namespace std;


void leftRotatedbyOne(int arr[], int n) {
    int temp = arr[0],i;
    
    for(i = 0;i<n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}

void leftRotate(int arr[],int d, int n) {
    for(int i = 0; i<d; i++) {
        leftRotatedbyOne(arr, n);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5,6,7};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    leftRotate(arr, 2, n);
    printArray(arr, n);
    
    
    return 0;
}
