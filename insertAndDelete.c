#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* createNode(int data){
node * newNode= (node*)malloc(sizeof(node));
newNode->data=data;
newNode->left = newNode->right = NULL;
return newNode;
}

node* insertNode(node* root, int data)
{
    if(root==NULL)
    {
        root = createNode(data);
    }
    if(root->data > data)
    {
        root->left=insertNode(root->left,data);
    }
    else if(root->data < data)
    {
        root->right=insertNode(root->right,data);
    }
    return root;
}

node* minValue(node* root)
{
    node* head = root;
    while(head && head->left!= NULL )
    {
        head=head->left;
        
    }
    return head;
}

node* deleteNode(node* root, int data)
{
    if(root== NULL){
        return root;
    }
    
    if(root->data == data)
    {
        // 0 child
        if(root->left==NULL && root->right == NULL)
        { 
            free(root);
            return NULL;
        }

        // 1 child
        //left
        if(root->left!=NULL && root->right == NULL) 
        {
            node* temp= root->left;
            free(root);
            return temp;

        }
        // right
            if(root->left==NULL && root->right != NULL) 
        {
            node* temp= root->right;
            free(root);
            return temp;

        }

        // 2 child
        if(root->left != NULL && root->right != NULL)
            {
                int mini= minValue(root->right)->data;
                root->data=mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
    
}
else if (data >root->data)
    {
        root->right=deleteNode(root->right,data);
    }

    else if (data < root->data)
    {
        root->left=deleteNode(root->left,data);
    }
return root;
}
void inorderTraversal(node* root){
    node* head= root;
    if(head!= NULL)
    {
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    node * root = NULL;
    root = insertNode(root,50);
    root = insertNode(root,30);
    root = insertNode(root,20);
    root = insertNode(root,40);
    root = insertNode(root,70);
    root = insertNode(root,60);
    root = insertNode(root,80);

printf("Inorder traversal : ");
inorderTraversal(root);
deleteNode(root,60);
printf("After deleting 60 : ");
inorderTraversal(root);
    return 0;
}