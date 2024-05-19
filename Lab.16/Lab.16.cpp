#include <iostream>
#include <string>
#include "windows.h"

using namespace std;
const int NUM_ABITURIENTS = 5;
class Abiturient {
    string surname;
    string name;
    string patronymic;
    string address;
    int grades[4];

public:
Abiturient(string sname, string n, string patr, string addr, int g[4])
        : surname(sname), name(n), patronymic(patr), address(addr) {
for (int i = 0; i < 4; ++i) {
grades[i] = g[i];
}
}

int sumGrades() const {
int sum = 0;
for (int i = 0; i < 4; ++i) {
sum += grades[i];
}
return sum;
}

bool hasUnsatisfactoryGrades() const {
for (int i = 0; i < 4; ++i) {
if (grades[i] < 60) {
return true;
}
}
return false;
}

    void show() const {
cout << surname << " " << name << " " << patronymic << ", " << address << ", оцінки: ";
for (int i = 0; i < 4; ++i) {
cout << grades[i] << " ";
}
cout << endl;
}
};
void printAbiturient(const Abiturient& abiturient) {
abiturient.show();
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
int g1[] = { 91, 85, 78, 92 };
int g2[] = { 50, 50, 50, 50 };
int g3[] = { 91, 93, 89, 85 };
int g4[] = { 59, 52, 30, 40 };
int g5[] = { 100, 95, 98, 99 };
Abiturient abiturients[NUM_ABITURIENTS] = {
Abiturient("іванов", "іван", "романович", "харків", g1),
Abiturient("шевченко", "андрій", "сідорович", "київ", g2),
Abiturient("мельник", "олексій", "андрійович", "харків", g3),
Abiturient("ященко", "єгор", "сергійович", "полтава", g4),
Abiturient("коваль", "віталій", "андрійович", "харків", g5)
};
cout << "абітурієнти з незадовільними оцінками:\n";
for (int i = 0; i < NUM_ABITURIENTS; ++i) {
if (abiturients[i].hasUnsatisfactoryGrades()) {
printAbiturient(abiturients[i]);
}
}
cout << endl;
int minSum;
cout << "введіть мінімальну суму балів: ";
cin >> minSum;
cout << "абітурієнти з сумою балів не менше " << minSum << ":\n";
for (int i = 0; i < NUM_ABITURIENTS; ++i) {
if (abiturients[i].sumGrades() >= minSum) {
printAbiturient(abiturients[i]);
}
}
cout << endl;
int N;
cout << "введіть кількість абітурієнтів для вибору з найвищою сумою балів: ";
cin >> N;

    
for (int i = 0; i < NUM_ABITURIENTS - 1; ++i) {
for (int j = 0; j < NUM_ABITURIENTS - i - 1; ++j) {
if (abiturients[j].sumGrades() < abiturients[j + 1].sumGrades()) {
swap(abiturients[j], abiturients[j + 1]);
}
}
}
cout << "топ " << N << " абітурієнтів з найвищою сумою балів:\n";
for (int i = 0; i < N && i < NUM_ABITURIENTS; ++i) {
printAbiturient(abiturients[i]);
}
cout << endl;
double passingScore;
cout << "введіть напівпрохідний бал: ";
cin >> passingScore;
cout << "абітурієнти з напівпрохідним балом " << passingScore << ":\n";
for (int i = 0; i < NUM_ABITURIENTS; ++i) {
if (abiturients[i].sumGrades() >= passingScore / 2 && abiturients[i].sumGrades() < passingScore) {
printAbiturient(abiturients[i]);
}
}
return 0;
}