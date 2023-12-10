//
//  StackB.cpp
//  DSA-Stack
//
//  Created by Hina Khalid  on 25/01/2022.
//  Copyright © 2022 Hina Khalid . All rights reserved.
//
/* C++ program to implement basic stack operations */

#include <iostream>

using namespace std;

#define MAX 10

class Stack {
    int top;
    int a[MAX];    // Maximum size of Stack
public:
    Stack() { top = -1; }
    
    bool push(int x)
    {
        if (top >= (MAX - 1)) {
            cout << "Stack Full"<<endl;
            return false;
        }
        else {
            a[++top] = x;
            cout << x << " pushed into stack"<<endl;
            return true;
        }
    }
    
    int pop()
    {
        if (isEmpty()) {
            return -1;
        }
        else {
            int x = a[top--];
            return x;
        }
    }
    int peek()
    {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return 0;
        }
        else {
            int x = a[top];
            return x;
        }
    }
    
    bool isEmpty()
    {
        return (top < 0);
    }
    bool isFull()
    {
        return (top == MAX);
    }
};

// Driver program to
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack"<<endl;
    cout << s.pop() << " Popped from stack"<<endl;
    cout << s.pop() << " Popped from stack"<<endl;
    cout << s.pop() << " Popped from stack"<<endl;
    cout<<"------------\n";
    
    //much better way
    if(s.pop()==-1)
        cout<<"Empty Stack"<<endl;
    cout<<"------------\n";
    
    // filling stack to max
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);
    s.push(107);
    s.push(108);
    s.push(109);
    s.push(110);
    s.push(111);

     cout<<"------------\n";
    
    //some intelligent popping
    while(!s.isEmpty())
    {
        cout << s.pop() << " Popped from stack"<<endl;
    }
    cout<<"------------\n";
    
    //better check before adding for space
    for( int i=0;i<10;i++)
        if(!s.isFull())
            s.push(20+i);
    cout<<"------------\n";
    //print all elements in stack :
    cout<<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout<<s.peek()<<" ";
        // remove top element in stack
        s.pop();
    }
    
    return 0;
}

