#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Student
{
private:
    std::wstring name;
    int age;
    std::wstring group;
public:
    Student();


    void inputconsole();
    void outputconsole() const;

    void inputFile(std::wifstream& in);
    void outputFile(std::wofstream& out) const;
};
