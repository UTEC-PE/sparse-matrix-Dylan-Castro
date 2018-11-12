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
            Node<T>** tempx= &hRows;
            Node<T>** tempy= &hColumns;
            columns=sizeX;
            rows=sizeY;
            for(int x=1;x<rows;x++){
                tempx=&(*tempx)->down;
                *tempx=new Node<T>;
            }
            for(int y=1;y<columns;y++){
                tempy=&(*tempy)->next;
                *tempy=new Node<T>;
            }
        };
        void set(int x, int y, T data){
            Node<T>** tempx= &hRows;
            Node<T>** tempy= &hColumns;
            Node<T>** nodo_x_anterior;
            Node<T>** nodo_y_anterior;
            for(int i=0;i<y;i++){
                tempy=&(*tempy)->next;
            }
            nodo_y_anterior=tempy;
            tempx=&*tempy;
            do{
                if((*tempx)->down==nullptr){
                    break;
                }
                nodo_y_anterior=tempx;
                tempx=&(*tempx)->down;
            }
            while((*tempx)->y < y);
            tempx= &hRows;
            for(int i=0;i<x;i++){
                tempx=&(*tempx)->down;
            }
            nodo_x_anterior=tempx;
            tempy=&*tempx;
            do{
                if((*tempy)->next==nullptr){
                    break;
                }
                nodo_x_anterior=tempy;
                tempy=&(*tempy)->next;
            }
            while((*tempy)->x<x);
            //cout << (*nodo_y_anterior)->down << "---" << (*nodo_x_anterior)->next << endl;
            if((*nodo_y_anterior)->down != nullptr && (*nodo_x_anterior)->next != nullptr){
                if(data==0){
                    Node<T>* temp= (*nodo_x_anterior)->next;
                    (*nodo_x_anterior)->next= (*nodo_x_anterior)->next->next;
                    (*nodo_y_anterior)->down= (*nodo_y_anterior)->down->down;
                    delete temp;
                    return;
                }
                (*nodo_y_anterior)->down->set(x,y,data);
                return;
            }
            Node<T>* nodo=new Node<T>;
            nodo->set(x,y,data);
            nodo->next=(*nodo_x_anterior)->next;
            nodo->down=(*nodo_y_anterior)->down;
            (*nodo_x_anterior)->next=nodo;
            (*nodo_y_anterior)->down=nodo;
        };
        T operator()(int x, int y){
            Node<T>* tempx=hRows;
            Node<T>* tempy;
            int contador=0;
            for(int i=0;i<x;i++){
                tempx=tempx->down;
            }
            tempy=tempx;
            do{
                if(tempy->next==nullptr){
                    break;
                }
                tempy=tempy->next;
            }
            while(tempy->x<x);
            if(tempy->x==x && tempy->y==y){
                return tempy->get();
            }
            else{
                return false;
            }
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
