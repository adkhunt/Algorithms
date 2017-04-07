#ifndef trie
#define trie

#include<stdlib.h>
#include<stdbool.h>
#define null NULL

/*
 * this header file hepls to construct the 
 * trie structure (Dictionary) to the program
 */

/*
 * This node struct will contain the count of word
 * occurance and also contain the end of word 
 * flag which will indicate if the word is end here
 * or not and contain other 230 self referential
 * structure pointer which store the character
 */

typedef struct node{
			struct node *ptr[26];
			bool eow;
			int count;
} node;

/*
 * This function will return the new node 
 * with some basic initialisation like initialize 
 * all 230 pointer with null and end of word(eow) flag
 * false
 */

node* get_new_node(void)
{
int i;

	node *temp = (node*) malloc(sizeof(node));
	
	for(i = 0 ; i < 26 ; ++i)
		temp->ptr[i] = null;

	temp->eow = false;
	temp->count = 0;

	return temp;
}

/*
 * This function will insert the new word into the 
 * existing trie structure
 */

void insert_word(node **head,char *str)
{
int i;
node *temp = *head;
int index;

	for(i = 0 ; str[i] ; ++i)
	{
		index = str[i] - 'a';

		if(temp->ptr[index] == null)
			temp->ptr[index] = get_new_node();

		temp = temp->ptr[index];
	}

	temp->eow = true;
	++(temp->count);
}

/*
 * Print the words contain this trie structure
 */

void print_word( node *root ,char *str,int level)
{
int i; 

	if(root == NULL)
		return;

	for( i = 0; i < 26 ; i++)
	{
		if( root->ptr[i] != NULL){
			str[level] = (char) i + 'a';
			print_word(root->ptr[i],str,level+1);
		}

	}
	
	if(root->eow == true)
	{
		str[level] = '\0';
		printf("%s -> %d\n",str,root->count);
	}
}

/* 
 * This function will search the word
 * if its present into the trie structure or 
 * not
 */

bool search_word(node *data,char *str)
{
int i;

	for(i = 0 ; str[i] ; ++i)
	{
		if(data->ptr[str[i] - 'a'] == null)
			return false;

		data = data->ptr[str[i]];
	}

	return true;
}

#endif
