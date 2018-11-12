//#include <GL/glut.h>
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(5, 5);
    a.set(3,3,5);
    a.set(4,3,10);
    a.set(2,3,11);
    cout << a.operator()(3,2) << endl;
    cout << a.operator()(3,3) << endl;
    cout << a.operator()(3,4) << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
