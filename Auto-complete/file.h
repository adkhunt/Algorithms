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

/*
 * This function will remove the special character 
 * from the word and insert into the trie structure
 */

void remove_special_chars(char *str,struct node **root)
{
char temp_buff[50];
int i,index = 0;

	for(i = 0 ; str[i] ; ++i)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			temp_buff[index++] = str[i];

		else if(str[i] >= 'A' && str[i] <= 'Z')
			temp_buff[index++] = str[i]+32;
	}

	temp_buff[index] = '\0';

	insert_word(root,temp_buff);
}

/*
 * Read the file which name is passed as a
 * function parameter and scan word by word 
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
		remove_special_chars(str,&root);

	return root;
}

#endif
