#pragma once
#include<bits/stdc++.h>
using namespace std;

struct TuringMachine{
    vector<vector<string>> tape;
    vector<string> states;
    vector<int> pos;
    int steps,end;
    string blank;
    TuringMachine(int t=3){
        tape.resize(t);
        pos.resize(t);
    }
    int read(int t){
        if(pos[t]>=tape[t].size())
            tape[t].resize(pos[t]+2,blank);
        steps++;
        return stoi(tape[t][pos[t]]);
    }
    void write(int t,int data){
        if(pos[t]>=tape[t].size())
            tape[t].resize(pos[t]+2,blank);
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
        for(int i=0;i<tape.size();i++){
            cout<<"Tape"<<i<<":";
            for(auto j:tape[i])
                cout<<j+" ";
            cout<<",pos:"<<pos[i]<<"\n";
        }
        cout<<"State:"+states[st]+"\n";
        //system("pause");
        cout<<"\n";
    }
    void final(){
        for(auto t:tape)
            while(t.back()==blank)
                t.pop_back();
        cout<<"Final State:\nStep:"<<steps<<",Size:"<<tape[1].size()<<"\n";
        print(end);
    }
};