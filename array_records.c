#include <stdio.h>

typedef struct Employee{
    int emp_id;
    char emp_fname[50];
    char emp_lname[50];
    int emp_dept;
} Employee;


void fillEmployeeArray(Employee employees[], int *n); // Function to fill the array of employee records
void displayEmployeeArray(Employee employees[], int n); // Function to display the array of employee records


int main() {
	
    int n;
    
    Employee employees[5];

    fillEmployeeArray(employees, &n);  // Fill the array with employee details
    
    displayEmployeeArray(employees, n);  // Display the array of employee details

    return 0;
}


void fillEmployeeArray(Employee employees[], int *n) {
	
    char choice;
    
    *n = 0;  // Initialize the employee count

    do {
        printf("Enter details for Employee %d:\n", *n + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[*n].emp_id);
        printf("First Name: ");
        scanf("%s", employees[*n].emp_fname);
        printf("Last Name: ");
        scanf("%s", employees[*n].emp_lname);
        printf("Department ID: ");
        scanf("%d", &employees[*n].emp_dept);

        (*n)++;  // Increment employee count
        
        printf("Would you like to enter another employee? (y/n): ");
        scanf(" %c", &choice);  // Notice the space before %c to skip any leftover newline character

    } while (choice == 'y' || choice == 'Y');
}

void displayEmployeeArray(Employee employees[], int n) {
	
    printf("\nEmployee Details:\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Employee ID: %d\n", employees[i].emp_id);
        printf("First Name: %s\n", employees[i].emp_fname);
        printf("Last Name: %s\n", employees[i].emp_lname);
        printf("Department ID: %d\n", employees[i].emp_dept);
        printf("------------------------------------------------------\n");
    }
}