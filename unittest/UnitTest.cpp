#include <gtest/gtest.h>
#include "../include/System.h"

std::string ReadFileContent(const std::string& filename) {
  std::ifstream file(filename);
  std::string content;
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      content += line + '\n';
    }
    file.close();
  }
  return content;
}
TEST(CreateUser,Subtest_Create_Leader){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);
    ASSERT_TRUE(users[1]->getFullName()=="Leader1");
    ASSERT_TRUE(users[1]->getCreatedBy()==-1);
    ASSERT_TRUE(users[1]->getRole()==Roles::leader);    
}
TEST(EditUser,Subtest_EditUserName){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);

    std::vector<std::string>information1;
    std::string directive1="edit user --by 1 --id 1 --fullname Member1ChangeName";
    splitDirective(directive1,' ',information1);
    EditUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);
    ASSERT_TRUE(users[1]->getFullName()=="Member1ChangeName");
}
TEST(DeleteUser,Subtest_DeleteUser){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information2;
    std::string directive2="delete user --by 2 --id 1";
    splitDirective(directive2,' ',information2);
    DeleteUser(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);
}
TEST(CreateProject,Subtest_4){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
      
}
TEST(EditProject,Subtest_5){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);

    std::vector<std::string>information4;
    std::string directive4="edit project --by 2 --id 1 --name Project2 --leaders 1 --members 3 --start_time 06012024 --end_time 16012024";
    splitDirective(directive4,' ',information4);
    EditProject(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects[1]->getEndTime()=="16012024");
    ASSERT_TRUE(projects[1]->getStartTime()=="06012024");
    ASSERT_TRUE(projects[1]->getName()=="Project2");
}
TEST(DeleteProject,Subtest_6){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);

    std::vector<std::string>information4;
    std::string directive4="delete project --by 2 --id 1 ";
    splitDirective(directive4,' ',information4);
    DeleteProject(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==0);      
}
TEST(CreateTask,Subtest_7){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);
    ASSERT_TRUE(tasks[1]->getName()=="buttonA");
    ASSERT_TRUE(tasks[1]->getStartTime()=="05012024");
    ASSERT_TRUE(tasks[1]->getEndTime()=="15012024");
}
TEST(EditTask,Subtest_8){
    SetupMapping();
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;

    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    splitDirective(directive,' ',information);
    
    
    SetDate("04012024",1,projects,users,tasks,issues);
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 20012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);

    std::vector<std::string>information5;
    std::string directive5="edit task --by 2 --id 1 --name buttonABC --start_time 06012024 --end_time 16012024 --members 3";
    splitDirective(directive5,' ',information5);
    EditTask(information5,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);
    ASSERT_TRUE(tasks[1]->getName()=="buttonABC");
    ASSERT_TRUE(tasks[1]->getStartTime()=="06012024");
    ASSERT_TRUE(tasks[1]->getEndTime()=="16012024");
}
TEST(DeleteTask,Subtest_9){
   SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);

    std::vector<std::string>information5;
    std::string directive5="delete task --by 2 --id 1 ";
    splitDirective(directive5,' ',information5);
    DeleteTask(information5,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==0); 
}
TEST(CreateIssue,Subtest_10){
   SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);

    std::vector<std::string>information5;
    std::string directive5="create issue --by 1 --name issueA --task_id 1 --members 3 --description createissueA";
    splitDirective(directive5,' ',information5);
    CreateIssue(information5,projects,users,tasks,issues,1);
    ASSERT_TRUE(issues.size()==1); 
    ASSERT_TRUE(issues[1]->getName()=="issueA"); 
    ASSERT_TRUE(issues[1]->getMembers()[0]==3); 
    ASSERT_TRUE(issues[1]->getDescription()=="createissueA"); 
}
TEST(EditIssue,Subtest_11){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);

    std::vector<std::string>information5;
    std::string directive5="create issue --by 1 --name issueA --task_id 1 --members 3 --description createissueA";
    splitDirective(directive5,' ',information5);
    CreateIssue(information5,projects,users,tasks,issues,1);
    ASSERT_TRUE(issues.size()==1); 
    ASSERT_TRUE(issues[1]->getName()=="issueA"); 
    ASSERT_TRUE(issues[1]->getMembers()[0]==3); 
    ASSERT_TRUE(issues[1]->getDescription()=="createissueA"); 

    std::vector<std::string>information6;
    std::string directive6="edit issue --by 1 --id 1 --name issueABC --members 3 --description createissueABC";
    splitDirective(directive6,' ',information6);
    EditIssue(information6,projects,users,tasks,issues,1);
    ASSERT_TRUE(issues.size()==1); 
    ASSERT_TRUE(issues[1]->getName()=="issueABC"); 
    ASSERT_TRUE(issues[1]->getMembers()[0]==3); 
    ASSERT_TRUE(issues[1]->getDescription()=="createissueABC"); 
       
}
TEST(DeleteIssue,Subtest_12){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);

    std::vector<std::string>information5;
    std::string directive5="create issue --by 1 --name issueA --task_id 1 --members 3 --description createissueA";
    splitDirective(directive5,' ',information5);
    CreateIssue(information5,projects,users,tasks,issues,1);
    ASSERT_TRUE(issues.size()==1); 
    ASSERT_TRUE(issues[1]->getName()=="issueA"); 
    ASSERT_TRUE(issues[1]->getMembers()[0]==3); 
    ASSERT_TRUE(issues[1]->getDescription()=="createissueA"); 

    std::vector<std::string>information6;
    std::string directive6="delete issue --by 1 --id 1";
    splitDirective(directive6,' ',information6);
    DeleteIssue(information6,projects,users,tasks,issues,1);
    ASSERT_TRUE(issues.size()==0); 
}
TEST(EditTask,Subtest_Late){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    SetDate("04012024",1,projects,users,tasks,issues);
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);

    std::vector<std::string>information5;
    std::string directive5="create issue --by 1 --name issueA --task_id 1 --members 3 --description createissueA";
    splitDirective(directive5,' ',information5);
    CreateIssue(information5,projects,users,tasks,issues,1);
    ASSERT_TRUE(issues.size()==1); 
    ASSERT_TRUE(issues[1]->getName()=="issueA"); 
    ASSERT_TRUE(issues[1]->getMembers()[0]==3); 
    ASSERT_TRUE(issues[1]->getDescription()=="createissueA"); 

    SetDate("16012024",1,projects,users,tasks,issues);
    ASSERT_TRUE(tasks[1]->getStatus()==TaskStatus::late); 
       
}
TEST(EditTask,Subtest_Extended){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    SetDate("04012024",1,projects,users,tasks,issues);
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 20012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);

    std::vector<std::string>information5;
    std::string directive5="create issue --by 1 --name issueA --task_id 1 --members 3 --description createissueA";
    splitDirective(directive5,' ',information5);
    CreateIssue(information5,projects,users,tasks,issues,1);
    ASSERT_TRUE(issues.size()==1); 
    ASSERT_TRUE(issues[1]->getName()=="issueA"); 
    ASSERT_TRUE(issues[1]->getMembers()[0]==3); 
    ASSERT_TRUE(issues[1]->getDescription()=="createissueA"); 

    SetDate("16012024",1,projects,users,tasks,issues);
    ASSERT_TRUE(tasks[1]->getStatus()==TaskStatus::late); 

    std::vector<std::string>information6;
    std::string directive6="edit task --by 1 --id 1  --members 3 --end_time 17012024";
    splitDirective(directive6,' ',information6);
    EditTask(information6,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks[1]->getStatus()==TaskStatus::extended);       
}

TEST(EditProject,Subtest_Running){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    SetDate("04012024",1,projects,users,tasks,issues);
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 20012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    ASSERT_TRUE(projects[1]->getStatus()==ProjectStatus::starting);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);
    ASSERT_TRUE(projects[1]->getStatus()==ProjectStatus::running);      
}
TEST(EditProject,Subtest_Late){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    SetDate("04012024",1,projects,users,tasks,issues);
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 20012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    ASSERT_TRUE(projects[1]->getStatus()==ProjectStatus::starting);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);
    ASSERT_TRUE(projects[1]->getStatus()==ProjectStatus::running);
    ASSERT_TRUE(tasks[1]->getStatus()==TaskStatus::initialized); 
    SetDate("16012024",1,projects,users,tasks,issues);  
    ASSERT_TRUE(tasks[1]->getStatus()==TaskStatus::late); 
    EXPECT_EQ(projects[1]->getStatus(),ProjectStatus::late); 
}
TEST(EditProject,Subtest_Delayed){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    SetDate("04012024",1,projects,users,tasks,issues);
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 20012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    ASSERT_TRUE(projects[1]->getStatus()==ProjectStatus::starting);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);
    ASSERT_TRUE(projects[1]->getStatus()==ProjectStatus::running);
    ASSERT_TRUE(tasks[1]->getStatus()==TaskStatus::initialized); 
    SetDate("21012024",1,projects,users,tasks,issues);  
    ASSERT_TRUE(tasks[1]->getStatus()==TaskStatus::late); 
    EXPECT_EQ(projects[1]->getStatus(),ProjectStatus::delayed); 
}
TEST(CreateReport,Subtest_10){
    SetupMapping();
    std::string directive="create user --fullname Leader1 --role leader";
    std::vector<std::string>information;
    
    splitDirective(directive,' ',information);
    
    std::map<int,Project*>projects;
    std::map<int,User*>users;
    std::map<int,Issue*>issues;
    std::map<int,Task*>tasks;
    SetDate("04012024",1,projects,users,tasks,issues);
    CreateUser(information,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==1);

    std::vector<std::string>information1;
    std::string directive1="create user --fullname Manager";
    splitDirective(directive1,' ',information1);
    CreateUser(information1,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==2);

    std::vector<std::string>information3;
    std::string directive3="create user --fullname Manager --role member";
    splitDirective(directive3,' ',information3);
    CreateUser(information3,projects,users,tasks,issues,1);
    ASSERT_TRUE(users.size()==3);

    std::vector<std::string>information2;
    std::string directive2="create project --by 2 --name Project1 --leaders 1 --members 3 --start_time 05012024 --end_time 15012024";
    splitDirective(directive2,' ',information2);
    CreateProject(information2,projects,users,tasks,issues,1);
    ASSERT_TRUE(projects.size()==1);
    
    std::vector<std::string>information4;
    std::string directive4="create task --by 2 --name buttonA --project_id 1 --start_time 05012024 --end_time 15012024 --members 3";
    splitDirective(directive4,' ',information4);
    CreateTask(information4,projects,users,tasks,issues,1);
    ASSERT_TRUE(tasks.size()==1);

    std::vector<std::string>information5;
    std::string directive5="create issue --by 1 --name issueA --task_id 1 --members 3 --description createissueA";
    splitDirective(directive5,' ',information5);
    CreateIssue(information5,projects,users,tasks,issues,1);
    ASSERT_TRUE(issues.size()==1); 
    ASSERT_TRUE(issues[1]->getName()=="issueA"); 
    ASSERT_TRUE(issues[1]->getMembers()[0]==3); 
    ASSERT_TRUE(issues[1]->getDescription()=="createissueA"); 
    CreateReport("input99.txt",projects,users,tasks,issues);
    std::string filePath = "Report_04012024.txt";
    std::string expectedContent = 
"PROJECT_START Project1\nSTATUS running\nSTART_TIME 05012024\nEND_TIME 15012024\nMANAGER Manager\nLEADER Leader1\nMEMBER Manager\nTASK_START buttonA\nSTATUS initialized\nCREATED_BY 2\nSTART_TIME 05012024\nEND_TIME 15012024\nMEMBER Manager\nISSUE_START issueA\nSTATUS found\nCREATED_BY 1\nMEMBER Manager\nDESCRIPTION createissueA\nISSUE_END\nTASK_END\nPROJECT_END\n";

    std::string fileContent = ReadFileContent(filePath);

    EXPECT_EQ(fileContent, expectedContent)<<fileContent;
}
