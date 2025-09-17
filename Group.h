#pragma once
#include "Student.h"
#include <vector>


class Group
{
private:
    std::vector<Student*> students;
public:
    Group();
    ~Group();

    void addStudent();
    void printAll() const;
    void readFromFile(const std::wstring& filename);
    void writeToFile(const std::wstring& filename) const;
    void clear();
};
