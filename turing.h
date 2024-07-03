#pragma once
#include<bits/stdc++.h>
using namespace std;

struct TuringMachine{
    string b;
    vector<string> tape[3],states;
    int pos[3]={},steps,end;
    int read(int t){
        if(pos[t]>=tape[t].size())
            tape[t].resize(pos[t]+2,b);
        steps++;
        return stoi(tape[t][pos[t]]);
    }
    void write(int t,int data){
        if(pos[t]>=tape[t].size())
            tape[t].resize(pos[t]+2,b);
        steps++;
        tape[t][pos[t]]=to_string(data);
    }
    void move(int t,int step){
        pos[t]+=step;
    }
    void moveTo(int t,int p){
        pos[t]=p;
    }
    void print(int st){
        for(int i=0;i<3;i++){
            cout<<"Tape"<<i<<":";
            for(auto j:tape[i])
                cout<<j<<" ";
            cout<<",pos:"<<pos[i]<<"\n";
        }
        cout<<"State:"<<states[st]<<"\n\n";
    }
    void final(){
        while(tape[1].back()==b)
            tape[1].pop_back();
        cout<<"Final State:\n";
        cout<<"Step:"<<steps<<",Size:"<<tape[1].size()<<"\n";
        print(end);
    }
};