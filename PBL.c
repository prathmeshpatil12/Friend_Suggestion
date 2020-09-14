#include<stdio.h>
#include<stdlib.h>

int number;
int top = -1;
int isPresent(int* , int );
int* push(int * , int);
void Display_stack(int *);

int adjacency_count(int matrix[number][number], int no)
{
	int i,j;
	int count =0;
	for(j=0;j<number;j++)
	{
		if(matrix[no][j]==1)
		{
			count++;
		}
	}
	return count;
}

int * adjacency_result (int matrix[number][number], int no, int * result)
{
	int i,j,k=0;
	int count;
	count = adjacency_count(matrix,no);
	for(j=0;j<number;j++)
	{
		if(matrix[no][j]==1)
		{
			result[k]=j;
			k++;
		}
	}
	return result;
}


void main()
{
    printf("\n\n\n\t\t\t\t\t\t   Project Based Learning\n\n\n");
    printf("\t\t\t\t\t\t Topic : Friend Suggestion\n\n\n");
    printf("\t\t\t\t\t\t\t ");
    printf("WELCOME\n\n\n");
	printf("Enter total number of nodes\n");
	scanf("%d",&number);
	int matrix[number][number];
	int count_adj[number];
	int i,j,k,no;
	int count;
	int *stack;
    char decision;
	stack = (int *)malloc(number * sizeof(int));
	printf("Enter 1 if friend and 0 if not a friend.\n");
	for(i=0;i<number;i++)
	{
		for(j=0;j<number;j++)
		{
		    printf("Is %d friend of %d : ",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
	while(1)
    {
        printf("\nEnter operation to perform : ");
        printf("\n1. My friends.\n2. Recommend me friends\n3. Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Who are you : ");
            scanf("%d",&no);
            int * friends;
            count = adjacency_count(matrix,no);
            friends = (int *) malloc(count*sizeof(int));
            friends = adjacency_result(matrix,no,friends);
            printf("Your friends are : ");
            for(i=0;i<count;i++)
            {
                printf("%d, ",friends[i]);
            }
            break;

        case 2:
            printf("Who are you : ");
            scanf("%d",&no);
            int flag;
            count = adjacency_count(matrix,no);
            int *result;
            result = (int *) malloc(count*sizeof(int));
            int *final_result;
            for(i=0;i<number;i++)
            {
                count_adj[i]=adjacency_count(matrix,i);
            }
            int final_result_size=0;

            for(i=0;i<count;i++)
            {
                final_result_size = final_result_size+ count_adj[i];
            }
            final_result = (int *) malloc(final_result_size*sizeof(int));
            //printf("Size of final result : %d  %d\n",final_result_size,sizeof(final_result));
            //printf("Count : %d\n",count);
            for(i=0;i<count;i++)
            {
                result = adjacency_result(matrix,no,result);
                final_result = adjacency_result(matrix,result[i],final_result);
                for(j=0;j<final_result_size;j++)
                {
                    flag =1;
                    if(final_result[j]==no)
                    {
                        flag =0;
                    }
                    else
                    {
                        for(k=0;k<count;k++)
                        {
                            /*printf("%d=%d=%d=  ",i,j,count);
                            printf("Result = %d, Final Result = %d\t",result[i],final_result[j]);*/
                            if(final_result[j]==result[k])
                            {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    if(flag ==1)
                    {
                        //printf("Element pushed = %d .\n",final_result[j]);
                        stack = push(stack,final_result[j]);
                    }
                }
            }

            printf("\n");
            printf("Recommendations : ");

            Display_stack(stack);
            printf("\n");
            printf("Do you want to send friend request? [y/n] : ");
            scanf(" %c",&decision);
            if(decision=='y')
            {
                printf("To whom do you want to send friend request : ");
                int send_req;
                scanf("%d",&send_req);
                printf("\n\nAccording to %d ",send_req);
                printf("\n%d has sent you friend request.",no);
                char accept_request;
                printf("\nDo you want to accept request? [y/n] : ");
                scanf(" %c",&accept_request);
                if(accept_request=='y')
                {
                    matrix[no][send_req]=1;
                    matrix[send_req][no]=1;
                }
            }
            top=-1;
            count=0;
            result = NULL;
            final_result = NULL;
            flag=1;
            break;

        case 3:
            exit(0);

        default:
            printf("Enter valid option\n");
        }
    }
}


int * push(int * stack, int no)
{
    if(no>=number||no<0)
    {
    }
    else if(isPresent(stack,no))
    {
    }
    else
    {
        top++;
        stack[top] = no;
        //printf("\tNo : %d--",stack[top]);
        //printf("\tTop : %d-",top);
    }
    return stack;
}

int isPresent(int *stack, int no)
{
    int i,flag = 0;
    for(i=0;i<=top;i++)
    {
        if(stack[i]==no)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

void Display_stack(int *stack)
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d, ",stack[i]);
    }
}

