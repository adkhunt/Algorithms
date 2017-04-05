#ifndef file
#define file

/*
 * This header file will open the file in read
 * mode and also scan the file word by word and
 * insert that word into the trie structure
 * after completing the insertion into file
 * it will return the struct node pointer which 
 * pointing to the whole trie structure
 */

struct node* read_file(char *file_name)
{
FILE *fp = NULL;
struct node *root = (struct node*)
			malloc(sizeof(struct node));
char str[50];

	fp = fopen(file_name,"r");

	if(fp == NULL)
	{
		printf("Error in opening file.\n");
		return NULL;
	}

	while(fscanf(fp,"%s",str) != EOF)
		insert_word(&root,str);

	return root;
}

#endif
