#include <iostream>
#include <array>
#include <chrono>

constexpr int LENGTH = 20;

using namespace std;
using namespace std::chrono;

class Stack
{
private:
    array<int, LENGTH> data;
    int topIndex = -1;

public:
    void push(int x)
    {
        if (topIndex == LENGTH - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        topIndex++;
        data[topIndex] = x;
    }

    int pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack Underflow\n";
            exit(1);
        }
        int value = data[topIndex];
        topIndex--;
        return value;
    }

    void display()
    {
        if (topIndex == -1)
        {
            cout << "Empty stack\n";
            return;
        }
        for (int i = 0; i <= topIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    auto start = high_resolution_clock::now();

    Stack stack;

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

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}