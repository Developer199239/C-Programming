//
//  main.cpp
//  Help_Natsu
//
//  Created by Murtuza Rahman on 1/9/19.
//  Copyright © 2019 Murtuza. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(string &s1, string &s2) {
    return s1.size() < s2.size();
}

void mergeAll(vector<pair<string,int>>&a, int start, int mid, int end) {
    int p = start, q = mid + 1;
    
    int k = 0;
    vector<pair<string,int>>Arr;
    
    for(int i = start; i<=end; i++) {
        if(p > mid) {
            Arr.push_back(make_pair(a[q].first,a[q].second));
            k++;
            q++;
        } else if(q > end) {
            Arr.push_back(make_pair(a[p].first,a[p].second));
            k++;
            p++;
        } else if(a[p].second < a[q].second) {
            Arr.push_back(make_pair(a[p].first,a[p].second));
            k++;
            p++;
        } else if(a[p].second > a[q].second){
            Arr.push_back(make_pair(a[q].first,a[q].second));
            k++;
            q++;
        } else {
            vector<pair<string,int>>tempArr;
            tempArr.push_back(make_pair(a[p].first,a[p].second));
            int value = a[p].second;
            k++;
            p++;
            
            for(int j = p; j<=mid; j++) {
                if(a[j].second == value) {
                    tempArr.push_back(make_pair(a[p].first,a[p].second));
                    k++;
                    p++;
                    i++;
                }
            }
            tempArr.push_back(make_pair(a[q].first,a[q].second));
            k++;
            q++;
            i++;
            
            
            for(int q = 0; q<tempArr.size(); q++) {
                Arr.push_back(make_pair(tempArr[q].first,tempArr[q].second));
            }
        }
    }
    
    for(int p = 0; p<k; p++) {
        a[start].first = Arr[p].first;
        a[start].second = Arr[p].second;
        start++;
    }
}

void margeSort(int start, int end,vector<pair<string,int>>&tasks) {
    if(start < end) {
        int mid = (start + end) / 2;
        margeSort(start, mid,tasks);
        margeSort(mid + 1, end,tasks);
        
        mergeAll(tasks,start,mid,end);
    }
    
}


int main(int argc, const char * argv[]) {
    int test;
    cin>>test;
    while(test--) {
        int n;
        cin>>n;
        map<string,int>mymap;
        string key;
        map<string,int>::iterator it;
        for(int i = 0; i<n; i++) {
            cin>>key;
            it = mymap.find(key);
            if(it != mymap.end()) {
                mymap[key]++;
            } else {
                mymap.insert(it,pair<string,int>(key,1));
            }
        }
        vector<pair<string,int>>tasks;
        for(it = mymap.begin(); it!=mymap.end(); it++) {
            tasks.push_back(make_pair(it->first, it->second));
        }
        
        margeSort(0,(int)tasks.size()-1,tasks);
        
        for(int i = 0; i<tasks.size(); i++) {
            cout<<tasks[i].second<<" "<<tasks[i].first<<endl;
        }
    }
    
    return 0;
}
