/* Pedro Schmidt
   10-10:50
   CSCI 230

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




//first linked list
 struct node
 {
      char *word;
      struct node *next;
     
   };
   
typedef struct node poemList;
typedef struct codex codexList;


   //reading poem words
void read_poemwords (poemList *(*front) , poemList *(*back), char word[])
   {
    poemList *words;
   //makiing new list 
   words = (poemList *)malloc(sizeof(poemList));
   //allocating space
   words->word = (char *)calloc(sizeof(char), strlen(word)+1);
   
    if ((*front) == NULL)
     {	
       strcpy(words->word, word);
       words->next = NULL;   
       (*front)= words;
       (*back) = words;
       }
     else
     {
       strcpy(words->word, word);
       words->next = NULL;
       (*back)->next = words;
       (*back)= words;
      } 
  }
    //2nd linked list
struct codex
    {
      char *word1;
      char *word2;
      struct codex *next;
   };
  
   
 //reading codex words
 void read_codexwords (codexList *(*front), codexList *(*back), char word1[], char word2[])
   {
    codexList *words;
   //make new list 
    words = (codexList *)malloc(sizeof(codexList));
    //allocate space
    words->word1 = (char *)calloc(sizeof(char), strlen(word1)+1);
    words->word2 = (char *)calloc(sizeof(char), strlen(word2)+1);
 if((*front) == NULL) 
   {	
       strcpy(words->word1, word1);
       strcpy(words->word2, word2);
       words->next = NULL;   
       (*front) = words;
       (*back) = words;
      }
     else 
      {
       strcpy(words->word1, word1);
       strcpy(words->word2, word2);
       words->next = NULL;
       (*back)->next = words;
       (*back) = words;
    }
    
 }

// sort correct poem words
void Psorter(poemList *(*frontp), codexList *backc)
  {
    poemList *words, *last, *new;
    codexList *codex;
    words =(*frontp);
    last =(*frontp);
    int sort =1;
    
 while(words != NULL)
     {
     codex = backc;
      //codex linked list 
 while (codex != NULL)
  {
   if (!strcmp(words->word, codex->word1)) //testing 
   {	
   if (!strcmp(codex->word2, "skip"))  //test for skip
   {   	
   if (words == (*frontp))
   {		
    (*frontp) = words->next;
    last = (*frontp);
    free(words);			// checking
    words =(*frontp);
    sort = 0;
   }
   else 
     {
      last->next = words->next;
      free(words);			// checking?
      words = last;
      }
   } 
 else 
  {
  //Make a new linklist.
  new = (poemList *)malloc(sizeof(poemList));
  // Allocate space for the replacement word in the new link.
  new->word = (char *)calloc(sizeof(char), strlen(codex->word2)+1);
  strcpy(new->word, codex->word2);
  // Replace word in poem.
 if (words == (*frontp)) 
   {
    (*frontp) = new;
    last = (*frontp);
    new->next = words->next;
    free(words);			// Is this correct?
    words = (*frontp);
    sort = 0;
   } 
  else 
  {
   last->next = new;
   new->next = words->next;
   free(words);			// Is this correct?
   words = new;
    }
   }
   break;					// Skip to next word in poem.
  }
   codex = codex->next;
 } 
 if (sort == 1)
  {
   last = words;
   words = words->next; 
 }
 else 
  {
   sort = 1;
   }
  }
}

//printwords
void printP(poemList *frontp)
{
  poemList *words;
  words = frontp;
 while (words !=NULL)
 {
  if (!strcmp(words->word, ".")) 
   {
     printf("%s\n", words->word);
   } 
 else if (!strcmp(words->word, ",")) 
   {
     printf("%s\n", words->word);
   } 
  else
   {
     printf(" %s", words->word);
   }
    words = words->next;
  }
}
 
void freep(poemList *frontp)
{
   poemList *word, *last;
      word = frontp;
      last = frontp;
   while (word != NULL)
   {
      word = word-> next;
      free(last);
      last = word;
     }
    frontp = NULL;
}
void freec(codexList *frontc)
{
   codexList *word, *last;
      word = frontc;
      last = frontc;
   while (word != NULL)
   {
      word = word-> next;
      free(last);
      last = word;
     }
    frontc = NULL;
}

int main(void)
{
   char word1[50];
   char word2[50];
   FILE *HW8data;
  poemList *frontp, *backp;
  codexList *frontc, *backc;
  //poem
  frontp = NULL;
  backp = frontp;
 
  
    //WORDS OF FILE
    poemList *words;
    //OPENING FILE
    if(( HW8data = fopen("./HW8data.txt" , "r")) == NULL)
        {
         printf(" error can't read  the file \n ");
         return 0;
        }
  
 while(1)
 {
  fscanf(HW8data, "%s", word1);
  if (feof(HW8data))
  break;
  //test  
 if(word1[strlen(word1)-1] == '.')
   {
    word1[strlen(word1)-1] = '\0';
    read_poemwords(&frontp, &backp, word1);
    read_poemwords(&frontp, &backp, ".");
   }
  else if (word1[strlen(word1)-1] = ',')
  {
   word1[strlen(word1)-1] = '\0';
   read_poemwords(&frontp, &backp, word1);
   read_poemwords(&frontp, &backp, ",");
  }
  else
  {
    read_poemwords(&frontp,&backp, word1);      //insert words     
   }
 }
fclose(HW8data);
        
//codex linked list 
  frontc = NULL;
  backc = frontc; 

//read 
   if(( HW8data = fopen("./HW8codex.txt" , "r")) == NULL)
        {
         printf(" error can't read  the file \n ");
         return 0;
        }
  //read data file
 while(1)
  { 
   //scanning
  fscanf(HW8data, "%s %s" , word1, word2);
  if(feof(HW8data)) 
  break;
  read_codexwords(&frontc, &backc, word1, word2);//insert
 }

 fclose(HW8data);
 //replace words
  Psorter(&frontp, backc);
  //print words
  printP(frontp);
  //free linked lists
  freep(frontp);
  freec(frontc);  
       
   return 0; 
}
