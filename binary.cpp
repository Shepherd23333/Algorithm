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
    void print(int state){
        for(int i=0;i<3;i++){
            cout<<"Tape"<<i<<":";
            for(auto j:bst.tape[i])
                cout<<j<<" ";
            cout<<",pos:"<<bst.pos[i]<<"\n";
        }
        cout<<"State:"<<state<<"\n";
    }
    void simulate(){
        print(0);
        int low=bst.read(0);
        bst.move(0,1);
        print(1);
        bst.write(1,low);bst.move(1,1);
        print(2);
        int high=bst.read(0);
        bst.move(0,1);
        print(3);
        bst.write(1,high);bst.move(1,-1);
        print(4);
        if(low>high){
            print(bst.end=5);
            bst.write(2,-1);
            return ;
        }else{
            bst.move(1,2);
            print(6);
        }
        while(1){
            int mid=(low+high)/2;
            bst.write(1,mid);bst.moveTo(0,mid+3);
            print(7);
            int n=bst.read(0);
            bst.moveTo(0,2);
            print(8);
            int x=bst.read(0);
            if(n==x){
                print(bst.end=9);
                bst.write(2,mid);
                return ;
            }else if(n<x){
                bst.moveTo(1,0);
                print(10);
                bst.write(1,low=mid+1);bst.move(1,1);
                print(11);
                if(low>high){
                    print(bst.end=5);
                    bst.write(2,-1);
                    return ;
                }else{
                    bst.move(1,1);
                    print(6);
                }
            }else{
                bst.moveTo(1,1);
                print(12);
                bst.write(1,high=mid-1);bst.move(1,-1);
                print(4);
                if(low>high){
                    print(bst.end=5);
                    bst.write(2,-1);
                    return ;
                }else{
                    bst.move(1,2);
                    print(6);
                }
            }
        }
    }
    void final(){
        while(bst.tape[1].back()=="-1")
            bst.tape[1].pop_back();
        cout<<"Final State:\n";
        print(bst.end);
        cout<<"Step:"<<bst.steps<<",Size:"<<bst.tape[1].size()<<"\n";
    }
}