#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class Node{
    string word, meaning;
    Node* left;
    Node* right;
public:
    Node(){
        left = right = NULL;
        word = meaning = "";
    }
    Node(string w , string m){
        word = w;
        meaning = m;
        left = NULL;
        right = NULL;
    }
    friend class bst;
};

class bst{
    Node* root;
public:
    bst(){
        root = NULL;
    } 

    void insert(string word , string meaning);
    Node* deletion(Node* root,string word);
    void deleteNode(string word); //jockey
    Node* searchdict(Node* root, string word);
    void search(string word); //jockey
    void update(string word);
    void inOrderLRR(Node* root);  //left root right
    void inOrderRRL(Node* root);  //right root left
    void display();
    int maxComparison(string word);
};

void bst :: insert(string word , string meaning){
    Node* pnew;
    pnew = new Node(word , meaning);
    if(root == NULL){
        root = pnew;
        cout<<"\nDictionary Created!"<<endl;
    }
    else{
        Node* temp = root;
        do{
            if(word < temp->word){
                temp = temp->left;               
                if(temp == NULL){
                    temp->left = pnew;
                    cout<<"\n"<<word<<" Node Inserted to Left of : "<<temp->word;
                    break;
                }
            }
            else if(word > temp->word){
                temp = temp->right;                
                if(temp == NULL){
                    temp->right = pnew;
                    cout<<"\n"<<word<<" Node Inserted to Rigth of : "<<temp->word;
                    break;
                }
            }
            else if(word == temp->word){
                cout<<"Word already available in Dictionary!"<<endl;
                break;
            }
        }while(temp != NULL);
    }
}

Node* bst :: deletion(Node* root, string word){
    if(root == NULL){
        cout<<"\nWord not Found!";
        return root;
    }
    if(word < root->word){
        cout<<"\nSearching in Left Sub-Tree";
        root->left = deletion(root->left , word);
    }
    else if(word > root->word){
        cout<<"\nSearching in Right Sub-Tree";
        root->right = deletion(root->right , word);
    }
    else{ //node found
        if(root->right == NULL){
            return root->left;
        }
        else{
            Node* ptr; //in-order successor ptr
            ptr = root->right;
            while(ptr->left != NULL){
                ptr = ptr->left;
            }
            root->word = ptr->word;
            root->right = deletion(root->right , ptr->word);
        }
    }
    return root;
}

void bst :: deleteNode(string word){
    root = deletion(root, word);
}

Node* bst :: searchdict(Node* root, string word){
    if(root == NULL){
        cout<<"\nWord not Found!";
        return NULL;
    }
    if (word < root->word){
        root = searchdict(root->left , word);
        return root;
    }
    else if (word > root->word){
        root = searchdict(root->right, word);
        return root;
    }
    else{
        return root;
    }
}

void bst :: search(string word){
    root = searchdict(root,word);
    if(root == NULL){
        cout<<"\nWord not Found in the Dictionary!";
    }
    else{
        cout<<"\nElement Found -> "<<endl;
        cout<<"Word : "<<root->word<<endl;
        cout<<"Meaning : "<<root->meaning<<endl;
    }
}

void bst :: update(string word){
    string updatedMeaning;
    root = searchdict(root,word);
    if(root == NULL){
        cout<<"\nWord not Found in the Dictionary!";
    }
    else{
        cout<<"\nElement Found -> "<<endl;
        cout<<"Word : "<<root->word<<endl;
        cout<<"Original Meaning : "<<root->meaning<<endl;
        cout<<"Enter Updated Meaning : ";
        cin>>updatedMeaning;
        root->meaning = updatedMeaning;
    }
}

void bst :: inOrderLRR(Node* root){  //ascending
    if(root != NULL){
        inOrderLRR(root->left);
        cout<<root->word<<" - ";
        inOrderLRR(root->right);
    }
    else{
        cout<<"\nDictionary Not Yet Created!";
    }
}

void bst :: inOrderRRL(Node* root){  //decending
    if(root != NULL){
        inOrderLRR(root->right);
        cout<<root->word<<" - ";
        inOrderLRR(root->left);
    }
    else{
        cout<<"\nDictionary Not Yet Created!";
    }
}

int bst :: maxComparison(string word){
    int cnt = 0;
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->word == word){
            cnt += 1;
        }
        else{
            cout<<"\nWord Not Found !";
        }
    }
    else{
        do{
            if(word < root->word){
                cnt++;
                if(root->word == word){
                    break;
                }
                root = root->left;
            }
            else if(word > root->word){
                cnt++;
                if(root->word == word){
                    break;
                }
                root = root->right;
            }
        }while(root != NULL);
    }
    return cnt;
}

void bst :: display(){
    int choice = 0;
    cout<<"\n\t1) Ascending \n\t2) Decending"<<endl;
    cout<<"Enter choice : ";
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 1:
            inOrderLRR(root);
        case 2:
            inOrderRRL(root);
        default:
            cout<<"Invalid Choice !";
    }
}

int main()
{
    bst d1;
    
    d1.insert("dog"      , "loyal");
    d1.insert("cat "     , "pet");
    d1.insert("grand"    , "exception");
    d1.insert("apple"    , "fruit");
    d1.insert("fresh"    , "newly");
    d1.insert("elephant" , "huge");
    d1.insert("bear"     , "animal");

    // d1.display();

    // int choice;
    // string word, meaning;

    // while(choice != 7){
    //     cout<<"\n\t\t DICTIONARY"
    //         <<"\n1) Add Word to Dictionary"
    //         <<"\n2) Search Word" 
    //         <<"\n3) Update Word/Change Word Meaning"
    //         <<"\n4) Check Max Comparisons Required for a Word to Search"
    //         <<"\n5) Display Dictionary"
    //         <<"\n6) Delete Word"
    //         <<"\n7) Exit"<<endl;
    //     cout<<"\nEnter Choice : ";
    //     cin>>choice;

    //     switch(choice){
    //         case 1:
    //             cout<<"\nEnter Word : ";
    //             cin>>word;
    //             cout<<"\nEnter Meaning : ";
    //             cin>>meaning;
    //             d1.insert(word, meaning);
    //             break;
    //         case 2:
    //             cout<<"\nEnter Word : ";
    //             cin>>word;
    //             d1.search(word);
    //             break;
    //         case 3:
    //            cout<<"\nEnter Word : ";
    //            cin>>word;
    //            d1.update(word);
    //            break;
    //         case 4:
    //             cout<<"\nEnter Word : ";
    //             cin>>word;
    //             cout<<d1.maxComparison(word); 
    //             break;
    //         case 5:
    //             d1.display();
    //             break;
    //         case 6:
    //             cout<<"\nEnter Word : ";
    //             cin>>word;
    //             d1.deleteNode(word);
    //             break;
    //         case 7:
    //             exit(0);
    //             break;
    //         default:
    //             cout<<"Invalid Input!"<<endl;
    //             break;
    //     }
    // }

    return 0;
}