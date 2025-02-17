#include <bits/stdc++.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name, subject;
    int gradeCount;
    std::vector<int> grades;
};

struct SubjectInfo {
    std::string subject;
    std::vector<std::string> students;
    int count = 0;
};

bool compareSubjects(const SubjectInfo &a, const SubjectInfo &b) {
    if (a.count == b.count) return a.subject < b.subject;
    return a.count > b.count;
}

int main() {
    std::ifstream fin("U2.txt");
    std::ofstream fout("U2rez.txt");
    
    int m;
    fin >> m;
    
    std::vector<Student> students(m);
    for (int i = 0; i < m; i++) {
        fin >> students[i].name >> students[i].subject >> students[i].gradeCount;
        students[i].grades.resize(students[i].gradeCount);
        for (int j = 0; j < students[i].gradeCount; j++) {
            fin >> students[i].grades[j];
        }
    }
    
    std::vector<SubjectInfo> subjects;
    
    for (int i = 0; i < students.size(); i++) {
        double sum = 0;
        for (int j = 0; j < students[i].grades.size(); j++) {
            sum += students[i].grades[j];
        }
        double avg = sum / students[i].gradeCount;
        
        if (avg >= 9.0) {
            bool found = false;
            for (int k = 0; k < subjects.size(); k++) {
                if (subjects[k].subject == students[i].subject) {
                    subjects[k].students.push_back(students[i].name);
                    subjects[k].count++;
                    found = true;
                    break;
                }
            }
            if (!found) {
                SubjectInfo newSubject;
                newSubject.subject = students[i].subject;
                newSubject.students.push_back(students[i].name);
                newSubject.count = 1;
                subjects.push_back(newSubject);
            }
        }
    }
    
    if (subjects.empty()) {
        fout << "Neatitinka vidurkis" << std::endl;
    } else {
        std::sort(subjects.begin(), subjects.end(), compareSubjects);
        for (int i = 0; i < subjects.size(); i++) {
            fout << subjects[i].subject << " " << subjects[i].count << std::endl;
            for (int j = 0; j < subjects[i].students.size(); j++) {
                fout << subjects[i].students[j] << std::endl;
            }
        }
    }
    
    return 0;
}
