#ifndef _List_hpp_
#define _List_hpp_

/****************/
/*Abstract class*/
/****************/

template <typename T>
class List
{
public:
    List() {}

    virtual int get_size () const = 0;
    virtual int currnt_pos () = 0;
    virtual int capacity () const = 0;

    virtual void move_to_start () = 0;
    virtual void move_to_pos (int) = 0;
    virtual void move_to_end () = 0;

    virtual void clear () = 0;
    virtual void set_value (const T&,int) = 0;

    virtual bool empty () const = 0;
    virtual bool del_currnt() = 0;
    virtual bool del_pos (int) = 0;

    virtual bool start (const T&) = 0;
    virtual bool insert (const T&) = 0;
    virtual bool append (const T&) = 0;

    virtual T get_value (int) = 0;
};

#endif//end including List.hpp file
