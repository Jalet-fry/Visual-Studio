#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<int, std::string> students;
    students.insert({101, "Alice"});
    students.insert({102, "Bob"});
    students.insert({101, "Charlie"});

    int studentID = 101;
    auto range = students.equal_range(studentID);
    std::cout << "Students with ID " << studentID << ": ";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;

    return 0;
}
