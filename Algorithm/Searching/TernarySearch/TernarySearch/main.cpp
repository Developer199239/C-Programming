//
//  main.cpp
//  TernarySearch
//
//  Created by Zeeshan Khan on 12/31/18.
//  Copyright © 2018 Murtuza. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int ternary_search(int a[],int l,int r, int x) {
    int left = l;
    int right = r;
    while (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if(a[mid1] == x) {
            return mid1;
        } else if(a[mid2] == x) {
            return mid2;
        }
    
        if(x < a[mid1]) {
            right = mid1 - 1;
        } else if(x>a[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    int ar[] = {1,2,3,5,8,9,10};
    int index = ternary_search(ar, 0, 6, -1);
    cout<<index<<endl;
    return 0;
}
