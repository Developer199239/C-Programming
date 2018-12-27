//
//  main.cpp
//  LayerBound
//
//  Created by Zeeshan Khan on 12/12/18.
//  Copyright © 2018 Murtuza. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int searchLowerBound(int a[],int size,int key) {
    int begin = 0;
    int end = size - 1;
    int index = -1;
    
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if(key == a[mid]) {
            index = mid;
            end = mid - 1;
        } else if(key > a[mid]) {
            begin = mid + 1;
        } else if(key < a[mid]) {
            end = mid - 1;
        }
    }
    return begin;
}


int searchUperBound(int a[], int size, int key) {
    int begin = 0;
    int end = size - 1;
    int index = -1;
    
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if(key == a[mid]) {
            index = mid;
//            end = mid - 1;
            begin++;
        } else if(key > a[mid]) {
            begin = mid + 1;
        } else if(key < a[mid]) {
            end = mid - 1;
        }
    }
    return begin;
}



int main(int argc, const char * argv[]) {
    int a[7] = {1,1,1,5,7,9,12};
//    int lowerBound = searchLowerBound(a, 7, 1);
//    cout<<lowerBound<<endl;
        int uperBound = searchUperBound(a, 7, 40);
        cout<<uperBound<<endl;
    return 0;
}
