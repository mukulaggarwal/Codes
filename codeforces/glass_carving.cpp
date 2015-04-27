#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
typedef pair< pair<int,int> , pair<int,int> > pairs;

struct Node
{
    pairs data;
    struct Node *left,*right;
};
typedef struct Node node;

node* build(node *root,char type,int val)
{
    if(type=='H')
    {
        if(root->data.second.first<=val&&root->data.second.second>=val)
        {
            if(root->left==NULL)
            {
                root->left=(node*)malloc(sizeof(node));
                root->left->data.first.first=root->data.first.first;
                root->left->data.first.second=root->data.first.second;
                root->left->data.second.first=root->data.second.first;
                root->left->data.second.second=val;
                root->left->left=NULL;
                root->left->right=NULL;

                root->right=(node*)malloc(sizeof(node));
                root->right->data.first.first=root->data.first.first;
                root->right->data.first.second=root->data.first.second;
                root->right->data.second.first=val;
                root->right->data.second.second=root->data.second.second;
                root->right->left=NULL;
                root->right->right=NULL;
                return root;
            }
            else
            {
                root->left=build(root->left,type,val);
                root->right=build(root->right,type,val);
                return root;
            }
        }
        return root;
    }
    else
    {
         if(root->data.first.first<=val&&root->data.first.second>=val)
        {
            if(root->left==NULL)
            {
                root->left=(node*)malloc(sizeof(node));
                root->left->data.first.first=root->data.first.first;
                root->left->data.first.second=val;
                root->left->data.second.first=root->data.second.first;
                root->left->data.second.second=root->data.second.second;
                root->left->left=NULL;
                root->left->right=NULL;

                root->right=(node*)malloc(sizeof(node));
                root->right->data.first.first=val;
                root->right->data.first.second=root->data.first.second;
                root->right->data.second.first=root->data.second.first;
                root->right->data.second.second=root->data.second.second;
                root->right->left=NULL;
                root->right->right=NULL;
                return root;
            }
            else
            {
                root->left=build(root->left,type,val);
                root->right=build(root->right,type,val);
                return root;
            }
        }
        return root;
    }
}

int maximum(node *root)
{
    if(root==NULL)
        return 1;
    if(root->left!=NULL&&root->right!=NULL)
    {
        return max(maximum(root->left),maximum(root->right));
    }
    else
        return ((root->data.first.second)-(root->data.first.first))*((root->data.second.second)-root->data.second.first);
}
int main()
{
    int n,h,w,i,val;
    char type;
    cin>>w>>h>>n;
    node *root;
    root=(node*)malloc(sizeof(node));
    root->data.first.first=0;
    root->data.first.second=w;
    root->data.second.first=0;
    root->data.second.second=h;
    root->left=NULL;
    root->right=NULL;
    for(i=0;i<n;i++)
    {
        getchar();
        scanf("%c",&type);
        scanf("%d",&val);
        root=build(root,type,val);
        cout<<maximum(root)<<endl;
    }
    return 0;
}
