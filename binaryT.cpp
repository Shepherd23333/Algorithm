#include "binaryT.h"
namespace binaryT{
    TuringMachine bst;
    void init(){
        bst.blank="-1";
        bst.states={
            "initLow","writeLow","initHigh","writeHigh","compLow","stop",
            "calMid","readMid","compMid","success","updateLow","compHigh",
            "updateHigh"
        };
        int n,x;
        cin>>n;
        bst.tape[0].push_back(to_string(0));
        bst.tape[0].push_back(to_string(n-1));
        bst.tape[0].push_back("");
        for(int i=0;i<n;i++){
            cin>>x;
            bst.tape[0].push_back(to_string(x));
        }
        cin>>x;
        bst.tape[0][2]=to_string(x);
    }
    void simulate(){
        system("pause");
        bst.print(0);
        int low=bst.read(0);bst.move(0,1);
        system("pause");
        bst.print(1);
        bst.write(1,low);bst.move(1,1);
        system("pause");
        bst.print(2);
        int high=bst.read(0);bst.move(0,1);
        system("pause");
        bst.print(3);
        bst.write(1,high);bst.move(1,-1);
        system("pause");
        bst.print(4);
        if(low>high){
            system("pause");
            bst.print(bst.end=5);
            bst.write(2,-1);
            bst.final();
            return ;
        }else{
            bst.move(1,2);
            system("pause");
            bst.print(6);
        }
        while(1){
            int mid=(low+high)/2;
            bst.write(1,mid);bst.moveTo(0,mid+3);
            system("pause");
            bst.print(7);
            int n=bst.read(0);bst.moveTo(0,2);
            system("pause");
            bst.print(8);
            int x=bst.read(0);
            if(n==x){
                system("pause");
                bst.print(bst.end=9);
                
                bst.write(2,mid);
                bst.final();
                return ;
            }else if(n<x){
                bst.moveTo(1,0);
                system("pause");
                bst.print(10);
                bst.write(1,low=mid+1);bst.move(1,1);
                system("pause");
                bst.print(11);
                if(low>high){
                    system("pause");
                    bst.print(bst.end=5);
                    bst.write(2,-1);
                    bst.final();
                    return ;
                }else{
                    system("pause");
                    bst.move(1,1);
                    bst.print(6);
                }
            }else{
                bst.moveTo(1,1);
                system("pause");
                bst.print(12);
                bst.write(1,high=mid-1);bst.move(1,-1);
                system("pause");
                bst.print(4);
                if(low>high){
                    system("pause");
                    bst.print(bst.end=5);
                    bst.write(2,-1);
                    bst.final();
                    return ;
                }else{
                    system("pause");
                    bst.move(1,2);
                    bst.print(6);
                }
            }
        }
    }
}