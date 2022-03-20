#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Tree;

class Node
{
    string data;
    Node *left;
    Node *right;

public:
    Node()
    {
        data =' ';
        left = NULL;
        right = NULL;
    }
    Node(string value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }

    friend class Tree;
};

class Tree
{
private:
    char dir;
    string val;

    Node *root;

public:
    Tree()
    {
        root = NULL;
    }

    Node *getRoot()
    {
        return root;
    }
    void insert(string value)
    {
        Node *pNew = new Node(value);
        if (root == NULL)
        {
            cout << "Root created" << endl;
            root = pNew;
        }
        else
        {
            Node *pTemp = root;
            do
            {
                cout << "Enter the direction (Left -> L) (Right -> R) :" << pTemp->data << endl;
                cin >> dir;

                if (dir == 'L' || dir == 'l')
                {
                    if (pTemp->left == NULL)
                    {
                        cout << "Value added at left of :" << pTemp->data << endl;
                        pTemp->left = pNew;
                        break;
                    }
                    else
                    {
                        // cout<<"Left called";
                        pTemp = pTemp->left;
                    }
                }
                else if (dir == 'R' || dir == 'r')
                {
                    if (pTemp->right == NULL)
                    {
                        cout << "Value added at right of :" << pTemp->data << endl;
                        pTemp->right = pNew;
                        break;
                    }
                    else
                    {
                        pTemp = pTemp->right;
                    }
                }
                else
                {
                    cout << "Please Enter correct direction" << endl;
                }
            } while (pTemp != NULL);
        }
    }

    void level_wise()
    {
        queue<Node *> qu;
        Node *ptemp = root;
        qu.push(ptemp);

        if (ptemp != NULL)
        {
            while (!qu.empty())
            {
                ptemp = qu.front();
                qu.pop();
                cout << ptemp->data << " ";
                if (ptemp->left != NULL)
                {
                    qu.push(ptemp->left);
                }
                if (ptemp->right != NULL)
                {
                    qu.push(ptemp->right);
                }
            }
        }
        else
        {
            cout << "Tree is Empty" << endl;
        }
    }

    void inorder_traversal()
    {
        stack<Node *> st;
        if (root != NULL)
        {
            Node *temp = root;
            do
            {
                while (temp != NULL)
                {
                    st.push(temp);
                    temp = temp->left;
                }
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                temp = temp->right;
            } while (!st.empty() || temp != NULL);
        }
        else
        {
            cout << "Tree is Empty" << endl;
        }
    }

    void preorder_traversal()
    {
        stack<Node *> st;
        if (root != NULL)
        {
            Node *temp = root;
            do
            {
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    st.push(temp);
                    temp = temp->left;
                }
                temp = st.top();
                st.pop();
                temp = temp->right;
            } while (!st.empty() || temp != NULL);
        }
        else
        {
            cout << "Tree is Empty" << endl;
        }
    }
};

int main()
{
    Tree bt;
    int n;
    string val;

    cout << "Enter number of nodes :";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        /* code */

        cout << "Enter the value :";
        cin >> val;
        bt.insert(val);
    }
    // bt.level_wise();
    bt.preorder_traversal();
    return 0;
}