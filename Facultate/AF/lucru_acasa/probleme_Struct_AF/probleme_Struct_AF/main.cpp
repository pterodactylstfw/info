#include <iostream>
#include <vector>
#include <fstream>

std::ifstream fin("date.txt");

struct Pixel
{
    int red, green, blue;
};

std::vector<std::vector<Pixel>>citire()
{
    
    
    int n, m;
    fin>>n>>m;
    std::vector<std::vector<Pixel>> vect;
    vect.resize(n);
    for(int i=0;i<n;i++)
        vect[i].resize(m);
    
    for(int i=0;i<vect.size();i++)
        for(int j=0;j<vect[i].size();j++)
            fin>>vect[i][j].red>>vect[i][j].green>>vect[i][j].blue;
    
    
    
    return vect;
    
}


void afisare(std::vector<std::vector<Pixel>> v)
{
    for(const auto& row: v)
    {for(const auto & elem:row)
        std::cout<<elem.red<<" "<<elem.green<<" "<<elem.blue<<"  ";
        std::cout<<'\n';}
}

int verif_culori_unice(std::vector<std::vector<Pixel>>v)
{
    for(const auto&row:v)
        for(const auto & elem:row)
        {
            if(elem.red==0&&elem.blue==0&&elem.green!=0) return 1;
            if(elem.red==0&&elem.blue!=0&&elem.green==0) return 1;
            if(elem.red!=0&&elem.blue==0&&elem.green==0) return 1;
        }
    return 0;
}

void rotire_90(std::vector<std::vector<Pixel>>&v)
{
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v[i].size();j++)
            std::swap(v[i][j],v[j][v.size()-i-1]);
}

int intensitate(Pixel px)
{
    return (px.green+px.blue+px.red)/3;
}

void prim_plan(const std::vector<std::vector<Pixel>>& v, int val) {
    for (int i = 0; i < v.size(); ++i) {
        const auto& row = v[i]; // row este acum un vector<Pixel>
        
        for (int j = 0; j < row.size(); ++j) {
            const auto& elem = row[j]; // elem este un Pixel
            
            if (intensitate(elem) > val) {
                std::cout << elem.red << " " << elem.green << " " << elem.blue << "  ";
                std::cout << "la pozitia i:" << i << " si pozitia j: " << j << std::endl;
            }
        }
    }
}


int main()
{
    std::vector<std::vector<Pixel>> pixel=citire();
    afisare(pixel);
    std::cout<<'\n'<<'\n';
    std::cout<<verif_culori_unice(pixel);
    std::cout<<'\n'<<'\n';
    rotire_90(pixel);
    afisare(pixel);
    std::cout<<'\n'<<'\n';
    
    int val;
    fin>>val;
    
    prim_plan(pixel, val);
    
    
}
