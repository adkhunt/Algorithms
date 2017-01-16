#ifndef insert
#define insert

struct node* insertTree(void)
{
struct node *root = null;
char ch;

	do{
		insertInTree(&root);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	return root;
}


#endif
