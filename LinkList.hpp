#ifndef _LinkList_hpp_
#define _LinkList_hpp_
#include "List.hpp"

/******************/
/*Link_Double_List*/
/******************/

template <typename T>
class LList:public List<T>
{
public:
    LList(int = 1000);

    int get_size () const;
    int currnt_pos();
    int capacity() const;

    void move_to_start();
    void move_to_pos(int);
    void move_to_end();

    void clear();
    void set_value(const T&,int);

    bool start (const T &);
    bool insert(const T &);
    bool append(const T &);

    bool empty()const;
    bool del_currnt();
    bool del_pos(int);

    T get_value (int);
private:
    bool New_node(const T&);

    struct Node
    {
        Node* next;
        Node* prev;
        T value;
    };
    Node* left;
    Node* right;
    Node* currnt;

    int max_size;
    int my_size;
};

template <typename T>
LList<T>::LList(int number):my_size(0),max_size(number),left(0),right(0),currnt(0)
{
    if (max_size > 1000 || max_size < 0)
        max_size = 1000;
}

template <typename T>
int LList<T>::get_size() const
{
    return my_size;
}

template <typename T>
int LList<T>::currnt_pos()
{
    Node* temp = currnt;
    int position = 0;
    move_to_start();
    while (currnt != temp)
    {
        ++position;
        currnt = currnt->next;
    }
    return position;
}

template <typename T>
int LList<T>::capacity() const
{
    return max_size;
}

template <typename T>
void LList<T>::move_to_start()
{
    currnt = left;
}

template <typename T>
void LList<T>::move_to_pos(int position)
{
    if (position > my_size)
        move_to_end();
    else if (position == 0)
        move_to_start();
    else
    {
        move_to_start();
        for (int i = 0;i < position;++i)
            currnt = currnt->next;
    }
}

template <typename T>
void LList<T>::move_to_end()
{
    currnt = right;
}

template <typename T>
void LList<T>::clear()
{
    my_size = 0;
    left = 0;
    right = 0;
    currnt = 0;
}

template <typename T>
void LList<T>::set_value(const T & value, int pos)
{
    if (pos > my_size)
        pos = my_size;
    else
    {
        move_to_pos(pos);
        currnt->value = value;
    }
}

template <typename T>
bool LList<T>::empty() const
{
    return my_size == 0;
}

template <typename T>
bool LList<T>::start (const T & value)
{
    if (my_size == max_size)
           return false;
    if (my_size == 0)
           return New_node(value);
    Node* node = new Node;
    node->next = left;
    left->prev = node;
    node->prev = 0;
    node->value = value ;
    left = node;
    ++ my_size;
    return true;
}

template <typename T>
bool LList<T>::insert(const T & value)
{
    if (my_size == max_size)
        return false;
    if (my_size == 0)
        return New_node(value);
    int position = currnt_pos();
    if (position == 0)
        return start(value);
    if (position == my_size-1)
        return append(value);
    Node* node = new Node;
    Node* temp = currnt->prev;
    temp->next = node;
    node->prev = temp;
    node->value = value;
    node->next = currnt;
    currnt->prev = node;
    currnt = node;
    ++my_size;
    return true;
}

template <typename T>
bool LList<T>::append (const T & value)
{
    if (my_size == max_size)
        return false;
    if (my_size == 0)
        return New_node(value);
    Node* node = new Node;
    node->prev = right;
    right->next = node;
    node->next = 0;
    node->value = value;
    right = node;
    ++my_size;
    return true;
}

template <typename T>
bool LList<T>::del_currnt()
{
    if (my_size == 0)
        return false;
    int pos = currnt_pos();
    if (pos == 0)
    {
        currnt = currnt->next;
        delete left;
        currnt->prev = 0;
        left = currnt;
        --my_size;
        return true;
    }
    if (pos == my_size-1)
    {
        currnt = currnt->prev;
        delete right;
        currnt->next = 0;
        right = currnt;
        -- my_size;
        return true;
    }
    Node* temp1 = currnt->prev;
    Node* temp2 = currnt->next;
    temp1->next = temp2;
    temp2->prev = temp1;
    --my_size;
    delete currnt;
    currnt = temp1;
    return true;
}

template <typename T>
bool LList<T>::del_pos(int position)
{
    if (position > my_size)
        return false;
    move_to_pos(position);
    return del_currnt();
}

template <typename T>
bool LList<T>::New_node(const T & value)
{
    if (max_size == 0)
        return false;
    Node* node = new Node;
    node->next = 0;
    node->prev = 0;
    left = node;
    right = node;
    currnt = node;
    node->value = value;
    ++my_size;
    return true;
}

template <typename T>
T LList<T>::get_value(int position)
{
    move_to_pos(position);
    return currnt->value;
}
#endif//end including LinkList.hpp file
