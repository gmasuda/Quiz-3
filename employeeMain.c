#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
    //defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryTofind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;  //Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else 
        printf("Employee Tony Bobcat is NOT found in the record\n");  
    
    //Phone Number found example
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("Employeee Number 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Number 909-555-2134 is NOT found in the record\n");
    
    //Phone Number NOT found example
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-456-7890");
    if (matchPtr != NULL)
        printf("Employeee Number 123-456-7890 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Number 123-456-7890 is NOT found in the record\n");

    //Salary found example
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);
    if (matchPtr != NULL)
        printf("Employee Salary 8.78 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Number 8.78 is NOT found in the record");

    //Salary NOT found example
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 1.11);
    if (matchPtr != NULL)
        printf("Employee Salary 1.11 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Number 1.11 is NOT found in the record");


    return EXIT_SUCCESS;
    //function to run code gcc employeeMain.c employeeTable.c employeeOne.c
}