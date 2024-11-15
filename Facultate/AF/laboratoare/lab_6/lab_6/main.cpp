#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> citire(){
    int n;
    cin>>n;
    vector<vector<int>> matr;
    matr.resize(n);
    for(int i=0;i<n;i++) matr[i].resize(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>matr[i][j];
    return matr;
}

void afisare(vector<vector<int>> matr)
{
    for( const auto& row: matr)
    {for(const auto& elem: row)
        cout<<elem<<" ";
        cout<<'\n';
        }
}

bool valid(vector<vector<int>>matr)
{
    int n=matr.size();
    vector<int> fr(n*n,0);
    
    for( const auto& row: matr)
      for(const auto& elem: row)
      {
          if(elem >= n*n&&elem<0) return false;
          fr[elem]++;
          if(fr[elem]>1) return false;
      }
    
    return 1;
}

vector<vector<vector<int>>> modif_matrice(vector<vector<int>> matr)
{
    pair<int, int> poszero ;
    vector<vector<vector<int>>> mdf_matr;
    
    for(int i=0;i<matr.size();i++)
        for(int j=0;j<matr[i].size();j++)
        {
            if(matr[i][j]==0) {poszero = {i,j};
                break;}
            
        }
    
    int x = poszero.first;
        int y = poszero.second;

        // Mutare spre Nord
        if (x > 0) {
            vector<vector<int>> matr_nord = matr;
            swap(matr_nord[x][y], matr_nord[x - 1][y]);
            mdf_matr.push_back(matr_nord);
        }

        // Mutare spre Sud
        if (x < matr.size() - 1) {
            vector<vector<int>> matr_sud = matr;
            swap(matr_sud[x][y], matr_sud[x + 1][y]);
            mdf_matr.push_back(matr_sud);
        }

        // Mutare spre Vest
        if (y > 0) {
            vector<vector<int>> matr_vest = matr;
            swap(matr_vest[x][y], matr_vest[x][y - 1]);
            mdf_matr.push_back(matr_vest);
        }

        // Mutare spre Est
        if (y < matr[x].size() - 1) {
            vector<vector<int>> matr_est = matr;
            swap(matr_est[x][y], matr_est[x][y + 1]);
            mdf_matr.push_back(matr_est);
        }

        return mdf_matr;
    
    
}

/*
 n = 5 => n^2-1 = 24
 */

int main(){
    
    vector<vector<int>> matr;
    matr=citire();
//    afisare(matr);
    
//    cout<<'\n'<<valid(matr);
    
    
    vector<vector<vector<int>>> mdf_matr;
    mdf_matr = modif_matrice(matr);
    
    cout<<endl<<endl;
    for(int i=0;i<mdf_matr.size();i++)
    {for(int j=0;j<mdf_matr[i].size();j++)
    {
        for(int k=0;k<mdf_matr[i][j].size();k++)
            cout<<mdf_matr[i][j][k]<<" ";
        cout<<endl;
    }
        cout<<endl;}
    
}
