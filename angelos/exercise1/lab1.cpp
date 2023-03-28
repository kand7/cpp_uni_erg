#include <iostream>
#include <climits>

using namespace std;

void find_2l_elements(int, double &, double &, double[]);
double &findMin(int, double[]);

int main()
{
    int size_of_array;
    double *array;
    double l1, l2;

    cout << "Enter the size of array: ";
    cin >> size_of_array;

    array = new double[size_of_array];

    cout << "\nEnter the elements of array:\n";
    for (int i = 0; i < size_of_array; i++)
    {
        cout << "Enter element no." << i + 1 << ": ";
        cin >> array[i];
    }

    cout << "\nInitial array:\n";
    // Print the array. Should be in function.
    cout << "[";
    for (int i = 0; i < size_of_array - 1; i++)
    {
        cout << array[i] << ", ";
    }
    cout << array[size_of_array - 1] << "]" << endl;

    find_2l_elements(size_of_array, l1, l2, array);
    double &min = findMin(size_of_array, array); // double min = findMin(size_of_array, array); does not change the value of the array.
    min *= 2;

    cout << "\nThe largest element is: " << l1 << endl;
    cout << "The 2nd largest element is: " << l2 << endl;
    cout << "The smallest element times 2 is: " << min << endl;
    cout << "The smallest element of the array has now been doubled.\n" << endl;

    cout << "Modified array:\n";
    // Print the array. Should be in function.
    cout << "[";
    for (int i = 0; i < size_of_array - 1; i++)
    {
        cout << array[i] << ", ";
    }
    cout << array[size_of_array - 1] << "]" << endl;

    return 0;
}

void find_2l_elements(int size, double &l1, double &l2, double array[])
{
    l1 = l2 = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > l2 && array[i] != l1)
        {
            if (array[i] > l1)
            {
                l2 = l1;
                l1 = array[i];
            }
            else
                l2 = array[i];
        }
    }
}

double &findMin(int size, double array[])
{
    int array_index = 0;

    for (int i = 1; i < size; i++)
        if (array[i] < array[array_index])
            array_index = i;

    return array[array_index];
}
