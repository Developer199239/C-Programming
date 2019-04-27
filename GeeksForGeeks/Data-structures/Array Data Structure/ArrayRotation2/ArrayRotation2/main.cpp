//
//  main.cpp
//  ArrayRotation2
//
//  Created by MURTUZA on 25/3/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

//https://www.youtube.com/watch?v=utE_1ppU5DY
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
     return gcd(b, a % b);
    }
}

void rotatedArray(int arr[],int d,int n) {
    int ro = gcd(n, d);
    for(int i = 0; i<ro; i++) {
        int j = i;
        int temp = arr[i];
        while(true) {
            int dd = (j+d) % n;
            if(i == dd) {
                break;
            }
            arr[j] = arr[dd];
            j = dd;
        }
        arr[j] = temp;
    }
}

void printAll(int arr[], int n){
    for(int i = 0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}


int main(int argc, const char * argv[]) {
    int arr[] = {1,2,3,4,5,6};
    int d = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    rotatedArray(arr, d, n);
    printAll(arr, n);
    return 0;
}
