#include "dp.h"
namespace dp{
    TuringMachine dpt;
    void init(){
        dpt.b="0";
        dpt.states={
            "readNum","readCapacity","readWeight","readValue","writeM(i,j)",
            "readM(i,j)","readW(i)","calM(i,j)","comp","ansM(i,j)","compAnsM(i,j)",
            "writeAns(i)","writeAns(n)","success"
        };
        int n,c;
        cin>>c>>n;
        dpt.tape[0].push_back(to_string(n));
        dpt.tape[0].push_back(to_string(c));
        int w[n],v[n];
        for(auto &i:w)
            cin>>i;
        for(auto &i:v)
            cin>>i;
        for(int i=0;i<n;i++){
            dpt.tape[0].push_back(to_string(w[i]));
            dpt.tape[0].push_back(to_string(v[i]));
        }
    }
    void simulate(){
        dpt.print(0);
        int n=dpt.read(0);dpt.move(0,1);
        dpt.print(1);
        int c=dpt.read(0),w,x;dpt.move(0,1);
        for(int i=0,v;i<n;i++){
            dpt.print(2);
            w=dpt.read(0);dpt.move(0,1);
            dpt.print(3);
            v=dpt.read(0);dpt.move(0,1);
            for(int j=0,t;j<=c;j++){
                if(i){
                    dpt.print(5);
                    dpt.moveTo(1,(i-1)*(c+1)+j);
                    x=dpt.read(1);
                    if(j>=w){
                        dpt.print(7);
                        dpt.move(1,-w);
                        int y=dpt.read(1);
                        dpt.print(8);
                        t=max(x,y+v);
                    }else
                        t=x;
                    dpt.moveTo(1,i*(c+1)+j);
                }else
                    t=(j>=w)*v;
                dpt.print(4);
                dpt.write(1,t);
                dpt.move(1,1);
            }
        }
        dpt.move(0,-2);dpt.move(1,-1);dpt.moveTo(2,n-1);
        for(int i=1,y;i<n;i++){
            dpt.print(6);
            w=dpt.read(0);dpt.move(0,-2);
            dpt.print(9);
            x=dpt.read(1);dpt.move(1,-c-1);
            dpt.print(10);
            y=dpt.read(1);
            if(x-y){
                dpt.print(11);
                dpt.write(2,1);dpt.move(1,-w);
            }
            dpt.move(2,-1);
        }
        dpt.print(12);
        x=dpt.read(1);
        if(x)
            dpt.write(2,1);
        dpt.print(dpt.end=13);
        dpt.final();
    }
};