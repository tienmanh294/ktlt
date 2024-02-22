#include <vector>
#include<string>
#ifndef USER_H
#define USER_H
enum Roles{
    RNONE=-1,
    project_manager,
    leader,
    member
};

class User{
    private:
        int id;
        std::string fullname;
        int created_by;
        Roles role;
        std::vector<int>projects;
        std::vector<int>tasks;
        std::vector<int>issues;
    public:
        int getID();
        void setID(int id);
        std::string getFullName();
        void setFullName(std::string fullname);
        int getCreatedBy();
        void setCreatedBy(int created_by);
        std::vector<int>getProjects();
        std::vector<int>getTasks();
        std::vector<int>getIssues();
        void addProject(int projectId);
        void addTask(int taskId);
        void addIssue(int issueId);
        void removeProject(int projectId);
        void removeTask(int taskId);
        void removeIssue(int issueId);
        Roles getRole();
        void setRole(Roles role);
        User();
};
#endif
