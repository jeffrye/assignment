#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"


int selected_option;
void menu();
void calculation();
void add_emp();
void display();
void search_emp_id();
void search_overall_performance();
void sort_id();
void sort_salary();
void sort_overall_performance();
void modify();
void delete();
void salarySort();


struct EmpData *list=NULL;

void menu()
{
            printf("\nThese are the list of options for the Employee System");
            printf("\n1 Calculate Salary Package of an Employee");
            printf("\n2 Add an Employee Record");
            printf("\n3 Display All Records");
            printf("\n4 Search by Employee ID");
            printf("\n5 Search by Employee Overall Performance");
            printf("\n6 Sort and display by Employee ID in ascending order");
            printf("\n7 Sort and display by Employee Overall Performance in ascending order");
            printf("\n8 Sort and display by Employee Salary in ascending order");
            printf("\n9 Modify an Employee Record");
            printf("\n10 Delete an Employee Record");
            printf("\n11 Exit");
            printf("\n\nPlease enter a number to continue: ");
            scanf("%d", &selected_option);
}



void sort(int mode)
{
     MergeSort(&list,mode);
     display(list);
}


int main()
{
    addEmp(&list,1,"Jerry",1000,"123","rapp",1,"IT",2);
    addEmp(&list,2,"Andi",500,"123","rapp",1,"IT",3);
    addEmp(&list,3,"Budi",2000,"123","rapp",1,"IT",1);
            do
            {
                        menu();
                                    switch (selected_option)
                                    {
                                    case 1:calculation();
                                                break;
                                    case 2:add_emp();
                                                break;
                                    case 3:display(list);
                                                break;
                                    case 4:search_emp_id();
                                                break;
                                    case 5:search_overall_performance();
                                                break;
                                    case 6:  sort(6);
                                                break;
                                    case 7:  sort(7);
                                                break;
                                    case 8: salarySort();
                                    	 	display(list);
                                                break;
                                    case 9:
                                                break;
                                    case 10:
                                                break;
                                    case 11:printf("The program will end now");
                                                break;
                                    default:
                                                printf("\nInvalid option, please try again");
                                    }
            } while (selected_option != 11);
            return 0;
}

void calculation()
{
            float empsalary;
            float emprental;
            float empadmissible_allowances;
            float net_salary;
            printf("\nEnter employee salary: ");
            scanf("%f", &empsalary);
            printf("\nEnter employee house rent fee: ");
            scanf("%f", &emprental);
            printf("\nEnter other admissible allowance: ");
            scanf("%f", &empadmissible_allowances);
            net_salary = empsalary - emprental - empadmissible_allowances;
            printf("\nEmployee net salary:%.2f ", net_salary);
            printf("\n");
}

void add_emp()
{
            int number,salary,deptNo,perf;
            char *name,*phone,*address,*deptName;

            printf("Enter Employee's ID: ");
            scanf("%d", &number);
            printf("Enter Employee's name: ");
            scanf("%s", &name);
            printf("Enter Employee's Phone Number: ");
            scanf("%s", &phone);
            printf("Enter Employee's Address: ");
            scanf("%s", &address);
            printf("Enter Employee's Salary: ");
            scanf("%d", &salary);
            printf("Enter Department Number: ");
            scanf("%d", &deptNo);
            printf("Enter the Department Name: ");
            scanf("%s", &deptName);
            printf("Enter Employee's Overall Performance: ");
            scanf("%d", &perf);
            if (perf >= 1 && perf <= 4)
            {
               addEmp(&list,number,name, salary, phone,address,deptNo,deptName,perf);
            }
            else
            {
               printf("\nInput from 1-4");
               getch();
            }
}

void display(struct EmpData *tempdisplay)
{
    if (tempdisplay == NULL)
        printf("\n// List is empty //\n");
    else
    {
        while (tempdisplay != NULL)
        {
             printf("----------------------------------------\n");
             printf("Employee Number\t\t\t: %d\n", tempdisplay->employee_number);
             printf("Employee Name\t\t\t: %s\n", tempdisplay->name);
             printf("Employee Phone Number\t\t: %s\n", tempdisplay->phone_number);
             printf("Employee Address\t\t: %s\n", tempdisplay->address);
             printf("Employee Salary\t\t\t: %d\n", tempdisplay->salary);
             printf("Employee Department Number\t: %d\n", tempdisplay->department_number);
             printf("Employee Department Name\t: %s\n", tempdisplay->department_name);
             printf("Employee Overall Performance\t: %d\n", tempdisplay->OverallPerformance);
            tempdisplay = tempdisplay->next;
        }
    }
}

void salarySort()
{
	int number,salary,deptNo,perf;
    char name[100],phone[100],address[100],deptName[100];
    struct EmpData *current,*cek;
    
    for(current=list;current!=NULL;current=current->next)
	{
		for(cek=current->next;cek!=NULL;cek=cek->next)
		{
			if(cek->salary < current->salary)
			{
				number=current->employee_number;
				salary=current->salary;
				deptNo=current->department_number;
				perf=current->OverallPerformance;
				strcpy(name,current->name);
				strcpy(phone,current->phone_number);
				strcpy(address,current->address);
				strcpy(deptName,current->department_name);

				current->employee_number=cek->employee_number;
				current->salary=cek->salary;
				current->department_number=cek->department_number;
				current->OverallPerformance=cek->OverallPerformance;
				strcpy(current->name,cek->name);
				strcpy(current->phone_number,cek->phone_number);
				strcpy(current->address,cek->address);
				strcpy(current->department_name,cek->department_name);
				
				cek->employee_number=number;
				cek->salary=salary;
				cek->department_number=deptNo;
				cek->OverallPerformance=perf;
				strcpy(cek->name,name);
				strcpy(cek->phone_number,phone);
				strcpy(cek->address,address);
				strcpy(cek->department_name,deptName);
			}
		}
	}
}

void search_emp_id()
{
     int search;
     struct EmpData *temp;
     
     printf("\nEnter employee's ID to search in the data: ");
     scanf("%d", &search);
     temp=find_id(list,search);

     if (temp!=NULL)
     {
          printf("----------------------------------------\n");
          printf("Employee Name: %s \n", temp->name);
          printf("Employee ID number: %d \n", temp->employee_number);
          printf("Employee Salary: %d \n", temp->salary);
          printf("Employee Address: %s \n", temp->address);
          printf("Employee Phone Number: %d \n", temp->phone_number);
          printf("Employee Department Name: %s \n", temp->department_name);
          printf("Employee Department Number: %d \n", temp->department_number);
          printf("Employee Overall Performance: %d \n", temp->OverallPerformance);
          printf("End of employee details\n");
      }
      else
      {
           printf("Employee not found\n");
      }
}

void search_overall_performance()
{
     int search;
     struct EmpData *temp;
     
     printf("\nEnter employee's overall performance to search in the data: ");
     scanf("%d", &search);
     temp=browse_perf(list,search);   
     display(temp);                
}
