#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<climits>
using namespace std;
struct Tree
{
    struct Tree *left,*right;
    int key;
};
typedef struct Tree node;

struct Linklist
{
    int data;
    struct Linklist *next;
};
typedef struct Linklist link;

node* insertion(node *root,int data)
{
    if(!root)
    {
        root=(node*)malloc(sizeof(node));
        root->key=data;
        root->left=root->right=NULL;
        return root;
    }
    if(root->key>data)
    {
        root->left=insertion(root->left,data);
    }
    else
    {
        root->right=insertion(root->right,data);
    }
    return root;
}

void inorder(node* root)
{
    if(!root)
        return ;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
    return ;
}

node* finding(node* root,int data)
{
    if(!root)
        return NULL;
    if(root->key==data)
        return root;
    else if(root->key>data)
        return finding(root->left,data);
    else
        return finding(root->right,data);
}

node* minimum(node* root)
{
    if(!root)
        return NULL;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node* deletion(node* root,int data)
{
    if(!root)
    {
        printf("element not found\n");
    }
    else
    {
        if(root->key>data)
            root->left=deletion(root->left,data);
        else if(root->key<data)
            root->right=deletion(root->right,data);
        else
        {
        if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node *temp=root->left;
            free(root);
            return temp;
        }
        node *temp=minimum(root->right);
        root->key=temp->key;
        root->right=deletion(root->right,temp->key);
        }
    }
    return root;
}

node *lcs(node* root,node* a,node *b)
{
    if(!root)
        return NULL;
    while(1)
    {
            cout<<root->key<<endl;
        if((a->key<=root->key&&b->key>=root->key)||(a->key>=root->key&&b->key<=root->key))
            return root;
        if(a->key<root->key)
            root=root->left;
        else
            root=root->right;
    }
}

int checkbinary(node *root,int *prev)
{
    if(!root)
        return 1;
    if(checkbinary(root->left,prev)==0)
        return 0;
    if(root->key<*prev)
        return 0;
    *prev=root->key;
    return checkbinary(root->right,prev);
}

node* circulardll(node *root)
{
    if(!root->left&&!root->right)
        return root;
    if(root->left)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp=circulardll(root->left);
        while(temp->right)
            temp=temp->right;
        temp->right=root;
        root->left=temp;
    }
    if(root->right)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp=circulardll(root->right);
        while(temp->left)
            temp=temp->left;
        temp->left=root;
        root->right=temp;
    }
    return root;
}

void printcircular(node *root)
{
    while(root->left!=NULL)
        root=root->left;
    while(root!=NULL)
    {
        cout<<root->key<<" ";
        root=root->right;
    }
    return ;
}

node* dllbinary(link *&head,int start,int en)
{
    if(start>en)
        return NULL;
    int mid=start+(en-start)/2;
    node *root=(node*)malloc(sizeof(node));
    root->left=dllbinary(head,start,mid-1);
    root->key=head->data;
    head=head->next;
    root->right=dllbinary(head,mid+1,en);
    return root;
}

void rangek1k2(node* root,int k1,int k2)
{
    if(!root)
        return ;
    if(k1<=root->key&&k2>=root->key)
        cout<<root->key<<" ";
    if(root->key<=k2)
        rangek1k2(root->right,k1,k2);
    if(root->key>=k1)
        rangek1k2(root->left,k1,k2);
}

void rangeinorder(node *root,int k1,int k2)
{
    if(!root)
        return ;
    rangeinorder(root->left,k1,k2);
    if(root->key>=k1&&root->key<=k2)
        cout<<root->key<<" ";
    if(root->key>k2)
        return ;
    rangeinorder(root->right,k1,k2);
}

int uniquebst(int n)
{
    if(n<=1)
        return 1;
    int sum=0,left,right,i;
    for(i=1;i<=n;i++)
    {
        left=uniquebst(i-1);
        right=uniquebst(n-i);
        sum+=left*right;
    }
    return sum;
}

int floorbst(node *root,int f)
{
    if(!root)
        return -1;
    if(root->key==f)
        return root->key;
    if(root->key>f)
        return floorbst(root->left,f);
    int ans=floorbst(root->right,f);
    if(ans<=f&&ans!=-1)
        return ans;
    else
        return root->key;
}

int ceilbst(node* root,int c)
{
    if(!root)
        return -1;
    if(root->key==c)
        return c;
    if(root->key<c)
        return ceilbst(root->right,c);
    int ans=ceilbst(root->left,c);
    return ans>=c?ans:root->key;
}
int main()
{
    int n,i,val;
    cout<<"enter the number of nodes\n";
    cin>>n;
    node *root=NULL;
    node *temp;
    for(i=0;i<n;i++)
    {
        cin>>val;
        root=insertion(root,val);
    }
    cout<<"binary search tree is \n";
    inorder(root);


    /*cout<<"\nenter the element to be searched\n";
    cin>>val;
    temp=finding(root,val);
    if(!temp)
        cout<<"element not found\n";
    else
        cout<<"element found\n";

    cout<<"enter the element to be deleted\n";
    cin>>val;
    root=deletion(root,val);
    cout<<"after deletion \n";
    inorder(root);*/

    /*int l,r;
    cout<<"enter the range values\n";
    cin>>l>>r;
    node *a=finding(root,l);
    node *b=finding(root,r);
    if(!a||!b)
        cout<<"lcs bnot possible\n";
    else
    {
        node *ans=lcs(root,a,b);
        cout<<"lcs is "<<ans->key<<endl;
    }*/

   /* int *prev;
    prev=(int*)malloc(sizeof(int));
    *prev=0;
    if(checkbinary(root,prev))
        cout<<"binary tree confirmed\n";
    else
        cout<<"not a binary tree\n";*/


    /*cout<<"\nconverting to circular dll\n";
    node *croot=(node*)malloc(sizeof(node));
    croot=circulardll(root);
    printcircular(croot);*/

   /* cout<<"\nconverting binary dll to binary tree\n";
    link *parent,*current,*head;
    parent=(link*)malloc(sizeof(link));
    parent->data=1;
    head=parent;
    for(i=2;i<=6;i++)
    {
        current=(link*)malloc(sizeof(link));
        current->data=i;
        parent->next=current;
        current->next=NULL;
        parent=current;
    }
    node *droot=(node*)malloc(sizeof(node));
    droot=dllbinary(head,1,6);
    inorder(droot);*/

    /*cout<<"\nfinding number between two ranges\n";
    int k1,k2;
    cin>>k1>>k2;
    //rangek1k2(root,k1,k2);
    rangeinorder(root,k1,k2);*/


   // cout<<"unique bst are "<<uniquebst(n)<<endl;

   /*cout<<"\nenter the floor and ceil value\n";
   int f,c;
   cin>>f>>c;
   cout<<"floor value is "<<floorbst(root,f)<<" ceil value is "<<ceilbst(root,c)<<endl;*/

    return 0;
}
