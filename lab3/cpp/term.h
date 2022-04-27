#include <string>
#include <unordered_set>

using namespace std;


struct term {
    string term_id;
    unordered_set<string> courses;
    string termName;

    term() {}

    term (string term_id, string course, string termName) {
        this->term_id = term_id;
        this->termName = termName;
        courses.insert(course);
    }

    void add_course(string course) {
        courses.insert(course);
    }

    string getTermName(){
        return termName;
    }

};
