#include <iostream>
#include "intArray.h"
using namespace std;

int main()
{
        try
        {
            IntArray badArray(1);
        }
        catch (const char* error)
        {
            cout << "Error creating an array: " << error << endl;
            std::terminate();
        }
        try
        {
            IntArray arr(4);
            arr.insertBefore(1, 0);
        }
        catch (const char* error)
        {
            cout << "Error during insertion: " << error << endl;
            std::terminate();
        }
        try
        {
            IntArray arr(3);
            arr[0] = 1;
            arr[1] = 2;
            arr[2] = 3;

            cout << "index: " << arr[0] << endl;
        }
        catch (const char* error)
        {
            cout << "Error accessing by index: " << error << endl;
            std::terminate();
        }

        try
        {
            IntArray arr(2);
            arr[0] = 10;
            arr[1] = 20;

            arr.remove(0);
        }
        catch (const char* error)
        {
            cout << "Error while deleting: " << error << endl;
            std::terminate();
        }

    IntArray array(10);
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i + 1;
    array.resize(8);
    array.insertBefore(20, 5);
    array.remove(3);
    array.insertAtEnd(30);
    array.insertAtBeginning(40);
    {
        IntArray b{ array };
        b = array;
        b = b;
        array = array;
    }
    for (int i{ 0 }; i < array.getLength(); ++i)
        cout << array[i] << ' ';
    cout << '\n';

    return 0;
}