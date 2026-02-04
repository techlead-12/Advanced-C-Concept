#include <iostream>
#include <queue>
using namespace std;

class BTreeNode {
public:
    int *key;
    BTreeNode **C;
    int n;
    int t;
    bool leaf;

    BTreeNode(int t, bool leaf) {
        this->t = t;
        this->leaf = leaf;

        key = new int[2*t - 1];
        C = new BTreeNode*[2*t];
        n = 0;
    }

    void traverse();
    BTreeNode* search(int k);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
};

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf)
            C[i]->traverse();
        cout << key[i] << " ";
    }
    if (!leaf)
        C[i]->traverse();
}

BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > key[i])
        i++;

    if (i < n && key[i] == k)
        return this;

    if (leaf)
        return NULL;

    return C[i]->search(k);
}

void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf) {
        while (i >= 0 && key[i] > k) {
            key[i + 1] = key[i];
            i--;
        }
        key[i + 1] = k;
        n++;
    } else {
        while (i >= 0 && key[i] > k)
            i--;

        if (C[i + 1]->n == 2*t - 1) {
            splitChild(i + 1, C[i + 1]);

            if (key[i + 1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->key[j] = y->key[j + t];

    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        C[j + 1] = C[j];

    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        key[j + 1] = key[j];

    key[i] = y->key[t - 1];
    n++;
}

class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int t) {
        root = NULL;
        this->t = t;
    }

    void insert(int k);
    void printTree();
};

void BTree::insert(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->key[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2*t - 1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->key[0] < k)
                i++;

            s->C[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

void BTree::printTree() {
    if (root == NULL) return;

    queue<BTreeNode*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        cout << "Level " << level << " : ";

        while (size--) {
            BTreeNode* node = q.front();
            q.pop();

            cout << "[ ";
            for (int i = 0; i < node->n; i++)
                cout << node->key[i] << " ";
            cout << "] ";

            if (!node->leaf) {
                for (int i = 0; i <= node->n; i++)
                    q.push(node->C[i]);
            }
        }
        cout << endl;
        level++;
    }
}

int main() {
    int order;
    cout << "Enter order (minimum degree) of B-Tree: ";
    cin >> order;

    BTree t(order);

    int n, value;
    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        t.insert(value);
    }

    cout << "\nB-Tree Level Order Traversal:\n";
    t.printTree();

    return 0;
}
