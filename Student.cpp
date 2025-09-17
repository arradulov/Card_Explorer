#include "Student.h"

Student::Student() : name(L""), age(0), group(L"") {}

void Student::inputconsole()
{
    std::wcout << L"¬ведите им€: ";
    std::wcin >> name;
    std::wcout << L"¬ведите возраст: ";
    std::wcin >> age;
    std::wcout << L"¬ведите группу: ";
    std::wcin >> group;
}

void Student::outputconsole() const
{
    std::wcout << L"»м€: " << name << L", возраст: " << age << L", группа: " << group << std::endl;
}

void Student::inputFile(std::wifstream& in)
{
    in >> name >> age >> group;
}

void Student::outputFile(std::wofstream& out) const
{
    out << name << L" " << age << L" " << group << std::endl;
}
