#include "BAB.h"
namespace bab{
    TuringMachine babt;
    struct node{
        int i,w,v;
        bool operator<(const node& n) const{
            return 1.0*v/w>1.0*n.v/n.w;
        }
    };
    void init(){
        babt.blank="0";
        babt.states={
            "readNum","readCapacity","updateW_greedy","updateV_greedy",
            "readWeight","readValue","readCur","readCurWeight","readCurValue",
            "writeAns_v","readAns(i)","readIndex","writeAns(i)",
            "readW(cur+1)","readV(cur+1)","writeHeadIndex","writeHeadWeight",
            "writeHeadValue","readCurVector(i)","readHeadVector(i)",
            "writeHeadVector(cur+1)","writeLeft","writeBound","readWeight(i)",
            "readValue(i)","writeBoundEnd","success"
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
            babt.moveTo(1,(n+3)*(y-1)+4);
            babt.print(6);
            int cur=babt.read(1);babt.move(1,1);
            babt.print(7);
            int p=babt.read(1);babt.move(1,1);
            babt.print(8);
            int q=babt.read(1),r,t,i;
            if(cur>=n){
                if(q>=v){
                    babt.moveTo(1,1);
                    babt.print(9);
                    babt.write(1,v=q);
                    babt.moveTo(0,2);babt.moveTo(1,(n+3)*(y-1)+7);
                    for(i=1;i<=n;i++){
                        babt.print(10);
                        r=babt.read(1);babt.move(1,1);
                        babt.print(11);
                        t=babt.read(0);babt.move(0,3);babt.moveTo(2,t);
                        babt.print(12);
                        babt.write(2,r);
                    }
                }
                continue;
            }
            babt.moveTo(0,3*cur+3);
            babt.print(13);
            r=babt.read(0);babt.move(0,1);
            babt.print(14);
            t=babt.read(0);
            if(p+r<=c){
                babt.moveTo(1,(n+3)*(x-1)+4);
                babt.print(15);
                babt.write(1,cur+1);babt.move(1,1);
                babt.print(16);
                babt.write(1,p+r);babt.move(1,1);
                babt.print(17);
                babt.write(1,q+t);babt.move(1,1);
                for(i=1;i<=cur;i++){
                    babt.move(1,(n+3)*(y-x));
                    babt.print(18);
                    r=babt.read(1);babt.move(1,(n+3)*(x-y));
                    babt.print(19);
                    babt.write(1,r);babt.move(1,1);
                }
                babt.print(20);
                babt.write(1,1);x++;
            }
            double l=c-p,b=q;
            babt.moveTo(1,2);
            babt.print(21);
            babt.write(1,l);babt.move(1,1);
            babt.print(22);
            babt.write(1,b);babt.moveTo(0,3*cur+3);
            for(i=cur+1;i<=n;i++){
                babt.print(23);
                r=babt.read(0);babt.move(0,1);
                babt.print(24);
                t=babt.read(0);babt.move(0,2);
                if(r<=l){
                    babt.move(1,-1);
                    babt.print(21);
                    babt.write(1,l-=r);babt.move(1,1);
                    babt.print(22);
                    babt.write(1,b+=t);
                }else{
                    babt.print(25);
                    babt.write(1,b+=l*t/r);
                    break;
                }
            }
            if(b>v){
                babt.moveTo(1,(n+3)*(x-1)+4);
                babt.print(15);
                babt.write(1,cur+1);babt.move(1,1);
                babt.print(16);
                babt.write(1,p);babt.move(1,1);
                babt.print(17);
                babt.write(1,q);babt.move(1,1);
                for(i=1;i<=cur;i++){
                    babt.move(1,(n+3)*(y-x));
                    babt.print(18);
                    r=babt.read(1);babt.move(1,(n+3)*(x-y));
                    babt.print(19);
                    babt.write(1,r);babt.move(1,1);
                }
                babt.print(20);
                babt.write(1,0);
                x++;
            }
        }
        babt.print(babt.end=26);
        babt.final();
    }
}