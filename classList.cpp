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

    int elementsCount = 0;

public:

    List() = default;

    List(const List& lst) //  Copy constructor
    {
        Node* temp = lst.first;
        while (temp != nullptr)
        {
            PushBack(temp->elem); // Copy each element into new list
            temp = temp->next;
        }

    }
    //Operator= overloading
    List& operator=(const List& temp)
    {
        if (this != &temp)
        {

            clear();

            Node* temp = temp.first;
            while (temp)
            {
                PushBack(temp->elem);
                temp = temp->next;
            }
        }
        return *this;
    }

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
        ++elementsCount;
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
        ++elementsCount;

    }

    void PopBack()
    {
        if (last != nullptr)
        {
            Node* temp = last;
            last = last->prev;

            if (last != nullptr)
            {
                last->next = nullptr;
            }

            else
            {
                first = nullptr;
            }

            delete temp;
            elementsCount--;
        }
    }

    void PopFront()
    {
        if (first != nullptr)
        {
            Node* temp = first;
            first = first->next;

            if (first != nullptr)
            {
                first->prev = nullptr;
            }
            else
            {
                last = nullptr;
            }
            delete temp;
            elementsCount--;
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
    //Get size of a list
    size_t GetSize()const
    {
        return elementsCount;
    }
    //Check if node is empty
    bool Empty()const
    {
        return first == nullptr;
    }

    void clear()
    {
        while (first)
        {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
        last = nullptr;
    }
};

int main()
{
    List<int> lst;

    lst.PushFront(1);
    lst.PushBack(7);
    lst.PushFront(2);
    lst.PushFront(3);
    lst.PushFront(5);

    List<int> newLst(lst);

    lst.PushBack(8);

    List<int> otherLst = lst;

    std::cout << "lst list: " << std::endl;
    while (!lst.Empty())
    {
        std::cout << lst.Front() << " ";
        lst.PopFront();
    }

    std::cout << std::endl << "newLst list: " << std::endl;
    while (!newLst.Empty())
    {
        std::cout << newLst.Front() << " ";
        newLst.PopFront();
    }
    std::cout << std::endl << "otherLst list: " << std::endl;
    while (!otherLst.Empty())
    {
        std::cout << otherLst.Front() << " ";
        otherLst.PopFront();
    }

    return 0;
}
