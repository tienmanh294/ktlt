#include <vector>
enum IssueStatus{
    found,
    working,
    expired,
    resolved
}

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
        
}