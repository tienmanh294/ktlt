#include "../include/User.h"
int User::getID(){
    return this.id;
};
void User::setID(int id){
    this.id=id;
};
std::string User::getFullName(){
    return this.fullname;
};
void User::setFullName(std::string fullname){
    this.fullname=fullname;
};
int User::getCreatedBy(){
    return this.created_by;
};
void User::setCreatedBy(int created_by){
    this.created_by=created_by;
};
Roles User::getRole(){
    return this.role;
};
void User::setRole(Roles role){
    this.role=role;
};