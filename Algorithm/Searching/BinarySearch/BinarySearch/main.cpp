//
//  main.cpp
//  BinarySearch
//
//  Created by Zeeshan Khan on 12/31/18.
//  Copyright © 2018 Murtuza. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int binarySearch(int a[],int low,int high,int key) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] < key) {
            low = mid + 1;
        } else if(a[mid] > key) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int ar[] = {1,4,7,9,10,45};
    int index = binarySearch(ar, 0, 5, 7);
    cout<<index<<endl;
    return 0;
}
