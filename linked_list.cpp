#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
}* start=NULL;
struct node *end= NULL;

void createList(int a[],int n)
{
 int i;
 struct node * temp,* newnode;
 start= (struct node *)malloc(sizeof(struct node));
 temp=start;
 end=temp;
 start->data=a[0];
 start->next=NULL;
 for(i=1;i<n;i++)
 {
  newnode= (struct node *)malloc(sizeof(struct node));
  newnode->data=a[i];
  temp->next=newnode;
  temp=temp->next;
  end=newnode;
 }
 end->next=NULL;
}

void insertAtFront()
{
  int data;
  struct node *newnode= (struct node *)malloc(sizeof(struct node));
  printf("enter the value you want to enter");
  scanf("%d",&data);
  newnode->data= data;
  if(start==NULL)
  {
    start=newnode;
    newnode->next=NULL;
    end=newnode;
  }
  else
  {
     newnode->next=start;
     start=newnode;
  }
}

void insertAtLast()
{
  int data;
  struct node *newnode= (struct node *)malloc(sizeof(struct node));
  printf("enter the value you want to enter");
  scanf("%d",&data);
  newnode->data= data;
  newnode->next= NULL;

  if(start==NULL)
  {
    start=newnode;
    end=newnode;
  }
  else
  {
    end->next=newnode;
    end=newnode;
  }
}
int count()
{
  struct node * temp= start;
  int count=0;
  while(temp!=NULL)
  {
   count++;
   temp=temp->next;
  }
  return count;
}
void insertAt()
{
  int position,data;
  struct node *newnode= (struct node *)malloc(sizeof(struct node));
  printf("enter the position at which you want to enter :");
  scanf("%d",&position);
  printf("\nenter the value you want to enter :");
  scanf("%d",&data);
  if(position>(count()+1))
  {
    printf("your entered position is invalid please enter valid position");
  }
  else
  {
    struct node *temp=start;
    newnode->data=data;
    int prev=1;
    while(prev<(position-1))
    {
     prev++;
     temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
  }
}
void display()
{
 struct node *temp= start;
 printf("[");
 while(temp!=NULL)
 {
  printf("%d,",temp->data);

  temp=temp->next;
 }
 printf("\b");
 printf("]\n");
}
void rDisplay(struct node * p)
{
 if(p!=NULL)
 {
 printf("%d ",p->data);
 rDisplay(p->next);
 }
}

int sum(struct node *p)
{
  int sum=0;
  while(p!=NULL)
  {
    sum=sum+p->data;
    p=p->next;
  }
  return sum;
}
int rSum(struct node *p)
{
 if(p->next==NULL)
 {
  return p->data;
 }
 else
 {
 return p->data+rSum(p->next);
 }
}
void deleteFirst()
{
  struct node *temp=start;
  start=start->next;
  free(temp);
}
void deleteLast()
{
    struct node * temp= start;
    int i=1;
    int cou=count();
    while(i<cou-1)
    {
        temp=temp->next;
        i++;
    }
    free(end);
    temp->next=NULL;
    end=temp;
}
void deleteAtPosition(int pos)
{
   int i=1;
   int data;
   struct node * temp= start;
   while(i<pos-1)
   {
       temp=temp->next;
       i++;
   }
   struct node *del = temp->next;
   temp->next=temp->next->next;
   free(del);
   printf("successfully deleted");
}

/*void reverseList()
{
   struct node * stemp = start;
   struct node * etemp = end;
   int s = 1;
   int e = count();
   int tempdata = NULL;


   while(s<e)
   {
       tempdata = stemp->data;
       stemp->data=etemp->data;
       etemp->data=temp->data;
       s++;
       e--;
       stemp=stemp
   }


}*/




int maximum()
{
    struct node * temp= start;
    int max=temp->data;
    while(temp!=NULL)
    {
        if(max<temp->data)
        {
            max=temp->data;
        }
        temp=temp->next;
    }
    return max;
}

int minimum()
{
    struct node * temp =start;
    int min = temp->data;
    while(temp!=NULL)
    {
        if(min > temp->data)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

int searchElement(int value)
{
    struct node * temp = start;
    int position = 1;
    while(temp!=NULL)
    {
        if(value==temp->data)
        {
            return position;
        }
        else
        {
            temp=temp->next;
            position++;
        }
    }
    return 0;
}


int main()
{
 int choice;
 printf("===================This is linked list implementaton===================\n");
 printf("\nCHOICES\n");
 printf("\n1 . Create linked list with some values");
 printf("\n2 . Insert at first");
 printf("\n3 . Insert at last");
 printf("\n4 . Insert at any position");
 printf("\n5 . Count the total elements");
 printf("\n6 . Display all elements of linked list");
 printf("\n7 . Display all elements through recursion");
 printf("\n8 . Sum of all elements");
 printf("\n9 . Sum of elements through recursion");
 printf("\n10. Delete the first element from the list");
 printf("\n11. Delete the last element from the list");
 printf("\n12. Delete the element from particular position");
 printf("\n13. Maximum in all elements ");
 printf("\n14. Minimum in all elements ");
 printf("\n15. Get the position of any element in the list ");
 printf("\n16. Exit");

 while(1)
 {
 printf("\nEnter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
   case 1:
	int num,i;
	int * arr;
	printf("Enter the number of elements for which you want to create linked list :");
	scanf("%d",&num);
	arr=(int *)malloc(num * sizeof(int));
	printf("enter %d elements in linked list \n",num);
	for(i=0;i<num;i++)
	{
	  scanf("%d",&arr[i]);
	}
	createList(arr,num);
	printf("List created successflly");
	break;
   case 2:
	insertAtFront();
	break;
   case 3:
	insertAtLast();
	break;
   case 4:
	insertAt();
	break;
   case 5:
	printf("\ntotal elements are: %d",count());
	break;
   case 6:
	display();
	break;
   case 7:
	rDisplay(start);
	break;
   case 8:
	printf("Sum of elements is : %d",sum(start));
	break;
   case 9:
	printf("sum through recursion is : %d",rSum(start));
	break;
   case 10:
	deleteFirst();
	printf("successfully first element deleted");
	break;
   case 11:
	deleteLast();
	printf("successfully last element deleted");
	break;
   case 12:
      int pos;
      printf("Enter the position at which you want to delete : ");
      scanf("%d",&pos);
      deleteAtPosition(pos);
      break;
   case 13:
      printf("Maximum : %d",maximum());
      break;
   case 14:
      printf("Minimum : %d",minimum());
      break;
   case 15:
      int val;
      printf("enter the element you want to search :");
      scanf("%d",&val);
      if(searchElement(val)!=0)
      {
          printf("Position of searched element is : %d",searchElement(val));
      }
      else
      {
          printf("Element is not found int the list");
      }

      break;
   case 16:
    exit(1);
   default:
	 printf("SORRY!!!! Enter a valid choice");
 }
 }
 return 1;
}
