#include <iostream>
#include <string>

struct BinSearchThree {
private:
    struct Node{
        std::string fileName;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;
        int val = 1;
    };

public:

    Node *root = nullptr;

    void Insert(Node *X, std::string _data) {
        Node *p = new Node;
        p->fileName = _data;

        if (root == nullptr) {
            root = p;
            return;
        }

        Node *exist = Search(root, _data);
        if (exist != nullptr) {
            exist->val++;
            return;
        }

        while (X != nullptr) {
            if (X->fileName < _data) {
                if (X->right == nullptr) {
                    X->right = p;
                    p->parent = X;
                    return;
                } else {
                    X = X->right;
                }
            } else {
                if (X->left == nullptr) {
                    X->left = p;
                    p->parent = X;
                    return;
                } else {
                    X = X->left;
                }
            }
        }
    }

    Node *Search(Node *X, std::string _data) {
        if (X == nullptr || X->fileName == _data) {
            return X;
        }
        if (_data < X->fileName) {
            return Search(X->left, _data);
        } else {
            return Search(X->right, _data);
        }
    }

    int markValue(std::string _data) {
        Node *p = Search(root, _data);
        switch (p->val) {
            case 3:
                return 0;
                break;
            case 2:
                return 1;
                break;
            case 1:
                return 3;
                break;
        }
    }


};

void FillArray(std::string *arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}


int main() {
    int n;
    std::cin >> n;
    std::string first[n], second[n], third[n];

    FillArray(first, n);
    FillArray(second, n);
    FillArray(third, n);

    BinSearchThree myThree;
    for (int i = 0; i < n; ++i) {
        myThree.Insert(myThree.root, first[i]);
        myThree.Insert(myThree.root, second[i]);
        myThree.Insert(myThree.root, third[i]);
    }

    int points[3] = {};

    for (int i = 0; i < n; ++i) {
        points[0] += myThree.markValue(first[i]);
        points[1] += myThree.markValue(second[i]);
        points[2] += myThree.markValue(third[i]);
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << points[i] << " ";
    }

    return 0;
}
