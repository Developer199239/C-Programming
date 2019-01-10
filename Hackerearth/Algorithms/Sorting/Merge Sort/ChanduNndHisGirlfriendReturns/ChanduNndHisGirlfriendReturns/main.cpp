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

void mergeAll(long int a[], long int start, long int mid, long int end) {
    long int p = start, q = mid + 1;
    
    long int Arr[end - start + 1], k = 0;
    
    for(long int i = start; i<=end; i++) {
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

void marge_sort(long int a[], long int start, long int end) {
    if(start < end) {
        long int mid = (start + end) / 2;
        marge_sort(a, start, mid);
        marge_sort(a, mid + 1, end);
        
        mergeAll(a,start,mid,end);
    }
}


int main(int argc, const char * argv[]) {
    int test;
    cin>>test;
    
    while(test--) {
        int n,m;
        cin>>n>>m;
        long int arr[n+m+1];
        long int cnt = 0;
        for(int i =0; i<n; i++) {
            cin>>arr[cnt++];
        }
        
        for(int i =0; i<m; i++) {
            cin>>arr[cnt++];
        }
        
        marge_sort(arr,0,cnt-1);
        
        for(long int i = cnt-1; i>=0; i--) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
