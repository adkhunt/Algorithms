#ifndef linklist
#define linklist

/*
 * This header file is mainly use to store
 * the pointer to the trie structure and make a
 * double linklist
 */

/*
 * Structure variable which contain pointer to 
 * tire structure and also contain two self
 * referencial structure
 */

typedef struct double_list{
			struct node *ptr;
			struct double_list *next;
			struct double_list *pre;
} d_list;

/*
 * This function will return the new node with 
 * basic initialisation to that node
 */

d_list* get_list_node(struct node *data)
{
	d_list *ret = (d_list*)
			malloc(sizeof(d_list));

	ret->ptr = data;
	ret->next = NULL;
	ret->pre = NULL;

	return ret;
}

/*
 * Add new node to the existing link list
 */

d_list* add_to_list(d_list *hptr,struct node *data)
{
	d_list *new_node = get_list_node(data);

	if(hptr != NULL)
	{
		hptr->next = new_node;
		new_node->pre = hptr;
		return;
	}

	return new_node;
}

/* 
 * This function will remove the last element
 * from the linklist
 */

d_list* remove_from_list(d_list *hptr)
{
	if(hptr == NULL)
		return NULL;

	d_list *ret = hptr->pre;
	free(hptr);
	return ret;
}

#endif
