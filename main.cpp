
#include <iostream>
    using std::cout;
#include "Foo.h"
#include "SharedPtr.h"



int main ()                                                                             //Main Function
{
    cout << "Starting Program...\n\n";

    //Copy Constructor Tests For Shared Pointers
    //Test with SharedPtrs and values.
    //Create the first instance
    cout << "Part 1: Test Shared Pointer.\nCreating first Shared Pointer.\n";
    SharedPtr<Foo> sp1{"test pointer"};
    cout << "Shared Pointer: " << *sp1 << '\n'
         << "Tag:            " << sp1->tag() << '\n'
         << "Serial:         " << sp1->serial() << "\n\n";

    {
        cout << "Creating second Shared Pointer.\n";                                    //Create the second instance
        SharedPtr<Foo> sp2 {"second test"};
        cout << '\n';
        cout << "Creating first copy of Shared Pointer 1.\n";                           //Create copy of first
        SharedPtr<Foo> sp_copy1{sp1};
        cout << "Shared Pointer Copy: " << *sp_copy1 << '\n'
             << "Tag:                 " << sp_copy1->tag() << '\n'
             << "Serial:              " << sp_copy1->serial() << "\n\n";

        {
            cout << "Creating second copy of Shared Pointer 1.\n";                      //Create second copy of first
            SharedPtr<Foo> sp_copy2{sp_copy1};
            cout << "Shared Pointer Copy: " << *sp_copy2 << '\n'
                 << "Tag:                 " << sp_copy2->tag() << '\n'
                 << "Serial:              " << sp_copy2->serial() << '\n';
        }                                                                               //sp_copy2 goes out of scope
    }                                                                                   //sp_copy1 and sp2 goes out of scope

    cout << "\n\nPart 2: Test Copy C-Tor with Shared Pointr.\n"                         //Test with SharedPtr's and no values.
         << "Creating first blank Foo object.\n";
    SharedPtr<Foo> ob1{new Foo};
    cout << "Shared Pointer: " << *ob1 << '\n'
         << "Tag:            " << ob1->tag() << '\n'
         << "Serial:         " << ob1->serial() << "\n\n";
    {
        cout << "Creating second Foo object.\n";                                        //Create the second instance
        SharedPtr<Foo> ob2 {new Foo};
        cout << "Shared Pointer: " << *ob2 << '\n'
             << "Tag:            " << ob2->tag() << '\n'
             << "Serial:         " << ob2->serial() << "\n\n";
        cout << "Creating first copy of Shared Pointer 1.\n";                           //Create copy of first
        SharedPtr<Foo> ob_copy1{ob1};
        cout << "Shared Pointer Copy: " << *ob_copy1 << '\n'
             << "Tag:                 " << ob_copy1->tag() << '\n'
             << "Serial:              " << ob_copy1->serial() << "\n\n";

        {
            cout << "Creating second copy of Shared Pointer 1.\n";                      //Create second copy of first
            SharedPtr<Foo> ob_copy2{ob_copy1};
            cout << "Shared Pointer Copy: " << *ob_copy2 << '\n'
                 << "Tag:                 " << ob_copy2->tag() << '\n'
                 << "Serial:              " << ob_copy2->serial() << "\n\n";
        }                                                                               //ob_copy2 goes out of scope
    }                                                                                   //ob_copy1 and ob2 goes out of scope

    //Assignment Operator Tests For Shared Pointers
    //Test with SharedPtrs and values.
    //Create the first instance
    cout << "\n\nPart 3: Test Assignment Operator For Shared Pointer.\n"
         << "Creating first Shared Pointer.\n";
    SharedPtr<Foo> sp3{"test pointer"};
    cout << "Shared Pointer: " << *sp3 << '\n'
         << "Tag:            " << sp3->tag() << '\n'
         << "Serial:         " << sp3->serial() << "\n\n";

    {
        cout << "Creating second Shared Pointer.\n";                                    //Create the second instance
        SharedPtr<Foo> sp4{"Hello, World!"};
        cout << "Shared Pointer: " << *sp4 << '\n'
             << "Tag:            " << sp4->tag() << '\n'
             << "Serial:         " << sp4->serial() << "\n\n";

        cout << "Creating first assignment of Shared Pointer 1.\n";                     //Create copy of first
        SharedPtr<Foo> sp_copy3 = sp3;
        cout << "Shared Pointer Copy: " << *sp_copy3 << '\n'
             << "Tag:                 " << sp_copy3->tag() << '\n'
             << "Serial:              " << sp_copy3->serial() << "\n\n";

        {
            cout << "Creating first assignment of Shared Pointer 2.\n";                 //Create copy of second
            SharedPtr<Foo> sp_copy4 = sp4;
            cout << "Shared Pointer: " << *sp_copy4 << '\n'
                 << "Tag:            " << sp_copy4->tag() << '\n'
                 << "Serial:         " << sp_copy4->serial() << "\n\n";

            cout << "Creating second assignment of Shared Pointer 1.\n";                //Create second copy of first
            SharedPtr<Foo> sp_copy5 = sp_copy3;
            cout << "Shared Pointer Copy: " << *sp_copy5 << '\n'
                 << "Tag:                 " << sp_copy5->tag() << '\n'
                 << "Serial:              " << sp_copy5->serial() << "\n\n";
        }                                                                               //sp_copy2 goes out of scope
    }                                                                                   //sp_copy1 and sp2 goes out of scope

    cout << "\n\nPart 4: Test Reassignment (For Two Differing Values and For\n"         //Test on reassignment of Two Different and
         << "One Reassignment Of Same Value) Of Shared Pointers.\n"                     //Reassignment of An Equal Pointer.
         << "Creating Shared Pointers 1_1 and 2_1.\n";
    SharedPtr<Foo> sp1_1{"Hello, World!"};
    SharedPtr<Foo> sp2_1{"Goodbye, World!"};
    cout << '\n';
    cout << "Shared Pointer: " << *sp1_1 << '\n'
         << "Tag:            " << sp1_1->tag() << '\n'
         << "Serial:         " << sp1_1->serial() << "\n\n";

    cout << "Shared Pointer: " << *sp2_1 << '\n'
         << "Tag:            " << sp2_1->tag() << '\n'
         << "Serial:         " << sp2_1->serial() << "\n\n";

    cout << "\nReassigning Shared Pointer 2_1 to 1_1.\n";
    sp2_1 = sp1_1;

    cout << "Shared Pointer: " << *sp2_1 << '\n'
         << "Tag:            " << sp2_1->tag() << '\n'
         << "Serial:         " << sp2_1->serial() << "\n\n";

    cout << "Creating Shared Pointer 3_1.\n";
    SharedPtr<Foo> sp3_1{"Miley, what's good?"};
    cout << "Reassigning Shared Pointer 3_1 to itself.\n";
    sp3_1 = sp3_1;
    cout << "Shared Pointer: " << *sp3_1 << '\n'
         << "Tag:            " << sp3_1->tag() << '\n'
         << "Serial:         " << sp3_1->serial() << "\n\n";

    //Copy Constructor Tests For Shared Pointers[]
    //Create the first instance
    cout << "\n\nPart 8: Test Copy C-Tor For Arrays.\n"
         << "Creating Array of Shared Pointers Double 1[].\n";
    SharedPtr<double []>  arrayOfDouble1{5};
    double x = .05;
    for(int i = 0; i < 5; i++){
        arrayOfDouble1[i] = i + x;
        cout << "Printing value contained in arrayOfDouble1[" << i << "]: "
             << arrayOfDouble1[i] << '\n';
    }
    {
        cout << "\nCreating Array of Shared Pointers Foo[].\n";                          //Create the second instance
        SharedPtr<Foo []> arrayOfFoo{4};

        cout << "\nCopying Array of Shared Pointer Double 1[].\n";                       //Create a copy of the first
        SharedPtr<double []> arrayOfDouble2{arrayOfDouble1};
        for(int i = 0; i < 5; i++){
            cout << "Printing value contained in arrayOfDouble2[" << i << "]: "
                 << arrayOfDouble2[i] << '\n';
        }
        {
            cout << "\nCopying Array of Shared Pointer Double 1[] (Again).\n";          //Create the second copy of the first
            SharedPtr<double []> arrayOfDouble3{arrayOfDouble2};
                for(int i = 0; i < 5; i++){
                    cout << "Printing value contained in arrayOfDouble3[" << i << "]: "
                         << arrayOfDouble3[i] << '\n';
                }
            cout << '\n';
        }
    }                                                                                  //second instance and copied array going out of scope.

    //Assignment Operator Test For Shared Pointers[]
    //Create the first instance
    cout << "\n\nPart 7: Test Assignment Operator For Array.\n"
         << "Creating Array of Shared Pointers Double 4[].\n";
    SharedPtr<double []>  arrayOfDouble4{5};
    x = .15;
    for(int i = 0; i < 5; i++){
        arrayOfDouble4[i] = i + x;
        cout << "Printing value contained in arrayOfDouble 4[" << i << "]: "
             << arrayOfDouble4[i] << '\n';
    }
    {
        cout << "\nAssigning Array of Shared Pointer Double 4[].\n";                 //Create a copy of the first
        SharedPtr<double []> arrayOfDouble5 = arrayOfDouble4;
        for(int i = 0; i < 5; i++){
            cout << "Printing value contained in arrayOfDouble5[" << i << "]: "
                 << arrayOfDouble5[i] << '\n';
        }
        {
            cout << "\nAssigning Array of Shared Pointer Double 4[] (Again).\n";    //Create the second copy of the first
            SharedPtr<double []> arrayOfDouble6 = arrayOfDouble5;
                for(int i = 0; i < 5; i++){
                    cout << "Printing value contained in arrayOfDouble6[" << i << "]: "
                         << arrayOfDouble6[i] << '\n';
                }
        }
    }                                                                              //second instance and copied array going out of scope.


    cout << "\n\nPart 8: Test Reassignment (For Two Differing Values and For\n"    //Reassignment Operator Test For Shared Pointers[] for an Array to another.
         << "One Reassignment Of Same Value) For Shared Pointers[].\n"
         << "Creating Array of Shared Pointers Double 7 and 8 [].\n";
    SharedPtr<double []> arrayOfDouble7{5};
    SharedPtr<double []> arrayOfDouble8{10};
    x = .02;
    for(int i = 0; i < 5; i++){
        arrayOfDouble7[i] = i + x;
        cout << "Printing value contained in arrayOfDouble7[" << i << "]: "
             << arrayOfDouble7[i] << '\n';
    }
    cout << '\n';
    x = .12;
    for(int i = 0; i < 10; i++){
        arrayOfDouble8[i] = i + x;
        cout << "Printing value contained in arrayOfDouble8[" << i << "]: "
             << arrayOfDouble8[i] << '\n';
    }

    cout << "\nReassinging arrayOfDouble8 to arrayOfDouble7.\n";
    arrayOfDouble8 = arrayOfDouble7;                            // spelling corrected by grader
    for(int i = 0; i < 5; i++){
        cout << "Printing value contained in arrayOfDouble7[" << i << "]: "
             << arrayOfDouble7[i] << '\n';
    }
    cout << '\n';
    for(int i = 0; i < 5; i++){
        cout << "Printing value contained in arrayOfDouble8[" << i << "]: "
             << arrayOfDouble8[i] << '\n';
    }

    //Ressignment Operator Test For Shared Pointers[] For an Array to Itself
    //Create the first instance
    cout << "\n\nCreating Array of Shared Pointers Double 9[].\n";
    SharedPtr<double []>  arrayOfDouble9{5};
    x = .15;
    for(int i = 0; i < 5; i++){
        arrayOfDouble9[i] = i + x;
        cout << "Printing value contained in arrayOfDouble9[" << i << "]: "
             << arrayOfDouble9[i] << '\n';
    }

    cout << "\nReassigning arrayOfDouble9 to itself.\n";
    arrayOfDouble9 = arrayOfDouble9;
    for(int i = 0; i < 5; i++){
        cout << "Printing value cotained in reassigned arrayOfDouble9["
             << i << "]: " << arrayOfDouble9[i] << '\n';
    }

    cout << "\nEnding Program...\n";
    return 0;
}
