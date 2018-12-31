//
//  main.cpp
//  SelectionSort
//
//  Created by Murtuza Rahman on 12/31/18.
//  Copyright © 2018 Murtuza. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int ar[] = {7,1,4,2};


void selectionSort(int n) {
    int minimum;
    for(int i = 0; i<n-1; i++) {
        minimum = i;
        for(int j = i+1; j<n; j++) {
            if(ar[j]<ar[minimum]) {
                minimum = j;
            }
        }
        if(minimum != i) {
            swap(ar[minimum], ar[i]);
        }
    
    }
}

int main(int argc, const char * argv[]) {
    int n = 4;
    selectionSort(n);
    
    for(int i = 0; i<n; i++) {
        cout<<ar[i]<<" ";
    }
    
    return 0;
}
