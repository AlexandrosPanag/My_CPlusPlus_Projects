/* ALEXANDROS PANAGIOTAKOPOULOS AM16108 */

#include <iostream>
#include <fstream>
#include<ctime>
#include<vector>
#include <algorithm>
#include<map>

using namespace std;


/* class course */
class course {
    private:string id;
    string title;
    int hours_theory;
    int hours_tutoring;
    int hours_lab;
    int credits;
    public:
    course(string id,string t,int ht,int htu,int hl,int c);
    string get_id()const;
    int get_hours()const;
    int get_hours_tutoring()const;
    int get_hours_lab()const;
    friend ostream &operator<<(ostream &os,const course &a_course);
};
enum class academic_rank
{
    DEP,
    EDIP,
    EXTERNAL,
    TEACHING_ASSISTANT,
};

/*CLASS LECTURER */
class lecturer{
    private:
    string name;
    academic_rank rank;
    public:
    lecturer(string n,academic_rank r);
    string get_name()const;
    string get_rank()const;
    friend ostream &operator<<(ostream&os,const lecturer);
};
class classroom{
    private:
    string id;
    int capacity;
    bool labartory;
    public:
    classroom(string id,int c,bool lab);
    string get_id()const;
    friend ostream &operator<<(ostream &os,const classroom &a_classrooms);
};
enum class teaching_type{
    THEORY,
    TUTORING,
    LABARTORY,
};
enum class days{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,   
};
class meeting
{
    private:
    course meeting_course;
    classroom meeting_classroom;
    vector<lecturer>lecturers;
    teaching_type type;
    days day;
    time_t start_time;
    int duration;
    
    public:
    meeting(course a_course,classroom a_classroom,teaching_type a_teaching_type,days a_day,string a_start_time,int a_duration);
    void add_lecturer(lecturer a_lecturer);
    course get_meeting_course()const;
    classroom get_classroom()const;
    vector<lecturer>get_lecturers()const;
    teaching_type get_teaching_type()const;
    days get_teaching_type_as_enum()const;
    string get_teaching_type_day()const;
    time_t get_start_time()const;
    string start_time_as_string()const;
    int get_duration()const;

    friend ostream &operator<<(ostream &os,const meeting &a_meeting);
};
/* class problem */

class problem{
    private:
    vector<course>courses;
    vector<classroom>classrooms;
    vector<meeting>meetings;
    public:
    void add_course(course a_course);
    void add_lecturer(lecturer a_lecturer);
    void add_classroom(classroom a_classroom);
    void add_meeting(meeting a_meeting);
    course get_course(string course_id)const;
    classroom get_classroom(string classroom_id)const;
    lecturer get_lecturer(string lecturer_name)const;
    bool is_valid()const;
    void print_timetable_by_day();
    void print_timetable_by_course();
    void print_time_table_by_lecturer();
};

/* capitalize */
string capitalize (string s){
    string ns;
    for(char c:s){
        ns.push_back(toupper(c));
    }
    return ns;
};

/* MAIN */
int main(){
fstream fin;

fin.open("semester.txt",ios::in);
string word;
string line;
string status= "none";
map<string,int>dictionairy;
while(fin>>word){
    word=capitalize(word);
    if(line.substr(0)=="#")
    {
        continue;
    }
    if(line.substr(0, string("[COURSE]").size()) =="[COURSE]")
    {
        status="course";
        continue;
    }
    else if(line.substr(0, string("[LECTURERS]").size()) =="[LECTURERS]")
    {
        status="lecturerers";
        continue;
    }
    else if(line.substr(0, string("[CLASSROOMS]").size()) =="[CLASSROOMS]")
    {
        status="classrooms";
        continue;
    }
    else if(line.substr(0, string("[MEETINGS]").size()) =="[MEETINGS]")
    {
        status="meetings";
        continue;
    }
    if(status=="course")
    {
        string course_id=line.substr(0, line.find(";"));
        line.erase(0, line.find(";")+1);
        string course_title=line.substr(0,line.find(";"));
        line.erase(0, line.find(";")+1);
        int hours_theory=stoi(line.substr(0,line.find(";")));
        line.erase(0, line.find(";")+1);
        int hours_tutoring=stoi(line.substr(0,line.find(";")));
        line.erase(0, line.find(";")+1);
        int hours_labartory=stoi(line.substr(0,line.find(";")));
        line.erase(0, line.find(";")+1);
        int credits=stoi(line.substr(0,line.find(";")));
        course a_course(course_id, course_title,hours_theory,hours_tutoring,hours_labartory,credits);
        cout<<a_course<<endl;
    }
    if(status=="lecturers")
    {
        string course_id=line.substr(0, line.find(";"));
        line.erase(0, line.find(";")+1);
        string course_title=line.substr(0,line.find(";"));
        line.erase(0, line.find(";")+1);
        int hours_theory=stoi(line.substr(0,line.find(";")));
        line.erase(0, line.find(";")+1);
        int hours_labartory=stoi(line.substr(0,line.find(";")));
        line.erase(0, line.find(";")+1);
        int credits=stoi(line.substr(0,line.find(";")));
        lecturer a_lecturer(string name,int academic_rank);
        cout<<a_lecturer<<endl;
    }
}
return 0;
}