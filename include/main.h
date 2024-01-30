#include "Issue.h"
#include "User.h"
#include "Task.h"
#include "Project.h"
#include "Utils.h"

void CreateUser(int user_id, std::string fullname, Roles role=NULL);
void EditUser(int by_user_id,int user_id, std::string fullname="", Roles role=NULL);
void DeleteUser(int by_user_id,int user_id);
void CreateTask(int by_user_id,std::string name, std::string start_time, std::string end_time, std::vector<int> members);
void EditTask(int by_user_id,int id,std::string name="", std::string start_time="", std::string end_time="", std::vector<int> members={},TaskStatus status=NULL);
void DeleteTask(int by_user_id,int user_id);
void CreateIssue(int by_user_id,int task_id,std::string name, std::vector<int> members,std::string description, IssueStatus status=NULL);
void EditIssue(int by_user_id,int id,std::string name="", std::vector<int> members,std::string description, IssueStatus status=NULL);
void DeleteIssue(int by_user_id,int user_id);
void CreateProject(int by_user_id,std::string name,std::vector<int> leaders, std::vector<int> members,std::string start_time, std::string end_time);
void EditProject(int by_user_id,int id,std::string name="",std::vector<int> leaders={}, std::vector<int> members={},std::string start_time="", std::string end_time="",ProjectStatus status=NULL);
void DeleteProject(int by_user_id,int user_id);
void SetDate(std::string date);
void CreateReport();