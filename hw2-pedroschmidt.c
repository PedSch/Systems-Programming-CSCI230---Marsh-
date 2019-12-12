/*
Pedro Schmidt
CSCI 230
HW2

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX  100
//
struct info
    {
    char data[30];
    int inumber;
    float fnumber;
    char data2[30];
    };

struct info array[MAX];
int Counter;
int option = 0;
void read()
    {
    printf(" read ");
    FILE *fptr;
    char data[MAX];
    Counter=0;
    fptr=fopen("hw2.data", "r");
     if ( fptr == NULL )
        {
          printf( "file could not open hw2.data.c\n" ) ;
          exit(1);
        }
    while(fgets(data, 30,fptr) != NULL)
        {
            char *tok = strtok (data, " ");
            while(tok !=NULL)
            {
            strcpy(array[Counter].data , tok);
           tok = strtok(NULL, " ");

           array[Counter].inumber = atof(tok) ;
           tok = strtok(NULL, " ");

           array[Counter].fnumber = atoi(tok);
           tok = strtok(NULL, " ");

           strcpy(array[Counter].data2 , tok);
           tok = strtok(NULL, " ");
           Counter++;
     }
  }
  printf("counter: %d", Counter);
  printf("\n");
  fclose(fptr) ;
}
//sorter
void sortArrayHighLow(){
  printf("choice: %d\n", option);
  printf("high to low : %d\n", Counter);
  if(option ==1 )
    {
    for(int i=0; i<Counter; i++)
        {
      for(int j=i+1; j<Counter; j++)
            {
        if(array[i].fnumber < array[j].fnumber)
            {
          float point = array[i].fnumber;
          array[i].fnumber= array[j].fnumber;
          array[j].fnumber= point;
        }
      }
    }
    for(int i=0; i<Counter; i++)
        {
      printf("%.1f \n", array[i].fnumber);
        }
    }
  else if(option ==3)
    {
    for(int i=0; i<Counter; i++)
        {
      for(int j=i+1; j<Counter; j++)
        {
        if(array[i].inumber < array[j].inumber)
            {
          int point = array[i].inumber;
          array[i].inumber= array[j].inumber;
          array[j].inumber = point;
            }
        }
    }
    for(int i=0; i<Counter; i++)
        {
      printf("%d \n", array[i].inumber);
        }
    }
}
//sorter
void sortArrayLowHigh()
    {
  printf("choice: %d\n", option);
  printf("sort array high to low  %d\n", Counter);
  if(option ==2 )
    {
    for(int i=0; i<Counter; i++)
        {
      for(int j=i+1; j<Counter; j++)
            {
        if(array[i].fnumber > array[j].fnumber)
            {
          float point = array[i].fnumber;
          array[i].fnumber= array[j].fnumber;
          array[j].fnumber = point;
            }
        }
    }
    for(int i=0; i<Counter; i++)
        {
      printf("%.1f \n", array[i].fnumber);
        }
    }
  else if(option ==4)
    {
    for(int i=0; i<Counter; i++)
        {
      for(int j=i+1; j<Counter; j++)
        {
        if(array[i].inumber > array[j].inumber)
            {
          int point = array[i].inumber;
          array[i].inumber= array[j].inumber;
          array[j].inumber = point;
        }
      }
    }
    for(int i=0; i<Counter; i++)
        {
      printf("%d \n", array[i].inumber);
        }
    }
}

 int egxit()
{
   printf("exit: %d\n", option);
   if(option ==5 )
    {
      printf("fail");
      exit(0);
    }
    return 0;
  } 
   
int main()
{
    read();
    char option;
    while(1)
    {
        printf("********************\n");
        printf("menu1\n");
        printf("*********************\n");
        printf("**** 1. sort data by the float value & print high to low****\n");
        printf("**** 2. sort data by the float value & print low to high***\n");
        printf("**** 3. sort data by the int value & print high to low**\n");
        printf("**** 4. sort data by the int value & print low to high*\n");
        printf("**** exit\n");
        printf("choose an option\n");
        scanf("%c" , &option);   
        
    switch(option)
        {
  case '1':
    sortArrayHighLow();
    break;
  case '2':
    sortArrayLowHigh();
    break;
  case '3':
    sortArrayHighLow();
    break;
  case '4':
    sortArrayLowHigh();
    break;
  case '5':
     egxit();
    exit(1);
    }
   }
}
