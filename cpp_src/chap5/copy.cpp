#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 20;
    int *pa = &a;
    int *pb = &b;

    cout << a << ", " << b << endl;
    cout << *pa << ", " << *pb << endl;

    pa = pb;    //대입

    return 0;
}