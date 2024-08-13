#include <iostream>
#include "shared_ptr.h"

class Resource
{
    int value;

public:
    Resource(int temp = 0) : value(temp) {}

    void display() const
    {
        std::cout << "Resource value: " << value << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Resource &res);
};

std::ostream &operator<<(std::ostream &out, const Resource &res)
{
    out << "Resource with value: " << res.value;
    return out;
}

int main()
{
    std::cout << "Demonstration of SharedPointer functionality:" << std::endl;

    SharedPointer<int> ptr1(new int(10)); 
    std::cout << "ptr1 points to: " << *ptr1 << ", useCount: " << ptr1.useCount() << std::endl;

    SharedPointer<int> ptr2 = ptr1;                                                             
    std::cout << "ptr2 points to: " << *ptr2 << ", useCount: " << ptr1.useCount() << std::endl; 

    
    SharedPointer<int> ptr3 = std::move(ptr2);                                                  
    std::cout << "ptr3 points to: " << *ptr3 << ", useCount: " << ptr1.useCount() << std::endl; 

    
    ptr3.reset(new int(20));
    std::cout << "ptr3 now points to: " << *ptr3 << ", useCount: " << ptr3.useCount() << std::endl; 

   
    SharedPointer<Resource> resPtr(new Resource(100));
    std::cout << *resPtr << ", useCount: " << resPtr.useCount() << std::endl;


    SharedPointer<Resource> resPtr2 = resPtr;
    std::cout << *resPtr << ", useCount: " << resPtr.useCount() << std::endl; 

    resPtr.reset(new Resource(200));
    std::cout << *resPtr << ", useCount: " << resPtr.useCount() << std::endl; 


    std::cout << *resPtr2 << ", useCount: " << resPtr2.useCount() << std::endl;

    return 0;
}
