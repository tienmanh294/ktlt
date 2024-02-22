#include <vector>
#include<string>
#ifndef PROJECT_H
#define PROJECT_H
enum class ProjectStatus{
    starting=1,
    running,
    late,
    delayed,
    finished
};

class Project{
    private:
        int id;
        std::string name;
        int project_manager;
        std::vector<int> leaders;
        std::vector<int> members;
        std::string start_time;
        std::string end_time;
        ProjectStatus status;
        std::vector<int> list_tasks;
    public:
        int getID();
        void setID(int id);
        std::string getName();
        void setName(std::string name);
        int getProjectManager();
        void setProjectManager(int id);
        std::vector<int> getLeaders();
        void setLeaders(std::vector<int> leaders);
        std::vector<int> getMembers();
        void setMembers(std::vector<int> members);
        std::string getStartTime();
        void setStartTime(std::string start_time);
        std::string getEndTime();
        void setEndTime(std::string end_time);
        ProjectStatus getStatus();
        void setStatus(ProjectStatus status);
        std::vector<int> getListTasks();
        void setListTasks(std::vector<int> list_tasks);
        void addTask(int taskId);
        void addMember(int memberId);
        void addLeader(int leaderId);
        void clearTasks();
        void clearMembers();
        void clearLeaders();
        void removeLeader(int leaderId);
        void removeMember(int memberId);
        void removeTask(int taskId);
};
#endif
