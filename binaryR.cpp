#include "binaryR.h"
struct dataB:public data{
    int high;
    dataB(int low,int high,int v=0,int e=0):high(high){
        para=low;value=v;entry=e;
    }
    friend ostream& operator<<(ostream& out,const dataB& d){
        out<<d.para<<" "<<d.high;
        return out;
    }
};
struct bsr:public recursiveFunction{
    void init(){
        t.blank="-1";
        t.states={
            "readLow","compareHigh","stop","return","calMid","readMid",
            "compareMid","success","updateLow","updateHigh"
        };
        int n,x;
        cin>>n;
        t.tape[0].push_back(to_string(0));
        t.tape[0].push_back(to_string(n-1));
        t.tape[0].push_back("");
        for(int i=0;i<n;i++){
            cin>>x;
            t.tape[0].push_back(to_string(x));
        }
        cin>>x;
        t.tape[0][2]=to_string(x);
    }
    void simulate(){
        Stack<dataB> s;
        auto print=[&](int state){
            t.print(state);
            cout<<"Stack:";
            s.print();
            cout<<"\n\n";
        };
        system("pause");
        print(0);
        int low=t.read(0);t.move(0,1);
        int high=t.read(0);
        s.push({low,high});
        while(s.size()){
            dataB dt=s.top();
            system("pause");
            print(1);
            if(dt.para>dt.high){
                system("pause");
                print(t.end=2);
                t.write(2,-1);
                while(s.size()){
                    system("pause");
                    print(3);
                    s.pop();
                    system("pause");
                    print(2);
                }
                break;
            }
            system("pause");
            print(4);
            int mid=(dt.para+dt.high)/2;
            t.write(1,mid);t.moveTo(0,mid+3);
            system("pause");
            print(5);
            int a=t.read(0);t.moveTo(0,2);
            system("pause");
            print(6);
            int x=t.read(0);
            if(a==x){
                system("pause");
                print(t.end=7);
                t.write(2,mid);
                while(s.size()){
                    system("pause");
                    print(3);
                    s.pop();
                    system("pause");
                    print(7);
                }
            }else if(a<x){
                system("pause");
                print(8);
                s.push({mid+1,dt.high});
            }else{
                system("pause");
                print(9);
                s.push({dt.para,mid-1});
            }
        }
        cout<<"Final State:\nStep:"<<t.steps<<"\nSize:Tape:"<<t.tape[1].size()
            <<", Stack:"<<2*s.maxSize()<<"\n";
        print(t.end);
    }
};
namespace binaryR{
    void simulate(){
        bsr s;
        s.init();
        s.simulate();
    }
}