#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void printLevel(struct node*, int);

struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void preOrder(struct node* node){
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
int calculateHeight(struct node* root){
    int lh,rh,maxHt;
    if(root == NULL)
        return 0;
    lh = calculateHeight(root->left);
    rh = calculateHeight(root->right);
    maxHt = (lh > rh)?lh:rh;
    return (maxHt + 1);
}

void LevelOrder(struct node* root){
    int i;
    int height = calculateHeight(root);
    for(i=1;i<=height;++i){
        printLevel(root,i);
        printf("\n");
    }
}

void printLevel(struct node* root, int level){
    if(root==NULL){
        return;
    }
    if(level==1){
        printf("%d ",root->data);
        return;
    }
    else if(level > 1){
    printLevel(root->left, level-1);

    printLevel(root->right, level-1);

    }
}

int main(){
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(7);
    printf("\nPREORDER\n");
    preOrder(root);
    printf("\nPrinting Last Level\n");
    printLevel(root, 3);
    printf("\nPrinting All Levels\n");
    LevelOrder(root);
    return 0;
}

