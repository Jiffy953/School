//main.cpp
//by Jared See
//section 2
//date 9-22-21


#include <vector>
#include <iostream>
using namespace std;

template<class myType>
class DynamicArray{ //creates template class using myType as the new type
public:
    const vector<myType> &classvector;  //creates the vector of myType to be used in the methods
    bool isEmpty()
    {
        if (classvector.size() == 0) //checks the size and if it is == to zero the array is empty returning true
        {
            return true; //returns true :)
        }
    }
    void clear()  //destroys all elements in the array and reduces its size to zero
    {
        classvector.clear();
    }
    void create(uint32_t size, myType object) //creates an array of a given size and adds the passed object into it with pushback
    {
        classvector.reserve(size); //sets total size
        classvector.pushback(object); //pushes object into array
    }

    void copy(myType object, uint32_t index) //adds the object to the given space into the array
    {
            classvector.push_back(object[index]);
    }
};

int main(){
}