#include <iostream>
#include <string>

struct My_stack{
    struct Node{
        int data;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    Node *first = nullptr;
    Node *last = nullptr;

    bool IsEmpty() {
        return first == nullptr;
    }

    void Push(int _data) {
        Node *p = new Node;
        p->data = _data;
        if (IsEmpty()) {
            first = p;
            last = p;
            return;
        }
        p->prev = last;
        last->next = p;
        last = p;
    }

    int GetData() {
        if (IsEmpty()) return 0;
        return last->data;
    }

    void Pop() {
        if (IsEmpty()) return;
        if (first == last) {
            first = nullptr;
            last = nullptr;
            return;
        }
        Node *p = last;
        last = p->prev;
    }
};

int Result(std::string s1) {
    My_stack stk;
    for (char symbol: s1) {
        if (symbol == ' ') continue;
        if (symbol != '+' && symbol != '-' && symbol != '*') {
            stk.Push(symbol-'0');
            continue;
        }

        int a = stk.GetData();
        stk.Pop();
        int b = stk.GetData();
        stk.Pop();

        switch (symbol) {
            case '+':
                stk.Push(a + b);
                break;

            case '-':
                stk.Push(b - a);
                break;

            case '*':
                stk.Push(a*b);
                break;
        }
    }
    return stk.GetData();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1;
    std::getline(std::cin, s1);
    std::cout << Result(s1);
    return 0;
}