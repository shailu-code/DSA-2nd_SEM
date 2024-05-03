#include <stdio.h>
#include <stdlib.h>

struct node
	{
		int data;
		struct node *next;
	};

void *print_list(struct node *head)
{
	struct node *temp;
	temp=head;
	printf("\n--Linked List--\n");				
	int i=0;
	while (temp->next!= head)
	{
		printf("--    node [%d]  -- \n",i);
		printf("Value || Adress of next node :: %d  ||  %p  \n\n", temp->data,temp->next);
		temp = temp->next;
		++i;
	}	
	printf("--    node [%d]  -- \n",i);
	printf("Value || Adress of next node :: %d  ||  %p  \n\n", temp->data,temp->next);									
}

int main()
{
	printf("\nMy name is Shailendra\n Sap id : 500125394\n\n");
	int value,type,x,index,i,count;								//Initializing Variables
	char choice,variable;
	struct node *head, *newnode,*currentnode,*temp,*prev;					//Initializing pointer Variables
	head = NULL;											
	printf("DO you want to Enter element ?? :  ");						//Asking user whether they want to input data or not
	scanf("%c",&choice);
	
	    while(choice == 'Y' || choice =='y')						//for Looping next small part of code
	    {
	        newnode=(struct node *)malloc(sizeof(struct node));				//Memory allocaton
		if(newnode==NULL)
		{
			printf("space not available\n");					
	         	return 1;	
	        }
	        else			
	        {
	         	 printf("Enter value you want to store in list: ");	         	//Asking for Data to be stored
		         scanf("%d",&value);
		         newnode->data=value;							//storing data in node
		         newnode->next=NULL;
		         if(head==NULL)								//if no element is present in list
		         {
		             head=newnode;
		             newnode->next=head;
		         }
		         else									//element was present and adding data in list
		         {
		             temp=head;
		             while(temp->next!=head)
		             {
		                 temp=temp->next;
		             }
		             temp->next=newnode;						//adding element in last 
		             newnode->next=head;      						//giving address of first node to added node in last to make it circular list
		         }
	        }
	        printf("Do you want to Enter Another Element: ");
	        scanf(" %c",&choice);
	    }
		print_list(head);
	
	    do							//for Looping next small part of code
	    {									
        	printf("-------What Operation you want to perform on Circular List--------\n");
		printf("Choose from below options--\n 1-Traversing \n 2-Insertion of node \n 3-Deletion of any node \n ");		
		printf("Enter Choice--");
		scanf("%d", &type);
		switch(type)
		{
			case 1:					//Traversing
				if(head==NULL)
					printf("Empty List\n");
				else
					print_list(head);
				break;
				
			case 2:					// Insertion of Node
	   			printf("Enter the data you want to store in the newnode: ");
	    			scanf("%d", &value);
	    			currentnode = (struct node *)malloc(sizeof(struct node));		//memory allocation at runtime to newnode to be inserted
	    			currentnode->data=value;						//entering data in newnode
	    			
	    			printf("-------Where you want to insert node--------\n");
				printf("Choose from below options--\n 1- At beggining \n 2- At end \n 3- At any particular index \n ");	
				printf("Enter Choice--");
				scanf("%d", &x);
				
				switch (x)
				{
					case 1:			//insertion at beginning
	    					currentnode->next=head;						//making it circular list of only one element
	    					if (head == NULL)
	    					{
	        					printf("List is empty.\n");
	        					head=currentnode;								
	    					}
	    					else
	    					{
	    						temp=head;
	        					while (temp->next != head)
	        					{
	        					    temp = temp->next;
	        					}
	        					temp->next = currentnode;				//providing address of newnode to last node 
	        					head = currentnode;					//making head to point out newnode
	    					}
	    					print_list(head);
		    				break;
		    			case 2:			//insertion at end
		    				while (temp->next != head)
	        				{
	        				    temp = temp->next;
	        				}
		    				temp->next=currentnode;									//providing address of newnode to last node
		    				currentnode->next=head;									//providing inserted node address of first node
		    				print_list(head);
		    				break;
		    			case 3:			//inserion at specific index
		    				printf("where you want to insert Node: ");
		    				scanf("%d", &index);
		    				i=0;
		    				temp=head;
		    				while (count<index && temp->next!=head)				//Insertion at particular  location
						{
							prev=temp;
							temp = temp->next;
							count++;
						}
						if (count<index && temp->next == head)
						{
							printf("Index are out of Bound \n");
						}
		    				currentnode->next=prev->next;
		    				prev->next=currentnode;
		    				print_list(head);
		    				break;
		    			default:
		    				printf("ERROR--Invalid Input--\n");
		    				break;
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
							head=NULL;									//deleted first element -- no element remain in list
						}
						else 
						{
							temp=head;
							temp=temp->next;											
							head=temp;					//adress of second node assigned to head
							temp=head;
							while (temp->next != head)
	        					{
	        					    temp = temp->next;
	        					}	
	        					temp->next=head;				//deleted first element
						}
						print_list(head);
						break;
					case 2:			//deletion from End
						temp = head;										
						if (head == NULL)
						{
							printf("List is already Empty");
						}
						else if (head->next==head)
						{
							head=NULL;
							
						}
						else
						{
							temp=head;
							while(temp->next!=head)
							{
								prev=temp;
								temp=temp->next;				//putting adress of first node into second last node
							}
							prev->next=head;
						}
						print_list(head);
						break;
					case 3:			//Deletion of node on specific Node
						printf("At which index you want to Delete Node: ");
		    				scanf("%d", &index);
		    				i=0;
		    				temp=head;
		    				while (count<index && temp->next!=head)				//Deletion at particular  location
						{
							prev=temp;
							temp = temp->next;
							count++;
						}
						if (count<index && temp->next == head)
						{
							printf("Index are out of Bound \n");
						}
		    				prev->next=temp->next;	
		    				
		    				print_list(head);											
						break;
					default:
	       					printf("ERROR--Invalid Input--\n");
	       					break;
				}
				break;
			default:
	       			printf("ERROR--Invalid Input--\n");
	       			break;
	       	}
	       	printf("Do you want to perform another operation: ");
	        scanf(" %c",&variable);
            }while(variable== 'Y' || variable =='y');
        return 0;
}
