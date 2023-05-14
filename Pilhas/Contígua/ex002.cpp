#include <iostream>
#include "Stack.h"
using namespace std;

//StackEntry = char
int main(){
    Stack S;
    StackEntry x, y, z;

    S.push('a');
    cout << S.toString() << endl;
    S.push('b');
    cout << S.toString() << endl;
    S.push('c');
    cout << S.toString() << endl;
    S.pop(x);
    cout << S.toString() << "\nx = " << x << endl;
    S.pop(y);
    cout << S.toString() << "\ny = " << y << endl;
    S.pop(z);
    cout << S.toString() << "\nz = " << z << endl;

    return 0;
}