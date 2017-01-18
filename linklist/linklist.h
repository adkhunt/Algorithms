#ifndef linklist
#define linklist

#define null NULL

typedef struct node{
		int num;
		struct node *next;
}Node;

Node* get_new_node(int num)
{
	Node *ret = (Node*) malloc(sizeof(Node));

	ret->num = num;
	ret->next = NULL;

	return ret;
}

void addAtEnd(Node **hptr,int num)
{
static Node *pre = NULL;

	Node *new_node = get_new_node(num);

	if(*hptr)
	{
		pre->next = new_node;
		pre = new_node;
	}

	else
	{
		*hptr = new_node;
		pre = new_node;
	}
}

Node* get_list(void)
{
Node *root = null;
int num;
char ch;

	do{
		printf("Enter number to add into list.\n");
		scanf("%d",&num);
		addAtEnd(&root,num);
		printf("Do you want to continue?(y/Y)\n");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch == 'Y');

	return root;
}

void addAtFront(Node **hptr,int num)
{
	Node *new_node = get_new_node(num);

	new_node->next = (*hptr)->next;
	(*hptr) = new_node;
}

void addAtMiddle(Node **hptr,int num)
{
	Node *new_node = get_new_node(num);

	if((*hptr) == NULL || (*hptr)->num >= num)
	{
		new_node -> next = (*hptr);
		*hptr = new_node;
	}

	else
	{
		Node *cur = *hptr;

		while(cur != NULL)
		{
			if(cur->next == NULL || cur->next->num >= num)
			{
				new_node->next = cur->next;
				cur->next = new_node;
				break;
			}

			cur = cur->next;
		}	
	}
}

void print_list(Node *hptr)
{
	while(hptr)
	{
		printf("%d ",hptr->num);
		hptr = hptr->next;
	}

	printf("\n");
}

#endif
