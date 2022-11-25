#include <iostream>

struct  BinarySearchThree{
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

        if (X == nullptr) {
            root = p;
            return;
        }

        if (Search(root, _data) == nullptr) {
            while (X != nullptr) {   //
                if (p->data > X->data) {
                    if (X->right != nullptr) {
                        X = X->right;
                    } else {
                        p->parent = X;
                        X->right = p;
                        return;
                    }
                } else {
                    if (X->left != nullptr) {
                        X = X->left;
                    } else {
                        p->parent = X;
                        X->left = p;
                        return;
                    }
                }
            }
        }
    }

    Node *Search (Node *X, int _data) {
        if (X == nullptr || X->data == _data) {
            return X;
        }
        if (_data < X->data) {
            return Search(X->left, _data);
        } else {
            return Search(X->right, _data);
        }
    }

    Node *Next(Node *X, int _data) {
        Node *ans = nullptr;
        while (X != nullptr) {
            if (X->data > _data) {
                ans = X;
                X = X->left;
            } else {
                X = X->right;
            }
        }
        return ans;
    }

    Node *Prev(Node *X, int _data) {
        Node *ans = nullptr;
        while (X != nullptr) {
            if (X->data < _data) {
                ans = X;
                X = X->right;
            } else {
                X = X->left;
            }
        }
        return ans;
    }

    void Delete(int _data) {
        Node *p = Search(root, _data);
        if (p == nullptr) return;

        if (p == root) {
            if (p->left == nullptr && p->right == nullptr) {
                root = nullptr;

            } else if (p->left == nullptr || p->right == nullptr) {
                if (p->left == nullptr) {
                    p->right->parent = nullptr;
                    root = p->right;
                } else {
                    p->left->parent = nullptr;
                    root = p->left;
                }

            } else {
                Node *NewRoot = Next(root, root->data);
                NewRoot->left = root->left;
                root->left->parent = NewRoot;
                root = root->right;
                root->parent = nullptr;

            }
            return;
        }

        Node *parent = p->parent;

        if (p->left == nullptr && p->right == nullptr) {
            if (p == parent->right) {
                parent->right = nullptr;
            } else {
                parent->left = nullptr;
            }

        } else if (p->left == nullptr || p->right == nullptr) {
            if (p->left != nullptr) {
                if (p == parent->right) {
                    parent->right = p->left;
                } else {
                    parent->left = p->left;
                }
                p->left->parent = parent;

            } else {
                if (p == parent->right) {
                    parent->right = p->right;
                } else {
                    parent->left = p->right;
                }
                p->right->parent = parent;
            }

        } else {
            Node *next = Next(root, p->data);
            p->data = next->data;
            if (next->parent->left == next) {
                next->parent->left = next->right;
            } else {
                next->parent->right = next->right;
            }
            if (next->right != nullptr) {
                next->right->parent = next->parent;
            }
        }
    }

};

int main() {
    BinarySearchThree myThree;
    while (!std::cin.eof()) {
        std::string commands[5] = {"insert", "delete", "exists", "next", "prev"};
        char input_command[10];
        int val;
        std::cin >> input_command >> val;

        if (input_command == commands[0]) {
            myThree.Insert(myThree.root, val);

        } else if (input_command == commands[1]) {
            myThree.Delete(val);

        } else if (input_command == commands[2]) {
            if (myThree.Search(myThree.root, val) != nullptr) {
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }

        } else if (input_command == commands[3]) {
            if (myThree.Next(myThree.root, val) != nullptr) {
                std::cout << myThree.Next(myThree.root, val)->data << "\n";
            } else {
                std::cout << "none\n";
            }

        } else if (input_command == commands[4]) {
            if (myThree.Prev(myThree.root, val) != nullptr) {
                std::cout << myThree.Prev(myThree.root, val)->data << "\n";
            } else {
                std::cout << "none\n";
            }
        }
    }
    return 0;
}