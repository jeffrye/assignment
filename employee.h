#define MAX 100

struct EmpData
{
int employee_number;
char name[MAX];
int salary;
char phone_number[MAX];
char address[MAX];
int department_number;
char department_name[MAX];
int OverallPerformance;
struct EmpData* next;
};

struct EmpData* find_id(struct EmpData* thead,int search)
{
       struct EmpData* temp;
       
       for (temp = thead; temp != NULL; temp = temp->next)
       {
             if (temp->employee_number == search)
                return temp;
       }
       return NULL;
}

void addEmp(struct EmpData** thead, int number,char name[MAX], int salary, char phone[MAX],char address[MAX],int deptNo,char deptName[MAX], int perf) 
{ 
    struct EmpData *new_node;
	new_node = (struct EmpData*)malloc(sizeof(struct EmpData));
	
	new_node->employee_number = number; 
	strcpy(new_node->name,name);
	new_node->salary=salary;
	strcpy(new_node->phone_number,phone);
	strcpy(new_node->address,address);
	new_node->department_number=deptNo;
	strcpy(new_node->department_name,deptName);
	new_node->OverallPerformance=perf;
	new_node->next = (*thead); 
	(*thead) = new_node; 
} 

struct EmpData* browse_perf(struct EmpData* thead,int search)
{
       struct EmpData* perfList=NULL;
       
       while (thead != NULL)
       {
             if(thead->OverallPerformance==search)
                addEmp(&perfList,thead->employee_number,thead->name,thead->salary,thead->phone_number,thead->address,thead->department_number,thead->department_name,thead->OverallPerformance);
             thead=thead->next;
       }
       return perfList;
}

int compare(struct EmpData* lst1, struct EmpData* lst2,int mode)
{
    int val1=0,val2=0;
    
    if(mode==6)
    {
       val1=lst1->employee_number;
       val2=lst2->employee_number;
    }
    else if(mode==7)
    {
         val1=lst1->OverallPerformance;
         val2=lst2->OverallPerformance;
    }
    else if(mode==8)
    {
         val1=lst1->salary;
         val2=lst2->salary;
    }
    if(val1<=val2)
       return 1;
    return 0;
}

struct EmpData* MergeSortedList(struct EmpData* lst1, struct EmpData* lst2,int mode) 
{ 
	struct EmpData* result = NULL; 

	if (lst1 == NULL) 
		return (lst2); 
	else if (lst2 == NULL) 
		return (lst1); 

	if (compare(lst1,lst2,mode)>0) { 
		result = lst1; 
		result->next = MergeSortedList(lst1->next, lst2,mode); 
	} 
	else { 
		result = lst2; 
		result->next = MergeSortedList(lst1, lst2->next,mode); 
	} 
	return result; 
} 

void SplitList(struct EmpData* source, struct EmpData** front, struct EmpData** back) 
{ 
	struct EmpData* ptr1; 
	struct EmpData* ptr2; 
	ptr2 = source; 
	ptr1 = source->next; 

	while (ptr1 != NULL) { 
		ptr1 = ptr1->next; 
		if (ptr1 != NULL) { 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
	} 
	*front = source; 
	*back = ptr2->next; 
	ptr2->next = NULL; 
} 

void MergeSort(struct EmpData** thead,int mode) 
{ 
	struct EmpData* head = *thead; 
	struct EmpData* ptr1; 
	struct EmpData* ptr2; 

	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	SplitList(head, &ptr1, &ptr2); 

	MergeSort(&ptr1,mode); 
	MergeSort(&ptr2,mode); 

	*thead = MergeSortedList(ptr1, ptr2,mode); 
} 
