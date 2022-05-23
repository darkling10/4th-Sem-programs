#include <bits/stdc++.h>
using namespace std;

class Student
{

private:
    char name[10], address[10];
    int rollNo;
    char div;

public:
    Student()
    {
        name[0] = '\0';
        address[0] = '\0';
        rollNo = -1;
        div = '\0';
    }

    void getData();
    void showData();
    int getRoll() { return rollNo; }
};

void Student ::getData()
{

    cout << "ENTER THE STUDENT DATA " << endl;
    cout << "Enter the name of the student :";
    cin >> name;

    cout << "\nEnter the address of the student : ";
    cin >> address;

    cout << "\nEnter the roll no of the student :";
    cin >> rollNo;

    cout << "\nEnter the division of the student :";
    cin >> div;
};

void Student ::showData()
{
    cout << "\n";
    cout << div << "\t" << rollNo << "\t" << name << "\t" << address << endl;
}

class Seq_File
{
    char fileName[10];

public:
    void create();
    // void update();
    void display();
    void insert();
    void delete_elem();
    bool search(int);
};

void Seq_File ::create()
{
    ofstream ofs;
    int num;
    cout << "Enter the filename :";
    cin >> fileName;
    Student S;
    ofs.open(fileName, ios::app);

    if (ofs)
    {
        cout << "Enter the number of student you want to add : ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            S.getData();
            ofs.write((char *)&S, sizeof(S));
        }

        ofs.close();
    }
};

void Seq_File ::delete_elem()
{

    int roll_del;
    cout << "Enter the roll no you want to delete :";
    cin >> roll_del;

    Student S;
    int Flag = 0;
    ofstream ofs;
    ifstream ifs;
    ifs.open(fileName);
    ofs.open("Temp.txt");

    if (ofs && ifs)
    {
        ifs.read((char *)&S, sizeof(S));

        while (!ifs.eof())
        {
            if (roll_del == S.getRoll())
            {
                S.showData();
                Flag = 1;
            }
            else
            {
                ofs.write((char *)&S, sizeof(S));
            }
            ifs.read((char *)&S, sizeof(S));
        }

        if (Flag == 0)
        {
            cout << "Roll not found";
        }
        ifs.close();
        ofs.close();
        remove(fileName);
        rename("Temp.txt", fileName);
    }
};

void Seq_File ::display()
{

    ifstream ifs;
    Student S;
    ifs.open(fileName);
    if (ifs)
    {

        cout << "__________________________________________\n";
        cout << "Div\tRollNo\tName\tAddress" << endl;
        cout << "__________________________________________\n";
        ifs.read((char *)(&S), sizeof(S));
        while (!ifs.eof())
        {
            S.showData();
            ifs.read((char *)(&S), sizeof(S));
        }
        ifs.close();
    }
    else
        cout << "\nFile opening Error";
};

void Seq_File ::insert()
{
    ofstream file;
    Student S;
    file.open(fileName, ios ::app);
    if (file)
    {
        S.getData();
        file.write((char *)&S, sizeof(S));
        file.close();
    }
};

bool Seq_File ::search(int key)
{
    ifstream ifs;
    Student S;
    bool flag = false;
    ifs.open(fileName);
    if (ifs)
    {
            ifs.read((char *)&S, sizeof(S));
        while (!ifs.eof())
        {
            if(S.getRoll() == key){
                S.showData();
                flag =true;
                return true;
            }
        ifs.read((char*)&S,sizeof(S));
        }
        ifs.close();
    }
    return false;
};

int main()
{
    Seq_File sFile;
    int key, Choice;
    int flag = true;
    while (flag)
    {

        cout << "\n1: Create Database\n2: Display Database\n3: Insert a record\n4: Delete a Record\n5: Search a record\n7: Exit\nEnter your choice: ";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            sFile.create();
            break;
        case 2:
            sFile.display();
            break;
        case 3:
            sFile.insert();
            break;
        case 4:
            sFile.delete_elem();
            break;
        case 5:
            cout << "\nEnter Roll No to Search";
            cin >> key;
            if (!sFile.search(key))
                cout << "\nRecord does not present";
            break;

        case 6:
            return 0;
        }
        char flag2;
        cout << endl;
        cout << "Do you want to continue(y or n) :" << endl;
        cin >> flag2;
        if (flag2 == 'n')
        {
            flag = false;
        }
    }
}

