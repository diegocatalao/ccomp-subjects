#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_STAFF_COUNT_SIZE         10

typedef struct _sStaff {
    char name[51];
    char registration[13];
    char address[66];
    char ssn[12];
    char cod_bank[4];
    char bank_agency[6];
    char bank_account[9];
    float hour_price;
    float payment;
} Staff;

typedef struct _sPayroll {
    char registration[13];
    int worked_hours;
} Payroll;

int swap_str_cpm(const void *, const void *);
void printf_staff(Staff *staff);

int main(int argc, char *argv[])
{
    FILE *fptr = NULL;
    char *lbuffer_char;
    Staff staff[MAX_STAFF_COUNT_SIZE];
    Payroll payroll;

    if ((fptr = fopen("assets/Funcionarios.txt", "r")) == NULL)
        assert((fptr != NULL) && "File not found.");

    for (int i = 0; i < MAX_STAFF_COUNT_SIZE; i++) {
        fgets(staff[i].name, sizeof(staff[i].name), fptr);
        fgetc(fptr);
        fgets(staff[i].registration, sizeof(staff[i].registration), fptr);
        fgetc(fptr);
        fgets(staff[i].address, sizeof(staff[i].address), fptr);
        fgetc(fptr);
        fgets(staff[i].ssn, sizeof(staff[i].ssn), fptr);
        fgetc(fptr);
        fgets(staff[i].cod_bank, sizeof(staff[i].cod_bank), fptr);
        fgetc(fptr);
        fgets(staff[i].bank_agency, sizeof(staff[i].bank_agency), fptr);
        fgetc(fptr);
        fgets(staff[i].bank_account, sizeof(staff[i].bank_account), fptr);
        fgetc(fptr);
        fscanf(fptr, "%f", &staff[i].hour_price);
        fgetc(fptr);
    }

    fclose(fptr);

    if ((fptr = fopen("assets/Novembro.txt", "r")) == NULL)
        assert((fptr != NULL) && "File not found.");

    for (int i = 0; i < MAX_STAFF_COUNT_SIZE; i++)
    {
        fscanf(fptr,
               "%12s/%d",
               payroll.registration,
               &payroll.worked_hours);
        
        for (int j = 0; j < MAX_STAFF_COUNT_SIZE; j++)
        {
            if (strcmp(staff[j].registration, payroll.registration) == 0)
            {
                staff[j].payment = staff[j].hour_price * payroll.worked_hours;
            }
        }
    }

    qsort(staff, MAX_STAFF_COUNT_SIZE, sizeof(staff[0]), swap_str_cpm);

    printf_staff(staff);

    fclose(fptr);

    return EXIT_SUCCESS;
}

void printf_staff(Staff *staff)
{
    for (int i = 0; i < MAX_STAFF_COUNT_SIZE; i++)
    {
        printf("%s|%s|%s|%s|%s|%s|%s|%.2f\n",
                staff[i].name,
                staff[i].registration,
                staff[i].address,
                staff[i].ssn,
                staff[i].cod_bank,
                staff[i].bank_agency,
                staff[i].bank_account,
                staff[i].payment);
    }
}

int swap_str_cpm(const void *first, const void *second)
{
    return strcmp(((Staff*) first)->name, ((Staff*) second)->name);
}