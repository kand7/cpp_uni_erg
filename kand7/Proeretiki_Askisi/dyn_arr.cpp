#include <iostream>

using namespace std;

int main()
{
    int startSize = 4;
    int arrSize = 0;
    int index = 0;
    int *myArray = new int[startSize];
    int userInput;
    while (1)
    {
        cout << "Enter your data: " << endl;
        cin >> userInput;
        if (userInput == 0)
        {
            break;
        }
        if (arrSize == startSize)
        {
            myArray = (int *)realloc(myArray, sizeof(int) * arrSize * 2);
            startSize *= 2;
        }
        arrSize++;
        myArray[index] = userInput;
        index++;
    }
    cout << "Size : " << arrSize << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << myArray[i];
    }

    return 0;
}