#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;
class node
{
public:
    string employee_id;
    string name;
    string post;
    string department;
    float salary;

    node *next_add;
};

class employee
{
private:
    node *head;

public:
    employee();
    void introduction();
    void login();
    void control_panel();
    void insert();
    void search_id();
    void Edit();
    void del();
    void display();
    void salaray_slip();
    void search_dept();
};

employee::employee()
{
    head = NULL;
}

void employee::introduction()
{
    system("cls");
    cout << "\n\n\n";
    cout << "\n\t\t\t============================== ";
    cout << "\n\n\t\t\t\4 Employee Management System \4 ";
    cout << "\n\n\t\t\t============================== ";
    getch();
}

void employee::login()
{
p:
    system("cls");
    string user;
    string pass;
    cout << "\n\n";
    cout << "\n\t\t\t============================== ";
    cout << "\n\n\t\t\t\t\4 Login Panel \4 ";
    cout << "\n\n\t\t\t============================== ";
    cout << "\n\t\t\tEnter Your Name: ";
    cin >> user;
    cout << "\t\t\tEnter Password: ";

    for (int i = 1; i <= 6; i++)
    {
        pass += getch();
        cout << "\4";
    }

    if (user == "MS" && pass == "123456")
    {
        cout << "\n\n\t\t\tCongratulations! Login Successful ";
        cout << "\n\n\t\t\t\t    Loading...";

        for (int i = 1; i < 6; i++)
        {
            Sleep(500);
            cout << ".";
        }
        control_panel();
    }

    else if (user != "MS" && pass == "123456")
    {
        cout << "\n\n\t\t\tUsername is wrong! ";
    }

    else if (user == "MS" && pass != "123456")
    {
        cout << "\n\n\t\t\tYour Password is wrong! ";
    }

    else
    {
        cout << "\n\n\t\t\tBoth, Username and Password are wrong! ";
    }
    getch();
    goto p;
}

void employee::control_panel()
{
p:
    system("cls");
    int x;
    cout << "\n\t\t\t============================== ";
    cout << "\n\t\t\t     Employee Control Panel ";
    cout << "\n\t\t\t============================== ";
    cout << "\n\n\n 1. Insert Record ";
    cout << "\n 2. Search Record ";
    cout << "\n 3. Edit Record ";
    cout << "\n 4. Delete Record ";
    cout << "\n 5. Display Record ";
    cout << "\n 6. Salary Slip ";
    cout << "\n 7. Search Department ";
    cout << "\n 8. Exit ";
    cout << "\n\n Select your choice: ";
    cin >> x;

    switch (x)
    {
    case 1:
        insert();
        break;
    case 2:
        search_id();
        break;
    case 3:
        Edit();
        break;
    case 4:
        del();
        break;
    case 5:
        display();
        break;
    case 6:
        salaray_slip();
        break;
    case 7:
        search_dept();
        break;
    case 8:
        exit(0);
    default:
        cout << "\n\n ___Invalid choice, please try again___ ";
    }
    getch();
    goto p;
}

void employee::insert()
{
    // create a new node and populate its data
    node *temp = new node;
    cout << "\nEnter employee ID: ";
    cin >> temp->employee_id;
    cout << "Enter name: ";
    cin >> temp->name;
    cout << "Enter post: ";
    cin >> temp->post;
    cout << "Enter department: ";
    cin >> temp->department;
    cout << "Enter salary: ";
    cin >> temp->salary;
    temp->next_add = NULL;

    // open a file and write the data to it
    fstream file;
    file.open("I'm_Here.txt", ios::out | ios::app);
    file << temp->employee_id << " " << temp->name << " " << temp->post << " " << temp->department << " " << temp->salary << endl;
    file.close();

    // add the node to the linked list
    temp->next_add = head;
    head = temp;

    cout << "\nRecord Inserted! ";
    getch();
}

void employee::search_id()
{
    system("cls");
    string id;
    cout << "\nEnter the ID of the employee to search: ";
    cin >> id;

    // open the file and read the data
    fstream file;
    file.open("I'm_Here.txt", ios::in);

    string cur_id, name, post, department;
    float salary;
    bool found = false;
    while (file >> cur_id >> name >> post >> department >> salary)
    {
        if (cur_id == id)
        {
            cout << "\nEmployee ID: " << cur_id << "\nName: " << name << "\nPost: " << post << "\nDepartment: " << department << "\nSalary: " << salary << endl;
            found = true;
            break;
        }
    }

    file.close();
    if (!found)
    {
        cout << "\nRecord not found! ";
    }
    getch();
}

void employee::Edit()
{
    system("cls");
    string id;
    cout << "\nEnter the ID of the employee to edit: ";
    cin >> id;

    // open the file and read the data
    fstream file;
    file.open("I'm_Here.txt", ios::in);
    string temp_file = "temp_I'm_Here.txt";
    fstream temp;
    temp.open(temp_file, ios::out);

    string cur_id, name, post, department;
    float salary;
    bool found = false;
    while (file >> cur_id >> name >> post >> department >> salary)
    {
        if (cur_id != id)
        {
            temp << cur_id << " " << name << " " << post << " " << department << " " << salary << endl;
        }
        else
        {
            found = true;
            cout << "Enter the new name: ";
            cin >> name;
            cout << "Enter the new post: ";
            cin >> post;
            cout << "Enter the new department: ";
            cin >> department;
            cout << "Enter the new salary: ";
            cin >> salary;
            temp << cur_id << " " << name << " " << post << " " << department << " " << salary << endl;
        }
    }

    file.close();
    temp.close();

    if (found)
    {
        remove("I'm_Here.txt");
        rename(temp_file.c_str(), "I'm_Here.txt");
        cout << "\nRecord Edited! ";
    }
    else
    {
        cout << "\nRecord not found! ";
    }
    getch();
}

void employee::del()
{
    system("cls");
    string id;
    cout << "\nEnter the ID of the employee to delete: ";
    cin >> id;

    // open the file and read the data
    fstream file;
    file.open("I'm_Here.txt", ios::in);
    string temp_file = "temp_I'm_Here.txt";
    fstream temp;
    temp.open(temp_file, ios::out);

    string cur_id, name, post, department;
    float salary;
    bool found = false;
    while (file >> cur_id >> name >> post >> department >> salary)
    {
        if (cur_id != id)
        {
            temp << cur_id << " " << name << " " << post << " " << department << " " << salary << endl;
        }
        else
        {
            found = true;
        }
    }

    file.close();
    temp.close();

    if (found)
    {
        remove("I'm_Here.txt");
        rename(temp_file.c_str(), "I'm_Here.txt");
        cout << "\nRecord Deleted! ";
    }
    else
    {
        cout << "\nRecord not found! ";
    }
    getch();
}

void employee::display()
{
    system("cls");
    cout << "\n\t\t\t============================== ";
    cout << "\n\t\t\t     Employee Records ";
    cout << "\n\t\t\t============================== ";

    // open the file and read the data
    fstream file;
    file.open("I'm_Here.txt", ios::in);

    string id, name, post, department;
    float salary;
    while (file >> id >> name >> post >> department >> salary)
    {
        cout << "\nEmployee ID: " << id << "\nName: " << name << "\nPost: " << post << "\nDepartment: " << department << "\nSalary: " << salary << endl;
    }

    file.close();
    getch();
}

void employee::salaray_slip()
{
    system("cls");
    int found = 0;
    string EmpId;

    cout << "\n\n\t\t\t============================== ";
    cout << "\n\n\t\t\t Salary Slip Generator ";
    cout << "\n\n\t\t\t============================== ";

    if (head == NULL)
    {
        cout << "\n\n   ___Linked List is Empty___ ";
    }

    else
    {
        cout << "\n\n   Employee ID for Slip: ";
        cin >> EmpId;
        node *ptr = head;

        while (ptr != NULL)
        {
            if (EmpId == ptr->employee_id)
            {
                system("cls");
                cout << "\n\t\t\t============================== ";
                cout << "\n\t\t\t=                            = ";
                cout << "\n\t\t\t=    Employee Salary Slip    = ";
                cout << "\n\t\t\t=                            = ";
                cout << "\n\t\t\t============================== ";

                cout << "\n\t\t\t   Employee ID:         " << ptr->employee_id;
                cout << "\n\t\t\t   Name:                " << ptr->name;
                cout << "\n\t\t\t   Post:                " << ptr->post;
                cout << "\n\t\t\t   Department:          " << ptr->department;
                cout << "\n\t\t\t   Salary:              " << ptr->salary;
                cout << "\n\n\t\t\t============================== ";
                cout << "\n\t\t\t============================== ";
                found++;
            }
            ptr = ptr->next_add;
        }

        if (found == 0)
        {
            cout << "\n\n ___Employee ID not found___ ";
        }
    }
}

void employee::search_dept()
{
    system("cls");
    string department;
    cout << "\nEnter the department to search: ";
    cin >> department;

    // open the file and read the data
    fstream file;
    file.open("I'm_Here.txt", ios::in);

    string id, name, post, cur_department;
    float salary;
    bool found = false;
    while (file >> id >> name >> post >> cur_department >> salary)
    {
        if (cur_department == department)
        {
            cout << "\nEmployee ID: " << id << "\nName: " << name << "\nPost: " << post << "\nDepartment: " << cur_department << "\nSalary: " << salary << endl;
            found = true;
        }
    }

    file.close();
    if (!found)
    {
        cout << "\nNo employees found in that department! ";
    }
    getch();
}

int main()
{
    employee obj;
    obj.introduction();
    obj.login();
}
