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

    char type[] = "instructorPassedReport";
    int totalInstructor = 0;
    int totalStudent = 0;
    int totalPassedStudent = 0;
    createFile(*type);
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
        // cout << "Instructor " << insId << " has " << totalStudentForCurrentIns << " and " << totalPassedForCurrentIns << " Passed \n";
        cout << "Instructor " << insId << " has " << totalStudentForCurrentIns << " and " << totalPassedForCurrentIns << " Passed and Pass Rate of " << passRate << endl;
    }
}

void instructorWReport(unordered_map<string, instructor*>* instructors){

    int totalInstructor = 0;
    int totalStudent = 0;
    int totalPassedStudent = 0;
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
        // cout << "Instructor " << insId << " has " << totalStudentForCurrentIns << " and " << totalPassedForCurrentIns << " Passed \n";
        cout << "Instructor " << insId << " has " << totalStudentForCurrentIns << " and " << totalPassedForCurrentIns << " Withdrew and W Rate of " << passRate << endl;
    }
}

void CoursePassedReport(unordered_map<string, section*>* courses){
    unordered_map<string,double> uniqueCourseNos;
    unordered_map<string,double> passedStudentOfCourseNos;
    int totalInstructor = 0;
    int totalStudent = 0;
    int totalPassedStudent = 0;
    string course_no;
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
        cout << "CourseNo " << currentCourseNum << " total Student " << total << " Passed = " << passed << " Rate of " << rate << endl; 
    }

}

void CourseWReport(unordered_map<string, section*>* courses){
    unordered_map<string,double> uniqueCourseNos;
    unordered_map<string,double> passedStudentOfCourseNos;
    int totalInstructor = 0;
    int totalStudent = 0;
    int totalPassedStudent = 0;
    string course_no;
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
        cout << "CourseNo " << currentCourseNum << " total Student " << total << " W = " << passed << " Rate of " << rate << endl; 
    }

}

int main () {
    instructorPassedReport(instructors);
    instructorWReport(instructors);
    CoursePassedReport(courses);
    CourseWReport(courses);
    return 0;
}

