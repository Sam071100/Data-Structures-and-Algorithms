#include <iostream>

using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BST
{
private:
    Node *root;

public:
    BST() { root = nullptr; }
    Node *getRoot() { return root; }
    void iInsert(int key);
    void Inorder(Node *p);
    Node *iSearch(int key);
    Node *rInsert(Node *p, int key);
    Node *rSearch(Node *p, int key);
    Node *Delete(Node *p, int key);
    int Height(Node *p);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);
};

void BST::iInsert(int key)
{

    Node *t = root;
    Node *p;
    Node *r;

    // root is empty
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while (t != nullptr)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }

    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node *BST::iSearch(int key)
{
    Node *t = root;
    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return nullptr;
}

Node *BST::rInsert(Node *p, int key)
{
    Node *t;
    if (p == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }
    return p; // key == p->data?
}

Node *BST::rSearch(Node *p, int key)
{
    if (p == nullptr)
    {
        return nullptr;
    }

    if (key == p->data)
    {
        return p;
    }
    else if (key < p->data)
    {
        return rSearch(p->lchild, key);
    }
    else
    {
        return rSearch(p->rchild, key);
    }
}

Node *BST::Delete(Node *p, int key)
{
    Node *q;

    if (p == nullptr)
    {
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr)
    {
        if (p == root)
        {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int BST::Height(Node *p)
{
    int x;
    int y;
    if (p == nullptr)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node *BST::InPre(Node *p)  // Inorder Successor
{
    if(p && p->lchild != nullptr)
    {
        p = p->lchild;
    }
    while (p->rchild != nullptr)
    {
        p = p->rchild;
    }
    return p;
}

Node *BST::InSucc(Node *p) // Inorder Successor
{
    if(p && p->rchild != nullptr)
    {
        p = p->rchild;
    }
    while (p->lchild != nullptr)
    {
        p = p->lchild;
    }
    return p;
}

int main()
{

    BST bst;

    // Iterative insert
    bst.iInsert(30);
    bst.iInsert(20);
    bst.iInsert(40);
    bst.iInsert(10);
    bst.iInsert(25);
    bst.iInsert(35);
    bst.iInsert(45);
    bst.iInsert(42);
    bst.iInsert(43);

    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Iterative search
    Node *temp = bst.iSearch(2);
    if (temp != nullptr)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // Recursive search
    temp = bst.rSearch(bst.getRoot(), 20);
    if (temp != nullptr)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // Recursive insert
    bst.rInsert(bst.getRoot(), 50);
    bst.rInsert(bst.getRoot(), 70);
    bst.rInsert(bst.getRoot(), 1);
    bst.Inorder(bst.getRoot());
    cout << "\n"
         << endl;

    // Inorder predecessor and inorder successor
    BST bs;
    bs.iInsert(30);
    bs.iInsert(20);
    bs.iInsert(40);
    bs.iInsert(10);
    bs.iInsert(25);
    bs.iInsert(35);
    bs.iInsert(45);
    bs.iInsert(42);
    bs.iInsert(43);

    temp = bs.InPre(bs.getRoot());
    cout <<"Root: "<<bs.getRoot()->data<<endl;
    cout << "InPre: " << temp->data << endl;

    temp = bs.InSucc(bs.getRoot());
    cout << "InSucc: " << temp->data << endl;

    bs.Inorder(bs.getRoot());
    cout << endl;

    // Delete
    bs.Delete(bs.getRoot(), 7);
    bs.Inorder(bs.getRoot());

    return 0;
}