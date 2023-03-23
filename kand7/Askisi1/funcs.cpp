#include <iostream>
#include "askisi1.h"
#include <climits>

using namespace std;

void twoMaxer(double array[], int size)
{
    double max1, max2;
    max1 = max2 = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if ((array[i] > max2) && (array[i] != max1))
        {
            if (array[i] > max1)
            {
                max2 = max1;
                max1 = array[i];
            }
            else
            {
                max2 = array[i];
            }
        }
    }
    cout << "Max1 : " << max1 << " Max2: " << max2 << endl;
}
double &smallest(double array[], double size)
{
    double tempSmallest = array[0];
    int smallestIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] <= tempSmallest)
        {
            tempSmallest = array[i];
            smallestIndex = i;
        }
    }
    return array[smallestIndex];
}

double *creatArray(int size)
{
    double *userArray = new double[size + 1];
    cout << "Creating Array of size " << size << endl;
    cout << "Enter your data\n";
    for (int i = 0; i < size; i++)
    {
        cin >> userArray[i];
    }
    cout << "Array has been created\nContains : " << size << " elements" << endl;
    return userArray;
}
