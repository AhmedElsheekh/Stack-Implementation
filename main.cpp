#include <iostream>

using namespace std;

//1- Stack Built on Array

class StackArray
{
private:
    int top;
    int length;
    int siz;
    int* items;
public:
    StackArray(int s)     //time memory O(1)
    {
        siz = s;
        top = -1;
        length = 0;
        items = new int[s];
    }

    void push(int k)     //time memory O(1)
    {
        if(top >= siz-1)
        {
            cout << "stack is full\n";
            return;
        }

        top++;
        items[top] = k;
        length++;
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "stack is empty\n";
            return ;
        }

        top--;
        length--;
    }

    int pop(int &x)
    {
        if(top == -1)
        {
            cout << "stack is empty\n";
            return -1;
        }

        x = items[top];

        top--;
        length--;

        return x;
    }

    int peek() {return items[top];}

    void display()    //time O(n) memory O(1)
    {
        for(int i = top; i >=0; i--)
            cout << items[i] << " ";
        cout << "\n";
    }
};
//----------------------------------------------------------------//

//2- Stack built on Linked List

class Node
{
public:
    int data;
    Node* next;
public:
    Node(int d):data(d),next(NULL)
    {
    }
};

class StackLinkedList
{
private:
    Node* top;
public:
    StackLinkedList()
    {
        top = NULL;
    }

    bool isempty()
    {
        return top == NULL;
    }

    void push(int item)                  //time memory O(1)
    {
        Node* newnode = new Node(item);

        if(isempty())
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }

    void display()            //time O(n) memory O(1)
    {
        Node* temp = top;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int pop()      //t m O(1)
    {
        int val;
        val = top->data;
        Node* delptr = top;
        top = top->next;
        delete delptr;
        return val;
    }

    int peek()
    {
        return top->data;
    }

    int counte()      //time O(n) memory O(1)
    {
        int counter = 0;
        Node* temp = top;
        while(temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool isfound(int key)    //time O(n) memory(1)
    {
        Node* temp = top;
        while(temp != NULL)
        {
            if(temp->data == key)
                return true;
            else
                temp = temp->next;
        }
        return false;
    }

    bool isfull()
    {
        Node* newnode = new Node(0);
        if(newnode == NULL)
            return true;
        return false;
    }
};

int main()
{
    StackArray st(20);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.display();
    cout << "\n";

    st.pop();
    st.display();
    cout << "\n";
    int n;
    st.pop(n);
    cout << n << endl;

    cout << st.peek() << endl;
    //----------------------------------------------//

    StackLinkedList stl;
    stl.push(1);
    stl.push(2);
    stl.push(3);
    stl.push(4);
    stl.push(5);
    stl.display();
    cout << "\n";
    cout << stl.counte() << endl;

    stl.pop();
    stl.pop();
    stl.display();
    cout << "\n";

    cout << stl.peek() << endl;
    cout << stl.isfound(5);


    return 0;
}
