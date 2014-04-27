
#ifndef __NODE_H
#define __NODE_H
/* C-examples/doublyLinkedLists/library/Node.h */
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
typedef struct node Node;
typedef struct node *NodePtr;
struct node {
	void *obj;
	NodePtr next;
	NodePtr prev;

};



NodePtr createNode( void *obj);

void freeNode(NodePtr node, void (*freeObject)(const void *));

#endif /* __NODE_H */
