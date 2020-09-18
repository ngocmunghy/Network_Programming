typedef struct nodeType_t {
	char name[30];
	char pass[30];
	int status;
	int isSignIn;
} nodeType;

struct Node_t{
	nodeType node_t;
	struct Node_t *next; 
};

typedef struct Node_t *node;

//node head = NULL;

node createNode(char *name, char *pass) {
	node tmp;
	tmp = (node)malloc(sizeof(struct Node_t));
	strcpy(tmp->node_t.name,name);
	strcpy(tmp->node_t.pass,pass);
	tmp->node_t.status = 1;
	tmp->node_t.isSignIn = 0;
	tmp->next = NULL;
	return tmp;
}

node addTail(node head, char *name, char *pass) {
	node tmp = createNode(name,pass);
	node tmp1;
	if(head == NULL) {
		head = tmp;
	} else {
		tmp1 = head;
		while(tmp1->next != NULL) {
			tmp1 = tmp1->next;
		}	
		tmp1->next = tmp;
	}
	return head;
}

node findByName(node head, char *name) {
	node tmp = head;
	while(tmp != NULL) {
		if(strcmp(tmp->node_t.name, name) == 0) 
			break;
		tmp = tmp->next;
	}
	return tmp;
}

int numOfNodes(node head) {
	node tmp = head;
	int count = 0;
	while(tmp != NULL) {
		count++;
		tmp = tmp->next;
	}
	return count;
}

void freeList(node head) {
	node tmp;
	while(head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void printList(node head) {
	node tmp = head;
	while(tmp != NULL) {
		printf("%s\t %s\n",tmp->node_t.name, tmp->node_t.pass);
		tmp = tmp->next;
	}
	//printf("%s\t %s\n",tmp->node_t.name, tmp->node_t.pass);
} 