#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DictionaryADT;

class DataField
{
private:
    int key = -1;
    int value = 0;
    DataField *next = NULL;

public:
    DataField()
    {
        key = -1;
        value = 0;
        next = NULL;
    }

    DataField(int id, string name, int number)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    void getData()
    {
        cout << "Enter the key  : " << endl;
        cin >> key;

        cout << "Enter the value  : " << endl;
        cin >> value;
    }

    void showDataa()
    {
        cout << "The key is :" << key << endl;
        cout << "The value is :" << value << endl;
    }

    friend class DictionaryADT;
};
//key - value
// 1 -   20 --------> 11 - 20

class DictionaryADT
{
    DataField *HT[10];

private:
    int index;

public:
    DictionaryADT()
    {
        for (int i = 0; i < 10; i++)
        {
            HT[i] = new DataField();
        }
    }
    int HashFunctions(DataField *c)
    {
        int index = c->key % 10;
        return index;
    }

    int HashFunctions(int c)
    {
        int index = c % 10;
        return index;
    }
    void insert()
    {
        DataField *newNode = new DataField();
        newNode->getData();

        index = HashFunctions(newNode);

        if (HT[index]->key == -1)
        {

            HT[index] = newNode;
            newNode->next = NULL;
        }
        else
        {
            DataField *temp = new DataField();
            temp = HT[index];

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = NULL;
        }
    }

    void show()
    {
        cout << "__________________________________________________________________________________" << endl;
        cout << "\nIndex\tkey\tvalue\n"
             << endl;
        cout << "__________________________________________________________________________________" << endl;

        for (int i = 0; i < 10; i++)
        {
            cout << i << "\t" << HT[i]->key << "\t" << HT[i]->value << "--> \t";
            DataField *temp = HT[i]->next;
            
            while (temp != NULL)
            {
                cout << temp->key << "\t" << temp->value << "-->\t ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    int choice;
    bool flag = true;
    DictionaryADT *cd = new DictionaryADT();
    while (flag)
    {
        cout << "\n________________________LIST________________________" << endl;
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n"
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cd->insert();
            break;

        case 2:
            // cd.search();
            break;

            // case 3:
            //     cd.deleteClient();
            //     break;

        case 4:
            cd->show();
            break;

        case 5:
            flag = false;
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