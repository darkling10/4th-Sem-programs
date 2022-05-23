#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    string word;
    string meaning;
    Node *left;
    Node *right;

public:
    Node()
    {
        word = "";
        meaning = "";
        left = NULL;
        right = NULL;
    }

    Node(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;

        left = NULL;
        right = NULL;
    }
    friend class AVL;
};

class AVL
{
    Node *root;

public:
    AVL()
    {
        root = NULL;
        cout << "Tree Created" << endl;
    }
    int Height(Node *root);
    int BalanceFactor(Node *root);
    Node *LeftRotate(Node *root);
    Node *RightRotate(Node *root);
    // Node *LRRotate(Node *root);
    // Node *RLRotate(Node *root);
    void inorder(Node *root);
    void inorder();
    void delete_word(string);
    Node *delete_word(string, Node *);
    void search(string);
    Node *search(string, Node *root);
    void insert(string word, string meaning);
    Node *insert(string word, string meaning, Node *root);
};

int AVL::Height(Node *root)
{
    int hl, hr;
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        hl = Height(root->left);
    hr = Height(root->right);
    if (hr >= hl)
        return hr + 1;
    else
        return hl + 1;
};

int AVL ::BalanceFactor(Node *root)
{
    int hl, hr;

    hl = Height(root->left);
    hr = Height(root->right);

    return hl - hr;
};

Node *AVL ::LeftRotate(Node *root)
{
    Node *A = root;
    Node *B;

    B = A->right;
    A->right = B->left;
    B->left = A;
    return B;
};

Node *AVL ::RightRotate(Node *root)
{
    Node *A = root;
    Node *B;

    B = A->left;
    A->left = B->right;
    B->right = A;
    return B;
};

void AVL ::insert(string word, string meaning)
{
    root = insert(word, meaning, root);
    cout << "Inserted Sucsess" << endl;
};

Node *AVL ::insert(string word, string meaning, Node *root)
{
    int bf;
    if (root == NULL)
    {
        root = new Node(word, meaning);
        return root;
    }

    if (root->word > word)
    {
        cout << "Inserting in left\n";
        root->left = insert(word, meaning, root->left);
        bf = BalanceFactor(root);
        cout << bf << endl;

        if (bf == 2)
        {
            if (BalanceFactor(root->left) == 1)
            {
                cout << "Left Heavy ,Right rotation" << endl;
                root = RightRotate(root);
            }
            else
            {
                cout << "Left Right condition";
                root->left = LeftRotate(root->left);
                root = RightRotate(root);
            }
        }
        return root;
    }
    else if (root->word < word)
    {
        cout << "Insert in Right" << endl;
        root->right = insert(word, meaning, root->right);
        bf = BalanceFactor(root);
        cout << bf << endl;

        if (bf == -2)
        {
            if (BalanceFactor(root->right) == -1)
            {
                cout << "Right Heavy ,Left rotation" << endl;
                root = LeftRotate(root);
            }
            else
            {
                cout << "Right Left condition";
                root->right = LeftRotate(root->right);
                root = LeftRotate(root);
            }
        }
        return root;
    }
    else
    {
        cout << "Duplicate" << endl;
    }

    return root;
}

void AVL ::search(string key)
{
    Node *ans = search(key, root);
    if (ans)
    {
        cout << " Found\n";
        cout << "Meaning :" << ans->meaning << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
};

Node *AVL ::search(string key, Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->word > key)
    {
        return search(key, root->left);
    }
    else if (root->word < key)
    {
        return search(key, root->right);
    }
    else
    {
        return root;
    }
};

void AVL ::delete_word(string key)
{
    root = delete_word(key, root);
    cout << "After deletion" << endl;
}

Node *AVL ::delete_word(string key, Node *root)
{
    if (root == NULL)
    {
        cout<<"Word not found";
        return NULL;
    }
    int bf;
    Node *temp;
    if (root->word > key)
    {
        root->left = delete_word(key, root->left);
        bf = BalanceFactor(root);
        if (bf == 2)
        {
            if (BalanceFactor(root->left) == 1)
            {
                cout << "Left Heavy ,Right rotation" << endl;
                root = RightRotate(root);
            }
            else
            {
                cout << "Left Right condition";
                root->left = LeftRotate(root->left);
                root = RightRotate(root);
            }
        }
        return root;
    }
    else if (root->word < key)
    {
        root->right = delete_word(key, root->right);
        bf = BalanceFactor(root);
        if (bf == -2)
        {
            if (BalanceFactor(root->right) == -1)
            {
                cout << "Right Heavy ,Left rotation" << endl;
                root = LeftRotate(root);
            }
            else
            {
                cout << "Right Left condition";
                root->right = LeftRotate(root->right);
                root = LeftRotate(root);
            }
        }
        return root;
    }
    else
    {
        cout << "Element found deleting it" << endl;
        if (root->right == NULL)
        {
            return root->left;
        }
        else
        {
            Node *pInsucc = root->right;

            while (pInsucc->left != NULL)
            {
                pInsucc = pInsucc->left;
            }

            root->word = pInsucc->word;
            root->meaning = pInsucc->meaning;

            root->right = delete_word(pInsucc->word, root->right);
            if (bf == 2)
            {
                if (BalanceFactor(root->left) == 1)
                {
                    cout << "Left Heavy ,Right rotation" << endl;
                    root = RightRotate(root);
                }
                else
                {
                    cout << "Left Right condition";
                    root->left = LeftRotate(root->left);
                    root = RightRotate(root);
                }
            }
            return root;
        }
    }
}

void AVL ::inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->word << " - " << root->meaning << endl;
    inorder(root->right);
}

void AVL ::inorder()
{
    cout << "Inorder Traversal is:" << endl;
    inorder(root);
}

int main()
{
    int ch;
    string key;
    AVL a1;
    while (1)
    {
        cout << "Enter Your Choice!" << endl;
        cout << "1. Insert 2.Search 3.Display 4.Delete 5.Update 0.Exit" << endl;
        cin >> ch;
        if (ch == 0)
        {
            return 0;
        }
        else if (ch == 1)
        {
            string value;
            string mean;
            cout << "Enter the Word to insert : ";
            cin >> value;
            cout << "Enter the Meaning to insert : ";
            cin >> mean;
            a1.insert(value, mean);
        }
        else if (ch == 2)
        {
            cout << "Enter the key :" << endl;
            cin >> key;
            a1.search(key);
        }
        else if (ch == 3)
        {
            a1.inorder();
        }
        else if(ch == 4){
            cout<<"Enter the word u want to delete:"<<endl;
            cin>>key;

            a1.delete_word(key);
        }
    }
    return 0;
}