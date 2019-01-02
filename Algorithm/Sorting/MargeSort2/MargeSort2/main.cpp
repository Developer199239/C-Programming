//
//  main.cpp
//  MargeSort2
//
//  Created by Zeeshan Khan on 1/2/19.
//  Copyright © 2019 Murtuza. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define arr_size 100

int arr[arr_size];
int temp[arr_size],counter = 0;

void marging(int startPoint, int midPoint, int endPoint) {
    int firstArrCnt,secArrCnt,i;
    firstArrCnt = startPoint;
    secArrCnt = midPoint + 1;
    
      for(i = firstArrCnt; firstArrCnt<=midPoint && secArrCnt<=endPoint; i++) {
        if(arr[firstArrCnt] < arr[secArrCnt]) {
            temp[i] = arr[firstArrCnt++];
        } else {
            temp[i] = arr[secArrCnt++];
        }
    }
    
    while (firstArrCnt <= midPoint) {
        temp[i++] = arr[firstArrCnt++];
    }
    
    while(secArrCnt<=endPoint) {
        temp[i++] = arr[secArrCnt++];
    }
    
    for(i = startPoint; i<=endPoint; i++) {
        arr[i] = temp[i];
    }
}

void margeSort(int startPoint, int endPoint) {
    int midPoint;
    if(startPoint >= endPoint) {
        return;
    }
    
    printf("Counter: %d: Start: %d, End: %d\n",++counter, startPoint, endPoint);
    midPoint = (startPoint + endPoint) / 2;
    printf("Mid = %d\n",midPoint);
    margeSort(startPoint, midPoint);
    margeSort(midPoint+1, endPoint);
    
    printf("StartPoint: %d, MidPoint: %d, endPoint: %d",startPoint,midPoint,endPoint);
    
    marging(startPoint, midPoint, endPoint);
    
}



int main(int argc, const char * argv[]) {
    arr[0] = 10;
    arr[1] = 2;
    arr[2] = 5;
    arr[3] = 100;
    arr[4] = 6;
    
    margeSort(0, 4);
    
    
    for(int i = 0; i<5; i++) {
        printf("%d ",arr[i]);
    }
    
    
    return 0;
}
