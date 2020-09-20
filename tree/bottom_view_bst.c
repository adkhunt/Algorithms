#include<stdio.h>
#include"tree.h"

typedef struct pair{

   int left;
   int right;
   int total;
   int mid;
} pair;

void width_util(node *root, int cur_col, pair *ret){

   if (root == NULL)
      return ;

   width_util(root->left, cur_col - 1, ret);
   width_util(root->right, cur_col + 1, ret);

   if (cur_col < ret->left)
      ret->left = cur_col;

   if (cur_col > ret->right)
      ret->right = cur_col;
}

pair get_width(node *root){

   if (root == NULL){
      pair res = {.left = 0, .right = 0, .total = 0, .mid = 0};
      return res;
   }

   pair res = {.left = 0, .right = 0, .total = 0, .mid = 0};
   width_util(root, 0, &res);
   res.total = abs(res.left) + abs(res.right) + 1;
   res.mid = abs(res.left);

   return res;
}

void bottom_utils(node *root, int cur_col, node **res){

   if (root == NULL)
      return;

   res[cur_col] = root;
   bottom_utils(root->left, cur_col - 1, res);
   bottom_utils(root->right, cur_col + 1, res);
}

/* Print the bottom view of given binary tree.
   Complexity for this function is
   Time Complexity: O(n), where n is total nodes in tree.
   Space Complexity: O(w), Where w is width of tree.

   Logic: First get the width of given binary tree. We will keep
   entering the nodes in created hash of size width.
 */
void print_bottom_view(node *root){

   if (root == NULL)
      return;

   pair res = get_width(root);
   node **table = (node**) malloc(sizeof(node*) * res.total);
   int i;

   bottom_utils(root, res.mid, table);

   for (i = 0 ; i < res.total ; ++i)
      printf ("%d ",table[i]->num);

   printf ("\n");
}

int main(){

   node *root = get_new_node(20);
   root->left = get_new_node(8);
   root->left->left = get_new_node(5);
   root->left->right = get_new_node(3);
   root->left->right->left = get_new_node(10);
   root->right = get_new_node(22);
   root->right->left = get_new_node(4);
   root->right->left->right = get_new_node(14);
   root->right->right = get_new_node(25);
   print_bottom_view(root);
   return 0;
}
