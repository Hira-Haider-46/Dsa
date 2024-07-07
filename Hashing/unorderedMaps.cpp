#include <iostream>
#include <unordered_map>
using namespace std;
// also called hash maps
struct Student
{
    string name;
    int dataStructure;
    int linearAlgebra;
    int databaseSystems;
};

int main()
{
    unordered_map<int, Student> studentData;
    studentData[101] = {"Mobeen", 85, 90, 78};
    studentData[102] = {"Babar", 92, 88, 95};
    studentData[103] = {"Usman", 78, 85, 80};
    int studentID;
    cout << "Enter the student ID to get information: ";
    cin >> studentID;
    auto it = studentData.find(studentID);
    if (it != studentData.end())
    {
        cout << "Student Name: " << it->second.name << "\n";
        cout << "Data Structure: " << it->second.dataStructure << "\n";
        cout << "Linear Algebra: " << it->second.linearAlgebra << "\n";
        cout << "Database Systems: " << it->second.databaseSystems << "\n";
    }
    else cout << "Student not found.\n";
}


// #include <iostream>
// #include <map>
// #include <unordered_map>
// using namespace std;

// int main()
// {
//     // creation
//     unordered_map<string, int> m;

//     // insertion
//     // 1
//     pair<string, int> p = make_pair("babbar", 3);
//     m.insert(p);

//     // 2
//     pair<string, int> pair2("love", 2);
//     m.insert(pair2);

//     // 3
//     m["mera"] = 1;

//     // what will happen
//     m["mera"] = 2;

//     // Search
//     cout << m["mera"] << endl;
//     cout << m.at("babbar") << endl;

//     // Output
//     cout << m["love"] << endl;
//     cout << m["unknownKey"] << endl;

//     // size
//     cout << m.size() << endl;

//     // to check presence
//     cout << m.count("love") << endl;

//     // erase
//     m.erase("love");
//     cout << m.size() << endl;

//     // iterator
//     unordered_map<string, int>::iterator it = m.begin();
//     while (it != m.end())
//     {
//         cout << it->first << " " << it->second << endl;
//         it++;
//     }
//     return 0;
// }