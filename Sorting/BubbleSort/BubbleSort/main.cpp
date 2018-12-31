//
//  main.cpp
//  BubbleSort
//
//  Created by MURTUZA RAHMAN on 12/31/18.
//  Copyright © 2018 Murtuza. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[] = {7, 4, 5, 2};
void bubble_sort(int n) {
    int temp;
    for(int k = 0; k < n-1; k++) {
        // n-k-1 is for ignoring bcz already sorting...
        for(int i = 0; i < n-k-1; i++) {
            if(arr[i] > arr[i+1]) {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }

}

int main(int argc, const char * argv[]) {
    int n = sizeof(arr);
    n = n/sizeof(int);
    bubble_sort(n);
    
    for(int i = 0; i<n; i++) {
        cout<<" "<<arr[i];
    }
    return 0;
}
