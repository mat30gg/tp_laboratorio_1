#define TAM 1000
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}sEmployees;

void HardcodearEmpleados(sEmployees[]);

int initEmployees(sEmployees[], int);//
int employeeEntry(sEmployees[], int);//
int findOpen(sEmployees[], int);//
int findLoaded(sEmployees[], int);//
void loadData(sEmployees[], int, int);//
sEmployees addEmployee(int, char[], char[], float, int);//
int findEmployeeById(sEmployees[], int, int);//
int removeEmployee(sEmployees[], int, int);//
int deleteEmployee(sEmployees);//
int sortEmployees(sEmployees[], int, int);//
int printEmployees(sEmployees[], int);
int findUsedID(sEmployees[], int, int);//
int modifyEmployee(sEmployees[], int);//
int requestID(char[], sEmployees[], int);//
void printOneEmployee(sEmployees);//
sEmployees modifyMenu(sEmployees);//
void modifyName(char[], char[], char[]);//
float modifySalary(sEmployees);//
int modifySector(sEmployees);//

void Swap(sEmployees[], int, int);
void CopyList(sEmployees[], sEmployees[], int);
void OrderBySector(sEmployees[], int);
int sortMenu(sEmployees[], int);
int AverageSalary(sEmployees[], int);
void printOverAverage(sEmployees[], int, float);
int CountLoaded(sEmployees[], int);
float SumSalaries(sEmployees[], int);
float GetAverage(float, int);
