//
//  main.cpp
//  InsertionSort
//
//  Created by MURTUZA on 1/1/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[] = {5,-10,10,20,3};

void insert_sort(int n) {
    for(int i = 0; i<n; i++) {
        int temp = a[i];
        int j = i;
        while(j>0 && temp < a[j-1]) {
            a[j] = a[j-1];
            j = j - 1;
        }
        a[j] = temp;
    }
}

int main(int argc, const char * argv[]) {
    int n = 5;
    insert_sort(n);
    for(int i = 0; i<n; i++) {
        printf("%d ",a[i]);
    }
    return 0;
}
