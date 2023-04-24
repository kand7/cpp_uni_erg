#include <iostream>
#include "askisi1.h"

using namespace std;

int main()
{
<<<<<<< HEAD
    double size = 0;
    double minimum = 0;
    double max1, max2 = 0;
=======
    int size = 0;
>>>>>>> 60f090963b7172f221984ff0730f9a8966ad6212
    cout << "Enter the size of your desired Array : ";
    cin >> size;
    printf("\n");
    double *myArray = creatArray(size);
<<<<<<< HEAD
    minimum = smallest(myArray, size);
    twoMaxerTwo(max1, max2, myArray, size);
    twoMaxerOne(myArray, size);
    cout << "Smallest number is : " << minimum << endl;
    cout << "Smallest number * 2 : " << minimum * 2 << endl;
=======
    double &minimum = smallest(myArray, size);
    twoMaxer(myArray, size);
    cout << "Smallest number is : " << minimum << endl;
    minimum *= 2;
    cout << "After minimum * 2 we have : " << minimum << "\nOur array is now" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Item : " << i << " =>" << myArray[i] << endl;
    }

>>>>>>> 60f090963b7172f221984ff0730f9a8966ad6212
    free(myArray);
    return 0;
}