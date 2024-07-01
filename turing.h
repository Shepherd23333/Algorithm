#include<bits/stdc++.h>
using namespace std;

class TuringMachine{
public:
    vector<string> tape[3];
    int read(int t){
        if(pos[t]>=tape[t].size())
            tape[t].resize(pos[t]+2);
        return stoi(tape[t][pos[t]]);
    }
    void write(int t,int data){
        if(pos[t]>=tape[t].size())
            tape[t].resize(pos[t]+2);
        tape[t][pos[t]]=to_string(data);
    }
    void move(int t,int step){
        pos[t]+=step;
    }
    void moveTo(int t,int p){
        pos[t]=p;
    }
private:
    int pos[3]={};
};