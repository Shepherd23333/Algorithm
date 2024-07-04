#include "BAB.h"
namespace bab{
    TuringMachine babt;
    struct node{
        int w,v;
        bool operator<(const node& n) const{
            return 1.0*v/w>1.0*n.v/n.w;
        }
    };
    void init(){
        babt.b="0";
        babt.states={
            "readNum","readCapacity","readWeight","readValue","writeM(i,j)",
            "readM(i,j)","readW(i)","calM(i,j)","comp","ansM(i,j)","compAnsM(i,j)",
            "writeAns(i)","writeAns(n)","success"
        };
        int n,c;
        cin>>c>>n;
        babt.tape[0].push_back(to_string(n));
        babt.tape[0].push_back(to_string(c));
        node a[n];
        for(int i=0;i<n;i++)
            cin>>a[i].w;
        for(int i=0;i<n;i++)
            cin>>a[i].v;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            babt.tape[0].push_back(to_string(a[i].w));
            babt.tape[0].push_back(to_string(a[i].v));
        }
    }
    void simulate(){
        
    }
}