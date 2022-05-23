#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DictionaryADT;
class DataField
{
private:
    int key;
    int value;

    DataField *next;

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

class DictionaryADT
{
    DataField c;

private:
    DataField HT[10];
    int index;

public:
    int HashFunctions(DataField c)
    {
        int index = c.key % 10;
        return index;
    }

    int HashFunctions(int c)
    {
        int index = c % 10;
        return index;
    }

    void insert()
    {
        
        c.getData();
        index = HashFunctions(c);
        DataField *temp = &(HT[index]);
        if (HT[index].key == -1)
        {
            HT[index] = c;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = &c;
            c.next =NULL;
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
            cout << i << "\t" << HT[i].key << "\t" << HT[i].value << "--> "<<endl;
            DataField *temp = HT[i].next;
            while (temp->next != NULL)
            {
                cout << temp->key << "\t" << temp->value << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
 
    void search()
    {
        int key;
        cout << "Enter the key you want to search : " << endl;
        cin >> key;

        int i;
        i = HashFunctions(key);

        if (HT[i].key == key)
        {
            cout << "Key Found" << endl;
            cout << "The value associated with the key is :" << HT[i].value << endl;
            return;
        }
        else
        {
            DataField *temp = HT[i].next;

            while (temp->key != key)
            {
                temp = temp->next;
            }
            if (temp->key == key)
            {
                cout << "Key Found" << endl;
                cout << "The value associated with the key is :" << temp->value << endl;
                return;
            }
        }
        cout << "Not found";
    }
};

int main()
{
    int choice;
    bool flag = true;
    DictionaryADT cd;
    while (flag)
    {
        cout << "\n________________________LIST________________________" << endl;
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n"
             << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cd.insert();
            break;

        case 2:
            cd.search();
            break;

            // case 3:
            //     cd.deleteClient();
            //     break;

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