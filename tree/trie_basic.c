#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define exit 0
#define null NULL

////////////////////////////////////////////////
//					      //
// Program to insertion and deletion in Trie- //
// Data structure			      //
//					      //
////////////////////////////////////////////////

typedef struct NODE{
			struct NODE *ch[26];
			bool eow;	//End Of Word
} node;

node* getNewNode(void)
{
	node *ret = (node*) malloc(sizeof(node));

int i;

	for(i = 0 ; i < 26 ; ++i)
		ret->ch[i] = null;

	ret->eow = false;

	return ret;
}

int charToInt(char ch)
{
	return (int) ch-97;
}

void insertWord(node *root,char *str)
{
int i;
int index;

	for(i = 0 ; str[i] ; ++i)
	{
		index = charToInt(str[i]);
		if(root->ch[index] == null)
			root->ch[index] = getNewNode();
		root = root->ch[index];
	}

	root->eow = true;
}

bool searchWord(node *root,char *str)
{
int i,index;

	for(i = 0 ; str[i] ; ++i)
	{
		index = charToInt(str[i]);
		if(root->ch[index] == null)
			return false;

		root = root->ch[index];
	}

	if(root->eow == true)
		return true;

	else 
		return false;
}


int main()
{
node *root = getNewNode();
int i;

	insertWord(root,"kash");
	insertWord(root,"programming");
	insertWord(root,"abcd");
	insertWord(root,"data");

	printf("%s\n",searchWord(root,"kash")?"Word is present":"Word is not present");
	printf("%s\n",searchWord(root,"code")?"Word is present":"Word is not present");
	printf("%s\n",searchWord(root,"abcd")?"Word is present":"Word is not present");
	printf("%s\n",searchWord(root,"data")?"Word is present":"Word is not present");
	printf("%s\n",searchWord(root,"aires")?"Word is present":"Word is not present");

	return exit;
}
