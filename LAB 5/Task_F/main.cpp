#include <iostream>

struct  BinarySearchThree{
private:

    struct Node{
        int data;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;
    };

    Node *Max(Node *X, int current) {
        Node *maximum = new Node;
        maximum = X;
        while (X != root) {
            if (X->parent->data < current) {
                X = X->parent;
                if (maximum->data < X->data) {
                    maximum = X;
                }
            } else {
                break;
            }
        }
        return maximum;
    }

public:

    Node *root = nullptr;

    void FillThree(int *arr, int n) {
        Node *arrAddress[n];

        root = new Node;

        root->data = arr[0];
        arrAddress[arr[0]] = root;
        for (int i = 1; i < n; ++i) {
            Node *p = new Node;
            p->data = arr[i];
            if (arr[i] < arr[i - 1]) {
                arrAddress[arr[i - 1]]->left = p;
                p->parent = arrAddress[arr[i - 1]];
                arrAddress[arr[i]] = p;
            } else {
                Node *parent = Max(arrAddress[arr[i - 1]], arr[i]);
                parent->right = p;
                p->parent = parent;
                arrAddress[arr[i]] = p;
            }
        }
    }

    void PostorderTraversal(Node *X) {
        if (X != nullptr) {
            PostorderTraversal(X->left);
            PostorderTraversal(X->right);
            std::cout << X->data << " ";
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    BinarySearchThree myThree;
    myThree.FillThree(array, n);

    myThree.PostorderTraversal(myThree.root);

    return 0;
}