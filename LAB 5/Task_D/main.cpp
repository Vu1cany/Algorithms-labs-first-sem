#include <iostream>

struct BinarySearchThree{
private:

    struct Node{
        int data;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;
    };

public:

    Node *root = nullptr;

    void Insert(Node *X,int _data) {
        Node *p = new Node;
        p->data = _data;
        while (X != nullptr) {   //
            if (p->data > X->data) {
                if (X->right != nullptr) {
                    X = X->right;
                } else {
                    X->right = p;
                    p->parent = X;
                    break;
                }
            } else {
                if (X->left != nullptr) {
                    X = X->left;
                } else {
                    X->left = p;
                    p->parent = X;
                    break;
                }
            }
        }
    }

    Node Search (Node *X,int _data) {
        if (X != nullptr || X->data == _data) {
            return *X;
        } else if (_data < X->data) {
            return Search(X->left, _data);
        } else {
            return Search(X->right, _data);
        }
    }

    void Next() {

    }

    void Prev() {

    }

    void Delete() {

    }

};

int main() {
    BinarySearchThree myThree;
    std::cout << ;
    return 0;
}