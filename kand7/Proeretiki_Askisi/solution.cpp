#include <iostream>

using namespace std;

int main()
{

    // ΦΤΙΑΞΕ ΑΛΛΟ ΠΙΝΑΚΑ ΟΤΑΝ ΓΕΜΙΣΕΙ Ο ΠΡΩΤΟΣ. ΣΒΗΚΕ ΜΕ DELETE ΤΟΝ ΠΡΩΤΟ ΚΑΙ ΒΑΛΕ ΤΟΝ ΠΡΩΤΟ ΝΑ ΔΕΙΧΝΕΙ ΣΤΟΝ ΔΕΥΤΕΡΟ
    int *A = new int[2];
    int x = 1, k = -1, size = 2;

    while (1)
    {
        cin >> x;
        if (x == 0)
        {
            break;
        }
        if (k == size - 1)
        {
            int *B = new int[size * 2];
            for (int i = 0; i < size; i++)
            {
                B[i] = A[i];
            }
            delete[] A;
            A = B; // δειξε στον Β οχι κατεστρεψε τον δεικτη
            size *= 2;
        }
        k++;
        A[k] = x;
    }
    cout << "Size : " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << A[i];
    }
    return 0;
}