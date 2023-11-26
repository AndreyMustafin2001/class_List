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
    };

    Node* first = nullptr;
    Node* last = nullptr;
public:
    List() = default;

};

int main()
{
    List<int> lst;
    return 0;
}
