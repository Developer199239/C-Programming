//
//  main.cpp
//  Find_maxsum_tations_array_n^2_solution
//
//  Created by MURTUZA on 29/3/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int rotations(int arr[],int n) {
    int maxSum = 0;
    int temp = arr[0];
    int i;
    for(i = 0; i<n-1; i++){
        arr[i] = arr[i+1];
        maxSum += (i*arr[i]);
    }
    arr[i] = temp;
    maxSum += (i*temp);
    return maxSum;
}

int findMaxSum(int arr[],int n) {
    int maxSum = 0;
    for(int i = 0; i<n; i++) {
        int sum = rotations(arr, n);
        if(sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int main(int argc, const char * argv[]) {
    int arr[] = {10,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<findMaxSum(arr, n);
    return 0;
}
