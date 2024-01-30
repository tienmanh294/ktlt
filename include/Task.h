#include <vector>
enum TaskStatus{
    initialized,
    running,
    late,
    extended,
    done
}

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
        void setStatus(TaskStatus status);
        
}