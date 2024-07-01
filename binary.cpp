#include "binary.h"
namespace binary{
    TuringMachine bst;
    void init(){
        int low,high,x;
        cin>>low>>high>>x;
        bst.tape[0].push_back(to_string(low));
        bst.tape[0].push_back(to_string(high));
        bst.tape[0].push_back(to_string(x));
        for(int i=low;i<=high;i++){
            cin>>x;
            bst.tape[0].push_back(to_string(x));
        }
    }
    void simulate(){
        int low=bst.read(0);
        bst.move(0,1);bst.write(1,low);bst.move(1,1);
        int high=bst.read(0);
        bst.move(0,1);bst.write(1,high);bst.move(1,-1);
        if(low>high){
            bst.write(2,-1);
            return ;
        }else
            bst.move(1,2);
        while(1){
            int mid=(low+high)/2;
            bst.write(1,mid);bst.moveTo(0,mid+3);
            int n=bst.read(0);
            bst.moveTo(0,2);
            int x=bst.read(0);
            if(n==x){
                bst.write(2,mid);
                return ;
            }else if(n<x){
                bst.moveTo(1,0);
                bst.write(1,low=mid);bst.move(1,1);
                if(low>high){
                    bst.write(2,-1);
                    return ;
                }else
                    bst.move(1,1);
            }else{
                bst.moveTo(1,1);
                bst.write(1,high=mid);bst.move(1,-1);
                if(low>high){
                    bst.write(2,-1);
                    return ;
                }else
                    bst.move(1,2);
            }
        }
    }
    void print(){
        cout<<bst.tape[2][0]<<"\n";
    }
}