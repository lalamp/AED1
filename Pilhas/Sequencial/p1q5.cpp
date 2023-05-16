#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack S1, S2, S3;
    StackEntry x;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S2.push(100);
    S2.push(200);

    cout << S1.toString() << endl;
    cout << S2.toString() << endl;

    while(!S1.empty()){
        S1.pop(x);
        S3.push(x);
    }
    while(!S3.empty()){
        S3.pop(x);
        S2.push(x);
    }

    cout << S1.toString() << endl;
    cout << S2.toString() << endl;
}