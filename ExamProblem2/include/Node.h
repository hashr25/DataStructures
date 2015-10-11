#ifndef NODE_H
#define NODE_H

#include <stdlib.h> //NULL


class Node
{
    public:
        Node(char);

        char getValue();
        void setValue(char);

        Node* getNext();
        void setNext(Node*);


    private:
        char value;
        Node* next;
};

#endif // NODE_H
