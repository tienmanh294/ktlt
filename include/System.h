#include <iostream>
#include <fstream>
#include "Issue.h"
#include "User.h"
#include "Task.h"
#include "Project.h"
#include "Utils.h"

#ifndef SYSTEM_H
#define SYSTEM_H

void SetupMapping();
void CreateUser(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void EditUser(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void DeleteUser(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void CreateTask(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void EditTask(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void DeleteTask(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void CreateIssue(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void EditIssue(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void DeleteIssue(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void CreateProject(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void EditProject(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void DeleteProject(std::vector<std::string>information,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);
void SetDate(std::string date,int lineNumber,std::map<int,Project*>projects,std::map<int,User*>users,std::map<int,Task*>tasks,std::map<int,Issue*>issues);
void CreateReport(std::string inputFileName,std::map<int,Project*>projects,std::map<int,User*>users,std::map<int,Task*>tasks,std::map<int,Issue*>issues);
void readDirective(std::string inputFileName,std::string directive,std::map<int,Project*>&projects,std::map<int,User*>&users,std::map<int,Task*>&tasks,std::map<int,Issue*>&issues,int lineNumber);

#endif