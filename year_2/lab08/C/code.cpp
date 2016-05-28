#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define FILENAME "tree"

using namespace std;

struct node {
    static int count;
    int depth, max_depth, id;
    node* parent;
    vector <node*> childs;

    node(){}

    node(node* parent, int depth) : parent(parent), depth(depth), id(++count) {}

    ~node() {
        for (size_t i = 0; i < childs.size(); i++) {
            childs[i]->parent = parent;
        }
        parent = NULL;
        childs.clear();
    }
};

int node::count = 0;

vector <int> suffix_array(const string &s) {
    int n = s.size();
    vector<int> res(n), color(n), nc(n);
    vector <int> tmp(max(150, n), 0), c(max(150, n), 0), sorted(n, 0);
    for (int i = 0; i < n; i++) {
        color[i] = s[i];
        res[i] = i;
        c[color[i]]++;
    }
    for (int i = 1; i < tmp.size(); i++) {
        tmp[i] = tmp[i - 1] + c[i - 1];
    }
    for (int i = 0; i < n; i++) {
        res[tmp[color[i]]++] = i;
    }
    color[res[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (s[res[i - 1]] != s[res[i]]) {
            color[res[i]] = color[res[i - 1]] + 1;
        } else {
            color[res[i]] = color[res[i - 1]];
        }
    }
    for (int l = 1; l <= n; l *= 2) {
        fill(c.begin(), c.end(), 0);
        vector <int> by(n);
        for (int i = 0; i < n; i++) {
            by[i] = (res[i] + n - l) % n;
        }
        tmp[0] = 0;
        for (int i = 0; i < n; i++) {
            c[color[by[i]]]++;
        }
        for (int i = 1; i < n; i++) {
            tmp[i] = tmp[i - 1] + c[i - 1];
        }
        for (int i = 0; i < n; i++) {
            sorted[tmp[color[by[i]]]++] = by[i];
        }
        res = sorted;
        nc[res[0]] = 0;
        for (int i = 1; i < n; i++) {
            int l1 = res[i - 1];
            int l2 = (res[i - 1] + l) % n;
            int r1 = res[i];
            int r2 = (res[i] + l) % n;
            if (color[l1] != color[r1] || color[l2] != color[r2]) {
                nc[r1] = nc[l1] + 1;
            } else {
                nc[r1] = nc[l1];
            }
        }
        color = nc;
    }
    return res;
}

vector <int> lcp(string &a) {
    int n = a.size();
    vector <int> suf = suffix_array(a), pos(n), res(n);
    for (int i = 0; i < n; i++) {
        pos[suf[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        k = max(0, k - 1);
        if (pos[i] == n - 1) {
            res[n - 1] = -1;
            k = 0;
        } else {
            int j = suf[pos[i] + 1];
            while (max(i + k, j + k) < n && a[i + k] == a[j + k]) {
                k++;
            }
            res[pos[i]] = k;
        }
    }
    return res;
}

node* add_suffix(node* nod, int len, int lc) {
    if (nod->depth == 0 || nod->depth == lc) {
        node* new_node = new node(nod, len);
        nod->childs.push_back(new_node);
        return new_node;
    } else {
        if (nod->parent->depth < lc) {
            node* new_node = new node(nod->parent, lc);
            nod->parent->childs.pop_back();
            nod->parent->childs.push_back(new_node);
            new_node->childs.push_back(nod);
            nod->parent = new_node;
        }
        return add_suffix(nod->parent, len, lc);
    }
}

void prettify(node* nod, int n) {
    for (size_t i = 0; i < nod->childs.size(); i++) {
        prettify(nod->childs[i], n);
        if (nod->childs[i]->childs.size() == 1) {
            node* old = nod->childs[i];
            nod->childs[i] = nod->childs[i]->childs[0];
            node::count--;
            delete old;
        }
        nod->childs[i]->id = ++node::count;
    }
}

node* suffix_tree(string s) {
    s = s + "#";
    int n = s.size();
    vector <int> sa = suffix_array(s), lc = lcp(s);
    node* root = new node(NULL, 0);
    node* pr = root;
    for (int i = 1; i < n; i++) {
        pr = add_suffix(pr, n - sa[i] - 1, lc[i - 1]);
    }
    node::count = 1;
    prettify(root, n);
    return root;
}

void count_max_depth(node* node) {
    node->max_depth = node->depth;
    for (size_t i = 0; i < node->childs.size(); i++) {
        count_max_depth(node->childs[i]);
        node->max_depth = max(node->max_depth, node->childs[i]->max_depth);
    }
}

pair <int, int> get_borders(node* parent, node* child, int n) {
    int l = n - child->max_depth + parent->depth;
    return make_pair(l, l + child->depth - parent->depth - 1);
}

void print(node* node, int n) {
    for (size_t i = 0; i < node->childs.size(); i++) {
        cout << node->id << ' ' << node->childs[i]->id << ' ' << get_borders(node, node->childs[i], n).first << ' ' << get_borders(node, node->childs[i], n).second << '\n';
        print(node->childs[i], n);
    }
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    string s;
    cin >> s;
    node* root = suffix_tree(s);
    count_max_depth(root);
    cout << node::count << ' ' << node::count - 1 << '\n';
    print(root, s.size() + 1);
}
