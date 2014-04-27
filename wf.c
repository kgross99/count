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

	printf("created temp node and word object from word: %s\n", checkword);
	tempNode = searchTable(table, (void *) word);
	printf("ran searchTable\n");
	if (tempNode != NULL) {
	  printf("found word: %s\n", checkword);
		WordObjPtr tempWord;
		tempWord = tempNode->obj;
		tempWord->frequency++;
		return;
	}
	word->frequency++;
	printf("did not find word adding: %s\n", word->word);
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

	printf("calling create table\n");
	htable = createTable(tablesize, (void *) hashcode, (void *) toString,
			(void *) freeWordObj, (void *) compareTo);
	printf("table created with table size %d\n", tablesize);

	int done = 0;
	
	while (!done) {
	  char * line = NULL;
	  chars_read = getline(&line, &maxlinelength, stdin);
	  printf("Read %d Characters\n",chars_read);
	  if (chars_read > 0) {
	    token = strtok(line, delimiters);
	    
	    while (token != NULL) {
	      CountWord(htable, token);

	      token = strtok(NULL, delimiters);
	      //if (token!=NULL){
	      //CountWord(htable, token);
		printf("tokenized\n");
	      //}
	    }
	  }
	  else if (chars_read < 0) {
	    done = 1;
	  }

	}
	printf("finished sample\n");
	printTable(htable);
	printf("ran printTable\n");
	freeTable(htable);
	printf("ran freetable\n");

	return 0;
}
