//
//  main.cpp
//  GameOfStrengths
//
//  Created by Zeeshan Khan on 1/8/19.
//  Copyright © 2019 Murtuza. All rights reserved.
//
#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007

void mergeAll(long int a[], int start, int mid, int end) {
    int p = start, q = mid + 1;
    
    long int Arr[end - start + 1], k = 0;
    
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

void marge_sort(long int a[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        marge_sort(a, start, mid);
        marge_sort(a, mid + 1, end);
        
        mergeAll(a,start,mid,end);
    }
}


int main(int argc, const char * argv[]) {
    
    int test;
    cin>>test;
    
    for(;test; test--) {
        int n;
        cin>>n;
        long int ar[n+1];
        for(int i = 0; i<n; i++) {
            cin>>ar[i];
        }
        marge_sort(ar, 0, n-1);
        
        long int sum = 0;
        for(int i = n-1; i>=0; i--) {
            sum = (sum + (((i*ar[i])%mod) - (((n-1-i)*ar[i])%mod))%mod);
        }
        
        sum = ((sum%mod) * (ar[n-1]%mod) % mod);
        cout<<sum<<endl;
    }
    
    return 0;
}
