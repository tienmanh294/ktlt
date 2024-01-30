#include "../include/Utils.h"
void customSplit(string str, char separator,vector<string>strings) {
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++) {
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
}
void readTime(std::string time){
    int day=stoi(time.substr(0,2));
    int month=stoi(time.substr(2,2));
    int year=stoi(time.substr(4,4));
}

std::vector<string> readUsers(std::string list_users){
    vector<string>users;
    customSplit(list_users,",",users);
    return users;
}

void readDirective(std::string directive){
    std::vector<std::string>temp;
    std::map<string,bool> keyword;
    keyword["create"]=true;
    keyword["delete"]=true;
    keyword["edit"]=true;
    customSplit(directive,",",temp);
    if (keyword.find(temp[0]) == m.end()) {
        if (temp[0]=="create_report"){
            CreateReport();
        }else{
            SetDate(temp[1]);
        }
    } else {
        switch (temp[1])  {
            case "task":
                switch (temp[0])  {
                    case "create":
                        
                        break;

                    case "edit":
                        
                        break;
                    case "delete":
                        break;
                    default:
                        break;
                }
                break;

            case "project":
                
                break;
            case "issue":
                
                break;

            case "user":
                
                break;
                
            default:
                break;
        }
    }
}