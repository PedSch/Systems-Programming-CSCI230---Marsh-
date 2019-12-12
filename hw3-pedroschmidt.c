/*
Pedro Schmidt
CSCI 230
HW3

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main ()
{
    int i; //for final loop
    int f1, f2,f3;
    int total;
    int o = 0; //counter
    int p = 0;//counter
    char words[50];// array of words 
    char **mergedfile; //mergedfile
    FILE *fptr1, *fptr2, *fptr3;  // making files
    
 
    //size of f1
    fptr1 = fopen("american0.txt" , "r");   
    while (1) // inserts
    {
         fscanf(fptr1, "%s", words);
         if (feof(fptr1))break;
         f1++;
    }
    fclose(fptr1);
    
    //size of f2
    fptr2 = fopen("american1.txt" , "r");
    while (1)
    {
         fscanf(fptr2, "%s", words);
         if (feof(fptr2))break;
         f2++;
    }
    fclose(fptr2);
    
    //size of f3
    fptr3 = fopen("american2.txt" , "r");
    while (1)
    {

      fscanf(fptr3, "%s", words);
         if (feof(fptr3))break;
         f3++;
    }
    fclose(fptr3);
    
    //creating dynamic array 
    total = f1+f2+f3;
    mergedfile =calloc(total,sizeof(*mergedfile)); //using malloc function 
    for (i = 0; i < total; i++) 
    {
        mergedfile[i] = calloc(50, sizeof(char));
    }                                                                                                                                                                                       
      
//adding info into dynamic arrays
fptr1 = fopen("american0.txt" , "r");
    for (i = 0; i < f1; i++) 
    {
       fscanf(fptr1, "%s", mergedfile[o++]);
    } 
   fclose(fptr1);
 fptr2 = fopen("american1.txt" , "r");
   for (i = 0; i < f1; i++) 
    {
       fscanf(fptr2, "%s", mergedfile[o++]);
    } 
 fclose(fptr2);
 
 fptr3 = fopen("american2.txt" , "r"); 
 for (i = 0; i < f1; i++) 
    {
       fscanf(fptr3, "%s", mergedfile[o++]);
    } 
   fclose(fptr3);
   
 //sort list      
for(int i = 0; i <total ; i++)
   {
    for(int o = 0; o < total-1; o++)
      {
        if(strcmp(mergedfile[o], mergedfile[o+1]) > 0)
         {
          strcpy(words, mergedfile[o+1]);
          strcpy(mergedfile[o+1], mergedfile[o]);
         strcpy(mergedfile[o], words);
       }
    }
 }

 //save info     
 FILE *fptr4 = fopen("words.txt" , "w");
 for(i = 0; i < total; i++)
 {
 fprintf(fptr4,"%s\n", mergedfile[i]); 
 printf("mereged american0.txt and american1.txt and american2.txt into words.txt" );
  }
  fclose(fptr4);
     //free dynamic array 
  for (i = 0; i < total; i++) 
   {
   free(mergedfile[i]);
   }
   free(mergedfile);
}





