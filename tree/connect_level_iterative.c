#include<stdio.h>
#include<stdlib.h>
#define SIZE 11  // Size of binary search tree.

typedef struct node{
   int data;
   struct node *left;
   struct node *right;
   struct node *next;   // Arbitary pointer which points to sibling.
} node;

node* get_new_node(int num){

   node *new_node = (node*) malloc(sizeof(node));
   new_node->data = num;
   new_node->left = NULL;
   new_node->right = NULL;
   new_node->next = NULL;

   return new_node;
}

void add_node(node **root, int num){

   if(*root){
      node *cur = *root;
      node *pre = NULL;

      while(cur){
         pre = cur;
         if(cur->data > num)
            cur = cur->left;
         else
            cur = cur->right;
      }

      if (pre->data > num)
         pre->left = get_new_node(num);
      else
         pre->right = get_new_node(num);
   } else{
      *root = get_new_node(num);
   }
}

void print_tree(node *root){

   if(root == NULL)
      return;

   print_tree(root->left);
   // Below printf will show that link is connected.
   printf ("Root = %p, Data = %d, Next = %p\n",root, root->data, root->next);
   print_tree(root->right);
}

// Get the total height of binary tree.
int get_height(node *root){

   if (root == NULL)
      return 0;

   int lh = get_height(root->left) + 1;
   int rh = get_height(root->right) + 1;

   return lh > rh ? lh : rh;
}

void connect_nodes(node *root, node **hash, int cur_level){

   if (root == NULL)
      return ;

   connect_nodes(root->left, hash, cur_level + 1);
   if (hash[cur_level])
      hash[cur_level]->next = root;
   hash[cur_level] = root;
   connect_nodes(root->right, hash, cur_level + 1);
}

/* Connect the level binary tree in O(n) time and O(h) coplexity,
   where, h is height of binary tree and n is total nodes in binary tree.
   Idea of connecting nodes is keep the last visited node from given level
   and connect last visited node to root.
 */
void connect_level(node *root){

   if (root == NULL)
      return;

   int height = get_height(root);
   int i;
   node **hash = (node**)malloc(sizeof(node*)*height);
   for(i = 0 ; i < height ; ++i)
      hash[i] = NULL;

   connect_nodes(root, hash, 0);
}

int main(){

   node *root = NULL;
   int arr[SIZE] = {10, 6, 7, 4, 2, 18, 14, 15, 22, 21, 28};
   int i;

   for (i = 0 ; i < SIZE ; ++i)
      add_node(&root, arr[i]);

   print_tree(root);
   connect_level(root);
   printf ("After connecting nodes at same level.");
   print_tree(root);

   return 0;
}
