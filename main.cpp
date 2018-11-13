//#include <GL/glut.h>
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(5, 5);
    Matrix<int> b(5, 5);
    //b.set(3,3,5);
    //b.set(4,3,20);
    a.set(0,0,5);
    //a.set(0,3,0);
    a.set(1,0,10);
    a.set(2,0,7);
    a.set(3,0,11);
    a.set(4,0,15);
    a.set(0,4,8);
    a.set(0,0,0);
    //a=b;
    //a.operator-(b);
    //a.operator=(b);
    //a.operator*(7);
    //  a.transposed();
    //a.print();
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++){
            cout << a(x,y) << " ";
        }
        cout << endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
