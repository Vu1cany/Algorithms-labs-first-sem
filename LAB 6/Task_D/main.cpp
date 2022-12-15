#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::max;
using std::string;

struct AVLThree{
private:
    struct Node{    //Структура узла
        string fileName;
        int val = 1;
        int height = 1;
        int mark = 3;
        Node *leftChild = nullptr;
        Node *rightChild = nullptr;
        Node(string name) {fileName = name;}
    };

    int Height(Node* p){  //Для поулчения высоты конкретного узла
        if (p == nullptr) {
            return 0;
        } else {
            return p->height;
        }
    }

    int BalanceFactor(Node* p){   //Возвращает баланс для конкретного узла
        return Height(p->rightChild) - Height(p->leftChild);
    }

    void NewHeight(Node* p){    //Восстановаление высоты поддерева в узле
        int left = Height(p->leftChild);
        int right = Height(p->rightChild);
        p->height = max(left, right) + 1;
    }

    Node* RR(Node* p) {    //Правый поворот вокруг p
        Node* q = p->leftChild;
        p->leftChild = q->rightChild;
        q->rightChild = p;
        NewHeight(p);
        NewHeight(q);
        return q;
    }

    Node* RL(Node* q) {     // левый поворот вокруг q
        Node* p = q->rightChild;
        q->rightChild = p->leftChild;
        p->leftChild = q;
        NewHeight(q);
        NewHeight(p);
        return p;
    }

    Node* Balance(Node* p) {    //Балансировка узла
        NewHeight(p);
        if(BalanceFactor(p) == 2) {
            if(BalanceFactor(p->rightChild) < 0) {
                p->rightChild = RR(p->rightChild);
            }
            return RL(p);
        }
        if(BalanceFactor(p) == -2) {
            if(BalanceFactor(p->leftChild) > 0) {
                p->leftChild = RL(p->leftChild);
            }
            return RR(p);
        }
        return p; // Если балансировка не нужна
    }


    Node* Insert(Node* p, string name) {  //вставка нового ключа



        if(p == nullptr) return new Node(name);

        if(name < p->fileName) {
            p->leftChild = Insert(p->leftChild,name);
        } else {
            p->rightChild = Insert(p->rightChild,name);
        }
        return Balance(p);
    }

public:

    Node *InsertExists(string name) {
        Node *exist = Search(root, name);
        if (exist != nullptr) {
            exist->val++;

            if (exist->val == 2) {
                exist->mark = 1;
            } else if (exist->val == 3) {
                exist->mark = 0;
            }
            return root;
        } else {
            return Insert(root, name);
        }
    }

    Node *root = nullptr;

    Node *Search(Node *X, std::string name) {
        if (X == nullptr || X->fileName == name) {
            return X;
        }
        if (name < X->fileName) {
            return Search(X->leftChild, name);
        } else {
            return Search(X->rightChild, name);
        }
    }
};

void FillArray(std::string *arr, int n, AVLThree &myThree) {
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        myThree.root = myThree.InsertExists(arr[i]);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::string first[n], second[n], third[n];

    AVLThree myThree;

    FillArray(first, n, myThree);
    FillArray(second, n, myThree);
    FillArray(third, n, myThree);

    int points[3] = {};

    for (int i = 0; i < n; ++i) {
        points[0] += myThree.Search(myThree.root, first[i])->mark;
        points[1] += myThree.Search(myThree.root, second[i])->mark;
        points[2] += myThree.Search(myThree.root, third[i])->mark;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << points[i] << " ";
    }

    return 0;
}