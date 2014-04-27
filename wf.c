#include <stdio.h>
#include <stdlib.h>

#include "Node.h"
#include "WordObj.h"
#include "List.h"
#include "wf.h"
#include "HashTable.h"
#include "common.h"
int maxlinelength = 132;
int chars_read;
char *token;


const char* delimiters = " \t;{}()[].#<>\n\r+-/%*\"^'~&=!|:\\?,";
int tablesize;

NodePtr node;

void CountWord(HashTablePtr table, char * checkword);

void CountWord(HashTablePtr table, char * checkword) {
	NodePtr tempNode;
	WordObjPtr word = (WordObjPtr) malloc(sizeof(WordObjPtr));
	word = createWordObj(checkword, 0);

	tempNode = searchTable(table, (void *) word);

	if (tempNode != NULL) {

		WordObjPtr tempWord;
		tempWord = tempNode->obj;
		tempWord->frequency++;
		return;
	}
	word->frequency++;

	insert(table, (void *) word);

	return;
}

int main(int argc, char *argv[]) {

  	HashTablePtr htable;

	if (argc < 2) {
		printf("Usage wf int  size of hashtable\n");
		return 1;
	}
	tablesize = atoi(argv[1]);


	htable = createTable(tablesize, (void *) hashcode, (void *) toString,
			(void *) freeWordObj, (void *) compareTo);


	int done = 0;
	
	while (!done) {
	  char * line = NULL;
	  chars_read = getline(&line, &maxlinelength, stdin);

	  if (chars_read > 0) {
	    token = strtok(line, delimiters);
	    
	    while (token != NULL) {
	      CountWord(htable, token);

	      token = strtok(NULL, delimiters);




	    }
	  }
	  else if (chars_read < 0) {
	    done = 1;
	  }

	}

	printTable(htable);

	freeTable(htable);


	return 0;
}
