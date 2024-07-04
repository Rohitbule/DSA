#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_TREE 1
#define DATA_NOT_FOUND 2
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
    private:
        node *root;
        void recPreorder(node *);
        void recInorder(node*);
        void recPostorder(node*);
        void inorderCopy(BST&,node*);
    public:
        BST();
        BST(BST&);
        BST& operator=(BST&);
        ~BST();

        bool isEmpty();
        void insert(int);
        void preorder();
        void inorder();
        void postorder();
        node * search(int);
        void del(int);
};
BST::BST()
{
    root=NULL;
}
void BST::inorderCopy(BST &b,node*ptr)
{
     if(ptr)
    {
        inorderCopy(b,ptr->left);
        b.insert(ptr->item);
        inorderCopy(b,ptr->right);
    }
}
BST::BST(BST &bst)
{
    root=NULL;
    if(bst.root)
    {
        bst.inorderCopy(*this,bst.root);
    }
    
}
BST& BST::operator=(BST &bst)
{
    while(root)
        del(root->item);
    bst.inorderCopy(*this,bst.root);
    return *this;
}
BST::~BST()
{
    while(root)
        del(root->item);
}
bool BST::isEmpty()
{
    return root==NULL;
}
void BST::insert(int data)
{
    
    node *ptr;
    
    if(root==NULL)
    {
        node *n=new node;
        n->left=NULL;
        n->item=data;
        n->right=NULL; 
        root=n;
    }
    else
    {
        bool flag=true;
        ptr=root;
        while(flag)
        {
            if(data==ptr->item)
                break;
            if(data<ptr->item) //left subtree
            {
                if(ptr->left==NULL)
                {
                    node *n=new node;
                    n->left=NULL;
                    n->item=data;
                    n->right=NULL;
                    ptr->left=n;
                    flag=false;
                }
                else
                    ptr=ptr->left;
            }
            else //right subtree
            {
                if(ptr->right==NULL)
                {
                    node *n=new node;
                    n->left=NULL;
                    n->item=data;
                    n->right=NULL;
                    ptr->right=n;
                    flag=false;
                }
                else
                    ptr=ptr->right;
            }
        }
    }

}
void BST::recPreorder(node *ptr)
{
    if(ptr)
    {
        cout<<ptr->item<<" ";
        recPreorder(ptr->left);
        recPreorder(ptr->right);
    }
}
void BST::preorder()
{
    recPreorder(root);
}
void BST::recInorder(node *ptr)
{
    if(ptr)
    {
        recInorder(ptr->left);
        cout<<ptr->item<<" ";
        recInorder(ptr->right);
    }
}
void BST::inorder()
{
    recInorder(root);
}
void BST::recPostorder(node *ptr)
{
    if(ptr)
    {
        recPostorder(ptr->left);
        recPostorder(ptr->right);
        cout<<ptr->item<<" ";
    }
}
void BST::postorder()
{
    recPostorder(root);
}
node* BST::search(int data)
{
    node *ptr=root;

    while(ptr)
    {
        if(ptr->item==data)
            return ptr;
        if(data< ptr->item)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    return NULL;
}
void BST::del(int data)
{
    node *ptr,*parptr;
    if(root==NULL)
    {
        throw EMPTY_TREE;
    }
    parptr=NULL;
    ptr=root;
    while(ptr)
    {
        if(ptr->item==data)
            break;
        if(data < ptr->item)
        {
            parptr=ptr;
            ptr=ptr->left;
        }
        else
        {
            parptr=ptr;
            ptr=ptr->right;
        }
    }
    if(ptr==NULL)
        throw DATA_NOT_FOUND;
    if(parptr==NULL && ptr!=NULL) //root node to be deleted
    {
        if(ptr->left==NULL && ptr->right==NULL) //no child
        {
            delete ptr;
            root=NULL;
        }
        else if(ptr->left && ptr->right) //two children
        {
            node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left !=NULL)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            //now delete successor
            
            if(suc == parsuc->left)
                parsuc->left=suc->right;
            else
                parsuc->right=suc->right;
            delete suc;
            

        }
        else //one child
        {
            if(ptr->left)
                root=ptr->left;
            else
                root=ptr->right;
            delete ptr;
        }
    }
    else //node to be deleted is not a root node
    {
        if(ptr->left==NULL && ptr->right==NULL) //no child
        {
            if(ptr==parptr->left) //ptr is left child of parptr
            {
                parptr->left=NULL;
                delete ptr;
            }
            else //ptr is right child of parptr
            {
                parptr->right=NULL;
                delete ptr;
            }
        }
        else if(ptr->left && ptr->right) //two children
        {
            node *suc,*parsuc;
            suc=ptr->right;
            parsuc=ptr;
            while(suc->left !=NULL)
            {
                parsuc=suc;
                suc=suc->left;
            }
            ptr->item=suc->item;
            //now delete successor
            
            if(suc == parsuc->left)
                parsuc->left=suc->right;
            else
                parsuc->right=suc->right;
            delete suc;
            
        }
        else
        {
            if(ptr==parptr->left) //ptr is left child of parptr
            {
                if(ptr->left)
                    parptr->left=ptr->left;
                else
                    parptr->left=ptr->right;
                delete ptr;
            }
            else //ptr is right child of parptr
            {
                if(ptr->left)
                    parptr->right=ptr->left;
                else
                    parptr->right=ptr->right;

                delete ptr;
            }
        }
    }


}
