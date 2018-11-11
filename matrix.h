#ifndef MATRIX_H
#define MATRIX_H
#include "node.h"
using namespace std;
template <typename T>
class Matrix {
    private:
        Node<T>* hRows;
        Node<T>* hColumns;
        int columns;
        int rows;
    public:
        Matrix();
        Matrix(int sizeX, int sizeY){
            hRows=new Node<T>;
            hColumns= new Node<T>;
            Node<T>* tempx=hRows->next;
            Node<T>* tempy=hColumns->down;
            columns=sizeY;
            rows=sizeX;
            for(int x=0;x<rows;x++){
                tempx=new Node<T>;
                tempx=tempy->next;
            }
            for(int y=0;y<columns;y++){
                tempy=new Node<T>;
                tempy=tempy->down;
            }
        };
        void set(int x, int y, T data){
            if(data==0){
                return;
            }
            Node<T>* tempx=hRows;
            Node<T>* tempy=hColumns;
            Node<T>* auxx;
            Node<T>* auxy;
            for(int i=0;i<x;i++){
                if(tempx!=nullptr){
                    auxx=tempx;
                }
                tempx=tempy->next;
            }
            for(int i=0;i<y;i++){
                if(tempy!=nullptr){
                    auxy=tempy;
                }
                tempy=tempy->down;
            }
            if(tempx!= nullptr && tempy!= nullptr){
                return;
            }
            Node<T>* nodo=new Node<T>;
            nodo->set(x,y,data);
            nodo->next=auxx->next;
            nodo->down=auxy->down;
            auxx->next=nodo;
            auxy->down=nodo;
        };
        T operator()(int x, int y){

        };
        Matrix<T> operator*(Matrix<T> other);
        Matrix<T> operator*(T scalar);
        Matrix<T> operator+(Matrix<T> other);
        Matrix<T> operator-(Matrix<T> other);
        Matrix<T> transposed();
        Matrix<T> operator=(Matrix<T> other);
        //~Matrix();
};

#endif
