//
//  main.cpp
//  Divide & Impera (fisa I)  - problema 6, rafturi
//
//  Created by Raul Constantin on 27.11.2024.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
struct Carte{
    std::string titlu;
    int an_ap;
};


std::vector<std::vector<Carte>> citire()
{
    std::ifstream fin("date.txt");
    if (!fin.is_open()) {
        std::cerr << "Eroare: Nu pot deschide fisierul 'date.txt'!" << std::endl;
        return {};
    }

    std::vector<std::vector<Carte>> rafturi;
    std::string raft;

    while (getline(fin, raft)) {
        std::istringstream is(raft);
        std::string carte;
        std::vector<Carte> carti_pe_raft;

        while (getline(is, carte, ';')) {
            std::istringstream iss(carte);
            Carte c;
            getline(iss, c.titlu, ',');
            iss >> c.an_ap;

            
            carti_pe_raft.push_back(c);
        }

        rafturi.push_back(carti_pe_raft);
    }

    return rafturi;
}

void afisare(std::vector<std::vector<Carte>> v)
{
    for(auto elem: v)
        for(auto carte: elem)
            std::cout<<carte.an_ap<<" "<<carte.titlu<<'\n';
        
}

bool comparator(Carte a, Carte b)
{
    if(a.an_ap!= b.an_ap)
        return a.an_ap < b.an_ap;
    
    return a.titlu < b.titlu;
}

bool verificare_sortare_raft(std::vector<Carte> raft, bool comparator (Carte a, Carte b), int st, int dr)
{
    if(st>=dr) return true;

    int mij = (st+dr)/2;
    
    bool stangaSort =verificare_sortare_raft(raft, comparator, st, mij);
    
    bool dreaptaSort = verificare_sortare_raft(raft, comparator, mij+1, dr);
    bool granita = comparator(raft[mij], raft[mij+1]);
    
    return stangaSort&&dreaptaSort&&granita;
        
}

void verif_sort_biblioteca( std::vector<std::vector<Carte>> bibl)
{
    for(int i=0; i< bibl.size();i++)
    {if(verificare_sortare_raft(bibl[i], comparator, 0, bibl[i].size()-1))
    {std::cout<<"Raftul este sortat"<<'\n';
        }
        
    else {std::cout<<"Raftul nu este sortat!";
        }
    }
    
}



int main(int argc, const char * argv[]) {
    
    std::vector<std::vector<Carte>> rafturi = citire();
    afisare(rafturi);
    
    std::cout<<'\n'<<'\n';
    
    verif_sort_biblioteca(rafturi);
    return 0;
}

