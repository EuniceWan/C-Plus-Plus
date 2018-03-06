#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>
#include "hexapawn.h"

int main() {
    std::cout << "Welcome to Hexapawn!\n";
    std::cout<<"Please give a number within 3-8 as width: \n";
    int n;
    int m;
    std::cin >> n;
    if (n<3||n>8){
        std::cout<<"You give a wrong number"<<std::endl;
        exit(0);
    }
    std::cout<<"Please give a number within 3-8 as height: \n";
    std::cin >> m;
    if (m<3||m>8){
        std::cout<<"You give a wrong number"<<std::endl;
        exit(0);
    }
    hexapawn _hexapawn(n,m);
    _hexapawn.play();
}