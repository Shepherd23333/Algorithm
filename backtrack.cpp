#include "backtrack.h"
struct dataBt:public data{
    friend ostream& operator<<(ostream& out,const dataBt& d){
        out<<d.para<<" "<<d.entry;
        return out;
    }
};
struct node{
    int i,w,v;
    bool operator<(const node& n) const{
        return 1.0*v/w>1.0*n.v/n.w;
    }
};
struct bt:public recursiveFunction{
    void init(){
        t.blank="0";
        t.states={
            "readNum","readCapacity","compPos","updateAns_v","updateAns(i)",
            "readValue","compWeight","updateCurWeight","updateCurValue",
            "readIndex","updateVector(i)","backCurWeight","backCurValue",
            "backVector(i)","initLeft","initBound","readValue(i)",
            "compWeight(i)","updateLeft","updateBound","updateBoundEnd",
            "compBound","success"
        };
        int n,c;
        cin>>c>>n;
        t.tape[0].push_back(to_string(n));
        t.tape[0].push_back(to_string(c));
        node a[n];
        for(int i=0;i<n;i++){
            a[i].i=i;
            cin>>a[i].w;
        }
        for(int i=0;i<n;i++)
            cin>>a[i].v;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            t.tape[0].push_back(to_string(a[i].i));
            t.tape[0].push_back(to_string(a[i].w));
            t.tape[0].push_back(to_string(a[i].v));
        }
    }
    void simulate(){
        int n,c,cw=0,cv=0,res=0,w,v,i;
        double cl,b;
        Stack<dataBt> s;
        auto print=[&](int state){
            t.print(state);
            cout<<"Stack:";
            s.print();
            cout<<"\n\n";
        };
        auto bound=[&](int ind){
            t.moveTo(1,3);
            print(14);
            t.write(1,cl=c-cw);t.move(1,1);
            print(15);
            t.write(1,b=cv);
            for(;ind<=n;ind++){
                t.moveTo(0,3*ind+1);
                print(16);
                v=t.read(0);t.move(0,-1);
                print(17);
                w=t.read(0);
                if(w>cl)
                    break;
                t.move(1,-1);
                print(18);
                t.write(1,cl-=w);t.move(1,1);
                print(19);
                t.write(1,b+=v);
            }
            if(ind<=n){
                print(20);
                t.write(1,b+=cl*v/w);
            }
        };
        print(0);
        n=t.read(0);t.move(0,1);
        print(1);
        c=t.read(0);t.move(0,2);
        s.push({1});
        while(s.size()){
            dataBt dt=s.pop();
            switch(dt.entry){
                case 0:
                    print(2);
                    if(dt.para>n){
                        t.moveTo(2,0);
                        print(3);
                        t.write(2,res=cv);t.moveTo(1,4);
                        for(i=0;i<n;i++){
                            t.move(1,1);t.move(2,1);
                            print(4);
                            t.write(2,t.read(1));
                        }
                    }else{
                        t.moveTo(0,3*dt.para+1);
                        print(5);
                        v=t.read(0);t.move(0,-1);
                        print(6);
                        w=t.read(0);
                        if(cw+w<=c){
                            t.moveTo(1,0);
                            print(7);
                            t.write(1,cw+=w);t.move(1,1);
                            print(8);
                            t.write(1,cv+=v);t.moveTo(0,3*dt.para-1);
                            print(9);
                            i=t.read(0);t.moveTo(1,i+5);
                            print(10);
                            t.write(1,1);
                            dt.entry=1;
                            s.push(dt);s.push({dt.para+1});
                            break;
                        }
                        dt.entry=2;
                        s.push(dt);
                    }
                    break;
                case 1:
                    t.moveTo(0,3*dt.para);t.moveTo(1,0);
                    print(11);
                    t.write(1,cw-=w=t.read(0));
                    t.move(0,1);t.move(1,1);
                    print(12);
                    t.write(1,cv-=v=t.read(0));t.move(0,-2);
                    t.moveTo(1,(i=t.read(0))+5);
                    print(13);
                    t.write(1,0);
                    dt.entry=2;
                    s.push(dt);
                    break;
                case 2:
                    bound(dt.para+1);
                    print(21);
                    if(b>res)
                        s.push({dt.para+1});
                    break;
            }
        }
        print(t.end=22);
        cout<<"Final State:\nStep:"<<t.steps<<"\nSize:Tape:"<<t.tape[1].size()
            <<", Stack:"<<2*s.maxSize()<<"\n";
        print(t.end);
    }
};
namespace back{
    void simulate(){
        bt b;
        b.init();
        b.simulate();
    }
};