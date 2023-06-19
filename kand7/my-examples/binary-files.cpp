#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void writeArray(int *a, int size)
{
    fstream fout("binary.dat", ios::out | ios::binary);
    if (fout.good())
    {
        fout.write(reinterpret_cast<char *>(a), size * sizeof(int));
        fout.close();
    }
}

void readArray(int *a, int size)
{
    fstream fout("binary.dat", ios::in | ios::binary);
    if (fout.good())
    {
        fout.read(reinterpret_cast<char *>(a), size * sizeof(int));
        fout.close();
    }
}
int main()
{
    const int SIZE = 10;
    fstream fout;
    unsigned short x = 8678;
    char c = 'V';
    unsigned short y;
    fout.open("binary.dat", ios::out | ios::binary);
    if (fout.good())
    {
        fout.write(reinterpret_cast<char *>(&x), sizeof(unsigned short));
        fout.write(&c, sizeof(char));
        fout.close();
    }
    fout.open("binary.dat", ios::in | ios::binary);
    if (fout.good())
    {
        fout.read(reinterpret_cast<char *>(&y), sizeof(unsigned short));
        cout << y << endl;
        fout.close();
    }
    fout.open("binary.dat", ios::out | ios::binary);
    char myNameWrite[] = {'V', 'I', 'K', 'T', 'O', 'R'};
    char myNameRead[10];
    if (fout.good())
    {
        fout.write(myNameWrite, sizeof(myNameWrite));
        fout.write("\n", sizeof(char));
        fout.close();
    }
    fout.open("binary.dat", ios::in | ios::binary);
    if (fout.good())
    {
        fout.read(myNameRead, 10);
        cout << myNameRead << endl;
        fout.close();
    }
    int array[SIZE] = {5, 1, 3, 4, 5, 6, 7, 4, 4, 10};
    int read[SIZE];
    writeArray(array, SIZE);
    readArray(read, SIZE);
    for (int i : read)
    {
        cout << i << " ";
    }
    cin.get();
    return 0;
}