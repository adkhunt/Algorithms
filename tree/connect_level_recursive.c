#include<stdio.h>
#include<stdlib.h>

#define SIZE 11   // Total nodes in binary tree.

typedef struct node{

   int data;
   struct node *left;
   struct node *right;
   struct node *next;
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
   printf ("Root = %p, Data = %d, Next = %p\n",root, root->data, root->next);
   print_tree(root->right);
}

void connect_recursive_util(node *root, int cur_level,
                            int level_to_explore, node **pre){
   if(root == NULL)
      return;

   connect_recursive_util(root->left, cur_level + 1, level_to_explore, pre);
   if(cur_level == level_to_explore){
      if(*pre)
         (*pre)->next = root;
      *pre = root;
   }
   connect_recursive_util(root->right, cur_level + 1, level_to_explore, pre);
}

int get_height(node *root){

   if(root == NULL)
      return 0;

   int lh = get_height(root->left) + 1;
   int rh = get_height(root->right) + 1;

   return lh > rh ? lh : rh;
}

/* Connect the binary tree's node at same level with next pointer.
   Total time complexity of this function is O(n*h). Where, n is total
   nodes in binary tree and h is height of binary tree.
   Idea behind this logic is we will keep track of current level's last
   visited node and when we are on current level we connect the last node 
   with root.
 */
void connect_level(node *root){

   if(root == NULL)
      return;

   int height = get_height(root);
   node *pre = NULL;
   int i;

   for (i = 0 ; i < height ; ++i){
      connect_recursive_util(root, 0, i, &pre);
      pre = NULL;
   }
}

int main(){

   node *root = NULL;
   int arr[SIZE] = {10, 6, 7, 4, 2, 18, 14, 15, 22, 21, 28};
   int i;

   for (i = 0 ; i < SIZE ; ++i)
      add_node(&root, arr[i]);

   print_tree(root);
   printf ("Connecting node in same level.\n");
   connect_level(root);
   print_tree(root);

   return 0;
}
