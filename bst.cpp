#include <iostream>
using namespace std;
class Node
{
public:
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

private:
    int data;
    Node *left;
    Node *right;
    friend class bst;
};
class bst
{
public:
    bst()
    {
        root = NULL;
        cout << "Empty BST created";
    }
    void insert(int value);

private:
    Node *root;
};
void bst::insert(int value)
{
    Node *pNew;
    pNew = new Node(value);
    pNew->data = value;
    if (root == NULL)
    {
        root = pNew;
        cout << "Root created";
    }
    else
    {
        Node *pTemp;
        pTemp = root;
        do
        {
            if (value < pTemp->data)
            {
                if (pTemp->left == NULL)
                {
                    pTemp->left = pNew;
                    cout << "\nNew value inserted in left of " << pTemp->data;
                    break;
                }
                else
                {
                    pTemp = pTemp->left;
                }
            }
            else if (value > pTemp->data)
            {
                if (pTemp->right == NULL)
                {
                    pTemp->right = pNew;
                    cout << "\nNew value inserted in right of " << pTemp->data;
                    break;
                }
                else
                {
                    pTemp = pTemp->right;
                }
            }
            else
                cout << "\nDuplicate Value Found";
        } while (pTemp != NULL);
    }
}
int main()
{
    bst b;
    b.insert(20);
    b.insert(5);
    b.insert(2);
    b.insert(47);
    b.insert(15);
    b.insert(7);
    b.insert(25);
    b.insert(9);
    b.insert(12);
    return 0;
}
