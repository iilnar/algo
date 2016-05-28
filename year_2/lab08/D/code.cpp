#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

#define FILENAME "automaton"

struct node {
    map<char, int> next;
    int len;
    int link;
    bool terminal;

    node() {}

    node(int len, int link, bool terminal) : len(len), link(link), terminal(terminal) {
    }

    node (node const& other) : next(other.next), len(other.len), link(other.link), terminal(false) {
    }
};

int main(int charc, char** charv) {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    string s;
    vector <node> automaton;
    int last = 0;
    cin >> s;
    node tmp(0, -1, true);
    automaton.push_back(tmp);
    for (size_t i = 0; i < s.size(); i++) {
        size_t current_length = automaton.size();
        node current_node(automaton[last].len + 1, 0, false);
        int j = last;
        // cerr << i << '\n';
        while (j != -1 && automaton[j].next.find(s[i]) == automaton[j].next.end()) {
            automaton[j].next[s[i]] = current_length;
            j = automaton[j].link;
        }
        if (j == -1) {
            automaton.push_back(current_node);
            last = current_length;
            continue;
        }
        // cerr << i << '\n';
        int next = automaton[j].next[s[i]];
        // cerr << "next: " << next << '\n';
        // cerr << "j: " << j << '\n';
        // cerr << automaton[j].len + 1 << ' ' << automaton[next].len << '\n';
        if (automaton[j].len + 1 == automaton[next].len) {
            current_node.link = next;
            automaton.push_back(current_node);
            last = current_length;
            continue;
        }
        // cerr << i << '\n';
        size_t new_node_id = automaton.size() + 1;
        node new_node(automaton[next]);
        new_node.len = automaton[j].len + 1;
        while (j != -1 && automaton[j].next[s[i]] == next) {
            automaton[j].next[s[i]] = new_node_id;
            j = automaton[j].link;
        }
        automaton[next].link = new_node_id;
        current_node.link = new_node_id;
        automaton.push_back(current_node);
        automaton.push_back(new_node);
        last = current_length;
    }
    // for (int i = 0; i < automaton.size(); i++) {
    //     cerr << i << ' ' << automaton[i].len << ' ' << automaton[i].link << '\n';
    //     for (auto it : automaton[i].next) {
    //         cerr << ' ' << it.first << ' ' << it.second << '\n';
    //     }
    //     cerr << '\n';
    // }
    int j = last;
    vector <int> terminal;
    while (j != -1) {
        automaton[j].terminal = true;
        j = automaton[j].link;
    }
    for (size_t i = 0; i < automaton.size(); i++) {
        if (automaton[i].terminal) {
            terminal.push_back(i + 1);
        }
    }
    size_t ans = 0;
    for (auto note : automaton) {
        ans += note.next.size();
    }
    cout << automaton.size() << ' ' << ans << '\n';
    for (size_t i = 0; i < automaton.size(); i++) {
        for (auto vert : automaton[i].next) {
            cout << i + 1 << ' ' << vert.second + 1 << ' ' << vert.first << '\n';
        }
    }
    cout << terminal.size() << '\n';
    for (size_t i = 0; i < terminal.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << terminal[i];
    }
    cout << '\n';

}
