#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"keyboard.h"
#include"linklist.h"
#include"trie.h"
#include"file.h"

#define BACKSPACE 127

/* This program is to auto complete suggestion
 * like when you type any character
 * it will show all possible word which have the
 * same prefix
 */

/*
 * funtion which convert the charater to
 * its ascii value
 */

int char_to_int(char ch)
{
	return (int) ch;
}

/*
 * This function will return the next
 * node which pointes by the charater which 
 * is passed into the parameter
 * if such node not found than it will return 
 * null otherwise it will return the node pointer
 */

struct node* search_possible(struct node *root,char ch)
{
	if(root == NULL)
		return NULL;

	int index = char_to_int(ch);
	if(root->ptr[index] == NULL)
		return NULL;

	return root->ptr[index];
}

/*
 * main function which will init the auto complete
 * to the root trie structure
 */

void init_autocomplete(struct node *root)
{
char buff[50] = {'\0'};
d_list *hptr = get_list_node(root);
int index = 0;
char ch;
int ret = 0;

	printf("Enter string for auto-complete\n");

	while(1)
	{
		buff[index] = '\0';
		printf("%s",buff);
		while(!keypressed());		// Block until key is not pressed
		system("clear");		// Clear the command prompt
		ch = getchar();			// Get the entered character

		if(ch == BACKSPACE && index > 0)
		{
			hptr = remove_from_list(hptr);
			--index;
		}

		else if(ch != BACKSPACE)
		{
			buff[index++] = ch;
			buff[index] = '\0';

			root = search_possible(hptr->ptr,buff[index-1]);
			hptr = add_to_list(hptr,root);
			if(hptr == NULL || root == NULL)
				printf("No such word exist in file.\n");
		}
		
		if(hptr != NULL && index > 0)
			print_word(hptr->ptr,buff,index);		// Print all possible word with prefix match
	}
}

int main(int argc,char **argv)
{
struct node *root = NULL;

	if(argc < 2)
	{
		printf("Enter filename with commnad line argument.\n");
		return EXIT_FAILURE;
	}

	root = read_file(argv[1]);	// Read file passed in command line and insert word into trie

	if(root == NULL)
		return EXIT_FAILURE;

	init_autocomplete(root);

	return EXIT_SUCCESS;
}
