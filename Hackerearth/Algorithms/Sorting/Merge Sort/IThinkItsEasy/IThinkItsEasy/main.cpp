//
//  main.cpp
//  IThinkTtsEasy
//
//  Created by MURTUZA on 4/1/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <iterator>
using namespace std;
#define arr_size 52

void marging(int start, int mid, int end, int A[],string nameString[]) {
    int p = start ,q = mid+1;
    
    int Arr[end-start+1] , k=0;
    string ArrStr[end-start+1];
    
    for(int i = start ;i <= end ;i++) {
        if(p > mid) {
            Arr[ k] = A[q] ;
            ArrStr[ k] = nameString[q] ;
            k++;
            q++;
        } else if ( q > end) {
            Arr[ k ] = A[p];
            ArrStr[ k ] = nameString[p];
            k++;
            p++;
        } else if( A[ p ] < A[ q ]) {
            Arr[ k ] = A[ p ];
            ArrStr[ k ] = nameString[ p ];
            k++;
            p++;
        } else if(A[ p ] > A[ q ]){
            Arr[ k ] = A[ q];
            ArrStr[ k ] = nameString[ q];
            k++;
            q++;
        } else {
            Arr[ k ] = A[ p];
            ArrStr[ k ] = nameString[ p];
            int value = A[p];
            k++;
            p++;
            
            for(int j = p;j<=mid; j++) {
                if(value == A[j]) {
                    Arr[ k ] = A[ p];
                    ArrStr[ k ] = nameString[ p];
                    k++;
                    p++;
                    i++;
                }
            }
            
            Arr[ k ] = A[ q];
            ArrStr[ k ] = nameString[ q];
            k++;
            q++;
            i++;
            
        }
    }
    for (int p=0 ; p< k ;p ++) {
        /* Now the real array has elements in sorted manner including both
         parts.*/
        A[ start ] = Arr[ p ] ;
        nameString[ start] = ArrStr[ p ] ;
        start++;
    }
    
    
}

void margeSort(int startPoint, int endPoint,int nameInt[],string nameString[]) {
    int midPoint;
    if(startPoint >= endPoint) {
        return;
    }
    midPoint = (startPoint + endPoint) / 2;
    margeSort(startPoint, midPoint,nameInt,nameString);
    margeSort(midPoint+1, endPoint,nameInt,nameString);
    
    marging(startPoint, midPoint, endPoint,nameInt,nameString);
    
}


int main() {
    
    
//        string input;
//        getline(cin, input); // get input until enter key is pressed
    
    int test;
    cin>>test;
    getchar();
    while(test--) {
        
        string nameString[51];
        int nameInt[51];
       
        char input[30000];
        gets(input);
        
        
        int cnt = 0;
        char *p = strtok (input, " ");
        char *array[51];
        
        while (p != NULL)
        {
            array[cnt++] = p;
            p = strtok (NULL, " ");
        }
        
        
        for (int i = 0; i < cnt; ++i)
        {
            nameString[i] = array[i];
            nameInt[i] = strlen(array[i]);
        }
        
        
        margeSort(0, cnt-1,nameInt,nameString);
        cout<<" ";
        for(int i=0; i<cnt; i++) {
            if(i == cnt-1) {
                cout<<nameString[i]<<endl;
            } else {
                cout<<nameString[i]<<" ";
            }
            
        }
        
    }
    return 0;
}
