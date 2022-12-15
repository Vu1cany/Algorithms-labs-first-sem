#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::max;
using std::string;

struct AVLThree {
private:
    struct Node {    //Структура узла
        string key;
        int height = 1;
        Node *leftChild = nullptr;
        Node *rightChild = nullptr;

        Node(string k) { key = k; }
    };

    int Height(Node *p) {  //Для поулчения высоты конкретного узла
        if (p == nullptr) {
            return 0;
        } else {
            return p->height;
        }
    }

    int BalanceFactor(Node *p) {   //Возвращает баланс для конкретного узла
        return Height(p->rightChild) - Height(p->leftChild);
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

    Node* Insert(Node* p, string k) {  //вставка нового ключа

        if(p == nullptr) return new Node(k);

        if(k < p->key) {
            p->leftChild = Insert(p->leftChild,k);
        } else {
            p->rightChild = Insert(p->rightChild,k);
        }
        return Balance(p);
    }

    bool RepeatSymbol(string s, int i) {
        for (int j = i + 1; j < s.length(); ++j) {
            if (s[i] == s[j]) {
                return 0;
            }
        }
        return 1;
    }

    Node *Search(Node *X, string k) {
        if (X == nullptr || X->key == k) {
            return X;
        }
        if (k < X->key) {
            return Search(X->leftChild, k);
        } else {
            return Search(X->rightChild, k);
        }
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

    Node *Delete(Node *p, string k) {  // удаление ключа k из дерева p
        //if (Search(root, k) == nullptr) return root;

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

public:
    Node *InsertExists(string k, int &count) {
        Node *exist = Search(root, k);
        if (exist != nullptr) {
            bool different = false;
            int l = k.length();
            for (int i = 0; i < l; ++i) {
                count += RepeatSymbol(k, i);
            }

            return root;
        } else {
            return Insert(root, k);
        }
    }


    Node *root = nullptr;
};

int main() {
    int n;
    cin >> n;
    string arr[n];
    AVLThree myThree;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        myThree.root = myThree.InsertExists(arr[i], count);
    }

    cout << count;

    return 0;
}
