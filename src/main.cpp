#include <iostream>
#include <fstream>
#include "../include/main.h"
int main(int argc, char* argv[]){
    if (argc<=1){
        return 0;
    }
    std::string filename="../test/input/";
    std::ifstream input(filename+argv[1]);
    if (input.is_open()) {
        std::string line;
        while (std::getline(input, line)) {
            printf("%s\n", line.c_str());
        }
        input.close();
    }
}