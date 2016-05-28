#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#define FILENAME "refrain"

using namespace std;

struct node {
    static int count;
    int leafs, depth, max_depth, id;
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

vector <int> suffix_array(vector <int> &s) {
    int n = s.size();
    vector<int> res(n), color(n), nc(n);
    vector <int> tmp(max(15, n), 0), c(max(15, n), 0), sorted(n, 0);
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

vector <int> lcp(vector <int> &a) {
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
    nod->leafs = 0;
    nod->max_depth = nod->depth;
    for (size_t i = 0; i < nod->childs.size(); i++) {
        prettify(nod->childs[i], n);
        if (nod->childs[i]->childs.size() == 1) {
            node* old = nod->childs[i];
            nod->childs[i] = nod->childs[i]->childs[0];
            node::count--;
            delete old;
        }
        nod->leafs += nod->childs[i]->leafs;
        nod->max_depth = max(nod->max_depth, nod->childs[i]->max_depth);
        nod->childs[i]->id = ++node::count;
    }
    if (nod->childs.size() == 0) {
        nod->leafs = 1;
    }
}

node* suffix_tree(vector <int> s) {
    s.push_back(0);
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

long long mx = 0, d = 0, r = 0;

void calc(node* node, int n) {
    int is_leaf = 0;
    if (node->childs.size() == 0) {
        is_leaf = 1;
    }
    if (mx < 1LL * node->leafs * (node->depth - is_leaf)) {
        mx = 1LL * node->leafs * (node->depth - is_leaf);
        d = node->depth - is_leaf;
        r = get_borders(node->parent, node, n).second - is_leaf;
    }
    for (int i = 0; i < node->childs.size(); i++) {
        calc(node->childs[i], n);
    }
}

void delete_node(node* node) {
    for (int i = 0; i < node->childs.size(); i++) {
        delete_node(node->childs[i]);
    }
    node->childs.clear();
    delete node;
}

int main() {
    freopen(FILENAME".in", "r", stdin);freopen(FILENAME".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]++;
    }
    s.push_back(1);
    node* root = suffix_tree(s);
    calc(root, n + 2);
    int l = r - d;
    cout << mx << '\n' << d << '\n';
    for (; l < r; l++) {
        cout << s[l] - 1 << ' ';
    }
    cout << '\n';
    delete_node(root);
}
