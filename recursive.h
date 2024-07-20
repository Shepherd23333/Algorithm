#pragma once
#include "turing.h"
template<typename T>
class Stack{
public:
    int size(){ return cap.size(); }
    int maxSize(){ return maxSiz; }
    void push(T value){
        cap.push_back(value);
        maxSiz=max(1ull*maxSiz,cap.size());
    }
    T top(){
        if(cap.empty())
            throw runtime_error("Empty stack");
        return cap.back();
    }
    T pop(){
        T value=top();cap.pop_back();
        return value;
    }
    void print(){
        for(auto i:cap)
            cout<<i<<" ";
    }
private:
    vector<T> cap;
    int maxSiz=0;    
};
struct data{
    int para,value,entry;
};
struct recursiveFunction{
    TuringMachine t;
    virtual void simulate()=0;
};