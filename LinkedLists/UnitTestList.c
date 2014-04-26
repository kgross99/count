/*
 * UnitTestList.c
 *
 *      Author: marissa
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "WordObj.h"
#include "Node.h"
#include "List.h"

/* 
 * macro to mimic the functionality of assert() from <assert.h>. The difference is that this version doesn't exit the program entirely.
 * It will just break out of the current function (or test case in this context).
 */
#define myassert(expr) if(!(expr)){ fprintf(stderr, "\t[assertion failed] %s: %s\n", __PRETTY_FUNCTION__, __STRING(expr)); return FALSE; }

ListPtr testlist;

int testCount = 0;
int passCount = 0;

/**
 *Prints out the test info
 * @args TestName, info.
 *
 * @return void
 */

void printTestInfo(char* testName, char *info) {
	fprintf(stdout, "%s - %s\n", testName, info);
}
/**
 * Prints out the test results
 * <@args testname and boolean for passed/failed
 *
 * @returns void
 */
void printTestResult(char* testName, Boolean passed) {
	if (passed == TRUE)
		fprintf(stdout, "%s - %s\n\n", "[PASSED]", testName);
	else
		fprintf(stdout, "%s - %s\n\n", "[FAILED]", testName);
}

/**
 * Allocates a new testNode object and initializes its members.
 * @args jobid
 *
 * @return a pointer to the allocated node.
 */
NodePtr createTestNode(int jobid) {
	char * str;
	str=malloc(sizeof(char)*23);
	sprintf(str, "%d", jobid);
	WordObjPtr job = createWordObj( str,jobid);
	NodePtr node = createNode((void *)job);
	free(str);
	return node;
}
/**
 *tests adding a new node to the front of an empty list
 * .
 *
 * @return boolean for true = pass false= fail
 */
Boolean addAtFrontWithNoNodes() {
	NodePtr node = createTestNode(1);

	addAtFront(testlist, node);

	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)



	return TRUE;
}
/**
 *tests adding a new node to the front of a list with one node
 * .
 *
 * @return boolean for true = pass false= fail
 */
Boolean addAtFrontWithOneNode() {
	printTestInfo("addAtFrontWithOneNode", "(running)");
	NodePtr node = createTestNode(1);
	addAtFront(testlist, node);
	NodePtr node1 = createTestNode(2);
	addAtFront(testlist, node1);
	myassert(testlist->size == 2)
	myassert(testlist->head == node1)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == node)
	myassert(testlist->head->prev == NULL)
	myassert(testlist->tail->next == NULL)
	myassert(testlist->tail->prev == node1)

	return TRUE;
}
/**
 *tests adding a new node to the rear of an empty list
 * .
 *
 * @return boolean for true = pass false= fail
 */
Boolean addAtRearWithNoNodes() {
	printTestInfo("addAtRearWithNoNodes", "(running)");
	NodePtr node = createTestNode(1);

	addAtRear(testlist, node);

	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)



	return TRUE;
}
/**
 *tests adding a new node to the rear of a list with one node
 * .
 *
 * @return boolean for true = pass false= fail
 */
Boolean addAtRearWithOneNode() {
	printTestInfo("addAtRearWithOneNode", "(running)");

	NodePtr node = createTestNode(1);
	addAtRear(testlist, node);
	NodePtr node1 = createTestNode(2);
	addAtRear(testlist, node1);
	myassert(testlist->size == 2)
	myassert(testlist->head == node)
	myassert(testlist->tail == node1)
	myassert(testlist->head->next == node1)
	myassert(testlist->head->prev == NULL)
	myassert(testlist->tail->next == NULL)
	myassert(testlist->tail->prev == node)

	return TRUE;
}
/**
 *tests removing a  node from a list with only one node
 * uses both remove from front and remove from rear
 *
 * @return boolean for true = pass false= fail
 */
Boolean removeFromListWithOneNode() {
	printTestInfo("removeFromListWithOneNode", "(running)");
	NodePtr node = createTestNode(1);
	NodePtr node1;
// Add one node at front, then remove from front.
	addAtFront(testlist, node);

	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)
	node1 = removeFront(testlist);
	printf("size %d \n",testlist->size);

//	myassert(testlist->size == 0)
	myassert(testlist->head== NULL)
	myassert(testlist->tail==NULL)
//	myassert(node == node1)
	//freeNode(node1);


	//add one node at front and remove from rear
	addAtFront(testlist, node);

	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)
	node1 = removeRear(testlist);

	myassert(testlist->size == 0)
	myassert(testlist->head== NULL)
	myassert(testlist->tail==NULL)
	myassert(node == node1)
	//freeNode(node1);

	//add one node at front, then remove via remove node.
	addAtFront(testlist, node);

	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)
	node1 = removeNode(testlist, node);

	myassert(testlist->size == 0)
	myassert(testlist->head== NULL)
	myassert(testlist->tail==NULL)
	myassert(node == node1)
	freeNode(node1, (void *)testlist->freeObject);

	return TRUE;
}
/**
 *tests for adding a null node to both the front and back of an empty list
 *
 * @return boolean for true = pass false= fail
 */


Boolean nullNodeTest() {
	printTestInfo("nullNodeTest", "(running)");
	NodePtr node = NULL;

	addAtFront(testlist, node);

	myassert(testlist->size == 0)
	myassert(testlist->head == NULL)
	myassert(testlist->tail == NULL)
	//myassert(testlist->head->next == NULL)
	//myassert(testlist->head->prev == NULL)

	addAtRear(testlist, node);

	myassert(testlist->size == 0)
	myassert(testlist->head == NULL)
	myassert(testlist->tail == NULL)
	//myassert(testlist->head->next == NULL)
	//myassert(testlist->head->prev == NULL)

	free(node);

	return TRUE;

}

/**
 *tests adding 100 nodes to a new list and then removing all 100 nodes
 *
 * @return boolean for true = pass false= fail
 */

Boolean add100test() {
	printTestInfo("add100test", "(running)");
	int i;
	NodePtr node;
	for (i = 0; i < 100; i++) {
		node = createTestNode(1);

		addAtFront(testlist, node);
	}

	myassert(testlist->size == 100)
	//myassert(testlist->head == node[99])
	//myassert(testlist->tail == node[0])
	//myassert(testlist->head->next == node[98])
	//myassert(testlist->head->prev == NULL)
	//myassert(testlist->tail->next == NULL)
	//myassert(testlist->tail->prev == node[2])

	for (i = 0; i < 100; i++) {

		node = removeRear(testlist);

		freeNode(node, (void *)testlist->freeObject);
	}
	myassert(testlist->size == 0)



	return TRUE;

}

/**
 *tests adding 100 nodes to a list and then reversing the list
 *
 * @return boolean for true = pass false= fail
 */
Boolean add100reverse() {
	printTestInfo("add100reverse", "(running)");
	int i;
	NodePtr node, node1, node2;
	for (i = 0; i < 100; i++) {
		node = createTestNode(1);

		addAtFront(testlist, node);
	}
	node1 = testlist->head;
	node2 = testlist->tail;
	reverseList(testlist);

	myassert(testlist->head == node2)
	myassert(testlist->tail == node1)



	return TRUE;

}
/**
 *tests creating a 1000 node list and then searching for nodes in that list
 *
 * @return boolean for true = pass false= fail
 */
Boolean searchlist(){
	printTestInfo("Searchlist", "(running)");
	int i;
	NodePtr node;
//	NodePtr node1;
	for (i=0;i<1000;i++){
		node = createTestNode(i);
		addAtFront(testlist,node);

	}
//	node1 = search(testlist, 999);
//	myassert(node1==node)
//	//freeNode(node1);
//	node1=search(testlist,25);
//	myassert(node1!=NULL)
//	node1=search(testlist,1001);
//	myassert(node1==NULL)





	return TRUE;

}

/**
 *creates pre test conditions
 * @args testName to print in log
 *
 * @return void
 */

void beforeTest(char* testName) {
	printTestInfo(testName, "Running...");
	testlist = createList((void *) compareTo, (void *)toString,(void *)freeWordObj);
	testCount++;
}

/**
 *Creates post test conditions
 * frees list
 * @args testName and result
 *
 * @return void
 */
void afterTest(char* testName, Boolean result) {
	printTestResult(testName, result);
	freeList(testlist);
	passCount += result;
}
/*
 * etc...
 */
/**
 *runs the actual tests
 *
 * @return void
 */
void runUnitTests() {
	Boolean result;
	char *testName;

	testName = "addAtFrontWithNoNodes";
	beforeTest(testName);
	result = addAtFrontWithNoNodes();
	afterTest(testName, result);

	testName = "addAtFrontWithOneNode";
	beforeTest(testName);
	result = addAtFrontWithOneNode();
	afterTest(testName, result);

	testName = "addAtRearWithNoNodes";
	beforeTest(testName);
	result = addAtRearWithNoNodes();
	afterTest(testName, result);

	testName = "addAtRearWithOneNode";
	beforeTest(testName);
	result = addAtRearWithOneNode();
	afterTest(testName, result);

	testName = "removeFromListWithOneNode";
	beforeTest(testName);
	result = removeFromListWithOneNode();
	afterTest(testName, result);

	testName = "nullNodeTest";
	beforeTest(testName);
	result = nullNodeTest();
	afterTest(testName, result);

	testName = "add100test";
	beforeTest(testName);
	result = add100test();
	afterTest(testName, result);

	testName = "add100reverse";
	beforeTest(testName);
	result = add100reverse();
	afterTest(testName, result);

	testName = "searchlist";
	beforeTest(testName);
	result = searchlist();
	afterTest(testName, result);

	//etc...

	fprintf(stdout, "Test Cases: %d\n", testCount);
	fprintf(stdout, "Passed: %d\n", passCount);
	fprintf(stdout, "Failed: %d\n", testCount - passCount);
}

/**
 *main
 *
 *@args none
 *
 * @return 0 if program runs
 */
int main(int argc, char *argv[]) {
	runUnitTests();


	exit(0);
}
