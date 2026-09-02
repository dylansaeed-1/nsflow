#include <iostream>
#include "nsflow/version.hpp"
int main(int argc, char *argv[]){
    std::cout << version() << std::endl;
    return 1;
}