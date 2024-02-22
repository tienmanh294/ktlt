#include <vector>
#include <map>
#include <string>
#include <sstream>
#ifndef UTILS_H
#define UTILS_H
void customSplit(std::string str,char separator,std::vector<std::string>&strings);
void readTime(std::string time);
std::vector<std::string> readUsers(std::string list_users);
bool isNumber(std::string number);
bool isDateValid(std::string date);
int compareDate(std::string date1, std::string date2);
#endif