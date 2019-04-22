#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool CorrectCurriculmMap(int n, vector<string> Courses, vector<pair<string,string> > Map){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(Courses[j] == )
        }
    }


    return true;
}


int main()
{
    int n, m;
    bool ans;
    string course,courseA,courseB;
    vector<string> ListCourses;
    vector<pair<string,string> > MapCourses;
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++){
        cin >> course;
        ListCourses.push_back(course);
    }
    for(int i = 0; i < m; i++){
        cin >> courseA;
        cin >> courseB;
        pair<string,string> subCourses(courseA,courseB);
        MapCourses.push_back(subCourses);
    }

    ans = CorrectCurriculmMap(n,ListCourses,MapCourses);

    if(ans){
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }

    return 0;
}
