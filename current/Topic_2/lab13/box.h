/*
 * Name        : box.h
 * Author      : Russell Powell
 * Description : creation of a 'type' class template
 * Links       : https://github.com/RussPowell/Hello-World.git
 *               https://hello-world-russpowell.c9users.io
 * Sources     : Absolute C++ by Walter Savitch 
 */
#ifndef BOX_H
#define BOX_H

#include <string>
#include <ostream>
using std::string;
using std::ostream;
using std::stringstream;
using std::endl;

template<class T>
class Box
{
    public:
        Box();
        Box(T newContents);
        
 
        void setContents(T newContents);
        T getContents() const;
        
        template<class o>
        friend ostream&  operator <<(ostream& output, const Box<o>& contents);
        

    protected:
        T contents;
};
template<class T> 
Box<T>::Box()
{
    contents = 0;
}

template<class T>
Box<T>::Box(T newContents)
{
    contents = newContents;
}

template<class T>
void Box<T>::setContents(T newContents)
{
    contents = newContents;
}


template<class T>
T Box<T>::getContents() const
{
    return contents;
}

template<class o>
ostream& operator <<(ostream& output, const Box<o> &newContents) 
{
    //contents = newContents;
    
    output << newContents.contents;
    return output;
}




template <typename T>
T Sum(T values, unsigned int size)
{
    T sum = "zero";
    int i = 0;//declare iterator
    
    for( i; i < size; i++)
    {
        sum+=values[i];
    }
 return sum;   
};



#endif