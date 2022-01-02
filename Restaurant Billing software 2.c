#include<stdio.h>
#include<string.h>
#include<stdlib.h>


double price[7] = { 250 , 300 , 20 , 120 , 150 , 160 , 50 };
double mealTaxPrices[7];
int adultNumber,childNumber;


void printMeals();
void orderMeals();
double orderForAdult();
double orderForChildren();
int main()
{
    char response = 'y';


     printMeals();
     while(response == 'y'|| response == 'Y')
    {
            printf("please enter number of adults  :");
            scanf("%d",&adultNumber);

            printf("please enter number of children:");
            scanf("%d",&childNumber);


            orderMeals();

            printf("\nwould you like to continue(y/n):");
            scanf("\n%c",&response);
    }

 printf("\n      ******************** THANK YOU FOR COMING  *************************\n");
 printf("\20**********************   PLEASE VISIT US NEXT TIME  **************************\20 \n");
   system("pause");
   return 0;
}

void printMeals()
{

      printf("\20*******************  WELCOME TO SRM RESTURANT **************************\20\n");
      printf(" \t\t\t Below is the menue:\20\n");
      printf(" \t\t\t MEALS\t\t\tPRICE:\n");
      printf(" \t\t\t \22*******************************\22\n");
      printf(" \t\t\t 1- Veg Biryani\t\t250/-\n");
      printf(" \t\t\t 2- Special Meal\t300/-\n");
      printf(" \t\t\t 3- Roti\t\t20/-\n");
      printf(" \t\t\t 4- Dal\t\t\t120/-\n");
      printf(" \t\t\t 5- Paneer Tikka\t150/-\n");
      printf(" \t\t\t 6- Veg mix\t\t160/-\n");
      printf(" \t\t\t 7- Icecream\t\t50/-\n");



      printf("\n");
}
void orderMeals()
{
	double totalPriceForAdult, totalPriceForChildren;
	double allPayment,discount;
         printf("                      \t\t**** ORDER MENUE****\n");


        totalPriceForAdult =  orderForAdult();
        totalPriceForChildren = orderForChildren();
		allPayment = totalPriceForAdult + totalPriceForChildren ;

     printf("\n \t\t     \22**************************************\22    \n");
     printf(" \t\t   ******************  final BILL   ************      \n");
     printf(" \t\t\tadult/child\tcount\t\ttotal price\n");
     printf(" \t\t\tadults\t\t%d\t\t%5.2f\n",adultNumber,totalPriceForAdult);
     printf(" \t\t\tchildren\t%d\t\t%5.2f\n",childNumber,totalPriceForChildren);
     printf(" \t\t\tTotal bill\t\t\t%5.2f\n",allPayment );



     if(allPayment < 100)
		 discount=((allPayment * 0.5)/100);
     else if(allPayment>= 100 && allPayment<200)
          discount=((allPayment * 1)/100);
     else if(allPayment>= 200 && allPayment<300)
          discount=((allPayment * 1.5)/100);
     else if(allPayment>= 300 && allPayment<400)
          discount=((allPayment * 2.0)/100);
	 else
		  discount= ((allPayment * 5.0)/100);

          printf(" \t\t\tTotal bill after discount\t%5.2f\n",allPayment-discount);

}
double orderForAdult()
{
     int menuOption,i,amount;
      char response = 'y';
      double totalPerPerson = 0.0,totalAllPerson = 0.0;
      double tax = 5.0;
      if(adultNumber <=0)
		   printf("\n ");
	  else
      printf("*\tadults:\n");
      for(i=0;i<adultNumber;i++)
     {
               printf("adult %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \nagain! ");
								  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",&amount);


                           totalPerPerson = totalPerPerson + (amount * price[menuOption - 1] );

                              printf("\nWould you like to enter more orders(y/n):");
                              scanf("\n%c",&response);



               }
               printf("\n");
               totalAllPerson += totalAllPerson +  totalPerPerson;
               totalPerPerson = 0.0;
               response = 'y';
     }

     return totalAllPerson + ((totalAllPerson * tax) / 100);
}
double orderForChildren()
{
       int menuOption,i,amount;
      char response = 'y';
      double totalPerChild = 0.0,totalAllChildren = 0.0;
      double tax = 5.0,oneOrder;
       if(childNumber <=0)
		   printf("\n");
	   else
       printf("*\tChildren:\n");
       for(i=0;i<childNumber;i++)
     {
               printf("child %d please enter your orders\n",i+1);
               while(response == 'y' || response == 'Y')
               {
                              printf("please enter your option:");
                              scanf("%d",&menuOption);
							  if(menuOption<1 || menuOption>7)
							  {
								  printf("sorry we don`t have this order \nagain! ");
                                  continue;
							  }
                              printf("please enter your amount of order:");
                              scanf("%d",&amount);

                              oneOrder = (price[menuOption - 1] * 60)/100 ;//this one order for a child with discount %60 of one order of adult
                              totalPerChild = totalPerChild + (amount * oneOrder)  ;

							  printf("Would you like to enter more orders(y/n):");
                              scanf("\n%c",&response);


               }
               totalAllChildren += totalAllChildren +  totalPerChild;
               response = 'y';
               totalPerChild = 0.0;

               printf("\n");

     }

     return totalAllChildren + ((totalAllChildren * tax) / 100);
}
