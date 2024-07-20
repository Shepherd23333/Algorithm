#include "binaryT.h"
#include "binaryR.h"
#include "dp.h"
#include "BAB.h"
#include "memory.h"
int main(){
    int mode;
    cout<<"Input the mode:";
    cin>>mode;
    cout<<"Input the data:\n";
    switch(mode){
        case 1:
            binaryT::init();
            binaryT::simulate();
            break;
        case 2:
            binaryR::simulate();
            break;
        case 3:
            dp::init();
            dp::simulate();
            break;
        case 4:
            bab::init();
            bab::simulate();
            break;
        case 5:
            memory::simulate();
            break;
    }
    system("pause");
    return 0;
}