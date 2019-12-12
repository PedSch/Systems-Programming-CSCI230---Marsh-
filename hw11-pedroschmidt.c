/* Pedro Schmidt
    hw-11
    10-10:50
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//each node max of 10
//record number of nodes in each node
//double linear search to find nodes
//head pointer have 2 nodes
//randomly traverse forward
//function rand
//array of pointers
//2 column of arrays


// adjacent node
struct adjlistnode
{
    char destination[100];
    int array;
    struct adjlistnode *next;
};

//adjacent list
struct Adjlist
{
    char location[100];
    struct Adjlist *next;
    struct adjlistnode *head;
    int connections;
};


struct adjlistnode* new_adjlistnode(int array)
{
    struct adjlistnode* new_node = (struct adjlistnode*)malloc(sizeof(struct adjlistnode));
    new_node->array = array;
    new_node->next = NULL;
    return new_node;
};


typedef struct Adjlist list;
typedef struct adjlistnode *adjNode;

// declaring all functions
void addEdge(list **head, adjNode *tempNode, char *token1, char *token2, int token3);
void printList(list *(*head));
adjNode *traverse(char *start, list *(*head));
list *newStart(char *start, list **head);
int counter(adjNode *current);
int randomNum(int count);
adjNode *nextNode(adjNode *(*newHead), int count);

int overall = 0;
int seed = 0;

 void file_gen()
 {
   size_t size;
  time_t t = time(NULL);
  srand((unsigned) time(&t));
  int index = 0;
  int *rand_int = (int*) calloc (1, sizeof(int));
  FILE *p_file = fopen("./hw11.data", "r");//new file
  p_file = fopen("./hw11.data", "w");

  if (!p_file)
    {
    printf("!p_file\n");
    exit(1);
  }
 for (index = 0; index < size; index++)
    {
    *rand_int = rand();// % (20000 - 1) + 1;
    fprintf(p_file, "%d\n", *rand_int);
  }
  free(rand_int);
  fclose(p_file);
}



//defines all the functions
int main(void)
{
    file_gen();
    size_t n = 0;
    char *line = NULL;
    char *token;
    char *token1;
    char *token2;
    char *start;
    int  token3;
    list *lhead = NULL;
    list *tail = NULL;
    list *current = NULL;
    adjNode *aHead;
    adjNode *aTail;
    adjNode *tempNode;
    adjNode *aEnd;

 FILE *p_file = fopen("hw11.data", "r");//new file
 if(p_file == NULL)
   {
    printf("error");
    exit(0);
   }
 while(1)
  {
    getline(&line, &n, p_file);
    token = strtok(line , "\n");
    if(strcmp(token, "STOP") == 0)
     {
      break;
     }
   else
   {
    current = (list*)malloc(sizeof(list));
    aHead = (adjNode*)malloc(sizeof((adjNode*) 10));
    if(lhead == NULL)
     {
       strcpy(current->location, token);
       current->next = NULL;
       current->head = aHead;
       current->connections = 0;
       strcpy(aHead->destination, token);
       aHead->next = NULL;
       lhead = current;
       tail = current;
    }
  else
   {
     strcpy(current->location, token);
     current->next = NULL;
     current->head = aHead;
     current->connections = 0;
     strcpy(aHead->destination, token);
     aHead->next = NULL;
     tail->next = current;
     tail = current;
    }
  }
}
while(1)
 {
   getline(&line, &n, p_file);
   if(strcmp(line, "STOP STOP 0\n") == 0) break;
   token1 = strtok(line, " " );
   token2 = strtok(NULL, " " );
   token3 = atoi(strtok(NULL, "\n" ));
   tempNode = (adjNode*)malloc(sizeof(adjNode));
   addEdge(&lhead, tempNode, token1, token2, token3);
  }
  getline(&line, &n, p_file);
  start = strtok(line, "\n ");
  printList(&lhead);
  aEnd = traverse(start, &lhead);
  printf("start location: %s\n", start);
  printf("ending location: %s\n", aEnd->destination);
  printf("Total cost: %d\n" , overall);
  fclose(p_file);
  line = NULL;
  return 0;
}
void addEdge(list **head, adjNode *tempNode, char *token1,char *token2, int token3)
 {
  list *current = *head;
  adjNode *aCurrent = NULL;
  adjNode *aTail = NULL;
 while (current)
  {
   if(strcmp(token1, current->head->destination) == 0)
     {
     aCurrent = current->head;
   if(aCurrent->next == NULL)
     {
     current->connections++;
   if(current->connections > 10)
     {
      printf("max amount");
      exit(0);
     }
     aCurrent->next = tempNode;
     strcpy(tempNode->destination, token2);
     tempNode->array = token3;
     tempNode->next = NULL;
     aTail = tempNode;
     break;
    }
   else
    {
    current->connections++;
    if(current->connections >10)
     {
      printf("max amount ");
      exit(0);
     }
     while(1)
     {
      aTail = aCurrent;
     while(1)
     {
     if(aTail->next !=NULL)
     {
      aTail = aTail->next;
     }
     else
    {
     break;
     }
  }
  if(strcmp(aCurrent->destination, token1) == 0)
    {
     strcpy(tempNode->destination, token2);
     tempNode->array = token3;
     tempNode->next = NULL;
     aTail->next = tempNode;
     aTail = tempNode;
    break;
    }
   else
   {
     current = current->next;
     aCurrent = current->head;
    }
   }
  break;
  }
 }
 else
 {
    current = current->next;
  }
 }
}
     // represents the graph and prints adjacent list
void printList(list *(*head))
{
    list *current;
    current = *head;
    adjNode *pCrawl;
 while(pCrawl)
    {
  if(current->head !=NULL)
    {
      pCrawl = current->head->next;
      printf("location: %s \n", pCrawl->destination);
  while(pCrawl)
   {  
      printf("%s \n", pCrawl->destination);
      pCrawl = pCrawl->next;
    }
  if(strcmp(current->location, "home") == 0);
    {
      printf("\n %s connection = %d\n" , current-> location, current->connections);
    }
     pCrawl = pCrawl->next;
   }
 }
adjNode *traverse(char *start, list *(*head))
{
    int connect = 0;
    list *current = head;
    adjNode *adjCurrent;
    adjCurrent = NULL;
    current = newStart( start, head);
    connect = counter(current->Head);
  if (connect == 0 )
    {
        printf("location \n");
    }
}
list *newStart(char *start, list **head)
{
    list *current;
    adjNode *aCurrent = NULL;
    current = *head;
    while(1)
    {
        if(strcmp(start, current->location)==0)
        {
            return current;
        }
    else
    {
        current = current->next;
        if(current == NULL)
        {
            printf("no location found");
            exit(0);
            }
        }
    }
}
int counter(adjNode *current)
{
    int c = 0;
    while(1)
    {
    current = current->next;
    if(current == NULL)
    return c;
    else c++;
    }
}
 struct adjlistnode* new_adjlistnode(int destination)
{
    struct adjlistnode* new_node = (struct adjlistnode*)malloc(sizeof(struct adjlistnode));
    new_node->destination = destination;
    new_node->next = NULL;
    return new_node;
}
int randomNum(int count)
{
    int num;
    seed += time(0);
    srand(seed);
    num = rand() % count;
    return num;
  }

