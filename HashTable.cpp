#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Client_db;
class Client
{
private:
    int id;
    string name;
    long long int number;
    int next_prob;

public:
    Client()
    {
        id = -1;
        name = " ";
        number = 0;
        next_prob = -1;
    }

    Client(int id, string name, int number)
    {
        this->id = id;
        this->name = name;
        this->number = number;
    }

    void getData()
    {
        cout << "Enter the id of the client : " << endl;
        cin >> id;

        cout << "Enter the name of the client : " << endl;
        cin >> name;

        cout << "Enter the number of the client : " << endl;
        cin >> number;
    }

    void showDataa()
    {
        cout << "The id of the client is :" << id << endl;
        cout << "The name of the client is :" << name << endl;
        cout << "The number of the client is :" << number << endl;
    }

    friend class Client_db;
};

class Client_db
{
    Client c;

private:
    Client HT[10];
    int index;

public:
    int HashFunctions(Client c)
    {
        int index = c.id % 10;
        return index;
    }

    int HashFunctions(int key)
    {
        int index = key % 10;
        return index;
    }

    void insert_record()
    {
        c.getData();
        index = HashFunctions(c);

        if (HT[index].next_prob == -1)
        {
            cout << "No collision occured\nElement inserted" << endl;
            HT[index] = c;
            HT[index].next_prob = index + 1;
        }
        else
        {
            cout << "Collisions Occured" << endl;
            int i = index;

            while (HT[i].next_prob != -1)
            {
                i = HT[i].next_prob;
            }

            HT[i] = c;
            HT[i].next_prob = i + 1;
        }
    }

    void search()
    {
        int i, key;
        cout << "Enter the key you want to insert:";
        cin >> key;

        // Client bt;
        // bt.id = key;
        i = HashFunctions(key);

        while (key != HT[i].id && i != -1)
        {

            i = HT[i].next_prob;
        }

        if (key == HT[i].id)
        {
            cout << "Client found" << endl;
            cout << "Name:" << HT[i].name << endl;
            cout << "Number:" << HT[i].number << endl;
            return;
        }

        cout << "Not Found" << endl;
    }

    void deleteClient()
    {
        int i, key, fkag = 0;
        int prev,next,temp;
        cout << "Enter the id to delete : " << endl;
        cin >> key;

        Client dt;
        dt.id = key;

        i = HashFunctions(dt);
        while (key != HT[i].id && i != -1)
        {
            prev=i;
            i = HT[i].next_prob;
        }
        if (HT[i].id == key)
        {

            cout << "Deleting ......" << endl;
            HT[prev].next_prob = HT[i].next_prob;
            HT[i].id = -1;
            HT[i].name = " ";
            HT[i].number = 0;
            HT[i].next_prob = -1;
            return;
        }
        cout << "Not found";
        show();
    }

    void show()
    {
        cout << "__________________________________________________________________________________" << endl;
        cout << "\nIndex\tId\tName\t\tNumber\n"
             << endl;
        cout << "__________________________________________________________________________________" << endl;

        for (int i = 0; i < 10; i++)
        {
            cout << i << "\t" << HT[i].id << "\t" << HT[i].name << "\t" << HT[i].number << endl;
        }
    }
};

int main()
{
    int choice;
    bool flag = true;
    Client_db cd;
    while (flag)
    {
        cout << "\n________________________LIST________________________" << endl;
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n"
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cd.insert_record();
            break;

        case 2:
            cd.search();
            break;

        case 3:
            cd.deleteClient();
            break;

        case 4:
            cd.show();
            break;

        case 5:
            break;

        default:
            cout << "Please Enter a valid entry";
            break;
        }

        char chr;
        cout << "Do you want to continue(y or n)" << endl;
        cin >> chr;

        if (chr == 'n')
        {
            flag = false;
        }
    }

    return 0;
}