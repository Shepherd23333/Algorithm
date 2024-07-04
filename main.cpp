#include "binaryT.h"
#include "dp.h"
#include "BAB.h"
int main(){
    int mode;
    cout<<"Input the mode:";
    cin>>mode;
    cout<<"Input the data:\n";
    switch(mode){
        case 1:
            binary::init();
            binary::simulate();
            break;
        case 2:
            break;
        case 3:
            dp::init();
            dp::simulate();
            break;
        case 4:
            bab::init();
            bab::simulate();
            break;
    }
    system("pause");
    return 0;
}