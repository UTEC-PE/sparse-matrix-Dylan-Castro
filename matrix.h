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
            Node<T>** fila= &hRows;
            Node<T>** columna= &hColumns;
            Node<T>** nodo_x_anterior;
            Node<T>** nodo_y_anterior;
            for(int i=0;i<x;i++){
                fila=&(*fila)->down;
            }
            columna=fila;
            do{
                nodo_y_anterior=columna;
                if((*columna)->next==nullptr){
                    break;
                }
                columna=&(*columna)->next;
            }
            while((*columna)->y < y);

            columna= &hColumns;
            for(int i=0;i<y;i++){
                columna=&(*columna)->next;
            }
            fila=columna;
            do{
                nodo_x_anterior=fila;
                if((*fila)->down==nullptr){
                    break;
                }
                fila=&(*fila)->down;
            }
            while((*fila)->x < x);

            if(data==0){
                Node<T>* temp= (*nodo_x_anterior)->down;
                (*nodo_x_anterior)->down= (*nodo_x_anterior)->down->down;
                (*nodo_y_anterior)->next= (*nodo_y_anterior)->next->next;
                delete temp;
                return;
            }
            Node<T>* nodo=new Node<T>;
            nodo->set(x,y,data);
            nodo->next=(*nodo_y_anterior)->next;
            nodo->down=(*nodo_x_anterior)->down;
            (*nodo_y_anterior)->next=nodo;
            (*nodo_x_anterior)->down=nodo;
        };

        void print(){
            cout << hColumns->next->next->next->next->down->get();
            cout << hColumns->down->get();
            cout << hColumns->down->down->get();
            cout << hColumns->down->down->down->get();
            cout << hColumns->down->down->down->down->get();
            cout << hColumns->down->down->down->down->down->get();
        }
        T operator()(int x, int y){
             Node<T>** fila= &hRows;
            Node<T>** columna= &hColumns;
            for(int i=0;i<x;i++){
                fila=&(*fila)->down;
            }
            columna=fila;
            do{
                if((*columna)->next==nullptr){
                    break;
                }
                columna=&(*columna)->next;
            }
            while((*columna)->y < y);

            if((*columna)->y==y){
                return (*columna)->get();
            }
            else{
                return false;
            }
        };
        Matrix<T> operator*(Matrix<T> other);
        Matrix<T> operator*(T scalar){
            for(int x=0;x<5;x++){
                for(int y=0;y<5;y++){
                    if(this->operator()(x,y)!=0){
                        set(x,y,this->operator()(x,y)*scalar);
                    }
                }
            }
        };
        Matrix<T> operator+(Matrix<T> other){
            Matrix<int> c(5,5);
            int suma=0;
            for(int x=0;x<5;x++){
                for(int y=0;y<5;y++){
                    if(this->operator()(x,y)!=0 || other.operator()(x,y)!=0){
                        c.set(x,y,this->operator()(x,y)+ other.operator()(x,y));
                    }
                }
            }
            return c;
        };
        Matrix<T> operator-(Matrix<T> other){
            Matrix<int> c(5,5);
            int resta=0;
            for(int x=0;x<5;x++){
                for(int y=0;y<5;y++){
                    if(this->operator()(x,y)!=0 || other.operator()(x,y)!=0){
                        c.set(x,y,this->operator()(x,y) - other.operator()(x,y));
                    }
                }
            }
            return c;
        };
        Matrix<T> transposed(){
            Matrix<T> temp(rows,columns);
            for(int x=0;x<rows;x++){
                for(int y=0;y<columns;y++){
                    if(this->operator()(x,y)!=0){
                        temp.set(y,x,this->operator()(x,y));
                    }
                }
            }
            return temp;
        };
        Matrix<T> operator=(Matrix<T> other){
            for(int x=0;x<5;x++){
                for(int y=0;y<5;y++){
                    set(x,y,0);
                }
            }
            for(int x=0;x<5;x++){
                for(int y=0;y<5;y++){
                    if(other.operator()(x,y)!=0){
                        set(x,y,other.operator()(x,y));
                    }
                }
            }
            return *this;
        };
        //~Matrix();
};
#endif
