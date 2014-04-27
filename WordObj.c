#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "Node.h"
#include "WordObj.h"





WordObjPtr createWordObj(const char * word, const unsigned long int count){
WordObjPtr newWordObj = (WordObjPtr) malloc (sizeof(WordObjPtr));

newWordObj->word = (char *) malloc(sizeof(char)*(strlen(word)+1));
strcpy(newWordObj->word, word);
newWordObj->frequency = count;
return newWordObj;
}






unsigned long int hashcode(const void * g)
 {
	char * word;
	word =(char *)g;
unsigned long int hashval;
for (hashval = 0; *word !='\0'; word++)
hashval = *word + 31 * hashval;
return hashval;
 }




char * toString(const void * g){
WordObjPtr tempWordObj=(WordObjPtr) g;

char *temp;
temp=(char *)malloc(sizeof(char)*strlen(tempWordObj->word)+1+22);
sprintf(temp, "%s %lu",tempWordObj->word,tempWordObj->frequency);
return temp;



}


void freeWordObj(const void *g){
	WordObjPtr tempWordObj=(WordObjPtr)g;
	if (tempWordObj==NULL) return;
	free(tempWordObj->word);
	free(tempWordObj);
}





int compareTo(const void * g, const void * k){
WordObjPtr obj1=(WordObjPtr)g;
WordObjPtr obj2=(WordObjPtr)k;
return strcmp(obj1->word, obj2->word);
}
