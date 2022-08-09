#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int tam = 140;
    int i = 0, j = 0, arr = 0, hash = 0;
    char tweet[tam];
    string list_hashtag[10];
    string list_arroba[10];

    while (cin >> tweet)
    {
        if (tweet[0] == '#')
        {
            hash++;
            i++;
            list_hashtag[i] = tweet;
        }
        if (tweet[0] == '@')
        {
            arr++;
            j++;
            list_arroba[j] = tweet;
        }
    }

    if (hash > 0 && hash <= 3)
    {
        cout << "Hashtags:";
        for (i = 0; i < 10; i++)
            cout << list_hashtag[i] << endl;
    }
    if (hash == 0)
        cout << "O tweet não possui hashtags." << endl;
    if (hash > 3)
        cout << "Tweet inválido." << endl;
    if (arr > 0 && arr <= 3)

    {
        cout << "Arrobas:";
        for (j = 0; j < 10; j++)
            cout << list_arroba[j] << endl;
    }
    if (arr == 0)
        cout << "O tweet não possui arrobas." << endl;
    if (arr > 3)
        cout << "Tweet inválido." << endl;

    return 0;
}
