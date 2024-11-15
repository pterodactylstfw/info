#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
ifstream fin("teren.in");
ofstream fout("teren.out");

void citire(int &n, int &m, vector<vector<int>>& trn)
{
    // Verificăm dacă fișierul s-a deschis cu succes
    if (!fin) {
        cout << "Nu s-a putut deschide fisierul teren.in" << endl;
        return;
    }

    // Citim dimensiunile matricei
    fin >> n >> m;

    // Redimensionăm matricea
    trn.resize(n, vector<int>(m));

    // Citim valorile matricei
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> trn[i][j];
        }
    }
}

void afisare_initiala(int n, int m, vector<vector<int>>trn)
{
    cout<<n<<" "<<m<<'\n';
    for (const auto& row : trn) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
}

int validare(int n, int m, vector<vector<int>> trn)
{
    if(n<1||m<1) return 0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0,k=j+1;j<m-1,k<m;j++,k++)
        {
            if(trn[i][j]!=0&&trn[i][k]!=0)
            {
                if(fabs(trn[i][j]-trn[i][k])==min(trn[i][j],trn[i][k])) return 0;
            }
        }
    }
    
    return 1;
}
struct padure{
    int tip, sum;
};

void suma_paduri(int n, int m, vector<vector<int>>trn, vector<padure>&sumpad)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(trn[i][j]!=0)
                sumpad[trn[i][j]].sum++;
            if(sumpad[trn[i][j]].tip==0) sumpad[trn[i][j]].tip=trn[i][j];
        }
    
    for(int i=1;i<sumpad.size();i++)
        for(int j=i+1;j<sumpad.size();j++)
            if(sumpad[i].sum<sumpad[j].sum)
            {
                swap(sumpad[i],sumpad[j]);
            }
    
    for(int i=1;i<sumpad.size();i++)
        fout<<sumpad[i].tip<<" ";
    
}
struct pozitie{
    int x, y;
};

void leg_paduri(int n, int m, vector<vector<int>>trn, vector<pozitie>&poz)
{
    for(int i=1;i<n-2;i++)
        for(int j=1;j<m-2;j++)
        {
            int k=j+1;
            while (trn[i][k]!=0) k++;
            j=k-1;
            if(trn[i][j]==trn[i][k+1]) poz.push_back({i,k}); //verificat pe orizontala spre dreapta
            
            
        }
    
    for(int j=1;j<m-2;j++)
        for(int i=1;i<n-2;i++)
        {
            int k=i+1;
            while(trn[k][j]!=0) k++;
            i=k-1;
            if(trn[i][j]==trn[k+1][j]) poz.push_back({k,j});
        }
    
    for(auto i:poz)
        cout<<i.x<<" "<<i.y<<" ";
}
 //de revizuit


int main()
{
    int n,m;
    vector<vector<int>> trn;
    vector <padure> sumpad(5);
    vector<pozitie> poz;
    citire(n,m,trn);
//    afisare_initiala(n, m, trn);
//    fout<<validare(n, m, trn);
//    suma_paduri(n, m, trn, sumpad);
    leg_paduri(n, m, trn, poz);
    
    
}
