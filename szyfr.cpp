#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int ub = 255, lb = 1;
    string phrase;
    bool ceout = true;
    char characterencoding[255];
    cin >> phrase;
    srand (time(NULL));
    for (int i = 0; i <= 254; i++) //generuj klucz
    {
        int randomnb = (rand() % (ub - lb + 1)) + lb;
        if (i != 0)
        {
            for (int e = 0; e == i; e++) //weryfikuj, czy encja ju¿ wyst¹pi³a
            {
                if ((char)randomnb == characterencoding[e] && randomnb >= 32)
                {
                    i--;
                    ceout = false;
                }
                if (randomnb == characterencoding[e] && randomnb < 32)
                {
                    i--;
                    ceout = false;
                }
            }
            if (ceout == true) //scenariusz: encja nie wyst¹pi³a
            {
                cout << (char)randomnb;
            }
            else //scenariusz: encja wyst¹pi³a (reset cyklu)
            {
                ceout = true;
            }
        }
    }
}
