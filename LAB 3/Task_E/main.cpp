#include <iostream>
#include <string>

struct myStack{
    struct Node {
        int data;
        int max_data;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    Node *first = nullptr;
    Node *last = nullptr;

    bool empty() {
        return first == nullptr;
    }

    void add(int _data) {
        Node *p = new Node;
        p->data = _data;
        if (empty()) {
            p->next = p;
            p->prev = p;
            first = p;
            first->max_data = _data;
            last = p;
            return;
        }
        last->next = p;
        p->prev = last;
        p->next = nullptr;
        p->max_data = std::max(p->data, last->max_data);
        last = p;
    }

    void delLast() {
        if (empty()) return;
        if (last == first) {
            first = nullptr;
            last = nullptr;
            return;
        }
        Node *p = last;
        last = p->prev;
        last-> next = nullptr;
        delete p;
    }

    int max() {
        return last->max_data;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int value;
    std::string command;
    myStack stack1;
    for (int i = 0; i < n; ++i) {
        std::cin >> command;
        if (command == "+") {
            std::cin >> value;
            stack1.add(value);
        } else if (command == "-") {
            stack1.delLast();
        } else if (command == "max") {
            std::cout << stack1.max() << "\n";
        }
    }
    return 0;
}
