//
//  main.cpp
//  parentheses_check
//
//  Created by MURTUZA on 23/2/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int top;

int check(char str[],int n, char stack[]) {
    for(int i = 0; i<n; i++) {
        if(str[i] == '(') {
            top = top + 1;
            stack[top] = '('
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
