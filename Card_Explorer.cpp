#include <iostream>
#include <Windows.h>
#include <locale>
#include "Group.h"




int main()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    std::locale::global(std::locale("rus_rus.866"));
    std::wcin.imbue(std::locale("rus_rus.866"));
    std::wcout.imbue(std::locale());

    Group group;
    int choice;
    std::wstring filename;

    do {
        std::wcout << L"\n=== МЕНЮ ===\n";
        std::wcout << L"1. Добавить студента\n";
        std::wcout << L"2. Показать всех студентов\n";
        std::wcout << L"3. Загрузить из файла\n";
        std::wcout << L"4. Сохранить в файл\n";
        std::wcout << L"5. Очистить список\n";
        std::wcout << L"0. Выход\n";
        std::wcout << L"Ваш выбор: ";
        std::wcin >> choice;

        switch (choice) {
        case 1:
            group.addStudent();
            break;
        case 2:
            group.printAll();
            break;
        case 3:
            std::wcout << L"Введите имя файла для загрузки: ";
            std::wcin >> filename;
            group.readFromFile(filename);
            break;
        case 4:
            std::wcout << L"Введите имя файла для сохранения: ";
            std::wcin >> filename;
            group.writeToFile(filename);
            break;
        case 5:
            group.clear();
            std::wcout << L"Список очищен!" << std::endl;
            break;
        case 0:
            std::wcout << L"Выход..." << std::endl;
            break;
        default:
            std::wcout << L"Неверный выбор!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
