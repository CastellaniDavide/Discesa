/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>
using namespace std;

int A;
int massima_pendenza=0;
vector < vector <int> > piramide;

void prova_strada (int pendenza, int strada_percorcorsa, int ultimo_passo)
{
    //cout << strada_percorcorsa << endl;
    if(strada_percorcorsa==A)
    {
        if(pendenza>massima_pendenza)
            massima_pendenza=pendenza;
    }
    else
    {
        prova_strada(pendenza+piramide[strada_percorcorsa][ultimo_passo],   strada_percorcorsa+1, ultimo_passo  );
        prova_strada(pendenza+piramide[strada_percorcorsa][ultimo_passo+1], strada_percorcorsa+1, ultimo_passo+1);
    }
}

int main()
{
//  uncomment the following lines if you want to read/write from files
  freopen("input2.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    cin >> A;
    piramide.resize(A);
    int temp;
    for(int i=0; i<A; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            cin >> temp;
            piramide[i].push_back(temp);
            //cout << temp << endl;
        }
    }

    prova_strada(piramide[0][0], 1, 0);
    cout << massima_pendenza << endl;
    return 0;
}
