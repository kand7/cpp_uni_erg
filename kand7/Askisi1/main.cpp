#include <iostream>
#include "askisi1.h"

using namespace std;

int main()
{
    int size = 0;
    cout << "Enter the size of your desired Array : ";
    cin >> size;
    printf("\n");
    double *myArray = creatArray(size);
    double &minimum = smallest(myArray, size);
    twoMaxer(myArray, size);
    cout << "Smallest number is : " << minimum << endl;
    minimum *= 2;
    cout << "After minimum * 2 we have : " << minimum << "\nOur array is now" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Item : " << i << " =>" << myArray[i] << endl;
    }

    free(myArray);
    return 0;
}