#include <iostream>
#include <string>
#include <vector>
using namespace std;

int a = 0;

//Struct để lưu trữ thông tin của mỗi thành viên hội đồng
struct BoardMember {
    string name;
    string academicRank;
    string degree;
    string availableTime;
};

//Khoa
struct DepartmentBoard {
    string departmentName;
    vector<BoardMember> boardMembers;
    string scheduledTime;
};

BoardMember inputBoardMember() {
    BoardMember member;
    cout << "Nhap thong tin hoi dong sau: " << endl;
    cout << "Ten hoi dong: ";
    getline(cin, member.name);
    cout << "Hoc ham: ";
    getline(cin, member.academicRank);
    cout << "Hoc vi: ";
    getline(cin, member.degree);
    cout << "Khung gio: ";
    getline(cin, member.availableTime);
    return member;
}

DepartmentBoard inputDepartmentBoard() {
    DepartmentBoard department;
    cout << "Nhap cac thong tin khoa sau: " << endl;
    cout << "Ten khoa: ";
    getline(cin, department.departmentName);
    cout << "Time to chuc: ";
    getline(cin, department.scheduledTime);
    int numMembers;
    cout << "So luong hoi dong: ";
    cin >> numMembers;
    cin.ignore();
    for (int i = 0; i < numMembers; ++i) {
        cout << "Thong tin cua tung thanh vien hoi dong " << i + 1 << ":" << endl;
        department.boardMembers.push_back(inputBoardMember());
    }
    return department;
}

bool isConflict(const string& time1, const string& time2) {
    return time1 == time2;
}


void autoSchedule(vector<DepartmentBoard>& departments) {
    for (int i = 0; i < departments.size(); ++i) {
        for (int j = i + 1; j < departments.size(); ++j) {
            if (isConflict(departments[i].scheduledTime, departments[j].scheduledTime)) {
                cout << "Co su trung lich giua cac phong ban: " << departments[i].departmentName << " Và " << departments[j].departmentName << endl;
            }
        }
    }
}


void searchSchedule(const vector<DepartmentBoard>& departments, const string& lecturerName) {
    cout << "Tim kiem hoi dong theo ten giang vien: '" << lecturerName << "':" << endl;
    bool found = false;
    for (const auto& department : departments) {
        for (const auto& member : department.boardMembers) {
            if (member.name == lecturerName) {
                cout << "Khoa: " << department.departmentName << ", Khung gio: " << department.scheduledTime << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << "Giang vien nay khong duoc tim thay trong hoi dong" << endl;
    }
}


void displayDepartmentBoard(const vector<DepartmentBoard>& departments) {
    cout << "\nLich hoi dong:" << endl;
    for (const auto& department : departments) {
        cout << "Khoa: " << department.departmentName << ", Khung gio: " << department.scheduledTime << endl;
    }
}



int main() {
  
    vector<DepartmentBoard> department;

    int n;
    std::cout << "Nhap so Luong hoi dong" << endl; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Thong tin khoa thu " << i << ":" << endl;
        department.push_back(inputDepartmentBoard());
    }

    autoSchedule(department);

    string lecturerName;
    std::cout << "Nhap ten giang vien : " << endl;
    getline(cin, lecturerName);
    searchSchedule(department, lecturerName);

    displayDepartmentBoard(department);

   return 0;
}
