#include "../include/Task.h"
int Task::getID(){
    return this->id;
};
void Task::setID(int id){
    this->id=id;
};
std::string Task::getName(){
    return this->name;
};
void Task::setName(std::string name){
    this->name=name;
};
int Task::getCreatedBy(){
    return this->created_by;
};
void Task::setCreatedBy(int created_by){
    this->created_by=created_by;
};
std::vector<int> Task::getIssues(){
    return this->issues;
};
void Task::setIssues(std::vector<int> issues){
    this->issues=issues;
};
std::vector<int> Task::getMembers(){
    return this->members;
};
void Task::setMembers(std::vector<int> members){
    this->members=members;
};
std::string Task::getStartTime(){
    return this->start_time;
};
void Task::setStartTime(std::string start_time){
    this->start_time=start_time;
};
std::string Task::getEndTime(){
    return this->end_time;
};
void Task::setEndTime(std::string end_time){
    this->end_time=end_time;
};
TaskStatus Task::getStatus(){
    return this->status;
};
void Task::setStatus(TaskStatus status){
    this->status=status;
};
int Task::getProjectId(){
    return this->projectId;
};
void Task::setProjectId(int projectId){
    this->projectId=projectId;
};
void Task::addIssue(int issueId){
    this->issues.push_back(issueId);
};
void Task::addMember(int memberId){
    this->members.push_back(memberId);
};
void Task::clearIssues(){
    this->issues.clear();
};
void Task::clearMembers(){
    this->members.clear();
};

void Task::removeMember(int memberId){
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
void Task::removeIssue(int issueId){
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
bool Task::isIssueResolved( std::map<int,Issue*>issuesReference){
    for(int i=0;i<this->issues.size();i++){
        int issueID=this->issues[i];
        if(issuesReference[issueID]->getStatus()!=IssueStatus::resolved){
            return false;
        }
    }
    return true;
}