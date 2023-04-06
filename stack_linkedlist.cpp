#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << "Element popped: " << temp->data << endl;
        delete temp;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Empty stack!" << endl;
            return;
        }
        Node *ptr = top;
        cout << "Elements: ";
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    int ch, val;

    stack.push(8);
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);

    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    stack.display();

    stack.push(4);
    stack.push(30);
    stack.push(3);
    stack.push(1);

    stack.display();

    return 0;
}