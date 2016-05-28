#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define FILENAME "trie"

struct node{
    int v, parent;
    node* childs[26];
    node() {
        for (int i = 0; i < 26; i++) {
            childs[i] = NULL;
        }
    }

    node(int v, int parent) : v(v), parent(parent){
        for (int i = 0; i < 26; i++) {
            childs[i] = NULL;
        }
    }
};

void print(node* root) {
    for (char c = 'a'; c <= 'z'; c++) {
        if (root->childs[c - 'a'] != NULL) {
            cout << root->v << ' ' << root->childs[c - 'a']->v << ' ' << c << '\n';
            print(root->childs[c - 'a']);
        }
    }
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    string s;
    cin >> s;
    node root(1, -1);
    int n = 1;
    cerr << n << '\n';
    for (size_t i = 0; i < s.size(); i++) {
        node* tmp = &root;
        for (size_t j = i; j < s.size(); j++) {
            cerr << i << ' ' << j << '\n';
            if (tmp->childs[s[j] - 'a'] == NULL) {
                tmp->childs[s[j] - 'a'] = new node(++n, tmp->v);
            }
            tmp = tmp->childs[s[j] - 'a'];
        }
    }
    cerr << "done\n";
    cout << n << ' ' << n - 1 << '\n';
    print(&root);
}
