#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
struct node* prev;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search(); 
void main()
{
int choice=0; 
while(choice != 9)
{
printf("\n*********Main Menu*********\n");
printf("\nChoose one option from the following list ...\n");
printf("\n===============================================\n");
printf("\n1.Insert in begining\n");
printf("\n2.Insert at last\n");
printf("\n3.Insert at any random location\n");
printf("\n4.Delete from Beginning\n");
printf("\n5.Delete from last\n");
printf("\n6.Delete the node after the given data\n");
printf("\n7.Search\n");
printf("\n8.Show\n");
printf("\n9.Exit\n");
printf("\nEnter your choice?\n");
scanf("\n%d",&choice);
 switch(choice)
 {
 case 1:
 insertion_beginning();
 break;
 case 2:
 insertion_last();
 break;
 case 3:
 insertion_specified();
 break;
 case 4:
 deletion_beginning();
 break;
 case 5:
 deletion_last();
 break;
 case 6:
 deletion_specified();
 break;
 case 7:
 search();
 break;
 case 8:
 display();
 break;
 case 9:
 exit(0);
 break;
 default:
 printf("Please enter valid choice..");
 }
} 
}
void insertion_beginning()
{
 struct node *temp;
 int item;
 temp = (struct node *)malloc(sizeof(struct node));
 if(temp == NULL)
 {
 printf("\nOVERFLOW");
 }
 else
 {
 printf("\nEnter Item value");
 scanf("%d",&item);
 if(head==NULL)
 {
 temp->next = NULL;
 temp->prev=NULL; 
 temp->data=item;
 head=temp;
 }
 else
 {
 temp->data=item;
 temp->prev=NULL;
 temp->next=head;
 head->prev=temp;
 head=temp;
 }
 printf("\nNode inserted\n");
}
}
void insertion_last()
{
 struct node *ptr,*temp;
 int item;
 ptr=(struct node *) malloc(sizeof(struct node));
 if(ptr==NULL)
 {
 printf("\nOVERFLOW");
 }
 else
 {
 printf("\nEnter value");
 scanf("%d",&item);
 ptr->data=item;
 if(head==NULL)
 { 
 ptr->next=NULL;
 ptr->prev=NULL;
 head=ptr;
 }
 else
 {
 temp=head;
 while(temp->next!=NULL)
 {
 temp=temp->next;
 }
 temp->next=ptr;
 ptr->prev=temp;
 ptr->next=NULL;
 }
 }
 printf("\nNode inserted\n");
 } 
void insertion_specified()
{
 struct node *ptr,*temp;
 int item,loc,i;
 ptr=(struct node *)malloc(sizeof(struct node));
 if(ptr==NULL)
 {
 printf("\nOVERFLOW");
 }
 else
 {
 temp=head; 
 printf("Enter the location");
 scanf("%d",&loc);
 for(i=0;i<loc;i++)
 {
 temp=temp->next;
 if(temp==NULL)
 {
 printf("\nThere are less than %d elements",loc);
 return;
 }
 }
 printf("Enter value");
 scanf("%d",&item);
 ptr->data=item;
 ptr->next=temp->next;
 ptr->prev=temp;
 temp->next=ptr;
 temp->next->prev=ptr;
 printf("\nNode inserted\n");
 }
}
void search()
{
 struct node *ptr;
 int item,i=0,flag;
 ptr = head;
 if(ptr == NULL)
 {
 printf("\nEmpty List\n");
 }
 else
 {
 printf("\nEnter item which you want to search?\n");
 scanf("%d",&item);
 while (ptr!=NULL)
 {
 if(ptr->data == item)
 {
 printf("\nitem found at location %d ",i+1); 
 flag=0;
 break;
 }
 else
 {
 flag=1;
 }
 i++;
 ptr = ptr -> next;
 }
 if(flag==1)
 {
 printf("\nItem not found\n");
 }
 }
}
void deletion_beginning()
{
 struct node *temp;
 if(head==NULL)
 {
 printf("\nUNDERFLOW");
 }
 else if(head->next==NULL)
 {
 head=NULL; 
 free(head);
 printf("\nNode deleted\n");
 }
 else
 {
 temp=head;
 head=head->next;
 head->prev=NULL;
 free(temp);
 printf("\nNode deleted\n");
 }
}
void deletion_last()
{
 struct node *temp;
 if(head==NULL)
 {
 printf("\nUNDERFLOW");
 }
 else if(head->next==NULL)
 {
 head=NULL;
 free(head);
 printf("\nNode deleted\n");
 }
 else
 {
 temp=head;
 if(temp->next!=NULL)
 { 
 temp=temp->next;
 }
 temp->prev->next=NULL;
 free(temp);
 printf("\nNode deleted\n");
 }
}
void deletion_specified()
{
 struct node *ptr, *temp;
 int val;
 printf("\n Enter the data after which the node is to be deleted : ");
 scanf("%d", &val);
 ptr=head;
 while(ptr->data!=val)
 ptr=ptr->next;
 if(ptr->next==NULL)
 {
 printf("\nCan't delete the specified Node\n");
 }
 else if(ptr->next->next==NULL)
 {
 ptr->next=NULL;
 }
 else
 {
 temp=ptr->next;
 ptr->next=temp->next;
 temp->next->prev=ptr;
 free(temp);
 printf("\nNode deleted\n"); 
 }
}
void display()
{
 struct node *ptr;
 printf("\n printing values...\n");
 ptr = head;
 while(ptr != NULL)
 {
 printf("%d\n",ptr->data);
 ptr=ptr->next;
 }
} 
