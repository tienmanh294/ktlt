#include "../include/Project.h"
int Project::getID(){
    return this->id;
};
void Project::setID(int id){
    this->id=id;
};
std::string Project::getName(){
    return this->name;
};
void Project::setName(std::string name){
this->name=name;
};
int Project::getProjectManager(){
    return this->project_manager;
};
void Project::setProjectManager(int project_manager){
this->project_manager=project_manager;
};
std::vector<int> Project::getLeaders(){
    return this->leaders;
};
void Project::setLeaders(std::vector<int> leaders){
this->leaders=leaders;
};
std::vector<int> Project::getMembers(){
    return this->members;
};
void Project::setMembers(std::vector<int> members){
this->members=members;
};
std::string Project::getStartTime(){
    return this->start_time;
};
void Project::setStartTime(std::string start_time){
this->start_time=start_time;
};
std::string Project::getEndTime(){
    return this->end_time;
};
void Project::setEndTime(std::string end_time){
this->end_time=end_time;
};
ProjectStatus Project::getStatus(){
    return this->status;
};
void Project::setStatus(ProjectStatus status){
this->status=status;
};
std::vector<int> Project::getListTasks(){
    return this->list_tasks;
};
void Project::setListTasks(std::vector<int> list_tasks){
    this->list_tasks=list_tasks;
};
void Project::addMember(int memberId){
    this->members.push_back(memberId);
};
void Project::addTask(int taskId){
    this->list_tasks.push_back(taskId);
};
void Project::addLeader(int leaderId){
    this->leaders.push_back(leaderId);
};

void Project::clearTasks(){
    this->list_tasks.clear();
};
void Project::clearMembers(){
    this->members.clear();
};
void Project::clearLeaders(){
    this->leaders.clear();
};

void Project::removeLeader(int leaderId){
    int position=-1;
    for(int i=0;i<this->leaders.size(); i++){
        if(this->leaders[i]==leaderId){
            position=i;
        }
    }
    if(position!=-1){
        this->leaders.erase(this->leaders.begin()+position,this->leaders.begin()+position+1);
    }
};
void Project::removeMember(int memberId){
    int position=-1;
    for(int i=0;i<this->members.size(); i++){
        if(this->members[i]==memberId){
            position=i;
        }
    }
    if(position!=-1){
        this->members.erase(this->members.begin()+position,this->members.begin()+position+1);
    }
};
void Project::removeTask(int taskId){
    int position=-1;
    for(int i=0;i<this->list_tasks.size(); i++){
        if(this->list_tasks[i]==taskId){
            position=i;
        }
    }
    if(position!=-1){
        this->list_tasks.erase(this->list_tasks.begin()+position,this->list_tasks.begin()+position+1);
    }
};
void Project::removeLeaderReference(std::map<int,User*>&users){
    std::vector<int>projectLeaders=this->getLeaders();
    for(int i=0;i<projectLeaders.size();i++){
        users[projectLeaders[i]]->removeProject(this->id);
    }
};
void Project::removeMemberReference(std::map<int,User*>&users){
    std::vector<int>projectMembers=this->members;
    for(int i=0;i<projectMembers.size();i++){
        users[projectMembers[i]]->removeProject(this->id);
    }
};
void Project::removeTaskReference(std::map<int,Task*>&tasks){
    std::vector<int>projectTasks=this->getListTasks();
    for(int i=0;i<projectTasks.size();i++){
        delete tasks[projectTasks[i]];
        tasks.erase(projectTasks[i]);
    }
};