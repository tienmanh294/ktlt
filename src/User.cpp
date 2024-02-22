#include "../include/User.h"
int User::getID(){
    return this->id;
};
void User::setID(int id){
    this->id=id;
};
std::string User::getFullName(){
    return this->fullname;
};
void User::setFullName(std::string fullname){
    this->fullname=fullname;
};
int User::getCreatedBy(){
    return this->created_by;
};
void User::setCreatedBy(int created_by){
    this->created_by=created_by;
};
Roles User::getRole(){
    return this->role;
};
void User::setRole(Roles role){
    this->role=role;
};
User::User(){
    this->created_by=-1;
    this->role=Roles::project_manager;
}
std::vector<int> User::getProjects(){
    return this->projects;
};
std::vector<int> User::getTasks(){
    return this->tasks;
};
std::vector<int> User::getIssues(){
    return this->issues;
};
void User::addProject(int projectId){
    this->projects.push_back(projectId);
};
void User::addTask(int taskId){
    this->tasks.push_back(taskId);
};
void User::addIssue(int issueId){
    this->issues.push_back(issueId);
};
void User::removeProject(int projectId){
    int position=-1;
    for(int i=0;i<this->projects.size(); i++){
        if(this->projects[i]==projectId){
            position=i;
        }
    }
    if(position!=-1){
        this->projects.erase(this->projects.begin()+position,this->projects.begin()+position+1);
    }
};
void User::removeTask(int taskId){
    int position=-1;
    for(int i=0;i<this->tasks.size(); i++){
        if(this->tasks[i]==taskId){
            position=i;
        }
    }
    if(position!=-1){
        this->tasks.erase(this->tasks.begin()+position,this->tasks.begin()+position+1);
    }
};
void User::removeIssue(int issueId){
    int position=-1;
    for(int i=0;i<this->issues.size(); i++){
        if(this->issues[i]==issueId){
            position=i;
        }
    }
    if(position!=-1){
        this->issues.erase(this->issues.begin()+position,this->issues.begin()+position+1);
    }
};