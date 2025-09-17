#include "Group.h"
#include <fstream>
#include <locale>

Group::Group() {}

Group::~Group() {
    clear();
}

void Group::addStudent() {
    Student* st = new Student();
    st->inputconsole();
    students.push_back(st);
}

void Group::printAll() const {
    if (students.empty()) {
        std::wcout << L"Список пуст!" << std::endl;
        return;
    }
    for (size_t i = 0; i < students.size(); i++) {
        std::wcout << i + 1 << L". ";
        students[i]->outputconsole();
    }
}

void Group::readFromFile(const std::wstring& filename) {
    clear();
    std::wifstream in(filename);
    if (!in.is_open()) {
        std::wcout << L"Ошибка открытия файла!" << std::endl;
        return;
    }
    else {
        std::wcout << L"Данные успешно загружены" << std::endl;
    }
    while (!in.eof()) {
        Student* st = new Student();
        st->inputFile(in);
        if (in) students.push_back(st);
        else delete st;
    }
    in.close();
}

void Group::writeToFile(const std::wstring& filename) const {
    std::wofstream out(filename);
    if (!out.is_open()) {
        std::wcout << L"Ошибка открытия файла!" << std::endl;
        return;
    }
    std::wcout << L"Успешное сохранение!" << std::endl;

    for (auto st : students) {
        st->outputFile(out);
    }
    out.close();
}

void Group::clear() {
    for (auto st : students) {
        delete st;
    }
    students.clear();
}
