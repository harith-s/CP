
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MinMaxStack : public stack<T>
{
private:
    stack<T> min_stack;
    stack<T> max_stack;

public:
    bool isEmpty()
    {
        return stack<T>::empty();
    }
    void push(T a)
    {
        if (min_stack.empty() || a < min_stack.top())
            min_stack.push(a);
        else
            min_stack.push(min_stack.top());
        if (max_stack.empty() || a > max_stack.top())
            max_stack.push(a);
        else
            max_stack.push(max_stack.top());
        stack<T>::push(a);
    }

    void pop()
    {
        if (not(min_stack.empty()))
        {
            min_stack.pop();
            max_stack.pop();
            stack<T>::pop();
        }
    }
    T top()
    {
        return stack<T>::top();
    }
    T max()
    {
        return max_stack.top();
    }
    T min()
    {
        return min_stack.top();
    }
};

int main()
{
    MinMaxStack<int> s1;
    for (int i = 10; i < 100; i = i + 7)
    {
        s1.push(i % 13);
        cout << i % 13 << ",";
    }
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

}