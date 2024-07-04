#include "recursive.h"
// 栈的模拟
template <typename T>
class Stack{
public:
    void push(T value) { stack_.push(value); }
    T pop(){
        if (stack_.empty())
            throw std::runtime_error("Stack is empty!");
        T value = stack_.top();
        stack_.pop();
        return value;
    }
    bool empty() const { return stack_.empty(); }

private:
    std::stack<T> stack_;
    /* int low,high,mid; */
};
// 仿真类
class Simulation{
public:
    Simulation(TuringMachine t, int target)
        : t_(t), target_(target), steps_(0), paperTapeSpace_(0), stackSpace_(0) {}
    int simulateBinarySearch(){
        return simulateBinarySearchRecursive(0, t_.tape[0].size() - 4);
    }

    int simulateBinarySearchRecursive(int low, int high){
        steps_++;          // 递归调用步骤增加
        stackSpace_++;     // 栈空间增加（进入递归）
        paperTapeSpace_++; // 假设纸带空间增加（这里简单使用步骤数作为示例）

        cout << "Step " << steps_ <<endl;
        t_.print(0);
        steps_++;
        system("pause");

        t_.move(0, 1);
        cout << "Step " << steps_ <<endl;
        t_.print(1);
        steps_++;
        system("pause");

        if (low > high){
            cout << "Step " << steps_ <<endl;
            t_.print(2);
            steps_++;
            system("pause");

            t_.write(2, -1);
            return -1;
        }else {
            cout << "Step " << steps_ <<endl;
            t_.print(3);
            steps_++;
            system("pause");

            int mid = (low + high) / 2;
            t_.write(1, mid);
            t_.moveTo(0, mid + 3);
        }
        cout << "Step " << steps_ <<endl;
        t_.print(4);
        steps_++;
        system("pause");

        int n = t_.read(0);
        t_.moveTo(0, 2);
        cout << "Step " << steps_ <<endl;
        t_.print(5);
        steps_++;
        system("pause");

        if (n == target_){
            t_.write(2,n);
            cout << "Step " << steps_ <<endl;
            t_.print(6);
            steps_++;
            system("pause");

            t_.write(2, n);
            int p=3,w;
            t_.moveTo(0,3);
            while(1){
                w=t_.read(0);
                if(w!=target_){
                    p++;
                    t_.moveTo(0,p);
                }else
                    break;
            }
            return p-3;
        }else if (n < target_){
            cout << "Step " << steps_ <<endl;
            t_.print(7);
            printStepInfo(low, high);
            system("pause");

            simulateBinarySearchRecursive((low + high) / 2 + 1, high);
        }else{
            cout << "Step " << steps_ <<endl;
            t_.print(8);
            printStepInfo(low, high);
            system("pause");

            simulateBinarySearchRecursive(low, (low + high) / 2 - 1);
        }
    }
    TuringMachine t_;
    int target_;
    int steps_;
    int paperTapeSpace_;
    int stackSpace_;
    void printStepInfo(int low, int high){
        std::cout << "stack content:" << "  low:" << low << "  high:" << high << "  mid:" << (low + high) / 2 << std::endl;
    }
};
void main1(){
    TuringMachine t;
    t.blank = "-1";
    t.steps = 0;
    t.states = {
        "readLow", "readHigh", "compareHigh", "calMid", "readMid",
        "compareMid", "success", "updateLow", "updateHigh", "call"
    };
    int n, x;
    cin >> n >> x;
    t.tape[0].push_back(to_string(0));
    t.tape[0].push_back(to_string(n - 1));
    t.tape[0].push_back(to_string(x));
    for (int i = 0; i < n; i++){
        int x1;
        cin >> x1;
        t.tape[0].push_back(to_string(x1));
    }

    Simulation simulation(t, x);
    int result = simulation.simulateBinarySearch();

    if (result != -1)
        cout << "Found " << simulation.target_ << " at index " << result << endl;
    else
        cout << simulation.target_ << " not found in the array.\n";
    return;
}