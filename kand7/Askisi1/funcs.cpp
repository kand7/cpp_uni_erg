#include <iostream>
#include "askisi1.h"

using namespace std;

void twoMaxerOne(double array[], int size)
{
    double max1, max2;
    max1 = max2 = array[0];
    for (int i = 0; i < size; i++)
    {
        if ((array[i] > max1) && (array[i] > max2))
        {
            max2 = max1;
            max1 = array[i];
        }
        else if ((array[i] > max2) && (array[i] < max1))
        {
            max2 = array[i];
        }
    }
    cout << "Max1: " << max1 << " Max2 : " << max2 << endl;
}
void twoMaxerTwo(double &max1, double &max2, double array[], int size)
{
    max1 = max2 = array[0];
    for (int i = 0; i < size; i++)
    {
        if ((array[i] > max1) && (array[i] > max2))
        {
            max2 = max1;
            max1 = array[i];
        }
        else if ((array[i] > max2) && (array[i] < max1))
        {
            max2 = array[i];
        }
    }
    cout << "Max1: " << max1 << " Max2 : " << max2 << endl;
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

double *creatArray(double size)
{
    double *userArray = new double(size + 1);
    cout << "Creating Array of size " << size << endl;
    cout << "Enter your data\n";
    for (int i = 0; i < size; i++)
    {
        cin >> userArray[i];
    }
    cout << "Array has been created\nContains : " << size << " elements" << endl;
    return userArray;
}
