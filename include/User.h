#include <vector>
enum Roles{
    project_manager,
    leader,
    member
}

class User{
    private:
        int id;
        std::string fullname;
        int created_by;
        Roles role;
    public:
        int getID();
        void setID(int id);
        std::string getFullName();
        void setFullName(std::string fullname);
        int getCreatedBy();
        void setCreatedBy(int created_by);
        Roles getRole();
        void setRole(Roles role);
        
        
}