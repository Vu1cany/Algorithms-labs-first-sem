#include <iostream>

using std::cin;
using std::cout;
using std::max;

struct AVLThree {
private:
    struct Node {    //Структура узла
        int key = 0;
        int height = 1;
        Node *leftChild = nullptr;
        Node *rightChild = nullptr;

        Node(int k) { key = k; }
    };

    int Height(Node *p) {  //Для поулчения высоты конкретного узла
        if (p == nullptr) {
            return 0;
        } else {
            return p->height;
        }
    }

    void NewHeight(Node *p) {    //Восстановаление высоты поддерева в узле
        int left = Height(p->leftChild);
        int right = Height(p->rightChild);
        p->height = max(left, right) + 1;
    }

    Node *RR(Node *p) {    //Правый поворот вокруг p
        Node *q = p->leftChild;
        p->leftChild = q->rightChild;
        q->rightChild = p;
        NewHeight(p);
        NewHeight(q);
        return q;
    }

    Node *RL(Node *q) {     // левый поворот вокруг q
        Node *p = q->rightChild;
        q->rightChild = p->leftChild;
        p->leftChild = q;
        NewHeight(q);
        NewHeight(p);
        return p;
    }

    Node *Balance(Node *p) {    //Балансировка узла
        NewHeight(p);
        if (BalanceFactor(p) == 2) {
            if (BalanceFactor(p->rightChild) < 0) {
                p->rightChild = RR(p->rightChild);
            }
            return RL(p);
        }
        if (BalanceFactor(p) == -2) {
            if (BalanceFactor(p->leftChild) > 0) {
                p->leftChild = RL(p->leftChild);
            }
            return RR(p);
        }
        return p; // Если балансировка не нужна
    }

    Node* Insert(Node* p, int k) {  //вставка нового ключа

        if(p == nullptr) return new Node(k);

        if(k < p->key) {
            p->leftChild = Insert(p->leftChild,k);
        } else {
            p->rightChild = Insert(p->rightChild,k);
        }
        return Balance(p);
    }




    Node *FindMax(Node *p) {    //поиск узла с наибольним ключом в дереве p
        if (p->rightChild == nullptr) {
            return p;
        } else {
            return FindMax(p->rightChild);
        }
    }

    Node *DeleteMax(Node *p) {     // удаление узла с минимальным ключом из дерева p
        if (p->rightChild == nullptr) {
            return p->leftChild;
        } else {
            p->rightChild = DeleteMax(p->rightChild);
        }
        return Balance(p);
    }



public:

    int BalanceFactor(Node *p) {   //Возвращает баланс для конкретного узла
        return Height(p->rightChild) - Height(p->leftChild);
    }

    Node *root = nullptr;

    Node *InsertExists(int k) {
        Node *exist = Search(root, k);
        if (exist != nullptr) {
            return root;
        } else {
            return Insert(root, k);
        }
    }

    Node *Search(Node *X, int k) {
        if (X == nullptr || X->key == k) {
            return X;
        }
        if (k < X->key) {
            return Search(X->leftChild, k);
        } else {
            return Search(X->rightChild, k);
        }
    }

    Node *Delete(Node *p, int k) {  // удаление ключа k из дерева p
        if (Search(root, k) == nullptr) return root;

        if (p == nullptr) {
            return p;

        } else if (k < p->key) {
            p->leftChild = Delete(p->leftChild, k);

        } else if (k > p->key) {
            p->rightChild = Delete(p->rightChild, k);

        } else if (p->rightChild == nullptr && p->leftChild == nullptr) {
            p = nullptr;

        } else {
            if (p->leftChild != nullptr && p->rightChild != nullptr) {
                Node *l = p->leftChild;
                p->key = FindMax(l)->key;
                p->leftChild = Delete(l, p->key);

            } else if (p->rightChild == nullptr) {
                p = p->leftChild;

            } else if (p->leftChild == nullptr) {
                p = p->rightChild;
            }
        }

        if (p == nullptr) {
            return p;
        }

        return Balance(p);
    }

};

int main() {
    AVLThree three;
    int n;
    cin >> n;
    if (n == 0) {
        //cout << 0;
        return 0;
    }
    char operation;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> operation >> x;
        switch (operation) {
            case 'A':
                three.root = three.InsertExists(x);
                if (three.root == nullptr) {
                    cout << 0 << "\n";
                } else {
                    cout << three.BalanceFactor(three.root) << "\n";
                }
                break;
            case 'D':
                three.root = three.Delete(three.root, x);
                if (three.root == nullptr) {
                    cout << 0 << "\n";
                } else {
                    cout << three.BalanceFactor(three.root) << "\n";
                }
                break;
            case 'C':
                if (three.Search(three.root, x) != nullptr) {
                    cout << "Y\n";
                } else {
                    cout << "N\n";
                }
                break;
        }
    }
    return 0;
};