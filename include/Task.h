#include <vector>
#include<string>
#include<map>
#include "User.h"
#include "Issue.h"
#ifndef TASK_H
#define TASK_H
enum class TaskStatus{
    initialized=1,
    running,
    late,
    extended,
    done
};

class Task{
    private:
        int id;
        std::string name;
        int created_by;
        std::vector<int> members;
        std::string start_time;
        std::string end_time;
        TaskStatus status;
        std::vector<int> issues;
        int projectId;
    public:
        int getID();
        void setID(int id);
        std::string getName();
        void setName(std::string name);
        int getCreatedBy();
        void setCreatedBy(int created_by);
        std::vector<int> getIssues();
        void setIssues(std::vector<int> issues);
        std::vector<int> getMembers();
        void setMembers(std::vector<int> members);
        std::string getStartTime();
        void setStartTime(std::string start_time);
        std::string getEndTime();
        void setEndTime(std::string end_time);
        TaskStatus getStatus();
        int getProjectId();
        void setProjectId(int projectId);
        void setStatus(TaskStatus status);
        void addIssue(int issueId);
        void addMember(int memberId);
        void clearIssues();
        void clearMembers();
        void removeIssue(int issueId);
        void removeMember(int memberId);       
        bool isIssueResolved( std::map<int,Issue*>issuesReference); 
};
#endif
