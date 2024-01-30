#include "../include/Task.h"
int Task::getID(){
    return this.id;
};
void Task::setID(int id){
    this.id=id;
};
std::string Task::getName(){
    return this.name;
};
void Task::setName(std::string name){
    this.name=name;
};
int Task::getCreatedBy(){
    return this.created_by;
};
void Task::setCreatedBy(int created_by){
    this.created_by=created_by;
};
std::vector<int> Task::getIssues(){
    return this.issues;
};
void Task::setIssues(std::vector<int> issues){
    this.issues=issues;
};
std::vector<int> Task::getMembers(){
    return this.members;
};
void Task::setMembers(std::vector<int> members){
    this.members=members;
};
std::string Task::getStartTime(){
    return this.start_time;
};
void Task::setStartTime(std::string start_time){
    this.start_time=start_time;
};
std::string Task::getEndTime(){
    return this.end_time;
};
void Task::setEndTime(std::string end_time){
    this.end_time=end_time;
};
TaskStatus Task::getStatus(){
    return this.status;
};
void Task::setStatus(TaskStatus status){
    this.status=status;
};