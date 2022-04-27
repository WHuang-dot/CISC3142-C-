#include "collectionFiller.cpp"
#include "Output.cpp"

collection bc = fill();

unordered_map<string, section*>* courses = bc.getAllCourses();
unordered_map<string, student*>* students = bc.getAllStudents();
unordered_map<string, instructor*>* instructors = bc.getAllInstructors();
unordered_map<string, term*>* terms = bc.getAllTerms();

bool isPassed(string grade) {
    unordered_set<string> passing = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "CR"};
    return passing.count(grade);
}

bool isW(string grade) {
    unordered_set<string> Wgrade = {"W", "WN", "WU"};
    return Wgrade.count(grade);
}

void instructorPassedReport(unordered_map<string, instructor*>* instructors){

    string type = "-InstructorPassedReport";
    int totalInstructor = 0;
    int totalStudent = 0;
    int totalPassedStudent = 0;
    FILE* report = createFile(type);
    for(const auto& c : *instructors){
        int totalStudentForCurrentIns = 0;
        int totalPassedForCurrentIns = 0;
        totalInstructor++;
        string insId = c.second->getInsId();
        for(const auto& w: c.second->classes){
            for(string s : courses->at(w)->students) {
                totalStudentForCurrentIns++;
                string &grade = students->at(s)->classes[w];
                if(isPassed(grade)){
                    totalPassedStudent++;
                    totalPassedForCurrentIns++;
                }
                totalStudent++;
            }
        }
        double passRate = ((double)totalPassedForCurrentIns)/(double)totalStudentForCurrentIns;
        string passRateString = to_string(passRate);
        fprintf(report,"%s   %f \n",insId.c_str(), passRate);
    }

    fclose(report);
}

void instructorWReport(unordered_map<string, instructor*>* instructors){

    string type = "-InstructorWReport";

    int totalInstructor = 0;
    int totalStudent = 0;
    int totalPassedStudent = 0;
    FILE* report = createFile(type);
    for(const auto& c : *instructors){
        int totalStudentForCurrentIns = 0;
        int totalPassedForCurrentIns = 0;
        totalInstructor++;
        string insId = c.second->getInsId();
        for(const auto& w: c.second->classes){
            for(string s : courses->at(w)->students) {
                totalStudentForCurrentIns++;
                string &grade = students->at(s)->classes[w];
                if(isW(grade)){
                    totalPassedStudent++;
                    totalPassedForCurrentIns++;
                }
                totalStudent++;
            }
        }

        double passRate = ((double)totalPassedForCurrentIns)/(double)totalStudentForCurrentIns;
        fprintf(report,"%s   %f \n",insId.c_str(), passRate);
    }
}

void CoursePassedReport(unordered_map<string, section*>* courses){
    unordered_map<string,double> uniqueCourseNos;
    unordered_map<string,double> passedStudentOfCourseNos;
    string type = "-CoursePassedReport";
    int totalInstructor = 0;
    int totalStudent = 0;
    int totalPassedStudent = 0;
    string course_no;
    FILE* report = createFile(type);
    for(const auto& c : *courses){
        bool passed;
        for (const auto& s : c.second->students) {
            passed = isPassed(students->at(s)->classes.at(c.first));
        }
        course_no = c.second->course_no;
        if(!uniqueCourseNos.count(course_no)){
            uniqueCourseNos.insert({course_no,1});
        }else{
            uniqueCourseNos[course_no]++;
        }

        if(!passedStudentOfCourseNos.count(course_no)){
            if(passed){
                passedStudentOfCourseNos.insert({course_no,1});
            }else{
                passedStudentOfCourseNos.insert({course_no,0});
            }
        }else{
            if(passed){
                passedStudentOfCourseNos[course_no]++;
            }
        }
    }
    vector<string> availableCourses;
    for(const auto& courses: uniqueCourseNos){
        availableCourses.push_back(courses.first);
    }

    for(const auto& courseNums : availableCourses){
        string currentCourseNum = courseNums;
        double total = uniqueCourseNos[currentCourseNum];
        double passed = passedStudentOfCourseNos[currentCourseNum];
        double rate = (passed)/total;
        fprintf(report,"%s   %f \n",currentCourseNum.c_str(), rate);
    }

}

void CourseWReport(unordered_map<string, section*>* courses){
    unordered_map<string,double> uniqueCourseNos;
    unordered_map<string,double> passedStudentOfCourseNos;
    string type = "-CourseWReport";
    int totalInstructor = 0;
    int totalStudent = 0;
    int totalPassedStudent = 0;
    string course_no;
    FILE* report = createFile(type);
    for(const auto& c : *courses){
        bool passed;
        for (const auto& s : c.second->students) {
            passed = isW(students->at(s)->classes.at(c.first));
        }
        course_no = c.second->course_no;
        if(!uniqueCourseNos.count(course_no)){
            uniqueCourseNos.insert({course_no,1});
        }else{
            uniqueCourseNos[course_no]++;
        }

        if(!passedStudentOfCourseNos.count(course_no)){
            if(passed){
                passedStudentOfCourseNos.insert({course_no,1});
            }else{
                passedStudentOfCourseNos.insert({course_no,0});
            }
        }else{
            if(passed){
                passedStudentOfCourseNos[course_no]++;
            }
        }
    }
    vector<string> availableCourses;
    for(const auto& courses: uniqueCourseNos){
        availableCourses.push_back(courses.first);
    }

    for(const auto& courseNums : availableCourses){
        string currentCourseNum = courseNums;
        double total = uniqueCourseNos[currentCourseNum];
        double passed = passedStudentOfCourseNos[currentCourseNum];
        double rate = (passed)/total;
        fprintf(report,"%s   %f \n",currentCourseNum.c_str(), rate);
    }

}

int main () {
    instructorPassedReport(instructors);
    instructorWReport(instructors);
    CoursePassedReport(courses);
    CourseWReport(courses);
    return 0;
}

