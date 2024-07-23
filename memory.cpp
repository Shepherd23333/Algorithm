#include "memory.h"
struct dataM:public data{
    int cw;
    dataM(int pos,int c,int v=0,int e=0):cw(c){
        para=pos;value=v;entry=e;
    }
    friend ostream& operator<<(ostream& out,const dataM& d){
        out<<d.para<<" "<<d.cw<<" "<<d.value<<" "<<d.entry;
        return out;
    }
};
struct mem:public recursiveFunction{
    void init(){
        t.blank="-1";
        t.states={
            "readNum","readCacpacity","search","get","rangeOut","readWeight",
            "readValue","writePrice","readW(i)","ansM(i,j)","compM(i,j)",
            "success"
        };
        int n,c;
        cin>>c>>n;
        t.tape[0].push_back(to_string(n));
        t.tape[0].push_back(to_string(c));
        int w[n],v[n];
        for(auto &i:w)
            cin>>i;
        for(auto &i:v)
            cin>>i;
        for(int i=0;i<n;i++){
            t.tape[0].push_back(to_string(w[i]));
            t.tape[0].push_back(to_string(v[i]));
        }
    }
    void simulate(){
        Stack<dataM> s;
        auto print=[&](int state){
            t.print(state);
            cout<<"Stack:";
            s.print();
            cout<<"\n\n";
        };
        print(0);
        int n=t.read(0);t.move(0,1);
        print(1);
        int c=t.read(0),res,w,v,r;
        s.push({0,c});
        while(s.size()){
            dataM dt=s.pop();
            switch(dt.entry){
                case 0:
                    t.moveTo(1,dt.para*(c+1)+dt.cw);
                    print(2);
                    r=t.read(1);
                    if(r+1){
                        print(3);
                        res=r;
                    }else if(dt.para==n){
                        print(4);
                        t.write(1,res=0);
                    }else{
                        dt.entry=1;
                        s.push(dt);s.push({dt.para+1,dt.cw});
                    }
                    break;
                case 1:
                    t.moveTo(0,2*dt.para+2);
                    print(5);
                    w=t.read(0);t.move(0,1);
                    if(dt.cw>=w){
                        dt.value=res;dt.entry=2;
                        s.push(dt);s.push({dt.para+1,dt.cw-w});
                    }else{
                        t.moveTo(1,dt.para*(c+1)+dt.cw);
                        t.write(1,res);
                    }
                    break;
                case 2:
                    t.moveTo(0,2*dt.para+3);
                    print(6);
                    v=t.read(0);
                    t.moveTo(1,dt.para*(c+1)+dt.cw);
                    t.write(1,res=max(dt.value,res+v));
                    break;
            }
        }
        print(7);
        t.write(2,res);
        t.moveTo(0,2);t.moveTo(1,c);t.move(2,1);
        for(int i=0,x;i<n;i++){
            print(8);
            w=t.read(0);t.move(0,2);
            print(9);
            r=t.read(1);t.move(1,c+1);
            print(10);
            x=t.read(1);
            if(r-x){
                t.write(2,1);
                t.move(1,-w);
            }else
                t.write(2,0);
            t.move(2,1);
        }
        print(t.end=11);
        cout<<"Final State:\nStep:"<<t.steps<<"\nSize:Tape:"<<t.tape[1].size()
            <<", Stack:"<<4*s.maxSize()<<"\n";
        print(t.end);
    }
};
namespace memory{
    void simulate(){
        mem t;
        t.init();
        t.simulate();
    }
};