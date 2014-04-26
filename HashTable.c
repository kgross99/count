#include <stdio.h>
#include <stdlib.h>
#include <List.h>









HashTablePtr createTable(const int tableSize,
			 unsigned long int (*hashcode)(const void *),
			 char *(*toString)(const void * ),
			 void (*freeObject)(const void * ),
			 int (*compareTo)(const void *, const void * )){

HashTablePtr  hashTable =(HashTablePtr) malloc( sizeof(ListPtr));
hashTable->tableSize=tableSize;
hashTable->hashcode=hashcode;
hashTable->freeObject=freeObject;
hashTable->compareTo=compareTo;
hashTable->toString=toString;
hashTable->numElements=0;
int i;
for (i=0;i<tableSize;i++){
	hashTable->table[i]=malloc(sizeof(ListPtr));
}
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
	void * object=p;
	unsigned long int objecthash, tableslot;
	objecthash=checkTable->hashcode(p);
	tableslot=hashfunc(checkTable, objecthash);
	ListPtr hashlist=checkTable->table[tableslot];
	return search(hashlist,  object);

}

void insert(HashTablePtr table, const void * p){
	if (p==NULL) return;
	if (table==NULL) return;
	HashTablePtr checkTable=table;
	void * object=p;
	unsigned long int objecthash, tableslot;
	objecthash=checkTable->hashcode(p);
	tableslot=hashfunc(checkTable, objecthash);
	ListPtr hashlist=checkTable->table[tableslot];
	NodePtr tempnode=createNode(p);
	addAtFront(hashlist, tempnode);

}
void *delete(HashTablePtr table, const void * p){
	void * temp;
	NodePtr tempNode;
	if (p==NULL) return NULL;
		if (table==NULL) return NULL;
		HashTablePtr checkTable=table;
		void * object=p;
		unsigned long int objecthash, tableslot;
		objecthash=checkTable->hashcode(p);
		tableslot=hashfunc(checkTable, objecthash);
		ListPtr hashlist=checkTable->table[tableslot];
		tempNode=search(table, p);
		removeNode(hashlist, tempNode);
		return tempNode;

}

void freeTable(const HashTablePtr table){
	if (table==NULL)return;
	int i;
	for (i=0;i<table->tableSize;i++){
		table->table[i]=freeList(ListPtr);
	}
	free (table);
}

void printTable(const HashTablePtr table){
	HashTablePtr printTable=table;
	int i;
	for (i=0;i<table->tableSize;i++){
			table->table[i]=printList(ListPtr);

}
}

