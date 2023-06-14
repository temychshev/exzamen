#include <iostream>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
public:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
};

void fillStack(Stack& stack, int count) {
    for (int i = 0; i < count; i++) {
        stack.push(rand() % 100);
    }
}

void printStack(Stack& stack) {
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;
}

void mergeStacks(Stack& stack, Stack& stack1, Stack& stack2) {
    while (!stack1.isEmpty()) {
        int value = stack1.pop();
        Node* temp = stack2.top;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == value) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            stack.push(value);
        }
    }
    while (!stack2.isEmpty()) {
        int value = stack2.pop();
        Node* temp = stack1.top;
        bool found = false;
        while (temp != nullptr) {
            if (temp->data == value) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found) {
            stack.push(value);
        }
    }
}

int main() {
    srand(time(nullptr));
    Stack stack1, stack2, stack;
    fillStack(stack1, 50);
    fillStack(stack2, 50);
    mergeStacks(stack, stack1, stack2);
    printStack(stack);
    return 0;
}