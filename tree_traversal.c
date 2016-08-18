#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

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
void postOrder(struct node* node){
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}
void inOrder(struct node* node){
    if (node == NULL)
        return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
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

int calculateSize(struct node* root){
int size, sizeLeft, sizeRight;
    if(root==NULL)
        return 0;
    sizeLeft = calculateSize(root->left);
    sizeRight = calculateSize(root->right);
    size = sizeLeft + sizeRight + 1;
    return size;
}

int findMax(struct node* root){
    int max_left, max_right, temp_max, final_max;
    if(root == NULL)
        return -1;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    max_left = findMax(root->left);
    max_right = findMax(root->right);
    temp_max = (max_left > max_right)?max_left:max_right;
    final_max = (root->data > temp_max)?root->data:temp_max;
    return final_max;

}

int main(){
    int height;
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(7);
    printf("\nPREORDER\n");
    preOrder(root);
    printf("\nPOSTORDER\n");
    postOrder(root);
    printf("\nINORDER\n");
    inOrder(root);
    height = calculateHeight(root);
    printf("\nThe height is: %d", height);
    printf("\nThe size is: %d", calculateSize(root));
    printf("\nThe max value is: %d", findMax(root));
    return 0;
}
