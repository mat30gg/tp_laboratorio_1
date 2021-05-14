typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}sEmployees;

int initEmployees(sEmployees[], int);
int employeeEntry(sEmployees[], int);
int findOpen(sEmployees[], int);
void loadData(sEmployees[], int, int);
int addEmployee(sEmployees, int, int, char[], char[], float, int);
int findEmployeeById(sEmployees[], int, int);
int removeEmployee(sEmployees[], int, int);
int sortEmployees(sEmployees[], int, int);
int printEmployees(sEmployees[], int);
