/* Pedro Schmidt

   CSCI 230

*/

#include <stdio.h>
#include <stdlib.h>

//making linked list 
typedef struct node
{
   int data;
   struct node *next;
} node_t;

 //allocating next node 
void push(node_t **head , int data2)
    {
        struct node* node_2 = (struct node*) malloc(sizeof(node_t));
        node_2->data = data2;
        node_2->next = (*head);
         *head = node_2;
     }
    
 //search function and printing 
struct node*searchList(int value, struct node*head)
  {
   struct node* current = head;
    while (current!=NULL){
    //printf("current->data: %d\n", current->data);
    if(current->data == value){
        return current;
    }
    current = current->next;
  }
  //printf("Value not found in the linkedlist\n");
  return current;
}

void printL(struct node* head){
  while(head){
    printf("%d\n", head->data);
    head = head->next;
  }
}
 
 void freeList(struct node* head)
{
   struct node* tmp;
   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
} 
//main
int main()
{
  node_t *head = NULL;
  head = malloc(sizeof(node_t));
    if (head == NULL)
   {
      return 1;
   }
   
  int search = 0;
  int count = 10;
  int i;
  for (i= 0; i < count; i--)
      {
         printf ("%d",count);
         head->next->data = 2;
         return 0;
      }
      
   printf("Linked List:\n");
   printL(head);
  //User input
  printf("Please Enter a Number:\n");
  scanf("%d", &search);
  struct node* searchNode = searchList(search, head);
  if (searchNode){
    printf("[%d %d]\n", search, searchList(search, head)->data);
  }
  else
    printf("value %d not found\n", search);
  //calling free function
  freeList(head);
 }

