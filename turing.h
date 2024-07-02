#pragma once
#include<bits/stdc++.h>
using namespace std;

struct TuringMachine{
    vector<string> tape[3];
    int pos[3]={},steps,end;
    int read(int t){
        if(pos[t]>=tape[t].size())
            tape[t].resize(pos[t]+2,"-1");
        steps++;
        return stoi(tape[t][pos[t]]);
    }
    void write(int t,int data){
        if(pos[t]>=tape[t].size())
            tape[t].resize(pos[t]+2,"-1");
        steps++;
        tape[t][pos[t]]=to_string(data);
    }
    void move(int t,int step){
        pos[t]+=step;
    }
    void moveTo(int t,int p){
        pos[t]=p;
    }
};