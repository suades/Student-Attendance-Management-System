#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int adminView();
int studentView();
int studentLogin();
int checkCredentials(string userName, string password);
int getAllStudentsbyRollNo();
int deleteAllStudents();
int toggleSecurityQuestionFeature();
int deleteStudentbyRollno();
int checkListOfStudentsRegistered();
int checkPresenseCountbyRollno();
int getListOfStudentsWithTheirPresenseCount();
int registerStudent();
int adminLogin();
int registerStudent();
int markMyAttendance(string username, string password);
int countMyAttendance(string username, string password);
int delay();

int delay()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\n Saving Records ...";
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }

    cout << "\n Exiting Now ...";
    for (int i = 0; i < 3; i++)
    {
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }

    return 0;
}

int adminView()
{
    int goBack = 0;
    while (1)
    {
        system("cls");
        cout << "\n 1 Register a Student";
        cout << "\n 2 Delete All students name registered";
        cout << "\n 3 Delete student by rollno";
        cout << "\n 4 Check List of Student registered by userame";
        cout << "\n 5 Check presense count of any student by Roll No";
        cout << "\n 6 Get List of student with their attendance count";
        cout << "\n 7 Toggle an additional security question";
        cout << "\n 0. Go Back <- \n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerStudent();
            break;
        case 2:
            deleteAllStudents();
            break;
        case 3:
            deleteStudentbyRollno();
            break;
        case 4:
            checkListOfStudentsRegistered();
            break;
        case 5:
            checkPresenseCountbyRollno();
            break;
        case 6:
            checkPresenseCountbyRollno();
            break;
        case 7:
            toggleSecurityQuestionFeature();
            break;
        case 0:
            goBack = 1;
            break;
        default:
            cout << "\n Invalid choice. Enter again ";
            getchar();
        }

        if (goBack == 1)
        {
            break; // break the loop
        }
    }

    return 0;
}

int studentLogin()
{
    system("cls");
    cout << "\n -------- Student Login ---------";
    studentView();
    delay();
    return 0;
}

int adminLogin()
{
    system("cls");
    cout << "\n --------- Admin Login --------";

    string username;
    string password;

    cout << "\n Enter username : ";
    cin >> username;
    cout << "\n Enter password : ";
    cin >> password;

    if (username == "admin" && password == "admin!&")
    {
        adminView();
        getchar();
        delay();
    }
    else
    {
        cout << "\n Error ! Invalid Credintials..";
        cout << "\n Press any key for main menu ";
        getchar();
        getchar();
    }

    return 0;
}

int checkStudentCredentials(string username, string password, string answer)
{
    // read file line by line & check if username-password.dat exist?
    // if it exsist return 1 else 0

    ifstream read;
    read.open("db.dat");

    if (read)
    {
        // The file exists, and is open for input
        int recordFound = 0;
        string line;
        string temp = username + password + ".dat";
        cout << "\n file name is : " << temp;
        while (getline(read, line))
        {
            if (line == temp)
            {
                recordFound = 1;
                break;
            }
        }

        if (recordFound == 0){
            return 0;
        }else{
            return 1;
        }
        ifstream infile("security_question_enabled.dat");
        string isEnabled;
        getline(infile, isEnabled);
        infile.close();

        if (isEnabled == "1") {
            ifstream questionFile("security_question.dat");
            string securityQuestion;
            getline(questionFile, securityQuestion);
            questionFile.close();

            cout << "\n Security Question: " << securityQuestion << "\n";
            cout << "Answer: ";
            string inputAnswer;
            cin.ignore();
            getline(cin, inputAnswer);

            ifstream read(username + ".dat");
            string storedAnswer;
            getline(read, storedAnswer); // Assuming other details are read before this
            read.close();

            if (inputAnswer != storedAnswer) {
                cout << "\n Incorrect Security Answer!";
                getchar();
                return 0;
        }
    }

    studentView();
    return 0;
    }
    else
    {
        return 0;
    }
}

int getAllStudentsbyName()
{
    cout << "\n List all my students by name \n";
    cout << "\n Please any key to continue..";
    getchar();
    getchar();

    return 0;
}

int getAllStudentsbyRollNo()
{
    cout << "\n List  all my students by their ID number \n";

    cout << "\n Please any key to continue..";
    getchar();
    getchar();

    return 0;
}

int deleteStudentbyRollno()
{

    cout << "\n Remove a student by ID number \n";

    cout << "\n Please any key to continue..";
    getchar();
    getchar();

    return 0;
}

int checkPresenseCountbyRollno()
{
    cout << "\n List a student's attendance by ID number \n";

    cout << "\n Please any key to continue..";
    getchar();
    getchar();

    return 0;
}

int checkAllPresenseCountbyRollno()
{
    cout << "\n List attendance of all students by ID & Name \n";
    cout << "\n Please any key to continue..";
    getchar();
    getchar();

    return 0;
}

int studentView()
{
    cout << "\n ------- Student Login-------- \n";

    string username, password, answer;

    cout << "\n Enter username : ";
    cin >> username;

    cout << "\n Enter password : ";
    cin >> password;

    ifstream infile("security_question_enabled.dat");
    string isEnabled;
    getline(infile, isEnabled);
    infile.close();
    if (isEnabled == "1") {
        cout << "\n Enter answer to the security question : ";
        cin >> answer;
    }
    int res = checkStudentCredentials(username, password, answer);

    if (res == 0)
    {
        cout << "\n Invalid Credentials Inputed!!";
        cout << "\n Press any key to return to the main menu..";
        getchar();
        getchar();
        return 0;
    }

    int goBack = 0;
    while (1)
    {
        system("cls");

        cout << "\n 1 Mark attendance for today";
        cout << "\n 2 Count my attendance";
        cout << "\n 0. Go Back <- \n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                markMyAttendance(username, password);
                break;
            case 2:
                countMyAttendance(username, password);
                break;
            case 0:
                goBack = 1;
                break;
            default:
                cout << "\n Invalid choice. Enter again";
                getchar();
        }

        if (goBack == 1)
        {
            break; // break the loop
        }
    }

    return 0;
}

int markMyAttendance(string username, string password)
{
   string filename = username + password + ".dat";
    ifstream read(filename);
    if (!read.is_open()) {
        cout << "\n Error: Unable to open file for " << username;
        getchar();
        return 0;
    }

    string line, attendanceCountStr;
    vector<string> fileContent;

    // Read the entire file content and find the attendance line
    while (getline(read, line)) {
        fileContent.push_back(line);
    }
    read.close();

    // Assuming attendance count is the last line in the file
    attendanceCountStr = fileContent.back();
    int attendanceCount = stoi(attendanceCountStr);
    fileContent.back() = to_string(++attendanceCount); // Increment attendance

    // Write the updated content back to the file
    ofstream write(filename);
    for (const auto& l : fileContent) {
        write << l << "\n";
    }
    write.close();

    cout << "\n Attendance marked successfully for " << username << "!";
    cout << "\n Please any key to continue..";
    getchar();
    return 0;
}

int countMyAttendance(string username, string password)
{
    string filename = username + ".dat";
    ifstream read(filename);
    if (!read.is_open()) {
        cout << "\n Error: Unable to open file for " << username;
        getchar();
        return 0;
    }

    string line, attendanceCountStr;

    // Read the entire file to find the attendance line
    while (getline(read, line)) {
        attendanceCountStr = line; // Assuming attendance count is the last line
    }
    read.close();

    cout << "\n Your current attendance count is: " << attendanceCountStr;
    cout << "\n Please any key to continue..";
    getchar();
    return 0;
}

int deleteAllStudents()
{
    cout << "\n In delete all students!!";
    cout << "\n Please any key to continue..";
    // todo: implement this functionality

    getchar();
    getchar();
    return 0;
}

int checkListOfStudentRegistered()
{
    cout << "\n List of All registered registered!!";
    cout << "\n Please any key to continue..";

    // todo: implment this functionality

    getchar();
    getchar();
    return 0;
}

int getListOfStudentsWithTheirPresenseCount()
{
    cout << "\n All students with their attendance!!";
    cout << "\n Please any key to continue..";
    // todo: implement this functionality

    getchar();
    getchar();
    return 0;
}

int checkListOfStudentsRegistered()
{
    cout << "\n - Check List of Student Registered by Username-- ";

    // check if record already exist..
    ifstream read;
    read.open("db.dat");

    if (read)
    {
        int recordFound = 0;
        string line;
        while (getline(read, line))
        {
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name, (strlen(name) - 4));
            cout << " \n " << onlyname;
        }
        read.close();
    }
    else
    {
        cout << "\n No Record found :(";
    }

    cout << "\n Please any key to continue..";
    getchar();
    getchar();
    return 0;
}

//This function allows the admin to enable an additional security question 
int toggleSecurityQuestionFeature() {
    cout << "\n Toggle Security Question Feature";
    cout << "\n Do you want to enable the Security Question? (y/n): ";

    char choice;
    cin >> choice;

    ofstream outfile("security_question_enabled.dat");
    if (choice == 'y' || choice == 'Y') {
        outfile << "1"; // Enable feature
        cout << "\n Feature Enabled.";
        
        // Set the security question
        cout << "\n Enter the Security Question: ";
        cin.ignore(); // Clear input buffer
        string securityQuestion;
        getline(cin, securityQuestion);

        ofstream questionFile("security_question.dat");
        questionFile << securityQuestion;
        questionFile.close();

        cout << "\n Security Question Set.";
    } else {
        outfile << "0"; // Disable feature
        cout << "\n Feature Disabled.";
    }
    outfile.close();
    cout << "\n Returning to admin view...";
    getchar();
    getchar();
    return 0;
}


int registerStudent()
{
    cout << "\n ----- Form to Register Student ---- \n";

    string name, username, password, rollno, address, father, mother;

    cout << "\n Enter Name : ";
    cin >> name;
    cout << "\n Enter Username : ";
    cin >> username;
    cout << "\n Enter password : ";
    cin >> password;
    cout << "\n Enter rollno : ";
    cin >> rollno;
    getchar();

    char add[100];
    cout << "\n Enter address : ";
    cin.getline(add, 100);
    cout << "\n Enter father : ";
    cin >> father;
    cout << "\n Enter mother : ";
    cin >> mother;

    ifstream infile("security_question_enabled.dat");
    string isEnabled;
    getline(infile, isEnabled);
    infile.close();

    string securityAnswer;
    if (isEnabled == "1") { // Security question feature is enabled
        ifstream questionFile("security_question.dat");
        string securityQuestion;
        getline(questionFile, securityQuestion);
        questionFile.close();

        cout << "\n Security Question: " << securityQuestion;
        cout << "\n Enter your Answer: ";
        cin.ignore(); // clear input buffer
        getline(cin, securityAnswer);
    }

    // check if record already exist..
    ifstream read;
    read.open("db.dat");

    if (read)
    {
        int recordFound = 0;
        string line;
        while (getline(read, line))
        {
            if (line == username + ".dat")
            {
                recordFound = 1;
                break;
            }
        }
        if (recordFound == 1)
        {
            cout << "\n Username already Register. Please choose another username ";
            getchar();
            getchar();
            delay();
            read.close();
            return 0;
        }
    }
    read.close();

    ofstream out;
    out.open("db.dat", ios::app);
    out << username + password + ".dat"
        << "\n";
    out.close();

    ofstream out1;
    string temp = username + password + ".dat";
    out1.open(temp.c_str());
    out1 << name << "\n";
    out1 << username << "\n";
    out1 << password << "\n";
    out1 << rollno << "\n";
    out1 << add << "\n";
    out1 << father << "\n";
    out1 << mother << "\n";
    out1 << securityAnswer << "\n";
    out1 << 0;
    out1.close();
    cout << "\n Student Registered Successfully !!";

    cout << "\n Please any key to continue..";
    getchar();
    getchar();
    return 0;
}

int main(int argc, char **argv)
{

    while (1)
    {
        system("cls");
        cout << "\n Attendance Management System \n";
        cout << "-------------------------------------\n\n";

        cout << "1. Student Login\n";
        cout << "2. Admin Login\n";
        cout << "0. Exit\n";
        int choice;

        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentLogin();
            break;
        case 2:
            adminLogin();
            break;
        case 0:
            while (1)
            {
                system("cls");
                cout << "\n Are you sure, you want to exit? y | n \n";
                char ex;
                cin >> ex;
                if (ex == 'y' || ex == 'Y')
                    exit(0);
                else if (ex == 'n' || ex == 'N')
                {
                    break;
                }
                else
                {
                    cout << "\n Invalid choice !!!";
                    getchar();
                }
            }
            break;

        default:
            cout << "\n Invalid choice. Enter again ";
            getchar();
        }
    }

    return 0;
}