#include "binary.h"
#include "dp.h"
int main(){
    int mode;
    cout<<"Input the mode:";
    cin>>mode;
    cout<<"Input the data:\n";
    switch(mode){
        case 0:
            binary::init();
            binary::simulate();
            break;
        case 1:
            break;
        case 2:
            dp::init();
            dp::simulate();
            break;
        case 3:
            break;
    }
    system("pause");
    return 0;
}