#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "WordObj.h"
#include "HashTable.h"









HashTablePtr createTable(const int tableSize,
			 unsigned long int (*hashcode)(const void *),
			 char *(*toString)(const void * ),
			 void (*freeObject)(const void * ),
			 int (*compareTo)(const void *, const void * )){


	HashTablePtr hashTable= (HashTablePtr)malloc(sizeof(HashTablePtr));


	hashTable->tableSize=tableSize;
	hashTable->hashcode=hashcode;
	hashTable->freeObject=freeObject;
	hashTable->compareTo=compareTo;
	hashTable->toString=toString;
	hashTable->numElements=0;
	printf("set all struct values\n");
	hashTable->table=calloc(tableSize,sizeof(ListPtr));
	//int i;
	//for (i=0;i<tableSize;i++){
//	hashTable->table[i]=malloc(sizeof(ListPtr));
//}

return hashTable;


}


unsigned long int hashfunc(const HashTablePtr table, const unsigned long int hash){
	if (table==NULL) return 0
			;
return  hash % table->tableSize;
}

void *searchTable(const HashTablePtr ptr, const void * p){
	if (p==NULL) return NULL;
	if (ptr==NULL) return NULL;
	HashTablePtr checkTable=ptr;
//	void * object=p;
	unsigned long int objecthash, tableslot;
	objecthash=checkTable->hashcode(p);
	tableslot=hashfunc(checkTable, objecthash);
	ListPtr hashlist=checkTable->table[tableslot];
	return search(hashlist,  p);

}

void insert(HashTablePtr table, const void * p){
	if (p==NULL) return;
	if (table==NULL) return;
	HashTablePtr checkTable=table;

	unsigned long int objecthash, tableslot;
	objecthash=checkTable->hashcode(p);
	printf("hash %ul\n",tableslot);
	tableslot=hashfunc(checkTable, objecthash);
	printf("hash %ul\n",tableslot);
	ListPtr hashlist=checkTable->table[tableslot];
	NodePtr tempnode=createNode(p);
	printf("create node to add\n");
	addAtFront(hashlist, tempnode);
	printf("rand add at front");

}
void *delete(HashTablePtr table, const void * p){

	NodePtr tempNode;
	if (p==NULL) return NULL;
		if (table==NULL) return NULL;
		HashTablePtr checkTable=table;

		unsigned long int objecthash, tableslot;
		objecthash=checkTable->hashcode(p);
		tableslot=hashfunc(checkTable, objecthash);
		ListPtr hashlist=checkTable->table[tableslot];
		tempNode=search(hashlist, (void *)p);
		removeNode(hashlist, tempNode);
		return tempNode;

}

void freeTable(const HashTablePtr table){
	if (table==NULL)return;
	int i;
	for (i=0;i<table->tableSize;i++){
		freeList(table->table[i]);
	}
	free (table->table);
	free (table);
}

void printTable(const HashTablePtr table){

	int i;
	for (i=0;i<table->tableSize;i++){
		printf("trying to print list for slot %ul",i);
			printList(table->table[i]);

}
}

