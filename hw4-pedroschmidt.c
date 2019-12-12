/*
Pedro Schmidt
CSCI 230
HW4

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int function(char *c_array, int count)
{
    if((count % 30) < 1)
    {
     char *c_array2;//c_array for checking the size
    //adding one to the size of the vector
    c_array2 = (char*)malloc((sizeof(char)(count/30)*30);

    if(c_array2 == NULL) //checking for correct memory allocation
    {
      printf("Cannot allocate space for tempArray\n");
      printf("Exiting program\n");
      exit(0);
    }
    //copying values into a new array
    memcpy(c_array2, c_array, count);
    *c_array = *c_array2;
   }
   return *c_array;
   }


int main ()
{
   int count;//counter
   char *c_array3; //character array
   char character; // character
   int SizeCheck;

   c_array3 = (char*)malloc(sizeof(char)*30);// dynamically allocating character array

   if(c_array3 == NULL) //error checking
  {
    printf("Error allocating memory for str value\n");
    printf("exiting program\n");
    exit(0);
  }
   //ask user to enter characters
   printf("please enter a character:\n");//prompting user
   for(count = 0; character != '\n'; count++)
   {
      character = getchar(); // getting character
      printf("\n entered:\n");
      putchar(character);
      c_array3 = SizeCheck(c_array3 , count);
      c_array3(c_array3, &character , 1);
      c_array3[count+1] = '\0';
    // dynamically allocating character array

   for(int i=0; i < 30; i++) //access array brackets
      {
         c_array3[i] = 0;
      }
      c_array3 = function(c_array3, count);
    c_array3[count + 1] = '\0';
  }
   //inserted values
   char insert[count];
   c_array3(insert,c_array3);
   printf("Homework4 output: %s\n", insert);

   return 0;
}
