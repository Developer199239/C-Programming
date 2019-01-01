//
//  main.cpp
//  MargeSort
//
//  Created by MURTUZA on 1/1/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

void mergeAll(int a[], int start, int mid, int end) {
    int p = start, q = mid + 1;
    
    int Arr[end - start + 1], k = 0;
    
    for(int i = start; i<=end; i++) {
        if(p > mid) {
            Arr[k++] = a[q++];
        } else if(q > end) {
            Arr[k++] = a[p++];
        } else if(a[p] < a[q]) {
            Arr[k++] = a[p++];
        } else {
            Arr[k++] = a[q++];
        }
    }
    
    for(int p = 0; p<k; p++) {
        a[start++] = Arr[p];
    }
}

void marge_sort(int a[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        marge_sort(a, start, mid);
        marge_sort(a, mid + 1, end);
        
        mergeAll(a,start,mid,end);
    }
}


int main(int argc, const char * argv[]) {
    
    int arr[] = {10,2,90,1,5};
    marge_sort(arr, 0, 4);
    
    
    for(int i = 0; i<5; i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
