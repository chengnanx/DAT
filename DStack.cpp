#include <iostream>
#include <assert.h>
using namespace std;

template <typename StackElement>
class DStack
{
    public:
        DStack(int numElements = 128);
        DStack(const DStack<StackElement> & original);
        ~DStack();
        const DStack &operator=(const DStack<StackElement> &rightHandSide);
        bool empty() const;
        void push(const StackElement &value);
        void display(ostream &out) const;
        StackElement top() const;
        void pop();

    private:
        int myCapacity,
            myTop;
        StackElement *myArray;
};

template <typename StackElement>
DStack<StackElement>::~DStack()
{
    delete[] myArray;

}

template <typename StackElement>
DStack<StackElement>::DStack(int numElements)
{
    assert (numElements > 0);
    myCapacity =  numElements;
    myArray = new(nothrow) DStackElement[myCapacity];
    if (myArray != 0)
        myTop = -1;
    else
    {
        cout << "Inadequate memory to allocate DStack \n";
        exit(1);
    }
}

template <typename StackElement>
DStack<StackElement>::DStack(const DStack<StackElement> & original)
:myCapacity(original.myCapacity), myTop(original.myTop)
{
    myArray = new(nothrow) DStackElement[myCapacity];
    if (myArray != 0)
        for ( int pos = 0; pos <= myTop; pos++)
            myArray[pos] = original.myArray[pos];
    else
    {
        cout << "Indequate memory to allocate DStack \n";
        exit(1);
    }    
 }
template <typename StackElement>
const DStack<StackElement> &DStack<StackElement>::operator=(const DStack<StackElement> &rightHandSide)
 {
     if (this != & rightHandSide)
     {
         if (myCapacity != rightHandSide.myCapacity)
         {
             delete [] myArray;

             myCapacity = rightHandSide.myCapacity;
             myArray = new DStackElement[myCapacity];
             if (myArray == 0)
             {
                 cout << "*** Inadequate memory ***\n";
             }
         }
         myTop = rightHandSide.myTop;
         for (int pos = 0; pos <= myTop; pos++)
            myArray[pos] = rightHandSide.myArray[pos];   
     }
 }

template <typename StackElement>
bool DStack<StackElement>::empty() const
{
    return (myTop == -1);
}

template <typename StackElement>
void DStack<StackElement>::push(const StackElement & value)
{
    if (myTop < myCapacity - 1)
    {
        ++myTop;
        myArray[myTop] = value;
    }
    else 
    {
        cout << "*** DStack full --- can't add new value ***" << endl;
        exit(-1);
    }
}

template <typename StackElement>
 void DStack<StackElement>::display(ostream &out) const
{
    for (int i = myTop; i >= 0; i--)
    {
        cout << myArray[i] << endl;
    }
}

template <typename StackElement>
StackElement DStack<StackElement>::top() const
{   
    if (!empty())
    {
        return (myArray[myTop]);
    }
    else
    {
        cout << "*** DStack is empty ***" << endl;
        DStackElement garbage;
        return garbage;
    }
}

template <typename StackElement>
void DStack<StackElement>::pop()
{
    if (empty())
    {
        cout << "*** DStack is empty ***" << endl;
    }
    else
    {
        --myTop;
    }
}

int main()
{
    int cap;
    cout << "Enter stack capacity: ";
    cin >> cap;
    // DStack p(cap);
    DStack<int> s(cap);

   
    cout << "Stack created. Empty? " << boolalpha << s.empty() << endl;
    cout << "******************************" << endl;

    cout << "How many elements to add to the stack" << endl;
    int numItems;
    cin >> numItems;
    for ( int i = 0; i <= numItems; i++)
        s.push(i);
    
    cout << "Stack contents:\n";
    s.display(cout);

    cout << "*********************" << endl;
    cout << "Stack empty?"<< boolalpha << " "<<  s.empty() << endl;
    cout << "Top value: " << s.top() << endl;
    while (!s.empty())
    {
        cout << "Popping" << s.top() << endl;
        s.pop(); 
    }

    cout << "Stack empty?" << s.empty() << endl;
    cout << "************" << endl;
    cout << "top value: " << s.top() << endl;
    cout << "Trying to pop: " << endl;
    s.pop(); 
}