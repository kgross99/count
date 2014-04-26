#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "WordObj.h"
#include "Node.h"
#include "List.h"


int main(int argc, char **argv) {
	int i;
	int n;
	NodePtr node;
	WordObjPtr job;
	ListPtr list;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <list size> \n", argv[0]);
		exit(1);
	}
	n = atoi(argv[1]);

	list = createList((void *) compareTo, (void *)toString,(void *)freeWordObj);
	for (i = 0; i < n; i++) {
		char str[25];
				sprintf(str, "%d", i);
		job = createWordObj(str,1);
		node = createNode((void *)job);
		addAtFront(list, node);
	}
	job=createWordObj("hi",1);
	search(list, job);
	printf("searched\p");

	printList(list);


	reverseList(list);
	printList(list);

	reverseList(list);

	printList(list);


	freeList(list);

	exit(0);
}
