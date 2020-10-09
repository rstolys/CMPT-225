#include <iostream>
using namespace std;

int main()
    {
    test_1();

    test_2();

    test_3();

    return 0;
    }

int test_1()
    {
    int i = 2 ;
    int * a[3] = {9,8,7} ;
    int * b = new int[3] ;
    b[0] = 1 ;
    cout << a[*b] << ";" << *(a+1) << ";" << *a+1 << endl ;
    }


int test_2()
    {
    int i = 2 ;
    int * pi = &i ;
    int * pq = pi+1 ;
    int * pr = pi ;
    int * a[3] = {9,8,7} ;
    int * b = new int[3] ;
    b[1] = 5 ;
    cout << b[1]+a[i] << ";" << pq << ";" << pr << endl ;
    }


int test_3()
    {
    int i = 2 ;
    int * a[3] = {9,8,7} ;
    int * b = new int[3] ;
    b[0] = 1 ;
    cout << a[*b] << ";" << *(a+1) << ";" << *a+1 << endl ;
    }
