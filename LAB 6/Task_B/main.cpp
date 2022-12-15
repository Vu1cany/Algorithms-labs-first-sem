#include <iostream>

using std::cin;
using std::cout;
using std::max;

struct Node{    //Структура узла
    int key = 0;
    int index = 0;
    int height = 0;
    Node *leftChild = nullptr;
    Node *rightChild = nullptr;
};

struct AVLThree{
private:
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

public:
    void NewHeight(Node* p){    //Восстановаление высоты поддерева в узле
        if (p->leftChild != nullptr) {
            NewHeight(p->leftChild);
        }
        if (p->rightChild != nullptr) {
            NewHeight(p->rightChild);
        }
        int left = Height(p->leftChild);
        int right = Height(p->rightChild);
        p->height = max(left, right) + 1;
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

    void PreOrderIndex(Node *p, int &count) {
        if (p == nullptr) return;
        count++;
        p->index = count;
        PreOrderIndex(p->leftChild, count);
        PreOrderIndex(p->rightChild, count);
    }

    void PreOrderPrint(Node *p) {
        if (p == nullptr) return;
        int left;
        int right;

        if (p->leftChild == nullptr) {
            left = 0;
        } else {
            left = p->leftChild->index;
        }

        if (p->rightChild == nullptr) {
            right = 0;
        } else {
            right = p->rightChild->index;
        }
        cout << p->key << " " << left << " " << right << "\n";
        PreOrderPrint(p->leftChild);
        PreOrderPrint(p->rightChild);
    }

};

int main() {
    int n;
    cin >> n;
    AVLThree myAVL;
    Node arr[n];
    int left, right;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].key >> left >> right;

        if (left == 0) {
            arr[i].leftChild = nullptr;

        } else {
            arr[i].leftChild = &arr[left - 1];
        }

        if (right == 0) {
            arr[i].rightChild = nullptr;

        } else {
            arr[i].rightChild = &arr[right - 1];
        }
    }

    int count = 0;
    Node *root = &arr[0];
    myAVL.NewHeight(root);
    root = myAVL.Balance(root);
    myAVL.PreOrderIndex(root, count);
    cout << n << "\n";
    myAVL.PreOrderPrint(root);

    return 0;
}
