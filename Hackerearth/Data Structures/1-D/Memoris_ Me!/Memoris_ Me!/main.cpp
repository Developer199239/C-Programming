//
//  main.cpp
//  Memorise_Me
//
//  Created by MURTUZA on 21/1/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,score;
    cin>>n;
    map<int,int>numbers;
    for(;n>0;) {
        cin>>score;
        numbers[score]++;
        n--;
    }
    
    int q;
    map<int,int>::iterator it;
    cin>>q;
    for(;q>0;q--) {
        cin>>score;
        it = numbers.find(score);
        if(it != numbers.end()) {
            cout<<it->second<<endl;
        } else {
            cout<<"NOT PRESENT"<<endl;
        }
        
    }
    return 0;
}
