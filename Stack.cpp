// #include <iostream>
// using namespace std;
// typedef int Elemtype;


// typedef struct 
// {
//     Elemtype *base;
//     Elemtype *top;
//     int stackSize;
// }sqStack;


#include <iostream>
using namespace std;
const int STACK_CAPACITY = 128;
typedef int StackElement;

class Stack
{
    public:
        Stack();
        bool empty() const;
        void push(const StackElement &value);
        void display(ostream &out) const;
        StackElement top() const;
        void pop();

    private:
        StackElement myArray[STACK_CAPACITY];
        int myTop;
};

Stack::Stack():myTop(-1){};

bool Stack::empty() const
{
    return (myTop == -1);
}

void Stack::push(const StackElement & value)
{
    if (myTop < STACK_CAPACITY - 1)
    {
        ++myTop;
        myArray[myTop] = value;
    }
    else 
    {
        cout << "*** Stack full --- can't add new value ***" << endl;
        exit(-1);
    }
}

 void Stack::display(ostream &out) const
{
    for (int i = myTop; i >= 0; i--)
    {
        cout << myArray[i] << endl;
    }
}

StackElement Stack::top() const
{   
    if (!empty())
    {
        return (myArray[myTop]);
    }
    else
    {
        cout << "*** Stack is empty ***" << endl;
        StackElement garbage;
        return garbage;
    }
}

void Stack::pop()
{
    if (empty())
    {
        cout << "*** Stack is empty ***" << endl;
    }
    else
    {
        --myTop;
    }
}


int main()
{
    Stack s;
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
