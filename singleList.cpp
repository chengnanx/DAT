#include <iostream>
using namespace std;
typedef int ElementType;

class List
{
    private:
        class Node
        {
            public:
                ElementType data;
                Node *next;
                Node():next(0){};

                Node(ElementType dataValue): data(dataValue), next(0){};
        };
        typedef Node * NodePointer;
    
    public:
        List();
        List(const List &origList);
        ~List();
        const List & operator=(const List & rightSide);
        bool empty();
        void insert(ElementType dataVal, int index);
        void erase(int index);
        int search(ElementType dataval);
        void display() const;
        int nodeCount();
        void reverse();
        bool ascendingOrder();

    
    private:
        NodePointer first;
        int mySize;
};

ostream & operator<<(ostream &out, const List &aList);
istream & operator>>(istream &in, List &aList);

List::List()
:first(0), mySize(0)
{
}

List::List(const List &origList)
{
    mySize = origList.mySize;
    first = 0;
    if (mySize == 0) return;

    NodePointer origPtr, lastPtr;
    first = new Node(origList.first->data);
    //cout << origList.first->data << endl;
    lastPtr = first;
    origPtr = origList.first->next;
    while (origPtr != 0)
    {
        lastPtr->next = new Node(origPtr->data);
        origPtr = origPtr->next;
        lastPtr= lastPtr->next;
    }
}

inline List::~List()
{
    NodePointer prev = first, ptr;
    while (prev != 0)
    {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}


bool List::empty()
{
    cout << "*** The list is empty ***" << endl;
    return mySize == 0;
}

const List & List::operator=(const List & rightSide)
{
    mySize = rightSide.mySize;
    first = 0;
    if (mySize == 0) return *this;

    if (this != &rightSide)
    {
        this->~List();
        NodePointer origPtr, lastPtr;
        first = new Node(rightSide.first->data);
        lastPtr = first;
        origPtr = rightSide.first->next;
        while (origPtr != 0)
        {
            lastPtr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            lastPtr = lastPtr->next;
        } 
    }
    return *this;   
}

void List::insert(ElementType dataVal, int index)
{
    if (index < 0 || index >mySize)
    {
        cout << "--Illeage location to insert --" << endl;
        return;
    }
    mySize++;
    NodePointer newPtr = new Node(dataVal),
                predPtr = first;
    if (index == 0)
    {
        newPtr->next = first;
        first = newPtr;
    }
    else
    {
        for (int i = 1; i < index; i++)
            predPtr = predPtr->next;
        newPtr->next = predPtr->next;
        predPtr->next = newPtr;
    } 
}

void List::erase(int index)
{
    if (index < 0 || index >= mySize)
    {
        cout << "--Illegal location to delete--" << index << endl;
        return;
    }
    mySize--;
    NodePointer ptr,
                predPtr = first;
    if (index = 0)
    {
        ptr == first;
        first = ptr->next;
        delete ptr;
    }
    else
    {
        for (int i = 1; i < index; i++)
            predPtr = predPtr->next;
        ptr = predPtr->next;
        predPtr->next = ptr->next;
        delete ptr;
    }
    
}

int List::search(ElementType dataVal)
{
    int loc;
    NodePointer tempP =first;
    for (loc = 0; loc < mySize; loc++)
        if (tempP->data == dataVal)
            return loc;
        else
            tempP = tempP->next;
    return -1;    
}

int List::nodeCount()
{
    return mySize;
}

void List::reverse()
{
    NodePointer prevP = 0,
                currentP = first,
                nextP ;
    
    while (currentP != 0)
    {
        nextP = currentP->next;
        currentP->next = prevP; 
        prevP = currentP;
        currentP = nextP;
    }
    first = prevP;
}

bool List::ascendingOrder()
{
    if (mySize <= 1)
        return true;
    NodePointer prevP = first,
                tempP = first->next;
    
    while (tempP != 0 && prevP->data <= tempP->data)
    {
        prevP = tempP;
        tempP = tempP->next;
    }
    if(tempP != 0 )
        return false;
    else
        return true;    
}

void List::display() const
{
    NodePointer ptr = first;
    while (ptr != 0)
    {
        cout << ptr->data <<"  "<<endl;
        ptr = ptr->next;
    }
}

