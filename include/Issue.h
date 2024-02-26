#include <vector>
#include<string>
#include<map>
#include "User.h"
#ifndef ISSUE_H
#define ISSUE_H
enum class IssueStatus{
    found=1,
    working,
    expired,
    resolved
};

class Issue{
    private:
        int id;
        std::string name;
        int created_by;
        std::string description;
        std::vector<int> members;
        std::string start_time;
        std::string end_time;
        IssueStatus status;
        int taskId;
    public:
        int getID();
        void setID(int id);
        std::string getName();
        void setName(std::string name);
        int getCreatedBy();
        void setCreatedBy(int created_by);
        std::string getDescription();
        void setDescription(std::string description);
        std::vector<int> getMembers();
        void setMembers(std::vector<int> members);
        std::string getStartTime();
        void setStartTime(std::string start_time);
        std::string getEndTime();
        void setEndTime(std::string end_time);
        IssueStatus getStatus();
        void setStatus(IssueStatus status);
        void removeMemberReference(std::map<int,User*>&users);
        int getTaskId();
        void setTaskId(int taskId);
        void addMember(int memberId);
        void clearMembers();
        void removeMember(int memberId);      
};
#endif
