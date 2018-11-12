//#include <GL/glut.h>
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(5, 5);
    Matrix<int> b(5, 5);
    //b.set(3,3,5);
    //b.set(4,3,10);
    a.set(3,3,5);
    a.set(4,3,10);
    a.set(2,3,11);
    //a.set(3,3,5);
    a.operator+(b);
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++){
            cout << a.operator()(x,y) << " ";
        }
        cout << endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
