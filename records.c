#include <stdio.h>
#include <string.h>

typedef struct Employee{
    int emp_id;
    char emp_name[100];
    int nss;
    int emp_dept;
}Employee;


Employee getEmployee(); // Fonction qui retourne un employee


int main() {
	
	Employee emp;
	
	emp = getEmployee();
	
	printf("\n----------------------------------------\n");
	printf("Les informations de l'employee\n");
	printf("employee id : %d\n",emp.emp_id);
	printf("employee name : %s\n",emp.emp_name);
	printf("employee nss : %d\n",emp.nss);
    printf("employee department : %d\n",emp.emp_dept);
    printf("------------------------------------------\n");
    
    
    
    return 0;
}


Employee getEmployee(){
	
	Employee e;
	
	printf("Donner l'id de l'employee : ");
	scanf("%d",&e.emp_id);
	
	printf("Donner le nom de l'employee : ");
	getchar();  // Consume the newline character left by scanf
    fgets(e.emp_name, sizeof(e.emp_name), stdin);  // Read employee name
    e.emp_name[strcspn(e.emp_name, "\n")] = '\0'; // Remove the trailing newline character from fgets input (if any)
	
	printf("Donner le nss de l'employee : ");
	scanf("%d",&e.nss);
	
	printf("Donner le departement de l'employee : ");
	scanf("%d",&e.emp_dept);
	
	return e;	
}