#include <iostream>

using namespace std;

int main()
{
    int size = 0;
    int index = 0;
    int *myArray = new int(size);
    int userInput;
    while (1)
    {
        cout << "Enter your data: " << endl;
        cin >> userInput;
        if (userInput == 0)
        {
            break;
        }
        size++;
        myArray = (int *)realloc(myArray, sizeof(int) * size);
        myArray[index] = userInput;
        index++;
    }
    cout << "Size : " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i];
    }

    return 0;
}