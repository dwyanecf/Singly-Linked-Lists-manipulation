#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
typedef struct cell
{
    int data;
    struct cell *next;
}cell,*cellpr;

void DateSort(int a[],int m);
cellpr Creatcell(cellpr head,int i,int a[]);//Create the link list
void Member(cellpr head,int a);
cellpr Insert(cellpr head,int a);
cellpr Delete(cellpr head,int a);
void Measure(cellpr head,int i);
void Display(cellpr head);
cellpr Invert(cellpr head);
void printNthFromLast(cellpr head, int n);
int main()
{
   cellpr head=NULL;
   int c;
   FILE *fp;
   int i;
   int a[SIZE];//read file
   int m;
   int Idata;//append element
   int Ddata;//delete element
   int Sdata;//find member element
   if((fp=fopen("input.txt","r"))==NULL)
   {
       printf("Failure to open input.txt!\n");
       exit(0);
   }
   printf("Here are the initial create link list bellow:\n");
   for(i=0;(fscanf(fp,"%d",&a[i])==1);i++)
   {
       if(a[i]==-1){
            printf("\n");
        continue;
       }

       printf("%d\n",a[i]);
   }
   //DateSort(a,i);

   for(m=0;m<i;m++)//create link list
   {
      head=Creatcell(head,m,a);
   }
   while (1)
   {
   printf("Input the functions you want bellow£º\n"
          "*******************************\n"
          "1.Find a member of an element\n"
          "2.delete an element\n"
          "3.count the total length\n"
          "4.append an element\n"
          "5.reverse a single list\n"
          "6.display the single link list\n"
          "7.return the nth last element in the single link list\n"
          );

	scanf("%d",&c);
	switch (c)
	{
    case 1:
        printf("Input the member element you want to find :\n");
        scanf("%d",&Sdata);
        Member(head,Sdata);
        break;
   case 2:
     printf("Enter the element you want to delete :\n");
     scanf("%d",&Ddata);
     head=Delete(head,Ddata);
     i--;
      break;
       case 3:
     Measure(head,i);
     break;
    case 4:
      printf("Input the element you want to append:\n");
      scanf("%d",&Idata);
      head=Insert(head,Idata);
      i++;
      break;
       case 5:
    head=Invert(head);
    break;
    case 6:
      Display(head);
      break;
       case 7:
      printNthFromLast( head, 1);
      break;

    }
   }
    return 0;
}
/*
void DateSort(int a[],int m)// sort
{
    int i,j,temp;
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<m;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}

*/
cellpr Creatcell(cellpr head,int i,int a[])//create link list
{
    cellpr p = NULL; //tail pointer
	cellpr pr = head;
	p = (cellpr)malloc(sizeof(cell));
	if (p == NULL)
	{
		printf("No enough memory to allocate!\n");
		exit(0);
	}
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		while (pr->next != NULL)
		{
			pr = pr->next;
		}
		pr->next = p;
	}
    p->data=a[i];
    p->next=NULL;
    //printf("%d\n",p->data);
    return head;
}


void Member(cellpr head,int a)//find the member
{
    cellpr p=head;
    int j=1;
    int flag=0;
    p=p->next;

    while(p!=NULL)
    {
        if(a==p->data)
        {
        printf("The member element you want to find is the %d node\n",j+1);
        flag=1;
        }
        p=p->next;
        j++;
    }
    if(flag==0)
        {
            printf("The element you input is not the member of this list!\n");
        }
}

cellpr Insert(cellpr head, int nodeData)//append element
{
	cellpr pr = head, p = head, temp = NULL;
	p = (cellpr)malloc(sizeof(cell));
	if (p == NULL)
	{
		printf("No enough memory!\n");
		exit(0);
	}
	p->next = NULL;
	p->data = nodeData;
	if (head == NULL)
	{
     	head = p;
  	}
	else
	{
		while (pr->data < nodeData && pr->next != NULL)
       	{
				temp = pr;
				pr = pr->next;
		}
		if (pr->data >= nodeData)
		{
				if (pr == head)
				{
				  p->next = head;
				  head = p;
				}
				else
				{
					pr = temp;
					p->next = pr->next;
					pr->next = p;
				}
		}
		else
		{
				pr->next = p;
		}
	}
	return head;
}
void printNthFromLast(cellpr head, int n)
{
    int len = 0, i;
    cellpr temp = head;

    // 1) count the number of nodes in Linked List
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    // check if value of n is not more than length of the linked list
    if (len < n)
      return;

    temp = head;

    // 2) get the (n-len+1)th node from the begining
    for (i = 1; i < len-n+1; i++)
       temp = temp->next;

    printf ("The last element of this list is %d \n", temp->data);

    return;
}

void Measure(cellpr head,int i)//return link list length
{
    printf("This single link list has %d in total\n",i);
}
void Display(cellpr head)//display the link list
{
    cellpr p=head;
    int j=1;
    while(p!=NULL)
    {
        if(p->data!=-1)
        printf("%5d%10d\n",j,p->data);
        p=p->next;
        j++;
    }
}
cellpr Invert(cellpr head)//reverse the link list
{
    cellpr s,s1;
    s = head;
    head = NULL;
    while (s)
    {
        s1 = s;
        s = s->next;
        s1->next = head;
        head = s1;
    }
    return head;
}
cellpr Delete(cellpr head, int nodeData)
{
	struct cell *p = head, *pr = head;
	if (head == NULL)
	{
		printf("Linked Table is empty!\n");
		return(head);
	}
	while (nodeData != p->data && p->next != NULL)
	{
		pr = p;
		p = p->next;
	}
	if (nodeData == p->data)
	{
		if (p == head)
		{
				head = p->next;
		}
		else
		{
				pr->next = p->next;
		}
		free(p);
	}
	else
    {
		printf("The element you input does not exist!\n");
    }
	return head;
}
