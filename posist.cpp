#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
 struct Address
       {
              char HouseNo[25];
              char City[25];
              char PinCode[25];
       };
struct data{
    char owner_name[10000];
    struct Address Add;
    long int mobile;
    long int phone;
    float value;
};

struct node{
    string datetme;
    struct data D1;
    int NodeNumber;
    int NodeId;
    int ReferenceId;
    int ChildNodeId;
    int ReferenceChildNodeId;
    struct node *next;
}*head=NULL;
string generateKey(string str, string key)
{
    int x = str.size();

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

/*string encryption(string text,int s){
    string result="";
     for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i]))
            result += char(int(text[i]+s-65)%26 +65);
        else
        result += char(int(text[i]+s-97)%26 +97);
    }


    return result;
}*/
string cipherText(string str, string key)
{
    string cipher_text;

    for (int i = 0; i < str.size(); i++)
    {
        // converting in range 0-25
        int x = (str[i] + key[i]) %26;

        // convert into alphabets(ASCII)
        x += 'A';

        cipher_text.push_back(x);
    }
    return cipher_text;
}
string originalText(string cipher_text, string key)
{
    string orig_text;

    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        // converting in range 0-25
        int x = (cipher_text[i] - key[i] + 26) %26;

        // convert into alphabets(ASCII)
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}

void append()
{

    struct node* newnode = new node();
    struct node *last = head;
    cin>>newnode->NodeId>>newnode->ReferenceId>>newnode->ChildNodeId>>newnode->ReferenceChildNodeId;
    cin>>newnode->D1.owner_name>>newnode->D1.Add.HouseNo>>newnode->D1.Add.City>>newnode->D1.Add.PinCode;
    newnode->NodeNumber=newnode->NodeNumber+1;
    newnode->next = NULL;
    if (head == NULL)
    {
       head = newnode;
       return;
    }
    while (last->next != NULL)
        last = last->next;


    last->next = newnode;
    return;
}


struct node *findnode(int n){
    struct node *ptr=head;
    for(int i=1;i<=n;i++){
        ptr=ptr->next;
    }
    string algo_key;
    char str[10000];
    strcpy(str,ptr->D1.owner_name);
    cout<<str;
    generateKey(str,algo_key);
    string cipher_text=cipherText(str,algo_key);

    cout << "Ciphertext : "
         << cipher_text << "\n";

    cout << "Original/Decrypted Text : "
         << originalText(cipher_text,algo_key);
}
struct node *createLinkedList(int n){
    struct node *temp;
    while(n-- >0){
    struct node *newnode=new node();
    newnode->next=NULL;
    int i=0;
    cout<<"enter data for the node"<<endl;
    cout<<"enter NodeId,reference id,childNodeid,reference childNodeId,Address";
    i++;
    newnode->NodeNumber=i;
    cin>>newnode->NodeId>>newnode->ReferenceId>>newnode->ChildNodeId>>newnode->ReferenceChildNodeId;
    cin>>newnode->D1.owner_name>>newnode->D1.Add.HouseNo>>newnode->D1.Add.City>>newnode->D1.Add.PinCode;
    if(head==NULL){
        head=newnode;
        temp=newnode;
        continue;
    }
    temp->next=newnode;
    }
    return head;
}

void printlist(int n){
    struct node *newnode=head;
    for(int i=0;i<n;i++){
    cout<<newnode->NodeNumber<<newnode->NodeId<<" "<<newnode->ReferenceId<<" "<<newnode->ChildNodeId<<" "<<newnode->ReferenceChildNodeId<<endl;
    cout<<newnode->D1.owner_name<<" "<<newnode->D1.Add.HouseNo<<" "<<newnode->D1.Add.City<<" "<<newnode->D1.Add.PinCode<<endl;
    }
}

int main(){
    char ch;
    int choice;
do{
    int yes;
    cout<<"enter your preference:-"<<endl;
    cout<<"1-create first Node\n 2-display \n 3-encryption and decryption\n  \n 5-add a node to the list"<<endl;
    cout<<"6-option to break up any node\n 7-transfer owner of node 8-longest chain of main node 8-longest chain of sub node 9- merge two different set of node"<<endl;

    cin>>choice;
    switch(choice){
        case 0:{
            exit(0);
        }
        case 1:{
            cout<<"enter number of nodes to be created";
            cin>>n;
            createLinkedList(n);
            break;
        }
        case 2:{
            cout<<"display list"<<endl;
            printlist(n);
            break;
        }
        case 3:{
            cout<<"enter the node to be encrypt.Also node is starting from 0";
            int n;
            cin>>n;
            findnode(n);
            break;
        }

    }
    cout<<"do you want to continue.Yes or No"<<endl;

    cin>>ch;

}while(ch=='y');
}

