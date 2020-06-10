#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Employee{
       int employeeNumber;
       char* employeeName;
       float salary;
       struct Employee *next;
};

void printList(struct Employee *node)
{
     while(node !=NULL)
     {
         printf("%s",node->employeeName);
         node=node->next;
     }
}

void addNode(struct Employee** head)
{
     struct Employee* newNode=(struct Employee*)malloc(sizeof(struct Employee));
}

void addEmployee()
{
     int empNumber;
     char* empName;
     
     printf("Enter employee number : ");
     scanf(%d,&empNumber);
     printf("Enter employee name : ");
}

int main()
{
    int choice;
    struct Employee *node=NULL;
    
    do{
       printf("MENU\n");
       printf("1. Add Employee Record\n");
       printf("2. Display Employee Records\n");
       printf("9. EXIT\n");
       printf("Select your option (1..9) : ");
       scanf("%d", &choice);
       
       if(choice==1)
       {
       }
       
    }while(choice!=9);
    
    return 0;
}
