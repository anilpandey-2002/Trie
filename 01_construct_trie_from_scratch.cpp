
#include <iostream>
using namespace std;

struct Trienode
{
    char data;
    int wc;
    Trienode *child[26];
};
Trienode nodepool[100000];
Trienode *root;
int poolcount;

void init()
{
    poolcount = 0;
    root = &nodepool[poolcount++];
    root->data = '/';
    for (register int i = 0; i < 26; ++i)
        root->child[i] = NULL;
}

Trienode *getNode(char c)
{
    Trienode *newnode = &nodepool[poolcount++];
    newnode->data = c;
    for (register int i = 0; i < 26; ++i)
        newnode->child[i] = NULL;
    newnode->wc = 0;
    return newnode;
}

void insert(char *s)
{
    Trienode *curr = root;
    int index;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        index = s[i] - 'a';
        if (curr->child[index] == NULL)
            curr->child[index] = getNode(s[i]);
        curr->child[index]->wc += 1;
        curr = curr->child[index];
    }
}

bool search(char *s)
{
    Trienode *curr = root;
    int index;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        index = s[i] - 'a';
        if (curr->child[index] == NULL || curr->child[index]->wc == 0)
            return false;
        curr = curr->child[index];
    }
    return true;
}

bool Triedelete(char *s)
{
    if (search(s))
    {
        Trienode *curr = root;
        int index;
        for (int i = 0; s[i] != '\0'; ++i)
        {
            index = s[i] - 'a';
            curr->child[index]->wc -= 1;
            curr = curr->child[index];
        }
    }
}

int countPrefix(string s)
{
    Trienode *curr = root;
    int index;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        index = s[i] - 'a';
        if (curr->child[index] == NULL || curr->child[index]->wc == 0)
            return 0;
        curr = curr->child[index];
    }
    return curr->wc;
}

int main()
{
    init();
    char a[5] = {'a', 'r', 'm', 'y'};
    char b[5] = {'a', 'r', 'm'};
    char c[5] = {'a', 'r', 'm', 's'};
    char d[5] = {'a', 'r', 'y'};
    char e[5] = {'a', 'm', 'y'};
    char f[5] = {'a', 'p', 'i'};

    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);

    printf("No of strings with given prefix = %d\n", countPrefix("a"));
    printf("No of strings with given prefix = %d\n", countPrefix("ar"));
    printf("No of strings with given prefix = %d\n", countPrefix("arm"));
    printf("No of strings with given prefix = %d\n", countPrefix("army"));
    printf("No of strings with given prefix = %d\n", countPrefix("armi"));
    printf("No of strings with given prefix = %d\n", countPrefix("ary"));

    cout << "Deletion...STARTED\n";
    Triedelete(a);
    Triedelete(d);
    cout << "DONE...\n\n";

    printf("No of strings with given prefix = %d\n", countPrefix("a"));
    printf("No of strings with given prefix = %d\n", countPrefix("ar"));
    printf("No of strings with given prefix = %d\n", countPrefix("arm"));
    printf("No of strings with given prefix = %d\n", countPrefix("army"));
    printf("No of strings with given prefix = %d\n", countPrefix("armi"));
    printf("No of strings with given prefix = %d\n", countPrefix("ary"));

    return 0;
}

/*
    alternative way
*/

class Node
{
public:
    char data;
    unordered_map<char, Node *> m;
    bool isTerminal;

    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
            {
                temp->m[ch] = new Node(ch);
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;

        for (char ch : word)
        {
            if (temp->m.count(ch) == 0)
                return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }

    // void delete(string word) {}
};

int main()
{
    string words[] = {"viren", "shiva", "tgvs", "new", "news"};

    Trie t;
    for (auto w : words)
    {
        t.insert(w);
    }

    int q;
    cin >> q;

    string search_word;
    while (q--)
    {
        cin >> search_word;
        if (t.search(search_word))
        {
            cout << "Yes, it is present" << endl;
        }
        else
            cout << "No, it is not present" << endl;
    }

    return 0;
}