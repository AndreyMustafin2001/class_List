#include <iostream>

template<typename T>
class List
{
private:
    struct Node
    {
        T elem;
        Node* prev;
        Node* next;
        // Constructor for initialization node with value
        Node(T value) : elem(value), next(nullptr), prev(nullptr) {}
    };

    Node* first = nullptr;
    Node* last = nullptr;

public:

    List() = default;

     void PushBack(const T elem)
    {
        Node* node = new Node(elem);

        if (!first)
        {
            first = last = node;    //If list is empty , set first and last node the new node
        }
        else
        {
            node->prev = last;
            last->next = node;
            last = node;
        }
    }

    void PushFront(const T elem)
    {
        Node* node = new Node(elem);

        if (!first)
        {
            first = last = node;  // If list is empty , set first and last node the new node
        }
        else
        {
            node->next = first;
            first->prev = node;
            first = node;
        }

    }
    //Move to first node
    const T& Front()const
    {
        return first->elem;
    }
    //Move to last node
    const T& Back()const
    {
        return last->elem;
    }
};

int main()
{
    List<int> lst;

    lst.PushFront(1);

    std::cout << lst.Front() << "\n";

    lst.PushBack(2);

    std::cout << lst.Back() << "\n";

    return 0;
}
