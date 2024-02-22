#include "../include/Utils.h"
void customSplit(std::string str,char separator,std::vector<std::string>&strings) {
    std::stringstream ss(str);
 
    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, separator);
        if(substr==""){
            continue;
        }
        strings.push_back(substr);
    }
}
void readTime(std::string time){
    int day=std::stoi(time.substr(0,2));
    int month=std::stoi(time.substr(2,2));
    int year=std::stoi(time.substr(4,4));
}

std::vector<std::string> readUsers(std::string list_users){
    std::vector<std::string>users;
    customSplit(list_users,',',users);
    return users;
}

bool isNumber(std::string number){
    for(int i=0;i<number.length();i++){
        if(int(number[i])>57||int(number[i])<48){
            return false;
        }
    }
    return true;
};

bool isDateValid(std::string date){
    if(date.length()!=8){
        return false;
    }
    int day=std::stoi(date.substr(0,2));
    int month=std::stoi(date.substr(2,2));
    int year=std::stoi(date.substr(4,4));
    if(day>31||day<1){
        return false;
    }
    if(month>12||month<1){
        return false;
    }
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        if(day>31){
            return false;
        }
    }
    if(month==4||month==6||month==9||month==11){
        if(day>30){
            return false;
        }
    }
    if(month==2){
        if(day>29){
            return false;
        }
    }
    return true;
}
//date1>date2 return 1
//date1=date2 return 0
//date1<date2 return -1
int compareDate(std::string date1, std::string date2){
    int day1=std::stoi(date1.substr(0,2));
    int month1=std::stoi(date1.substr(2,2));
    int year1=std::stoi(date1.substr(4,4));
    int day2=std::stoi(date2.substr(0,2));
    int month2=std::stoi(date2.substr(2,2));
    int year2=std::stoi(date2.substr(4,4));
    if(year1>year2){
        return 1;
    }else if(year1<year2){
        return -1;
    }
    if(month1>month2){
        return 1;
    }else if(month1<month2){
        return -1;
    }
    if(day1>day2){
        return 1;
    }else if(day1<day2){
        return -1;
    }else{
        return 0;
    }
};