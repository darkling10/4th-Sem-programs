// A Dictionary stores keywords and its meanings. Provide facility for adding new
// keywords, deleting keywords, updating values of any entry. Provide facility to display
// whole word sorted in ascending/ Descending order. Also find how many maximum
// comparisons may require for finding any keyword. Use Height balance tree and find the
// complexity for finding a keyword

#include <iostream>
using namespace std;

class Node
{
    string word, meaning;
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
    Node(string value, string mean)
    {
        word = value;
        meaning = mean;
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
        cout << "Empty Binary Search Tree Created" << endl;
    }
    int height(Node *root);
    int BF(Node *root);
    Node *leftrot(Node *root);
    Node *rightrot(Node *root);
    void insert(string value, string mean);
    Node *insert(string value, string mean, Node *root);
    void search(string key);
    Node *search(Node *root, string key);
    void displayAVL();
    void inorderTraversal(Node *root);
    void deleteVal(string value);
    Node *remove(string value, Node *root);
};

int AVL::height(Node *root)
{
    int hl, hr;
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        hl = height(root->left);
    hr = height(root->right);
    if (hr >= hl)
        return hr + 1;
    else
        return hl + 1;
}

int AVL::BF(Node *root)
{
    int hl, hr;
    hl = height(root->left);
    hr = height(root->right);
    return hl - hr;
}

Node *AVL::leftrot(Node *root)
{
    Node *B;
    Node *A = root;
    B = A->right;
    A->right = B->left;
    B->left = A;
    return B;
}

Node *AVL::rightrot(Node *root)
{
    Node *B;
    Node *A = root;
    B = A->left;
    A->left = B->right;
    B->right = A;
    return B;
}

void AVL::insert(string value, string mean)
{
    root = insert(value, mean, root);
    cout << value << " IS INSERTED" << endl;
}

Node *AVL::insert(string value, string mean, Node *root)
{
    int bf;

    if (root == NULL)
    {
        root = new Node(value, mean);
        return root;
    }
    else if (root->word > value)
    {
        cout << "LEFT Subtree" << endl;
        root->left = insert(value, mean, root->left);
        bf = BF(root);
        cout << bf << endl;
        if (bf == 2)
        {
            if (BF(root->left) == 1)
            {
                // ll
                cout << "Left-Left Condition so Right-rotation" << endl;
                root = rightrot(root);
            }
            else
            {
                // lR
                cout << "Left-Right Condition so Left then Right-rotation" << endl;

                root->left = leftrot(root->left);
                root = rightrot(root);
            }
        }
        return root;
    }

    else if (root->word < value)
    {
        cout << "RIGHT Subtree" << endl;
        root->right = insert(value, mean, root->right);

        bf = BF(root);
        cout << bf << endl;
        if (bf == -2)
        {
            if (BF(root->right) == -1)
            {
                // RR
                cout << "Right-Right Condition so Left-rotation" << endl;
                root = leftrot(root);
            }
            else
            {
                // RL
                cout << "Right-Left Condition so Right then Left-rotation" << endl;
                root->right = rightrot(root->right);
                root = leftrot(root);
            }
        }
        return root;
    }

    else
    {
        cout << "Same Value" << endl;
        return root;
    }
}

void AVL ::search(string key)
{
    Node *flag;
    flag = search(root, key);
    if (flag == NULL)
    {
        cout << "Not Found!!!" << endl;
    }
}

Node *AVL::search(Node *root, string key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->word)
    {
        return search(root->left, key);
    }
    else if (key > root->word)
    {
        return search(root->right, key);
    }
    else
    {
        cout << "Element Found !!" << root->word << endl;
        return root;
    }
}

void AVL::displayAVL()
{
    cout << "Inorder traversal of the AVL Tree is :- " << endl;
    inorderTraversal(root);
    cout << endl;
}

void AVL::inorderTraversal(Node *root)
{
    Node *temp = root;
    if (temp != NULL)
    {
        inorderTraversal(temp->left);
        cout << "[" << temp->word << " - " << temp->meaning << " ] -> ";
        inorderTraversal(temp->right);
    }
}

void AVL::deleteVal(string value)
{
    root = remove(value, root);
    cout << "AVL after deletion is -" << endl;
    displayAVL();
}

Node *AVL ::remove(string value, Node *root)
{
    Node *temp;
    int bf;
    if (root == NULL)
    {
        return NULL;
    }
    else if (value < root->word)
    {
        root->left = remove(value, root->left);
        bf = BF(root);
        if (bf == -2)
        {
            if (BF(root->right) == -1) // rr
            {
                cout << "RR" << endl;
                root = leftrot(root);
            }
            else // rl
            {
                cout << "RL" << endl;
                root->right = rightrot(root->right);
                root = leftrot(root);
            }
        }
        return root;
    }
    else if (value > root->word)
    {
        root->right = remove(value, root->right);
        bf = BF(root);

        if (bf == 2)
        {
            if (BF(root->left) == 1) // ll
            {
                cout << "LL" << endl;
                root = rightrot(root);
            }
            else // lr
            {
                cout << "LR" << endl;
                root->left = leftrot(root->left);
                root = rightrot(root);
            }
        }

        return root;
    }
    else
    { // element found

        cout << "Value is found---deleting it" << endl;
        if (root->right == NULL)
            return root->left;
        else
        {
            Node *pInSucc;
            pInSucc = root->right;
            while (pInSucc->left != NULL)
            {
                pInSucc = pInSucc->left;
            }

            root->word = pInSucc->word;
            root->meaning = pInSucc->meaning;

            root->right = remove(pInSucc->word, root->right);

            if (bf == 2)
            {
                if (BF(root->left) == 1) // ll
                {
                    cout << "LL" << endl;
                    root = rightrot(root);
                }
                else // lr
                {
                    cout << "LR" << endl;
                    root->left = leftrot(root->left);
                    root = rightrot(root);
                }
            }
        }

        return root;
    }
}

int main()
{
    int ch;
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
            string key;
            cout << "Enter the Word to be Searched : ";
            cin >> key;
            a1.search(key);
        }
        else if (ch == 3)
        {
            a1.displayAVL();
        }
        else if (ch == 4)
        {
            string val;
            cout << "Enter the value to be deleted!!" << endl;
            cin >> val;
            a1.deleteVal(val);
        }
        else if (ch == 5)
        {
            string oldVal, newVal, newMean;
            cout << "Enter the Old word for Updation : ";
            cin >> oldVal;
            cout << "Enter the Word to Update : ";
            cin >> newVal;
            cout << "Enter the Meaning to Update : ";
            cin >> newMean;
            a1.deleteVal(oldVal);
            a1.insert(newVal, newMean);
        }
        else
        {
            cout << "Wrong input Try again!!" << endl;
        }
    }

    return 0;
}