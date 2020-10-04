#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Gourav's code to count the brackets
typedef struct nodetype
{
    char data;
    int pos;
    struct nodetype *next;
}stk;
stk *top=NULL;
stk *p;
int max;

//push in stack
char push(char ele,int max)
{
    stk *temp;
    temp = (stk*)malloc(sizeof(stk));
    if (temp == NULL)
    {
        printf("Overflow\n");
        return 0;
    }

    else
    {
        temp->pos = max+1;
        temp->data = ele;
        temp->next = top;
        top = temp;
    }
}


//pop from the stack
int pop()
{
    if(top ==  NULL)
    {
        printf("Underflow\n");
        return 0;
    }
    else
    {
        p = top;
        top = top->next;
        free(p);
    }
}


int main()
{
   stk *t;
   int i=0,count=0,flag=0;
   char str[100000],val,some;
   gets(str);
   while(str[i]!='\0')
   {
     val=str[i];

     if(val=='('||val=='{'||val=='[')
            {
                max = 1;
                push(val,i);
            }
     else if(val==')'||val=='}'||val==']')
     {
         if(top==NULL)
         {
             top=1;
             count++;
             break;
         }
         t = top;
         some = t->data;
         if(val==')')
         {
             val='(';
         }
         else if(val=='}')
         {
             val='{';
         }
         else if(val==']')
         {
             val='[';
         }

         if(some!=val)
         {
             flag = 1;
             count++;
             break;
         }
         if(some==val)
         {
             max++;
             pop();
         }

     }
     count++;
     i++;

   }
   if(top==NULL)
   {
       printf("\nSuccess");
   }
   else if(top==1)
   {
       printf("\n%d",count);
   }
   else if(flag==1)
   {
       printf("\n%d",count);
   }
   else{
    printf("\n%d",top->pos);
   }

}

