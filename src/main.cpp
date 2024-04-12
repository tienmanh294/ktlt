#include "../include/main.h"

int main(int argc, char* argv[]){
    if (argc<=1){
        std::cout<<"provide input file name"<<std::endl;
        return 0;
    }
    
    //std::string filename="test/input/";
    std::string inputFileName=argv[1];
    //std::ifstream input(filename+inputFileName);
    std::ifstream input(inputFileName);
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    SetupMapping();
    
    if (input.is_open()) {
        std::string line;
        int lineNumber=1;
        while (std::getline(input, line)) {
            if(line==""){
                continue;
            }
            readDirective(inputFileName,line,projects,users,tasks,issues,lineNumber);
            lineNumber++;
        }
        input.close();
    }
}
