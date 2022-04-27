#include <iostream>
#include <unordered_map>
#include <vector>
#include "section.h"
#include "student.h"
#include "instructor.h"
#include "term.h"

// class for the collection of data
class collection {

    public: 
    collection() {};

    unordered_map<string, student*> students;
    unordered_map<string, section*> courses;
    unordered_map<string, instructor*> instructors;
    unordered_map<string, term*> terms;

    student* get_student(string emplid);
    section* get_section(string class_id);
    instructor* get_instructor(string ins_id);
    term* get_term(string term_id);

    unordered_map<string, student*>* getAllStudents();
    unordered_map<string, section*>* getAllCourses();
    unordered_map<string, instructor*>* getAllInstructors();
    unordered_map<string, term*>* getAllTerms();

    void enroll_student(string emplid, string course, string grade);
    void assign_instructor(string ins_id, string course);
    void schedule_course(string course, section* sect);
    void schedule_term(string term_id, term* term);

};

// function definitions for the college class


//getters for individuals
student* collection::get_student(string emplid) {
        return students[emplid]; 
}

section* collection::get_section(string class_id) {
    return courses[class_id];
}

instructor* collection::get_instructor(string ins_id) {
    return instructors[ins_id]; 
}

term* collection::get_term(string term_id) {
    return terms[term_id];
}

//getters for specific datas
unordered_map<string, student*>* collection::getAllStudents() {
    return &students;
}
unordered_map<string, section*>* collection::getAllCourses() {
    return &courses;
}
unordered_map<string, instructor*>* collection::getAllInstructors() {
    return &instructors;
}
unordered_map<string, term*>* collection::getAllTerms() {
    return &terms;
}


// enrollment functions
void collection::enroll_student(string emplid, string course, string grade) {
    //only unique students are added, otherwise they only have a new course added to them
    if (!students.count(emplid)) {
        student* s = new student(emplid, course, grade);
        students[emplid] = s;
    } else {
        students[emplid]->add_course(course, grade);
    }
}

void collection::assign_instructor(string ins_id, string course) {
    //only unique instructors are added, otherwise they only have a new course added to them
    if (!instructors.count(ins_id)) {
        instructor* s = new instructor(ins_id, course);
        instructors[ins_id] = s;
    } else {
        instructors[ins_id]->add_course(course);
    }
}

void collection::schedule_course(string course, section* sect) {
    //courses are uniquely identified, so there is nothing else to do than to add them
    courses[course] = sect;   
}

void collection::schedule_term(string term_id, term* term) {
    terms[term_id] = term;
}
