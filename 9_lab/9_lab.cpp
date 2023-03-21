#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Student {
protected:
    string firstName;
    string lastName;
    string middleName;
    int course;
    string field;
    string subject;
    int semester;

public:
    //Student() {}
    Student(string firstName, 
            string lastName, 
            string middleName, 
            int course, 
            string field, 
            string subject, 
            int semester) : firstName(firstName), 
                            lastName(lastName), 
                            middleName(middleName), 
                            course(course), 
                            field(field), 
                            subject(subject), 
                            semester(semester) {}

    int getCourse() const {
        return course;
    }

    virtual void printData() const {
        cout << "\nФамилия: " << firstName << "\nИмя: " << lastName << "\nОтчество: " << middleName << "\nКурс: ";
        cout << course << "\nГруппа: " << field << "\nПридмет: " << subject << "\nСеместр: " << semester << " ";
    }
};

class ModuleMark : public Student {
private:
    int mark;

public:
    //ModuleMark() {}
    ModuleMark(string firstName, 
               string lastName, 
               string middleName, 
               int course, 
               string field, 
               string subject, 
               int semester, 
               int mark) : Student(firstName, 
                                   lastName, 
                                   middleName, 
                                   course, 
                                   field, 
                                   subject, 
                                   semester), mark(mark) {}

    void printData() const override {
        Student::printData();
        cout << "\nОценка: " << mark << endl;
    }
};

class CourseworkMark : public Student {
private:
    string courseworkTitle;
    int mark;

public:
    //CourseworkMark() {}
    CourseworkMark(string firstName,
                   string lastName, 
                   string middleName, 
                   int course, 
                   string field, 
                   string subject, 
                   int semester, 
                   string courseworkTitle, 
                   int mark) : Student(firstName, 
                                       lastName, 
                                       middleName, 
                                       course, 
                                       field, 
                                       subject, 
                                       semester), 
                                       courseworkTitle(courseworkTitle), mark(mark) {}

    void printData() const override {
        Student::printData();
        cout << "\nКурсовая работа: " << courseworkTitle << "\nОценка за курсовую работу: " << mark << endl;
    }
};

vector<ModuleMark> readModuleMarksFromFile(string fileName) {
    vector<ModuleMark> moduleMarks;

    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Не могу открыть файл " << fileName << endl;
        return moduleMarks;
    }

    string line;
    while (getline(inputFile, line)) {
        string firstName, lastName, middleName, field, subject;
        int course, semester, mark;

        stringstream ss(line);
        ss >> firstName >> lastName >> middleName >> course >> field >> subject >> semester >> mark;

        moduleMarks.push_back(ModuleMark(firstName, lastName, middleName, course, field, subject, semester, mark));
    }

    inputFile.close();
    return moduleMarks;
}

vector<CourseworkMark> readCourseworkMarksFromFile(string fileName) {
    vector<CourseworkMark> courseworkMarks;

    ifstream inputFile(fileName);
    if (!inputFile.is_open()){
        cout << "Не могу открыть файл" << fileName << endl;
        return courseworkMarks;
    }
    string line;
    while (getline(inputFile, line)) {
        string firstName, lastName, middleName, field, subject, courseworkTitle;
        int course, semester, mark;

        stringstream ss(line);
        ss >> firstName >>  lastName >>  middleName >> course >> field >> subject >> semester >> courseworkTitle >> mark;

        courseworkMarks.push_back(CourseworkMark(firstName, lastName, middleName, course, field, subject, semester, courseworkTitle, mark));
    }

    inputFile.close();
      return courseworkMarks;
}

void printMarksForCourse(int courseNum, vector<ModuleMark> moduleMarks, vector<CourseworkMark> courseworkMarks) {
    //cout << "Оценки модуля за курс " << courseNum << endl;
    for (const auto& moduleMark : moduleMarks) {
        if (moduleMark.getCourse() == courseNum) {
            moduleMark.printData();
        }
    }
    
    //cout << "Оценки за курсовую работу " << courseNum << endl;
    for (const auto& courseworkMark : courseworkMarks) {
        if (courseworkMark.getCourse() == courseNum) {
            courseworkMark.printData();
        }
    }

  
}

int main() {
    vector<ModuleMark> moduleMarks = readModuleMarksFromFile("module_marks.txt");
    vector<CourseworkMark> courseworkMarks = readCourseworkMarksFromFile("courseworkMarks.txt");
    int num;
    cout << "Введите курс:";
    cin >> num;
    printMarksForCourse(num, moduleMarks, courseworkMarks);

    return 0;
}

// moduleMarks data

Бажаткова Элина Эдуардовна 1 ИТ-22 Физика 1 80
Иванова София Ивановна 1 ИТ-22 История 1 90
Буракшаева Юлия Сергеевна 2 ИТ-22 Алгебра 2 85
Фурсова Елизавета Владимировна 1 ИТ-22 Физика 1 80 
Сапсай Иван Алексеевич 2 ИТ-22 История 1 90 
Богословский Артем Михайлович 3 ИТ-22 Алгебра 2 85 
Самбикина Юлия Владимировна 1 ИТ-22 Физика 1 80
Шпак Ангелина Эдуардовна 2 ИТ-22 История 1 90 
Пименов Максим Евгеньевич 3 ИТ-22 Алгебра 2 85 
Сигида Валерия Романовна 1 ИТ-22 Физика 1 80 
Миронова Елизавета Валерьевна 2 ИТ-22 История 1 90 
Безуглова Анастасия Александровна 3 ИТ-22 Алгебра 2 85 
Сергеева Мария Вячеславовна 1 ИТ-22 Физика 1 80 
Перфильева Милена Егоровна 2 ИТ-22 История 1 90 
Химич Елена Сергеевна 3 ИТ-22 Алгебра 2 85 
Бондина Анастасия Борисовна 1 ИТ-22 Физика 1 80 
Лебедева Екатерина Сергеевна 2 ИТ-22 История 1 90 
Мощева Алина Георгиевна 3 ИТ-22 Алгебра 2 85 
Моругина Ирина Николаевна 1 ИТ-22 Физика 1 80 
Прокопенко Алина Дмитривена 2 ИТ-22 История 1 90 


// courseworkMarks data

Белюга Татьяна Сергеевна 1 ИТ-22 Физика 1 Имя_Курсовая_работа1 90
Седенкова Анастасия Максимовна 2 ИТ-21 Физика 1 Имя_Курсовая_работа12 90
Храмова Полина Дмитриевна 3 ИТ-20 Алгебра 1 Имя_Курсовая_работа4 99 
Бирт Елизавета Александровна 1 ИТ-22 Физика 2 Имя_Курсовая_работа3 89
Власова Мария Борисовна 2 ИТ-21 Физика 2 Имя_Курсовая_работа2 79
Пискунова Валерия Александровна 3 ИТ-20 Алгебра 2 Имя_Курсовая_работа9 79
Бажаткова Элина Эдуардовна 1 ИТ-22 Физика 3 Имя_Курсовая_работа4 98    
Казанцева Елизавета Александровна 2 ИТ-21 Алгебра 3 Имя_Курсовая_работа6 67
