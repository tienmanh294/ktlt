#include "../include/Issue.h"
int Issue::getID(){
    return this->id;
};
void Issue::setID(int id){
    this->id=id;
};
std::string Issue::getName(){
    return this->name;
};
void Issue::setName(std::string name){
    this->name=name;
};
int Issue::getCreatedBy(){
    return this->created_by;
};
void Issue::setCreatedBy(int created_by){
    this->created_by=created_by;
};
std::string Issue::getDescription(){
    return this->description;
};
void Issue::setDescription(std::string description){
    this->description=description;
};
std::vector<int> Issue::getMembers(){
    return this->members;
};
void Issue::setMembers(std::vector<int> members){
    this->members=members;
};
std::string Issue::getStartTime(){
    return this->start_time;
};
void Issue::setStartTime(std::string start_time){
    this->start_time=start_time;
};
std::string Issue::getEndTime(){
    return this->end_time;
};
void Issue::setEndTime(std::string end_time){
    this->end_time=end_time;
};
IssueStatus Issue::getStatus(){
    return this->status;
};
void Issue::setStatus(IssueStatus status){
    this->status=status;
};
void Issue::addMember(int memberId){
    this->members.push_back(memberId);
};
void Issue::clearMembers(){
    this->members.clear();
};
void Issue::setTaskId(int taskId){
    this->taskId=taskId;
};
int Issue::getTaskId(){
    return this->taskId;
}
void Issue::removeMember(int memberId){
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
void Issue::removeMemberReference(std::map<int,User*>&users){
    std::vector<int>issueMembers=this->getMembers();
    for(int i=0;i<issueMembers.size();i++){
        users[issueMembers[i]]->removeIssue(this->id);
    }
};