
/*
    Pedro Schmidt
    HW-1
    CSCI230

*/
#include <stdio.h>
#include <stdlib.h>



int main(void)
   {
    float B = 2000.0;//B is the amount borrowed
    float r = 0.25;   //r is the annual interest rate
    float P = 0; // P is the payment amount (pick a value)

    printf ("Please enter your monthly payment! \n");
    scanf("%f", &P);
    printf("interest rate (r):%.2f\n", r);
    printf("initial Balance (B):%.1f\n", B);
    printf("payment amount (P):%.1f\n\n", P);

    int m = 1;//months
    float total = 0; //total interest
    int s = 0; // counter
    float amt[100]; //loan amount
    float i[100]; //interest

   while(B > 0) //condition
   {
      if(s == 0)
       {
         i[s] = (r/12)*B; //I[o] = is the interest due after the first month
         total = total + i[s];
         printf("%d %.2f %.2f\n" , m , i[s], B);
         amt[0] = P - i[s];
        }

     else if(s > 0)
      {
         i[s] = (r/12)*(B-P+i[s-1]);//I[n] = is the interst due after the nth month
         B = B-amt[0];
         printf("%d %.2f %.2f\n" , m , i[s], B);
         amt[0] = P - i[s];
         if(i[s] > 0)
           total = total + i[s];
      }

           m++;
        s++;

      }
    printf ("total interest paid: %.2f\n" , total);
   }
