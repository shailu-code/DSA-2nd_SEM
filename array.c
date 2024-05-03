#include <stdio.h>
void printarray(int a[], int max, int n)
{
	printf("Array--a[%d]:{",max);			//Starting of Array Printing
	for (int i=0; i<n; i++)				//Printing Elements in Array
	{
		printf(" %d,",a[i]);
	}
	printf("}\n\n");				//Closing of Printing Array
}

void main()
{
	printf("My name is Shailendra\n Sap id: 500125394\n\n");
	
	int max,i,UB,LB,type,x,Box,variable;						//Initialization of variables
	
	printf("Enter the Max Size of array: ");
	scanf("%d",&max);
	
	int a[max],n;								//Initialization of variables
	 
	printf("How many elements You want to enter in array? -: ");
	scanf("%d",&n);
   if (n<= max)
   {
		for (i=0; i<n; i++)
		{
			printf(" %d Element of array a[%d] is : ", i+1 , max);
			scanf("%d",&a[i]);
		}
		printf("\nChoosed ");
		printarray(a,max,n);					// calling function to print array
	
	//Lower Bound [LB] & Upper Bound [UB] 					// Generally LowerBound can be [LB=0]
	LB=0;									// Upper Bound must be - [ UB = n-1 ]					 
	UB = n-1;								// As elements in array are inputted by User		
	printf("\n Upper Bound [UB] = %d,\tLower Bound [LB] = %d \n",UB, LB);
	
	int temp=LB,value,index;								//Initialization of variables
	
	if (LB > UB )
	{
		printf("--------------Array is Empty-------------\n");
		printf("We Can only insert value in array\n");
	}
	
        do
        {
		printf("-------What Operation you want to perform on array--------\n");
		printf("Choose from below options--\n 1-Traversing \n 2-Searching \n 3-Insertion of element \n 4-Deletion of any element \n ");
		printf("Enter Choice--\n");
		scanf("%d", &type);
		switch(type)
		{
			case 1:
				temp=LB;
				while ( temp <= UB )
				{
					printf("a[%d]= %d \n", temp, a[temp]);
					temp++;
				}
				break ;
				
			case 2:
				printf("How you want to Search element--[ 1-index ,       2- Element ]\n Enter Choice: ");
				scanf("%d", &x);
				
				switch (x)
				{
					case 1:
						printf("Enter index : ");
						scanf("%d", &index);
						printf("a[%d] = %d \n", index , a[index]);
						printarray(a,max,n);
						
						break;
					case 2:
						printf("Enter Element: ");
						scanf("%d", &value);
						i=0,temp=0;
						while((a[i] != value) && (i<n))
						{
							i++;			//increasing value of i as at current element is not same as element provided by user
							if (a[i] == value)			
							{
								printf("--FOUND-- \nElement Found at a[%d]\n",i);
								temp = 0;
							}
							else 
							{
								temp ++;
							}
						}
						if ( temp != 00 )
						{
							printf("--'ERROR'--\n Element Not found In Array\n");
						}
						printf("Array provided By User is -\n");
						printarray(a,max,n);	
						
						break;
					default:
						printf("Invalid Input\n");
				}
				break;
			case 3:
				printf(" 1:insert in beginning\n 2:insert in end\n 3:insert at particular index\n Enter your choice = ");
				scanf("%d",&x);
				printf("Enter the element you want to enter ");
	       			scanf("%d",&value);
	       			switch(x)
	       			{
	       				case 1:
	      					if (UB == max )
	      					{
	      						printf("Array is full\n");
	       					}
	       					else 
	       					{
	      						temp=UB;
	      						while ( temp >= 0)
	      						{
	       							a[temp+1]= a[temp];
	       							temp--;
	       						}
	       						UB++;
	       						a[LB]=value;
	       					}
	       					printf("Updated array is - \n");
	       					printarray(a,max,n+1);
	       						
	       					break;
	       				case 2:
	       					UB++;
	       					a[UB]= value;
	       					printarray(a,max,n+1);
	       						
	       					break;
	       				case 3:
	       					printf("Enter The Index you want to enter element: ");
	       					scanf("%d", &index);
	       					temp=UB;
	       					while(temp>=index)
	       					{
	       						a[temp+1]= a[temp];
	       						temp--;
	       					}
	       					UB++;
	      					a[index]=value;
	      					printf("Updated array is - \n");
	       					printarray(a,max,n+1);
	       					
	       					break;
	       				default:
	       					printf("--INVALID INPUT--\n");
	       			}
	       			break;
	       		case 4:
	       			printf(" 1:Delete first element\n 2:Delete Last Element\n 3:Delete element of Particular Location\n--Enter Your Choice: ");
	       			scanf("%d", &x);
	       			switch (x)
	       			{
	       				case 1:
	       					if (UB<LB)
	       					{
	       						printf("--ERROR--Array is already Empty--\n");
	       					}
	       					else if (UB == LB)
	       					{
	       						Box=a[UB];
	       						UB--;
	       					}
	       					else
	       					{
	       						temp=UB;
	       						while(temp > LB)
	       						{
	       							a[temp-1]=a[temp];
	       							temp--;
	       						}
	       						UB--;	
	       					}
	       					printf("Updated array is - \n");
	       					printarray(a,max,UB+1);
	       					break;
	       				case 2:
	       					Box=a[UB];
	       					UB--;	
	       					printf("Updated array is - \n");
	       					printarray(a,max,UB+1);	
	       					break;
	       				case 3:
	       					printf("Enter index, where you want to delete element: ");
	       					scanf("%d", &index);
	       					temp=index;
	       					while(temp < UB)
	       					{
	       						a[temp]=a[temp+1];
	       						temp++;
	       					}
	       					UB--;
	       					printf("Updated array is - \n");
	       					printarray(a,max,UB+1);
	       					break;
	       				default:
	       					printf("--Invalid Input--\n");
	       			}
	       			break;
	       			
	       		default:
	       			printf("ERROR--Invalid Input--\n");
	       	}
	       	printf("Press 'y' if you wish to perform another operation in array ");
		scanf(" %c",&variable);
	}while(variable == 'Y' || variable == 'y');
   }
   else 
	{
		printf("--'ERROR'--\nArray size is less than the number of element you want to enter\n");
	}
}
       					
       							
       					
       						
					
			
			
	
