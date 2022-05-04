#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define APPROVED 1
#define FAILED 2
typedef struct student{
    char *name;
    double score;
    int serie;
} STUDENT;
typedef struct ra{
    int id[2];
    STUDENT *student;
    struct ra *next;
} RA;
typedef struct class{    
    RA *ra;
    RA *end;
    int gradeSchool;
} CLASS;
typedef struct report{
    RA *ra;
    RA *end;  
} REPORT;

int contClass1 , contClass2 , contClass3;
RA *raList;


int randomGradeSchool()
{
    return rand() % 3;
}
int randomGrade()
{
    return rand() % 10;
}
void initRaList(RA *raList){
    raList = (RA *) malloc(sizeof (RA));
    raList->id[0] = 0;
    raList->id[1] = 0;
    raList->student = NULL;
    raList->next = NULL;
}
char *randomName()
{
    int sizeName = rand() % 10 , i;
    char name[sizeName];
    for(i = 0; i < sizeName; i++){
        name[i] = (rand() % 26) + 65;
        printf(" %c", name[i]);
    }
    return name;
}
void printName(char *name){


    printf("\n |Name.......:");
    printf("%p", name);
    
    

}
STUDENT *schoolEnrollment(char *name, int gradeSchool)
{
    STUDENT *student;
    RA *ra , *aux;
    student = (STUDENT *) malloc(sizeof (STUDENT));
    ra = (RA *) malloc(sizeof (RA));
    student->name = name;
    student->serie = gradeSchool;
    student->score = 0;
    ra->student = student;
    ra->next = NULL;
    gradeSchool++;
    ra->id[0] = gradeSchool;
    if(gradeSchool == 1){
        ra->id[1] = contClass1 + 1;
        contClass1++;
    }else if(gradeSchool == 2){
        ra->id[1] = contClass2 + 1;
        contClass2++;
    }else if(gradeSchool == 3){
        ra->id[1] = contClass3 + 1;
        contClass3++;
    }else{
        return NULL;
    }
    aux = raList;
    raList = ra;
    raList->next = aux;
    printf("\n ------------------");
    printName(ra->student->name);
    printf("\n |RA.........: %2.2i%2.2i ",ra->id[0],ra->id[1]);
    printf("\n ------------------\n\n");

    
    return student;
}
CLASS *buildDiary(int gradeSchool)
{
    CLASS *class;
    RA *aux , *ant;
    class = (CLASS *) malloc(sizeof (CLASS));
    aux = raList;

    printf("\nCLASS---------%i", gradeSchool);
    while (aux != NULL)
    {
        ant = aux;
        if(aux->id[0] == gradeSchool && aux->student->name >=ant->student->name){
            
            printf("\n |RA.........: %2.2i%2.2i ",aux->id[0],aux->id[1]);
            if(aux->id[1] == 1){
            class->ra = aux;
            }
        }
        aux = aux->next;
        class->end = aux;
    }
    
    class->gradeSchool = gradeSchool;

    printf("\n--------------%i\n\n", gradeSchool);
    return class;
}
void launchGradeSchool(RA *ra, double grade)
{   
    ra->student->score = grade;
    printf("\n ------------------");
    printf("\n |RA.........: %2.2i%2.2i ",ra->id[0],ra->id[1]);
    printf("\n |Score......: %2.2f ",ra->student->score);
    printf("\n ------------------\n\n");
}
REPORT *approvedFailed(int gradeSchool)
{
    REPORT *report;
    RA *aux; 
    
    report = (REPORT *) malloc(sizeof (REPORT));

     aux = raList;
     while (aux != NULL){
        if(aux->id[0] == gradeSchool){
            printf("\n |RA.........: %2.2i%2.2i ",aux->id[0],aux->id[1]);
            if (aux->student->score >= 6){
            printf(" |Score......: APROVED ");
            }else{
            printf(" |Score......: REPROVED ");    
            }
            
        }
        aux = aux->next;
    }
    report->end = aux;
    return report;
}
void launchGradeClass(CLASS *class)
{   
    RA *s;
    s = raList;
     while (s != NULL){
        if(s->id[0] == class->gradeSchool){
           launchGradeSchool(s, randomGrade());
        }
        s = s->next;
    }
    return;
}
int main()
{
    CLASS *c1, *c2, *c3;
    REPORT *r1, *r2, *r3;
    STUDENT *s;
    int countStudent = 0; 
    contClass1 = 0;
    contClass2 = 0;
    contClass3 = 0;
    initRaList(raList);
    while (countStudent <= 2)
    {
        s = schoolEnrollment(randomName(), randomGradeSchool());
        countStudent++;
    }
    c1 = buildDiary(1);
    c2 = buildDiary(2);
    c3 = buildDiary(3);
    launchGradeClass(c1);
    launchGradeClass(c2);
    launchGradeClass(c3);
    r1 = approvedFailed(1);
    r2 = approvedFailed(2);
    r3 = approvedFailed(3);
    return 0;
}