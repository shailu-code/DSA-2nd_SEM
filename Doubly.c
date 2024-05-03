#include <stdio.h>
#include <stdlib.h>
struct node
	{
		int data;
		struct node *next;
		struct node *prv;
	};

void *print_list(struct node *head)
{
	struct node *temp;
	temp=head;
	printf("\n--Doubly List--\n");				//Printing  Doubly List
	int i=0;
	while (temp != NULL)
	{
		printf("--    node [%d]  -- \n",i);
		printf("Adress of previous node: %p \n", temp->prv);
		printf("Value in node : %d \n", temp->data);
		printf("Adress of next node: %p \n\n", temp->next);
		temp = temp->next;
		++i;
	}										
}


int main()
{
	
	
	printf("\nMy name is Shailendra\n Sap id : 500125394\n\n");
	
	int value,type,x,index,count,variable;						//Initializing Variables
	char choice,ch;
	struct node *head, *newnode,*currentnode,*temp,*prev;				//Initializing pointer Variables
	head = NULL;											
	printf("DO you want to Enter element ?? :  ");					//Asking user whether they want to input data or not
	scanf("%c",&choice);
	
	while(choice == 'Y' || choice =='y')						//for Looping next small part of code
	{
	        newnode=(struct node *)malloc(sizeof(struct node));			//Memory allocaton
		if(newnode==NULL)
		{
			printf("space not available\n");					
	         	return 1;	
	        }
	        else			
	        {
	         	 printf("Enter value you want to store in list: ");	         //Asking for Data to be stored
		         scanf("%d",&value);
		         newnode->data=value;						//storing data in node
		         newnode->prv=NULL;								
		         newnode->next=NULL;
		         if(head==NULL)							//if no element is present in list
		         {
		             head=newnode;
		         }
		         else								//element was present and adding data in list
		         {
		             temp=head;
		             while(temp->next!=NULL)
		             {
		                 temp=temp->next;
		             }
		             temp->next=newnode;					//adding element in last 
		             newnode->prv=temp;						//giving adress of previous last node in inserted node
		         }
	        }
	        printf("Do you want to Enter Another Element: ");
	        scanf(" %c",&choice);
	}
	print_list(head);								//Calling Function to print List

   do
   {	
	printf("-------What Operation you want to perform on Doubly List--------\n");
	printf("Choose from below options--\n 1-Traversing \n 2-Insertion of node \n 3-Deletion of any node \n ");		
	printf("Enter Choice--");
	scanf("%d", &type);
	switch(type)
	{
		case 1:
			printf("--Taversing Of The Doubly List--\n");			//code to Traverse the data of linked list		
			if (head==NULL)	
			{
				printf("Empty List\n");
			}
			else
			{
				print_list(head);					//Calling Function to print List
			}
			break;
		case 2:
			printf("Enter the data you want to store in the newnode: ");
	    		scanf("%d", &value);
	    		currentnode = (struct node *)malloc(sizeof(struct node));	//memory allocation at runtime to newnode to be inserted
	    		currentnode->data=value;					//entering data in newnode
	    		
	    		printf("-------Where you want to insert node--------\n");
			printf("Choose from below options--\n 1- At beggining \n 2- At end \n 3- At any particular index \n ");	
			printf("Enter Choice--");
			scanf("%d", &x);
			switch (x)
			{
				case 1:
					currentnode->prv=NULL;
					if (head==NULL)					//insertion when list is empty
					{
						printf("Empty List\n");
						head=currentnode;
						currentnode->next=NULL;
					}
					else 						//insertion at beginning while node are already present
					{
						currentnode->next=head;
						head->prv=currentnode;
						head=currentnode;
					}
					print_list(head);				//Calling Function to print List	
					break;
				case 2:
					currentnode->next=NULL;
					if (head==NULL)
					{
						printf("Empty List\n");
						head=currentnode;
						currentnode->prv=NULL;
					}
					else
					{
						temp = head;
						while (temp->next!=NULL)
						{
							temp=temp->next;
						}
						temp->next=currentnode;			//providing the address of newnode to last node of list
						currentnode->prv=temp;
					}
					print_list(head);				//Calling Function to print List
					break;
				case 3:
					printf("Choose the index where you want to insert node: ");	//Asking User to give index where they want to insert node
					scanf("%d",&index);
					temp = head;
					count=0;
					while (count<index && temp->next != NULL)	//Insertion at particular  location
					{
						prev=temp;
						temp = temp->next;
						++count;
					}
					if (count<index && temp == NULL)
					{
						printf("--ERROR--         Index are out of Bound \n");
					}
					else 
					{
						temp->prv=currentnode;
						currentnode->next=temp;
						prev->next=currentnode;
						currentnode->prv=prev;
					}
					print_list(head);				//Calling Function to print List
					break;
				default:
					printf("ERROR--Invalid Input--\n");
			}
			break;
		case 3:					//Deletion of Node
			printf("-------Were you want to Delete node--------\n");
			printf("Choose from below options--\n 1- At beggining \n 2- At end \n 3- At any particular Location \n ");
			printf("Enter Choice-- ");
			scanf("%d", &x);
			switch (x)
			{
				case 1:			//deletion from beginning
					if (head == NULL)
					{
						printf("List is already Empty");					
					}
					else if (head->next==head)
					{
						head=NULL;				//deleted first element -- no element remain in list
					}
					else 
					{
						temp=head;
						temp=temp->next;								
						temp->prv=NULL;
						head=temp;				//deleted first element
					}
					print_list(head);				//Calling Function to print List
					break;
				case 2:
					temp=head;
					while(temp->next!=NULL)
					{
						prev=temp;
						temp=temp->next;
					}
					prev->next=NULL;
					print_list(head);				//Calling Function to print List
					break;
				case 3:
					printf("At which index you want to Delete Node: ");
		    			scanf("%d", &index);
		    			count=0;
		    			temp=head;
		    			while (count<index && temp->next!=NULL)		//Deletion at particular  location
					{
						prev=temp;
						temp = temp->next;
						count++;
					}
					if (count<index && temp == NULL)
					{
						printf("Index are out of Bound \n");
					}
					else
					{
						prev->next=temp->next;
						temp->next->prv=prev;			//Trial of double arrow -"SUCCESSFUL"
					}
					print_list(head);				//Calling Function to print List
					break;
			}
			break;
		default:
			printf("ERROR--Invalid Input--\n");
	}
	printf("Do you want to perform another operation: ");
	scanf(" %c",&variable);
   }while(variable== 'Y' || variable =='y');
   return 0;
}	
