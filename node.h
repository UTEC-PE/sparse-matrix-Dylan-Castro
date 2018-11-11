#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
    T data;
    int x, y;
    public:
    void set(int x,int y, T data){
        this->x=x;
        this->y=y;
        this->data=data;
    }
    Node* next;
    Node* down;
};

#endif
