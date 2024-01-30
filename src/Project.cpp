#include "../include/Project.h"
int Project::getID(){
    return this.id;
};
void Project::setID(int id){
    this.id=id;
};
std::string Project::getName(){
    return this.name;
};
void Project::setName(std::string name){
this.name=name;
};
int Project::getProjectManager(){
    return this.project_manager;
};
void Project::setProjectManager(int project_manager){
this.project_manager=project_manager;
};
std::vector<int> Project::getLeaders(){
    return this.leaders;
};
void Project::setLeaders(std::vector<int> leaders){
this.leaders=leaders;
};
std::vector<int> Project::getMembers(){
    return this.members;
};
void Project::setMembers(std::vector<int> members){
this.members=members;
};
std::string Project::getStartTime(){
    return this.start_time;
};
void Project::setStartTime(std::string start_time){
this.start_time=start_time;
};
std::string Project::getEndTime(){
    return this.end_time;
};
void Project::setEndTime(std::string end_time){
this.end_time=end_time;
};
ProjectStatus Project::getStatus(){
    return this.status;
};
void Project::setStatus(ProjectStatus status){
this.status=status;
};
std::vector<int> Project::getListTasks(){
    return this.list_tasks;
};
void Project::setListTasks(std::vector<int> list_tasks){
this.list_tasks=list_tasks;
};