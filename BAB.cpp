#include "BAB.h"
namespace bab{
    TuringMachine babt(5);
    struct node{
        int i,w,v;
        bool operator<(const node& n) const{
            return 1.0*v/w>1.0*n.v/n.w;
        }
    };
    void init(){
        babt.blank="0";
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
        for(int i=0;i<n;i++){
            a[i].i=i;
            cin>>a[i].w;
        }
        for(int i=0;i<n;i++)
            cin>>a[i].v;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            babt.tape[0].push_back(to_string(a[i].i));
            babt.tape[0].push_back(to_string(a[i].w));
            babt.tape[0].push_back(to_string(a[i].v));
        }
    }
    void simulate(){
        babt.print(0);
        int n=babt.read(0);babt.move(0,1);
        babt.print(1);
        int c=babt.read(0);babt.move(0,2);
        babt.print(2);
        int x=babt.read(1);babt.move(1,1);
        babt.print(3);
        int y=babt.read(1),w,v;babt.move(1,-1);
        while(1){
            babt.print(4);
            w=babt.read(0);babt.move(0,1);
            if(x+w<=c){
                babt.print(5);
                v=babt.read(0);babt.move(0,2);
                babt.print(2);
                babt.write(1,x+=w);babt.move(1,1);
                babt.print(3);
                babt.write(1,y+=v);babt.move(1,-1);
            }else
                break;
        }
        v=y;
        for(x=2,y=1;x>y;y++){
            babt.moveTo(1,(n+3)*(y-1)+2);
            babt.print(6);
            int cur=babt.read(1);
            if(cur>=n){
                babt.move(1,2);
                babt.print(7);
                int cur_v=babt.read(1);
                if(cur_v>=v){
                    babt.moveTo(1,1);
                    babt.print(8);
                    babt.write(1,v=cur_v);
                    babt.moveTo(0,2);babt.moveTo(1,(n+3)*(y-1)+5);
                    for(int i=1,p,t;i<=n;i++){
                        babt.print(9);
                        p=babt.read(1);babt.move(1,1);
                        babt.print(10);
                        t=babt.read(0);babt.move(0,3);babt.moveTo(2,t);
                        babt.print(11);
                        babt.write(2,p);
                    }
                }
                continue;
            }
            
        }
    }
}