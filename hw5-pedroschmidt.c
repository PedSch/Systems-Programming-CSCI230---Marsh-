/* pedro schmidt
hw5
csci230
10-10:50 mwf
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>


struct data
 {
      char *name;
      long number;

  };

   //opening the file stream and return an integer indicating how many lines there are.
int SCAN(FILE *(*stream))
 {
   char *list;
   int size = 0;

   size_t counter;


  if ((*stream = fopen("./hw5.data", "r")) == NULL) {
      printf("fail \n");
      exit(0);
   }
    while(1)
    {

      list = NULL;
      getline(&list, &counter, *stream);
      free(list);
      if (feof(*stream)) break;

      size++;
      }
 return size;
 }
 // rewind the file, create ther dynamic array (of size) and read in the data
 struct data *LOAD(FILE *stream, int size)
   {
      int o;
      size_t counter;
      char *list;
      char *name , *phone;
      struct data *BlackBox;

   if ((BlackBox = (struct data*)calloc(size, sizeof(struct data))) == NULL)
    {
      printf("failed.\n");
      exit(0);
   }
   rewind (stream);

   for (o = 0; o < size; o++)
    {
       list = NULL;
       getline(&list, &counter, stream);
       name  = strtok(list, " ");
       phone = strtok(NULL, "\n");

       if ((BlackBox[o].name = (char*)calloc(strlen(name)+1, sizeof(char))) == NULL)
        {
          printf("failed.\n");
          exit(0);
       }
       strcpy(BlackBox[o].name, name);
       BlackBox[o].number = atol(phone);
       free(list);
   }
   fclose(stream);
   return BlackBox;
}

 //get the dynamic array of the struct passed to it
void SEARCH(struct data *BlackBox, char *name, int size)
   {
   int look = 0;
   printf("*\n");
   for (int i = 0; i < size; i++)
      {
       if (!strcmp(name, BlackBox[i].name))
         {
          printf("The name was found at the %d entry.\n", i);
          look = 1;
          break;
         }
      }
   if (look == 0)
      {
      printf(" NOT found.\n");
      }
   printf("*\n");
}

   //free up all the dynamic memory allocated
void FREE(struct data *BlackBox, int size)
   {
      int i;
      for (i = 0; i < size; i++)
         {
            free(BlackBox[i].name);
          }
      free(BlackBox);
      BlackBox = NULL;
   }
int main(int argv, char **argc)// command line arguments in the main
 {
   int size;
   FILE *stream;
   struct data *BlackBox;

   if( argv ==1)
      {
         printf("include a name");
         }
        else
        if (argv == 2)
         {
       size = SCAN(&stream);
       BlackBox = LOAD(stream, size);
       SEARCH(BlackBox, argc[1], size);

   }
}
