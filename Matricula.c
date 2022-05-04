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
    double porcent;    
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
 printf("\n |Name.......: %c", name);
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
    RA *aux;
    class = (CLASS *) malloc(sizeof (CLASS));
    aux = raList;
    while (aux->next != NULL)
    {
        aux = aux->next;
        
        if(aux->id[0] == gradeSchool){
            class->ra = aux;
            printf("\n |RA.........: %2.2i%2.2i ",class->ra->id[0],class->ra->id[1]);
        }
    }
    class->end = aux;
    class->gradeSchool = gradeSchool;

    if(class->ra == NULL){
        return NULL;
    }
    printf("\ndone CLASS %i", gradeSchool);
    return class;
}
void launchGradeSchool(RA *ra, double grade)
{   
    ra->student->score = grade;
    printf("\n ------------------");
    printName(ra->student->name);
    printf("\n |RA.........: %2.2i%2.2i ",ra->id[0],ra->id[1]);
    printf("\n |Score......: %2.2f ",ra->student->score);
    printf("\n ------------------\n\n");
}
REPORT *approvedFailed(int gradeSchool)
{
    REPORT *report;
    RA *ra, *aux; 
   report = (REPORT *) malloc(sizeof (REPORT));

     aux = raList;
     while (aux->next != NULL)
    {
        aux = aux->next;
        
        if(aux->id[0] == gradeSchool){
            ra = aux;
            printf("\n |RA.........: %2.2i%2.2i ",ra->id[0],ra->id[1]);
        }
    }
    report->end = aux;

    report->porcent = 4;
    return report;
}
void launchGradeClass(CLASS *class)
{   
    if(class->ra == NULL){
        return NULL;
    }

    RA *s = class->ra;
    while (s->next != NULL){ 
        printf("\n |RA.........: %2.2i%2.2i ",s->id[0],s->id[1]);
        printf("\n |RA.........: %2.2i%2.2i ",s->next->id[0],s->next->id[1]);
    launchGradeSchool(s, randomGrade());
        s = s->next;
    }
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
    while (countStudent <= 3)
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