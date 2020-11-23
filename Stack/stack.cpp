#include <iostream>
using namespace std;
#define newl cout << "\n";

template <typename T>
struct node
{
    T data;
    node *prev;
    node(T num)
    {
        data = num;
        prev = nullptr;
    }
};

template <typename T>
class stack
{
private:
    node<T> *front = nullptr;
    int size = 0;

public:
    bool isEmpty()
    {
        return (front == nullptr);
    }
    void push(T data)
    {
        node<T> *temp = new node<T>(data);
        temp->prev = front;
        front = temp;
        size++;
    }
    T peek()
    {
        if (front == nullptr)
        {
            cout << "sorry! today's stack stock is empty\n";
            return -1;
        }
        return front->data;
    }
    void pop()
    {
        node<T> *temp = front;
        if (front == nullptr)
        {
            return;
        }
        else
        {
            size--;
            front = front->prev;
            delete temp;
        }
    }
};

int main()
{
    stack<double> st;
    st.push(21.324);
    st.push(12.324);
    st.push(92.324);
    int top = 0;
    while (!st.isEmpty())
    {
        top++;
        if (top >= 2)
        {
            cout << top << " last element is : " << st.peek() << "\n";
        }
        else
        {
            cout << "stack top is : " << st.peek() << "\n";
        }
        st.pop();
    }
}