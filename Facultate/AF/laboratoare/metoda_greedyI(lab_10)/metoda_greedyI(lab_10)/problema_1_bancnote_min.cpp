//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct bancnota{
//    int bnc;
//    int ct;
//};
//
//bool comp(bancnota a, bancnota b) {
//    return a.bnc > b.bnc;
//}
//
//
//
//void nrbancnote_nelimitat(vector<bancnota> bnc, int s)
//{
//    int nrbnc=0;
//   
//    
//    vector<bancnota> vbnc;
//    sort(bnc.begin(), bnc.end(),comp);
//    int index=0;
//    while(index<bnc.size()&&s>0)
//    {
//        int ct = 0;
//        if(bnc[index].bnc<=s)
//        {
//            nrbnc += s/bnc[index].bnc;
//            ct = s/bnc[index].bnc;
//            s= s-(s/bnc[index].bnc)*bnc[index].bnc;
//        }
//        vbnc.push_back({ct,bnc[index].bnc});
//        index++;
//    }
//    
//   // cout<<"nr minim de bancnote este: "<<nrbnc;
//    for(int i=0;i<vbnc.size();i++)
//    {
//        if(vbnc[i].ct!=0)
//        cout<<"bancnota "<<vbnc[i].bnc<<" este folosita de "<<vbnc[i].ct<<" ori"<<'\n';
//    }
//}
//
//void nrbancnote_limitate(vector<bancnota> bnc, int s)
//{
//    int nrbnc=0;
//    
//    
//    sort(bnc.begin(), bnc.end(),comp);
//    int index=0;
//    
//    while(index<bnc.size()&&s>0)
//    {
//        
//        if(bnc[index].bnc<=s)
//        {
//            nrbnc += min(s/bnc[index].bnc,bnc[index].ct);
//            
//            s= s-min(s/bnc[index].bnc,bnc[index].ct)*bnc[index].bnc;
//        }
//        
//        index++;
//    }
//    
//   if(s==0)cout<<"nr minim de bancnote este: "<<nrbnc;
//   else cout<<"nu avem solutie";
//    
//}
//
//int main()
//{
//    std::vector<bancnota> bnc={{1,10},{5,3},{10,2},{20,3},{50,2},{100,3},{200,8},{500,1}};
//    int suma;
//    cout<<"Introduceti suma:";
//    cin>>suma;
//    nrbancnote_limitate(bnc, suma);
//    
//    
//}
