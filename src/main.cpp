#include <iostream>
#include <fstream>
#include "../include/main.h"

int numberOfProject=0;
int numberOfTask=0;
int numberOfUser=0;
int numberOfIssue=0;
std::map<std::string,Roles>userRoles;
std::map<std::string,TaskStatus>taskStatus;
std::map<std::string,ProjectStatus>projectStatus;
std::map<std::string,IssueStatus>issueStatus;
std::string globalDate;
int main(int argc, char* argv[]){
    if (argc<=1){
        std::cout<<"provide input file name"<<std::endl;
        return 0;
    }
    
    std::string filename="test/input/";
    std::string inputFileName=argv[1];
    //std::ifstream input(filename+inputFileName);
    std::ifstream input(inputFileName);
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    userRoles["leader"]=Roles::leader;
    userRoles["member"]=Roles::member;
    userRoles["project_manager"]=Roles::project_manager;
    taskStatus["initialized"]=TaskStatus::initialized;
    taskStatus["running"]=TaskStatus::running;
    taskStatus["late"]=TaskStatus::late;
    taskStatus["extended"]=TaskStatus::extended;
    taskStatus["done"]=TaskStatus::done;
    projectStatus["starting"]=ProjectStatus::starting;
    projectStatus["running"]=ProjectStatus::running;
    projectStatus["late"]=ProjectStatus::late;
    projectStatus["delayed"]=ProjectStatus::delayed;
    projectStatus["finished"]=ProjectStatus::finished;
    issueStatus["found"]=IssueStatus::found;
    issueStatus["working"]=IssueStatus::working;
    issueStatus["expired"]=IssueStatus::expired;
    issueStatus["resolved"]=IssueStatus::resolved;
    
    if (input.is_open()) {
        std::string line;
        int lineNumber=1;
        while (std::getline(input, line)) {
            if(line==""){
                continue;
            }
            //std::cout<<line<<std::endl;
            readDirective(inputFileName,line,projects,users,tasks,issues,lineNumber);
            lineNumber++;
        }
        input.close();
    }
}
void SetDate(std::string date,int lineNumber,std::map<int,Project*>projects,std::map<int,User*>users,std::map<int,Task*>tasks,std::map<int,Issue*>issues){
    if(!isDateValid(date)){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0);
    }
    std::map<int, Issue*>::iterator i;
    for (i = issues.begin(); i != issues.end(); i++)
    {
        Issue *currentIssue=i->second;
        if(currentIssue->getStatus()!=IssueStatus::resolved){
            std::string taskEndTime=tasks[currentIssue->getTaskId()]->getEndTime();
            if(compareDate(taskEndTime,date)==-1){
                currentIssue->setStatus(IssueStatus::expired);
            }
        }
    }
    globalDate=date;
};
void CreateReport(std::string inputFileName,std::map<int,Project*>projects,std::map<int,User*>users,std::map<int,Task*>tasks,std::map<int,Issue*>issues){
    std::map<Roles,std::string>userRoles;
    std::map<TaskStatus,std::string>taskStatus;
    std::map<ProjectStatus,std::string>projectStatus;
    std::map<IssueStatus,std::string>issueStatus;
    userRoles[Roles::leader]="leader";
    userRoles[Roles::member]="member";
    userRoles[Roles::project_manager]="project_manager";
    taskStatus[TaskStatus::initialized]="initialized";
    taskStatus[TaskStatus::running]="running";
    taskStatus[TaskStatus::late]="late";
    taskStatus[TaskStatus::extended]="extended";
    taskStatus[TaskStatus::done]="done";
    projectStatus[ProjectStatus::starting]="starting";
    projectStatus[ProjectStatus::running]="running";
    projectStatus[ProjectStatus::late]="late";
    projectStatus[ProjectStatus::delayed]="delayed";
    projectStatus[ProjectStatus::finished]="finished";
    issueStatus[IssueStatus::found]="found";
    issueStatus[IssueStatus::working]="working";
    issueStatus[IssueStatus::expired]="expired";
    issueStatus[IssueStatus::resolved]="resolved";
    std::string numberTestCase=inputFileName.substr(5,2);
    
    //std::ofstream output("test/output/output"+numberTestCase+"_"+globalDate+".txt");
    std::ofstream output("Report_"+globalDate+".txt");
    std::map<int, Project*>::iterator i;
    for (i = projects.begin(); i != projects.end(); i++)
    {
        
        Project *currentProject=i->second;
        
        output<<"PROJECT_START "+currentProject->getName()+"\n";
        output<<"STATUS "+projectStatus[currentProject->getStatus()]+"\n";
        output<<"START_TIME "+currentProject->getStartTime()+"\n";
        output<<"END_TIME "+currentProject->getEndTime()+"\n";
        output<<"MANAGER "+users[currentProject->getProjectManager()]->getFullName()+"\n";
        
        for(int j=0;j<currentProject->getLeaders().size();j++){
            output<<"LEADER "+users[currentProject->getLeaders()[j]]->getFullName()+"\n";
        }
        
        for(int j=0;j<currentProject->getMembers().size();j++){
            output<<"MEMBER "+users[currentProject->getMembers()[j]]->getFullName()+"\n";
        }
        
        std::vector<int>projectTasks=currentProject->getListTasks();
        for(int j=0;j<projectTasks.size();j++){
            Task *currentTask=tasks[projectTasks[j]];
            output<<"TASK_START "+currentTask->getName()+"\n";
            output<<"STATUS "+taskStatus[currentTask->getStatus()]+"\n";
            output<<"CREATED_BY "+std::to_string(currentTask->getCreatedBy())+"\n";
            output<<"START_TIME "+currentTask->getStartTime()+"\n";
            output<<"END_TIME "+currentTask->getEndTime()+"\n";
            std::vector<int>listTaskMembers=currentTask->getMembers();
            for(int k=0;k<listTaskMembers.size();k++){
                output<<"MEMBER "+users[listTaskMembers[k]]->getFullName()+"\n";
            }
            std::vector<int>listTaskIssues=currentTask->getIssues();
            
            for(int k=0;k<listTaskIssues.size();k++){
                Issue *currentIssue=issues[listTaskIssues[k]];
                output<<"ISSUE_START "+currentIssue->getName()+"\n";
                output<<"STATUS "+issueStatus[currentIssue->getStatus()]+"\n";
                output<<"CREATED_BY "+std::to_string(currentIssue->getCreatedBy())+"\n";

                std::vector<int>listIssueMembers=currentIssue->getMembers();
                for(int h=0;h<listIssueMembers.size();h++){
                    output<<"MEMBER "+users[listIssueMembers[h]]->getFullName()+"\n";
                }
                
                output<<"DESCRIPTION "+currentIssue->getDescription()+"\n";
                output<<"ISSUE_END\n";
            }
            output<<"TASK_END\n";
        }
        if(i->first==projects.rbegin()->first){
            output<<"PROJECT_END";
        }else{
            output<<"PROJECT_END\n";
        }
    }    
    output.close();
};
void readDirective(std::string inputFileName,std::string directive,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    std::vector<std::string>keyword;
    splitDirective(directive,' ',keyword);
    if (keyword[0]=="create_report") {
        CreateReport(inputFileName,projects,users,tasks,issues);
    } else if (keyword[0]=="set_date"){
        SetDate(keyword[1],lineNumber,projects,users,tasks,issues);
    } else if (keyword[0]=="create"){
        if(keyword[1]=="task"){
            CreateTask(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="user"){
            CreateUser(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="issue"){
            CreateIssue(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="project"){
            CreateProject(keyword,projects,users,tasks,issues,lineNumber);
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    } else if (keyword[0]=="edit"){
        if(keyword[1]=="task"){
            EditTask(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="user"){
            EditUser(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="issue"){
            EditIssue(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="project"){
            EditProject(keyword,projects,users,tasks,issues,lineNumber);
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        }
    } else if (keyword[0]=="delete"){
        if(keyword[1]=="task"){
            DeleteTask(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="user"){
            DeleteUser(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="issue"){
            DeleteIssue(keyword,projects,users,tasks,issues,lineNumber);
        }else if (keyword[1]=="project"){
            DeleteProject(keyword,projects,users,tasks,issues,lineNumber);
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }else{
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0);
    }
    // std::cout<<directive<<std::endl;
    // std::map<int, User*>::iterator user;
    // for(user=users.begin();user!=users.end();user++){
    //     std::cout<<user->first<<" "<<user->second->getFullName()<<std::endl;
    // }
    
};
void CreateUser(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    User *newUser= new User();
    if(information.size()%2!=0){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        delete newUser;
        exit(0); 
    }
    for(int i=2;i<information.size();i+=2){
        if(information[i]=="--by"){
            if(!isNumber(information[i+1])){//value is not a number
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete newUser;
                exit(0);
            }else{
                int id=std::stoi(information[i+1]);
                if(!users.count(id)){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete newUser;
                    exit(0);
                }
                newUser->setCreatedBy(id);
            }
        }else if(information[i]=="--fullname"){
            newUser->setFullName(information[i+1]);
        }else if(information[i]=="--role"){
            
            if(newUser->getCreatedBy()!=-1){
                if(users[newUser->getCreatedBy()]->getRole()>=userRoles[information[i+1]]){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete newUser;
                    exit(0);
                }
            }
            
            if(information[i+1]!="member"&&information[i+1]!="leader"&&information[i+1]!="project_manager"){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete newUser;
                exit(0);
            }
            newUser->setRole(userRoles[information[i+1]]);
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            delete newUser;
            exit(0);
        }
    }
    newUser->setID(numberOfUser+1);
    users[numberOfUser+1]=newUser;
    // std::cout<<numberOfUser+1<<std::endl;
    // std::cout<<newUser->getFullName()<<std::endl;
    // std::cout<<newUser<<std::endl;
    // std::map<int, User*>::iterator i;
    
    // for (i = users.begin(); i != users.end(); i++)
    // {
    //     std::cout<<i->first<<" "<<currentProject<<std::endl;
    // }
    numberOfUser++;
};
void EditUser(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()<6||information.size()%2!=0){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }
    
    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(information[4]!="--id"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[5])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[5]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    int editor=std::stoi(information[3]);
    int editedUser=std::stoi(information[5]);
    if(users[editor]->getRole()>users[std::stoi(information[5])]->getRole()){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0);
    }
    if(users[editor]->getRole()==Roles::member){//member edit another member
        if(editor!=editedUser){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    for(int i=6;i<information.size();i+=2){
        if(information[i]=="--fullname"){
            users[editedUser]->setFullName(information[i+1]);
        }
    }
};
void DeleteUser(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()!=6){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }

    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(information[4]!="--id"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[5])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[5]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(users[std::stoi(information[3])]->getRole()>=users[std::stoi(information[5])]->getRole()){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0);
    }else{
        int userId=std::stoi(information[5]);
        User *user=users[userId];
        std::vector<int> userProjects=user->getProjects();
        std::vector<int> userTasks=user->getTasks();
        std::vector<int> userIssues=user->getIssues();
        for(int i=0;i<userProjects.size();i++){
            projects[userProjects[i]]->removeLeader(userId);
            projects[userProjects[i]]->removeMember(userId);
        }
        for(int i=0;i<userTasks.size();i++){
            tasks[userTasks[i]]->removeMember(userId);
        }
        for(int i=0;i<userIssues.size();i++){
            issues[userIssues[i]]->removeMember(userId);
        }
        delete users[std::stoi(information[5])];
        users.erase(std::stoi(information[5]));
    }
};
void CreateTask(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()!=14){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }
    Task *task=new Task();
    task->setStatus(TaskStatus::initialized);
    int projectId=-1;
    int taskId=numberOfTask+1;
    if(information[2]=="--by"){
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            delete task;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            delete task;
            exit(0);
        }
        task->setCreatedBy(std::stoi(information[3])); 
    }
    if(users[std::stoi(information[3])]->getRole()!=Roles::leader&&users[std::stoi(information[3])]->getRole()!=Roles::project_manager){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        delete task;
        exit(0);
    }
    for(int i=4;i<information.size();i+=2){
         if(information[i]=="--project_id"){
            if(!isNumber(information[i+1])){//value is not a number
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete task;
                exit(0);
            }
            if(!projects.count(std::stoi(information[i+1]))){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete task;
                exit(0);
            }
            projectId=std::stoi(information[i+1]);
            if(task->getCreatedBy()!=projects[projectId]->getProjectManager()){//leader of another project create task to this project
                bool flag=false;
                for(int i=0;i<projects[projectId]->getLeaders().size();i++){
                    if(projects[projectId]->getLeaders()[i]==task->getCreatedBy()){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete task;
                    exit(0);
                }
            }
            task->setProjectId(projectId);
        }else if(information[i]=="--name"){
            task->setName(information[i+1]);
        }else if(information[i]=="--start_time"){
            if(!isDateValid(information[i+1])){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete task;
                exit(0);
            }
            task->setStartTime(information[i+1]);
        }else if(information[i]=="--end_time"){
            if(!isDateValid(information[i+1])){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete task;
                exit(0);
            }
            task->setEndTime(information[i+1]);
        }else if(information[i]=="--members"){
            std::vector<std::string>memberIds;
            splitDirective(information[i+1],',',memberIds);
            Project *project=projects[projectId];
            std::vector<int>members=project->getMembers();
            for(int i=0;i<memberIds.size();i++){
                bool flag=false;
                for(int j=0;j<members.size();j++){
                    if(!isNumber(memberIds[i])){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete task;
                        exit(0);
                    }
                    if(members[j]==std::stoi(memberIds[i])){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete task;
                    exit(0);
                }
            }
            for(int i=0;i<memberIds.size();i++){
                if(!isNumber(memberIds[i])){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete task;
                    exit(0);
                }else{
                    if(!users.count(std::stoi(memberIds[i]))){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete task;
                        exit(0);
                    }
                    task->addMember(std::stoi(memberIds[i]));
                    users[std::stoi(memberIds[i])]->addTask(taskId);
                }
            }
            
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            delete task;
            exit(0); 
        }
    }
    task->setID(taskId);
    tasks[taskId]=task;
    projects[projectId]->addTask(taskId);
    numberOfTask++;
};
void EditTask(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()<6||information.size()%2!=0){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }
    
    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(information[4]!="--id"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[5])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!tasks.count(std::stoi(information[5]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    int userId=std::stoi(information[3]);
    int taskId=std::stoi(information[5]);
    if(users[userId]->getRole()!=Roles::leader&&users[userId]->getRole()!=Roles::project_manager){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0);
    }
    
    Task *editTask=tasks[taskId];
    Project *project=projects[editTask->getProjectId()];
    int projectId=editTask->getProjectId();
    if(project->getProjectManager()!=userId){
        std::vector<int>leaders=project->getLeaders();
        bool flag=false;
        for(int i=0;i<leaders.size();i++){
            if(leaders[i]==userId){
                flag=true;
                break;
            }
        }
        if(!flag){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    for(int i=6;i<information.size();i+=2){
        if(information[i]=="--name"){
            editTask->setName(information[i+1]);
        }else if(information[i]=="--start_time"){
            if(!isDateValid(information[i+1])){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
            editTask->setStartTime(information[i+1]);
        }else if(information[i]=="--end_time"){
            if(!isDateValid(information[i+1])){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
            editTask->setEndTime(information[i+1]);
        }else if(information[i]=="--status"){
            if(taskStatus.count(information[i+1])){
                editTask->setStatus(taskStatus[information[i+1]]);
            }else{
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
        }else if(information[i]=="--members"){
            std::vector<int>taskMembers=editTask->getMembers();
            for(int i=0;i<taskMembers.size();i++){
                users[taskMembers[i]]->removeTask(taskId);
            }
            editTask->clearMembers();
            std::vector<std::string>memberIds;
            splitDirective(information[i+1],',',memberIds);
            Project *project=projects[projectId];
            std::vector<int>members=project->getMembers();
            for(int i=0;i<memberIds.size();i++){
                bool flag=false;
                for(int j=0;j<members.size();j++){
                    if(!isNumber(memberIds[i])){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        exit(0);
                    }
                    if(members[j]==std::stoi(memberIds[i])){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    exit(0);
                }
            }
            for(int i=0;i<memberIds.size();i++){
                if(!isNumber(memberIds[i])){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    exit(0);
                }else{
                    if(!users.count(std::stoi(memberIds[i]))){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        exit(0);
                    }
                    editTask->addMember(std::stoi(memberIds[i]));
                    users[std::stoi(memberIds[i])]->addTask(taskId);
                }
            }
            
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0); 
        }
    }
};
void DeleteTask(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()!=6){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }

    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(information[4]!="--id"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[5])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!tasks.count(std::stoi(information[5]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    
    int userId=std::stoi(information[3]);
    if(users[std::stoi(information[3])]->getRole()!=Roles::leader&&users[std::stoi(information[3])]->getRole()!=Roles::project_manager){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0);
    }else{
        int taskId=std::stoi(information[5]);
        Task *task=tasks[taskId];
        int projectId=task->getProjectId();
        Project *project=projects[projectId];
        if(project->getProjectManager()!=userId){
            std::vector<int>leaders=project->getLeaders();
            bool flag=false;
            for(int i=0;i<leaders.size();i++){
                if(leaders[i]==userId){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
        }
        project->removeTask(taskId);
        std::vector<int>taskIssues=task->getIssues();
        for(int i=0;i<taskIssues.size();i++){
            delete issues[taskIssues[i]];
            issues.erase(taskIssues[i]);
        }
        std::vector<int>taskMembers=task->getMembers();
        for(int i=0;i<taskMembers.size();i++){
            users[taskMembers[i]]->removeTask(taskId);
        }
        
        delete tasks[std::stoi(information[5])];
        tasks.erase(std::stoi(information[5]));
    }

};
void CreateIssue(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()!=12){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }
    Issue *issue=new Issue();
    issue->setStatus(IssueStatus::found);
    int taskId=-1;
    int createUserId=std::stoi(information[3]);
    int issueId=numberOfIssue+1;
    for(int i=2;i<information.size();i+=2){
        if(information[i]=="--by"){
            if(!isNumber(information[i+1])){//value is not a number
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete issue;
                exit(0);
            }
            if(!users.count(std::stoi(information[i+1]))){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete issue;
                exit(0);
            }
            issue->setCreatedBy(std::stoi(information[i+1]));
        }else if(information[i]=="--task_id"){
            if(!isNumber(information[i+1])){//value is not a number
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete issue;
                exit(0);
            }
            if(!tasks.count(std::stoi(information[i+1]))){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete issue;
                exit(0);
            }
            taskId=std::stoi(information[i+1]);
            int userId=issue->getCreatedBy();
            Task *task=tasks[taskId];
            Project *project=projects[task->getProjectId()];
            if(project->getProjectManager()!=userId){
                if(!isProjectHaveUser(userId,project->getLeaders(),project->getMembers())){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete issue;
                    exit(0);
                };
            }
            issue->setTaskId(taskId);
        }else if(information[i]=="--name"){
            issue->setName(information[i+1]);
        }else if(information[i]=="--description"){
            issue->setDescription(information[i+1]);
        }else if(information[i]=="--members"){
            std::vector<std::string>memberIds;
            splitDirective(information[i+1],',',memberIds);
            Task *task=tasks[taskId];
            std::vector<int>members=task->getMembers();
            for(int i=0;i<memberIds.size();i++){
                bool flag=false;
                for(int j=0;j<members.size();j++){
                    if(!isNumber(memberIds[i])){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete issue;
                        exit(0);
                    }
                    if(members[j]==std::stoi(memberIds[i])){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete issue;
                    exit(0);
                }
            }
            for(int i=0;i<memberIds.size();i++){
                if(!isNumber(memberIds[i])){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete issue;
                    exit(0);
                }else{
                    if(!users.count(std::stoi(memberIds[i]))){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete issue;
                        exit(0);
                    }
                    issue->addMember(std::stoi(memberIds[i]));
                    users[std::stoi(memberIds[i])]->addIssue(issueId);
                }
            }
            
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            delete issue;
            exit(0); 
        }
    }
    
    issue->setID(issueId);
    issues[issueId]=issue;
    tasks[taskId]->addIssue(issueId);
    numberOfIssue++;

};
void EditIssue(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()<6 || information.size()%2!=0){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }
    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(information[4]!="--id"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[5])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!issues.count(std::stoi(information[5]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    int editUser=std::stoi(information[3]);
    int issueId=std::stoi(information[5]);
    Issue *editIssue=issues[issueId];
    bool flag=false;
    Task *task=tasks[editIssue->getTaskId()];
    for(int i=0;i<task->getMembers().size();i++){
        if(task->getMembers()[i]==editUser){
            flag=true;
            break;
        }
    }
    if(!flag){
        Project *project=projects[task->getProjectId()];
        if(project->getProjectManager()!=editUser){
            bool flagInside=false;
            for(int i=0;i<project->getLeaders().size();i++){
                if(project->getLeaders()[i]==editUser){
                    flagInside=true;
                    break;
                }
            }
            if(!flagInside){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
        }
    }
    for(int i=6;i<information.size();i+=2){
        if(information[i]=="--name"){
            editIssue->setName(information[i+1]);
        }else if(information[i]=="--description"){
            editIssue->setDescription(information[i+1]);
        }else if(information[i]=="--status"){
            if(issueStatus.count(information[i+1])){
                if(information[i+1]=="resolved"){
                    if(users[editUser]->getRole()!=Roles::leader&&users[editUser]->getRole()!=Roles::project_manager){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        exit(0);
                    }
                }
                editIssue->setStatus(issueStatus[information[i+1]]);
            }else{
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
        }else if(information[i]=="--members"){
            editIssue->removeMemberReference(users);
            editIssue->clearMembers();
            std::vector<std::string>memberIds;
            splitDirective(information[i+1],',',memberIds);
            std::vector<int>members=task->getMembers();
            for(int i=0;i<memberIds.size();i++){
                bool flagInside2=false;
                for(int j=0;j<members.size();j++){
                    if(!isNumber(memberIds[i])){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        exit(0);
                    }
                    if(members[j]==std::stoi(memberIds[i])){
                        flagInside2=true;
                        break;
                    }
                }
                if(!flagInside2){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    exit(0);
                }
            }
            for(int i=0;i<memberIds.size();i++){
                if(!isNumber(memberIds[i])){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    exit(0);
                }else{
                    if(!users.count(std::stoi(memberIds[i]))){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        exit(0);
                    }
                    editIssue->addMember(std::stoi(memberIds[i]));
                    users[std::stoi(memberIds[i])]->addIssue(issueId);
                }
            }
            
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0); 
        }
    }
    
};
void DeleteIssue(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()!=6){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }

    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(information[4]!="--id"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[5])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!issues.count(std::stoi(information[5]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    
    int issueId=std::stoi(information[5]);
    Issue *issue=issues[issueId];
    int taskId=issue->getTaskId();
    tasks[taskId]->removeIssue(issueId);
    issue->removeMemberReference(users);
    delete issues[std::stoi(information[5])];
    issues.erase(std::stoi(information[5]));
};
void CreateProject(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()!=14){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }
    Project *project=new Project();
    project->setStatus(ProjectStatus::starting);
    int projectId=numberOfProject+1;
    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        delete project;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            delete project;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            delete project;
            exit(0);
        }
        int projectManagerId=std::stoi(information[3]);
        project->setProjectManager(projectManagerId);
    }
    if(users[std::stoi(information[3])]->getRole()!=Roles::project_manager){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        delete project;
        exit(0);
    }
    for(int i=4;i<information.size();i+=2){
        if(information[i]=="--name"){
            project->setName(information[i+1]);
        }else if(information[i]=="--start_time"){
            if(!isDateValid(information[i+1])){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete project;
                exit(0);
            }
            project->setStartTime(information[i+1]);
        }else if(information[i]=="--end_time"){
            if(!isDateValid(information[i+1])){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete project;
                exit(0);
            }
            project->setEndTime(information[i+1]);
        }else if(information[i]=="--members"){
            std::vector<std::string>memberIds;
            splitDirective(information[i+1],',',memberIds);
            if(memberIds.size()>5){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete project;
                exit(0);
            }
            for(int i=0;i<memberIds.size();i++){
                if(!isNumber(memberIds[i])){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete project;
                    exit(0);
                }else{
                    if(!users.count(std::stoi(memberIds[i]))){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete project;
                        exit(0);
                    }
                    if(users[std::stoi(memberIds[i])]->getRole()!=Roles::member){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete project;
                        exit(0);
                    }
                    project->addMember(std::stoi(memberIds[i]));
                    users[std::stoi(memberIds[i])]->addProject(projectId);
                }
            }
            
        }else if(information[i]=="--leaders"){
            std::vector<std::string>memberIds;
            splitDirective(information[i+1],',',memberIds);
            if(memberIds.size()>100){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                delete project;
                exit(0);
            }
            for(int i=0;i<memberIds.size();i++){
                if(!isNumber(memberIds[i])){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    delete project;
                    exit(0);
                }else{
                    if(!users.count(std::stoi(memberIds[i]))){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete project;
                        exit(0);
                    }
                    if(users[std::stoi(memberIds[i])]->getRole()!=Roles::leader){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete project;
                        exit(0);
                    }
                    project->addLeader(std::stoi(memberIds[i]));
                    users[std::stoi(memberIds[i])]->addProject(projectId);
                }
            }
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            delete project;
            exit(0); 
        }
    }
    project->setID(projectId);
    projects[projectId]=project;
    numberOfProject++;
};
void EditProject(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()<6 || information.size()%2!=0){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }
    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(information[4]!="--id"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[5])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!projects.count(std::stoi(information[5]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    int projectId=std::stoi(information[5]);
    Project *project=projects[projectId];
    if(users[std::stoi(information[3])]->getRole()!=Roles::project_manager){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0);
    }
    for(int i=6;i<information.size();i+=2){
        if(information[i]=="--name"){
            project->setName(information[i+1]);
        }else if(information[i]=="--start_time"){
            if(!isDateValid(information[i+1])){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
            project->setStartTime(information[i+1]);
        }else if(information[i]=="--end_time"){
            if(!isDateValid(information[i+1])){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
            project->setEndTime(information[i+1]);
        }else if(information[i]=="--status"){
            if(projectStatus.count(information[i+1])){
                project->setStatus(projectStatus[information[i+1]]);
            }else{
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
        }else if(information[i]=="--members"){
            project->removeMemberReference(users);
            project->clearMembers();
            std::vector<std::string>memberIds;
            splitDirective(information[i+1],',',memberIds);
            if(memberIds.size()>100){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
            for(int i=0;i<memberIds.size();i++){
                if(!isNumber(memberIds[i])){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    exit(0);
                }else{
                    if(!users.count(std::stoi(memberIds[i]))){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        exit(0);
                    }
                    if(users[std::stoi(memberIds[i])]->getRole()!=Roles::member){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete project;
                        exit(0);
                    }
                    project->addMember(std::stoi(memberIds[i]));
                    users[std::stoi(memberIds[i])]->addProject(projectId);
                }
            }
            
        }else if(information[i]=="--leaders"){
            project->removeLeaderReference(users);
            project->clearLeaders();
            std::vector<std::string>memberIds;
            splitDirective(information[i+1],',',memberIds);
            if(memberIds.size()>5){
                std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                exit(0);
            }
            for(int i=0;i<memberIds.size();i++){
                if(!isNumber(memberIds[i])){
                    std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                    exit(0);
                }else{
                    if(!users.count(std::stoi(memberIds[i]))){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        exit(0);
                    }
                    if(users[std::stoi(memberIds[i])]->getRole()!=Roles::leader){
                        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
                        delete project;
                        exit(0);
                    }
                    project->addLeader(std::stoi(memberIds[i]));
                    users[std::stoi(memberIds[i])]->addProject(projectId);
                }
            }
            
        }else{
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0); 
        }
    }

};
void DeleteProject(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber){
    if(information.size()!=6){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }
    
    if(information[2]!="--by"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[3])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!users.count(std::stoi(information[3]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    if(information[4]!="--id"){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0); 
    }else{
        if(!isNumber(information[5])){//value is not a number
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        if(!projects.count(std::stoi(information[5]))){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
    }
    int projectId=std::stoi(information[5]);
    int userId=std::stoi(information[3]);
    Project *deletedProject=projects[projectId];
    if(users[userId]->getRole()!=Roles::project_manager){
        std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
        exit(0);
    }else{
        if(userId!=deletedProject->getProjectManager()){
            std::cout<<"Error: Unexpected error in line "<<lineNumber<<std::endl;
            exit(0);
        }
        deletedProject->removeTaskReference(tasks);
        deletedProject->removeLeaderReference(users);
        deletedProject->removeMemberReference(users);
        delete projects[projectId];
        projects.erase(projectId);
    }

};