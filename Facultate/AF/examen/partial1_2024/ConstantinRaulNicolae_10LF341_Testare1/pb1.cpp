#include <iostream>
#include <vector>
using namespace std;


/*
 1 a) Secventa de cod data spre analiza adauga in matricea patratica
        termenii sirului Fibonacci pe casutele ce au ambii indici impari, de sus in jos in prima faza, mutandu-se pe urmatoarea coloana, la dreapta,
        in momentul in care nu mai exista celule disponibile pe coloana respectiva
 
 1 c) Valorile lui n pot fi 11 si 12, deoarece altfel valoarea ori nu se incadreaza exact in casuta mat[7][3], ori nu sunt suficiente casute pentru ca valoarea b ce se adauga in vector sa atinga valoarea 34 necesara.
 */



void modificare_matrice(int n, vector<vector<int>> &mat)
{
    int a=0,b=1;
    for(int j=0;j<n;j++)
    {
        int i=1;
        while(i+j<n)
        {
            if(i%2==1&&j%2==1)
            {
                int c;
                mat[i][j]=b;
                c=a+b;
                a=b;
                b=c;
            }
            i++;
        }
    }
}

void afisare(std::vector<std::vector<int>> mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    int dim;
    cin>>dim;
    vector<vector<int>>mat;
    mat.resize(dim);
    for(int i=0;i<dim;i++)
        mat[i].resize(dim,0);
    
    modificare_matrice(mat.size(), mat);
    
    afisare(mat);
    
}
