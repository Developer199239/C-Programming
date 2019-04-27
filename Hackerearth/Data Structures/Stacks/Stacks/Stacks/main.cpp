//
//  main.cpp
//  Stacks
//
//  Created by MURTUZA on 23/2/19.
//  Copyright © 2019 MURTUZA. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int top = -1;

void push(int stack[],int x, int n) {
    if(top == n - 1) {
        cout<<"Stack is full. Overflow condtion!"<<endl;
    }
    else{
        top = top + 1;
        stack[top] = x;
    }
}


bool isEmpty(){
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}

void pop(int stack[],int n) {
    if(isEmpty()) {
        cout<<"Stack is empty. Underflow condition!"<<endl;
    } else {
        
    }
}

int size(){
    return top + 1;
}

int topElement(int stack[]){
    return stack[top];
}


int main(int argc, const char * argv[]) {
    int stack[3];
    push(stack, 5, 3);
    
    cout<<"Current size of stack is "<<size()<<endl;
    
    push(stack, 10, 3);
    push(stack, 24, 3);
    
    cout<<"Current size of stack is "<<size()<<endl;
    
    push(stack, 12, 3);
    
    //Accessing the top element
    cout<<"The current top element in stack is "<<topElement(stack)<<endl;
    
    for(int i = 0; i<3; i++) {
        pop(stack,3);
    }
    
    cout<<"Current size of stack is "<<size()<<endl;
    
    //As the stack is emtpy, further popping will show an underflow condition.
    pop(stack, 3);
    return 0;
}
