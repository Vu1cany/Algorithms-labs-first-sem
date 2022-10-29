#include <iostream>
#include <string>

struct My_stack {
    struct Node{
        char data;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    Node *first = nullptr;
    Node *last = nullptr;

    bool empty() {
        return first == nullptr;
    }

    void push(char _data) {
        Node *p = new Node;
        p->data = _data;
        if (empty()) {
            first = p;
            last = p;
            return;
        } else {
            last->next = p;
            p->prev = last;
            last = p;
        }
    }

    char get_last_data() {
        if (empty()) return 0;
        return last->data;
    }

    void pop() {
        if (empty()) return;
        if (last == first) {
            Node *p = first;
            last = nullptr;
            first = nullptr;
            return;
        }
        Node *p = last;
        last = p->prev;
    }
};

bool Cor_Brack_seq(std::string string) {
    My_stack Close_brackets;
    for (int i = 0; i < size(string); ++i) {
        char bracket = string[i];
        if (bracket == '(' || bracket == '[') {
            Close_brackets.push(bracket);
            continue;
        }

        if (bracket == ')') {
            if (Close_brackets.get_last_data() == '(') {
                Close_brackets.pop();
            } else {
                return false;
            }
        } else {
            if (Close_brackets.get_last_data() == '[') {
                Close_brackets.pop();
            } else {
                return false;
            }
        }
    }

    if (Close_brackets.empty()) {
        return true;
    } else return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (true) {
        std::string s1;
        std::getline(std::cin,s1);
        if (s1 == "") break;
        if (Cor_Brack_seq(s1)) {
            std::cout << "YES" << "\n";
        } else std::cout << "NO" << "\n";

    }
    return 0;
}