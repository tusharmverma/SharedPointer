#ifndef SHAREDPTR_H
#define SHAREDPTR_H

//Include Statements
#include "Foo.h"
#include <iostream>
  using std::cout;

//Class Definitions
  //Class Definition For Shared Pointers
template <class PtrType>
class SharedPtr{
    public:
                    SharedPtr   (PtrType* ptr);         //Ptr Constructor
        template <typename... Args>
                    SharedPtr   (const Args&... args);  //Arg Constructor
                    SharedPtr   (const SharedPtr<PtrType>& original);
                                                        //Copy Constructor
                    ~SharedPtr  (void);
        PtrType&    operator*   (void) const { return *_ptr; };
        PtrType*    operator->  (void) const { return _ptr;  };
        SharedPtr&  operator=   (const SharedPtr& original)
                                /*{return (SharedPtr<PtrType> {original}); }*/;     //Assignment Constructor

    private:
        PtrType*    _ptr;
        int*        countPtr;
};

  //Class Definition For Shared Pointers []
template <typename PtrType>
class SharedPtr<PtrType[]>{
    public:
                    SharedPtr   (const int& size);  //Constructor
                    SharedPtr   (const SharedPtr&); //Copy Constructor
                    ~SharedPtr  (void);
        PtrType&    operator*   (void) const { return *_ptr; };
        PtrType&    operator[]  (int i) const { return _ptr[i]; };
        SharedPtr&  operator=   (const SharedPtr& original)
                                /*{ return (SharedPtr<PtrType> {original}); }*/; //Assignment Constructor
    private:
        int         sizeOfArray;
        PtrType*    _ptr;
        int*        countPtr;
};

//Methods For Shared Pointers
  //Constructor(s) For SharedPtr
/*
 * @brief       Constructor for Shared Pointers that uses a pointer
 *              to construct a new Shared Pointer.
 *
 * @remarks
 *      This method constructs and passes the pointer into the Shared Pointers
 *      private data, and increments this pointers specific count value.
 *
 * @param       ptr         The pointer, that currently points to some data,
 *                          used to store in the Shared Pointer object.
 *
 * @return  This method returns no value.
 */
template <class PtrType>
SharedPtr<PtrType>::SharedPtr(PtrType* ptr){
    _ptr = ptr;
    countPtr = new int (1);
    //cout << "Count: " << *countPtr << '\n';
    //Return nothing.
}

/*
 * @brief       Constructor for Shared Pointers that uses multiple
 *              types of arguements.
 *
 * @remarks
 *      This method constructs a new pointer and passes the data
 *      value's pointer into the Shared Pointers private data,
 *      and increments this pointers specific count value.
 *
 * @param       Args        The pointer, that currently points to some data,
 *                          used to store in the Shared Pointer object.
 *
 * @return  This method returns no value.
 */
template <typename PtrType> template <typename... Args>
SharedPtr<PtrType>::SharedPtr(const Args&... args) {
    _ptr = new PtrType{ args... };
    countPtr = new int (1);
    //cout << "Count: " << *countPtr << '\n';
}

/*
 * @brief       Copy Constructor for Shared Pointers that
 *              copies the data inside one Shared Pointer
 *              into a new copied Shared Pointer.
 *
 * @remarks
 *      This method constructs a new pointer and copies one
 *      Shared Pointer's data into a newly constructed one.
 *
 * @param       original    The Shared Pointer whos data you wish to copy.
 *
 * @return  This method returns no value.
 */
template<typename PtrType>
SharedPtr<PtrType>::SharedPtr(const SharedPtr<PtrType>& original){     //Copy Constructor

    _ptr = original._ptr;          //Assign copy of pointers.
    countPtr = original.countPtr;  //Assign copy of the count.
    *countPtr = *countPtr + 1; //Increment countPtr.
    //cout << "Copy count: " << *countPtr << '\n';  //Check for countPtr
    //No return value
}

  //Deconstructor(s) For SharedPtr
/*
 * @brief       Deconstructor for Shared Pointers deletes data
 *              only if it is ready to be deleted.
 *
 * @remarks
 *      This method deconstructs a Shared Pointer when the *countPtr
 *      is at zero. Until then the deconstructor does not delete the data.
 *
 * @param       void        This method uses no parameters
 *
 * @return  This method returns no value.
 */
template <class PtrType>
SharedPtr<PtrType>::~SharedPtr (void){
    *countPtr = *countPtr - 1;
    //cout << "Count: " << *countPtr << '\n';  //Check for countPtr
    if(*countPtr == 0){
        delete _ptr;
        delete countPtr;
        _ptr = nullptr;
        countPtr = nullptr;
    }
    //Return nothing.
    return;
}

  //Operator Overloader(s) for SharedPtr
/*
 * @brief       Assignment constructor for Shared Pointers.
 *
 *
 * @remarks
 *      This method reassigns the data in the Shared Pointer
 *      being assigned with the Shared Pointer passed
 *      into it with the data in the "original" Shared Pointer.
 *
 * @param       original    The Shared Pointer who's data we wish to
 *                          use to reassign "this" Shared Pointer.
 *
 * @return  This method returns "this" pointer that we have
 *          reassigned.
 */
template <class PtrType>
SharedPtr<PtrType>& SharedPtr<PtrType>::operator= (const SharedPtr& original){
    //Check if a _ptr is empty
    if(!_ptr){
        _ptr = original._ptr;       //If it is assign as normal
        countPtr = original.countPtr;
        *countPtr = *countPtr + 1;
    }
    //If _ptr already exists
    else if(_ptr){
        //If _ptr does not equal original
        if(_ptr != original._ptr){
            *countPtr = *countPtr - 1;
            //If only one pointer exists to this value delete it
            if(*countPtr == 0){
                delete _ptr;
                delete countPtr;
            }
            //Reassign this copy to original
            _ptr = original._ptr;
            countPtr = original.countPtr;
            *countPtr = *countPtr + 1;
        }
        //If _ptr already equals original: do nothing.
    }
    //Return the new copied Shared Pointer
    return *this;
}

//Methods For Shared Pointers []
  //Constructor(s) For SharedPtr []

/*
 * @brief       Assignment constructor for Shared Pointers
 *              for an array.
 *
 *
 * @remarks
 *      This method constructs a new array with the size passed to
 *      it and assigns the pointer to the new array to the Shared Pointer's
 *      private data _ptr.
 *
 * @param       size        The size of the array to be created
 *                          for the Shared Pointer.
 *
 * @return  This method returns no value.
 */
template <class PtrType>            //s     commented out by grader
SharedPtr<PtrType[]>::SharedPtr (const int& size){
    sizeOfArray = size;
    _ptr = new PtrType [size];
    countPtr = new int (1);
    //cout << "Count: " << *countPtr << '\n';
}

/*
 * @brief       Copy Constructor for Shared Pointer [] that
 *              copies the data inside one Shared Pointer
 *              into a new copied Shared Pointer.
 *
 * @remarks
 *      This method constructs a new pointer and copies one
 *      Shared Pointer's pointer data into a newly constructed one.
 *
 * @param       original    The Shared Pointer whos data you wish to copy.
 *
 * @return  This method returns no value.
 */
template <class PtrType>
SharedPtr<PtrType[]>::SharedPtr (const SharedPtr<PtrType[]>& original){
    _ptr = original._ptr;          //Assign copy of pointers.
    countPtr = original.countPtr;  //Assign copy of the count.
    (*countPtr)++;             //Increment countPtr.
    //cout << "Copy count: " << *countPtr << '\n';  //Check for countPtr
    //No return value
}

  //Deconstructor(s) For SharedPtr[]
/*
 * @brief       Deconstructor for Shared Pointers[] deletes data
 *              only if it is ready to be deleted.
 *
 * @remarks
 *      This method deconstructs a Shared Pointer when the *countPtr
 *      is at zero. Until then the deconstructor does not delete the data.
 *
 * @param       void        This method uses no parameters
 *
 * @return  This method returns no value.
 */
template <class PtrType>
SharedPtr<PtrType[]>::~SharedPtr (void){
    *countPtr = *countPtr - 1;
    //cout << "CountPtr: " << *countPtr << '\n';
    if(*countPtr == 0){
        delete [] _ptr;
        delete countPtr;
        _ptr = nullptr;
        countPtr = nullptr;
    }
    //Return nothing.
    return;
}

  //Operator Overloader(s) for SharedPtr
/*
 * @brief       Assignment constructor for Shared Pointers[].
 *
 *
 * @remarks
 *      This method reassigns the data in the Shared Pointer[]
 *      being assigned with the Shared Pointer[] passed
 *      into it with the pointer data in the "original" Shared Pointer[].
 *
 * @param       original    The Shared Pointer[] who's data we wish to
 *                          use to reassign "this" Shared Pointer.
 *
 * @return  This method returns "this" pointer that we have
 *          reassigned.
 */
template <class PtrType>
SharedPtr<PtrType[]>& SharedPtr<PtrType[]>::operator= (const SharedPtr& original){
    //Check if a _ptr is empty
    if(!_ptr){
        _ptr = original._ptr;
        countPtr = original.countPtr;
        *countPtr = *countPtr + 1;
    }
    //If _ptr already exists
    else if(_ptr){
        //If _ptr already points to original
        if(_ptr == original._ptr){
            //Do not delete or reassign, it already equals itself
        }
        //If _ptr does not equal original
        if(_ptr != original._ptr){
            *countPtr = *countPtr - 1;
            //If only one pointer exists to this value delete it
            if(*countPtr == 0){
                delete [] _ptr;
                delete [] countPtr;
            }
            //Reassign this copy to original
            _ptr = original._ptr;
            countPtr = original.countPtr;
            *countPtr = *countPtr + 1;
        }
    }
    //Return the new copied Shared Pointer
    return *this;
}
//End of Gaurd
#endif
