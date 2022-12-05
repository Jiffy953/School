#ifndef NODE_H
#define NODE_H

template<typename T>
class node {
public:
    T data;
    node *next;

    node() {
        next = nullptr;
    }

    node(T data) {
        this->data = data;
        next = nullptr;
    }

    node(T data, node *next) {
        this->data = data;
        this->next = next;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        node::data = data;
    }

    node *getNext() const {
        return next;
    }

    void setNext(node *next) {
        node::next = next;
    }


};


#endif //NODE_H
