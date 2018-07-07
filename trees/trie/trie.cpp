#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int words;
    map<char, Node*> chi;
    Node() {
        words = 0;
    }
    Node(char ch) {
        words = 1;
        chi[ch] = new Node();
    }
};

class Trie {
    public:
    Node *root;
    Trie() {
        root = NULL;
    }
    void insert(string str) {
        int len = str.size();
        int i = 0;
        Node *temp = root;
        while(i != len) {
            if(root == NULL) {
                root = new Node(str[i]);
                temp = root->chi[str[i]];
                cout<<"Root created"<<temp->words<<endl;
            }
            else{ //when root present
                if(temp->chi.find(str[i]) != temp->chi.end()) { //child found
                    cout<<"child found"<<endl;
                    temp->words++;
                    temp = temp->chi[str[i]];
                }
                else { //not found, create child, move temp to child
                    cout<<"child not"<<endl;
                    temp->words++;
                    temp->chi[str[i]] = new Node();
                    temp = temp->chi[str[i]];
                }
            }
            i++;
        }
        cout<<"Done inserting"<<root->words<<endl;
    }

    int find(string str) {
        int i = 0, len = str.size();
        int found = 0;
        Node *temp = root;
        while(i != len) {
            if(temp->chi.find(str[i]) != temp->chi.end()) {
                found = temp->words;
                temp = temp->chi[str[i]];
            }
            else
                return 0;
            i++;
        }
        return found;
    }

};

int main() {
    Trie t;
    t.insert("kappa");
    t.insert("kapar");
    cout<<t.find("kap")<<endl;
    cout<<t.find("doggo")<<endl;
    return 0;
}