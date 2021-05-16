#define TAM 5
typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}sEmployees;

int initEmployees(sEmployees[], int);//
int employeeEntry(sEmployees[], int);//
int findOpen(sEmployees[], int);//
int findLoaded(sEmployees[], int);//
void loadData(sEmployees[], int, int);//
sEmployees addEmployee(int, char[], char[], float, int);//
int findEmployeeById(sEmployees[], int, int);//
int removeEmployee(sEmployees[], int);//
int deleteEmployee(sEmployees);//
int sortEmployees(sEmployees[], int, int);//
int printEmployees(sEmployees[], int);
int findUsedID(sEmployees[], int, int);//
int modifyEmployee(sEmployees[], int);//
int requestID(char[], sEmployees[], int);//
int findIDPos(sEmployees[] ,int ,int);//
void printOneEmployee(sEmployees);//
sEmployees modifyMenu(sEmployees);//
void modifyName(char[], char[], char[]);//
float modifySalary(sEmployees);//
int modifySector(sEmployees);//
int VerifyChar(char[]);//
int verifyNumbers(char[]);//
int verifySpaces(char[]);//
int yesOrNo(int);
void AscendingOrder(sEmployees[], int);
void DescendingOrder(sEmployees[], int);
void CopyList(sEmployees[], sEmployees[], int);
void OrderBySector(sEmployees[], int);
void PrintEmployeesBySector(sEmployees[], int);
int sortMenu(sEmployees[], int);
int AverageSalary(sEmployees[], int);
void printOverAverage(sEmployees[], int, float);
int CountLoaded(sEmployees[], int);
int SumSalaries(sEmployees[], int);
