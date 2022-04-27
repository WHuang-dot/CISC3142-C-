#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <typeinfo>
#include "collection.cpp"

using namespace std;
collection fill()
{
string line;
vector<vector<string>> lines;

vector<string> paths = {"../data/1115.csv","../data/3115.csv","../data/3130.csv"};
stringstream ss;
collection data;
unordered_set<string> spring_terms = {"T04", "T07", "T09", "T12", "T15", "T17"};

for(string value : paths){
   ifstream fin(value);
   getline(fin, line);
   while (getline(fin, line))
   {
      string temp;
      vector<string> parts;
      ss << line;
      // we need for columns only so use a loop 6 times
      for (int i = 0; i < 6; i++)
      {
         getline(ss, temp, ',');
         parts.push_back(temp);
      }
      lines.push_back(parts);
      
      ss.ignore(numeric_limits<streamsize>::max(), '\n');
      ss.clear();
   }
}

for(auto parts : lines){
   string& id = parts[0];
   string& courseNo = parts[1];
   string& instructorid = parts[2];
   string& termid = parts[3];
   string& sectionid = parts[4];
   string& grade = parts[5];

   string class_id = id + '.' + courseNo + '.' + sectionid;
   //we attempt to retrieve the section and term from the college
   section* sect = data.get_section(class_id);
   term* t = data.get_term(termid);
   //if section is not already in college, we register it now:
   if(!sect) {
      sect = new section (class_id, courseNo, sectionid, instructorid, termid);
      data.schedule_course(class_id, sect);
   }

   if(!t) {
      string termName = spring_terms.count(termid)? "Spring" : "Fall";
      t = new term(termid, class_id, termName);
      data.schedule_term(termid, t);
   }

   //student from the current line gets added to the section
   sect->add_student(id);
   sect->add_courseNo(courseNo);
   t->add_course(class_id);
   //student and instructor from current line are added to the college
   data.enroll_student(id, class_id, grade);
   data.assign_instructor(instructorid, class_id);
}

return data;

}
