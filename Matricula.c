#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define APPROVED 1
#define FAILED 2

int contClass1 , contClass2 , contClass3;
 
typedef struct ra{
    int id[2];
    int address;
} RA;

typedef struct student{
    RA *ra;
    char *name;
    double score;
    int serie;
    struct student *next;
} STUDENT;
typedef struct class{    
    int maxStudent;
    STUDENT *student;
    STUDENT *end;
    int gradeSchool;
    int address;
} CLASS;
typedef struct report{
    CLASS class;
    double porcent;    
} REPORT;
int randomGradeSchool()
{
    return rand() % 3;
}
int randomGrade()
{
    return rand() % 10;
}
char *randomName()
{
    int sizeName = rand() % 10 , i;
    char name[sizeName];
    for(i = 0; i < sizeName; i++){
        name[i] = (rand() % 26) + 65;
        printf("%c", name[i]);
    }
    return name;
}
STUDENT *schoolEnrollment(char *name, int gradeSchool)
{
    STUDENT *student;

     student = (STUDENT *) malloc(sizeof (STUDENT));

    student->name = name;
    student->serie = gradeSchool;
    student->score = 0;
    student->next = NULL;
    student->ra->address = &student;
    student->ra->id[0] = gradeSchool;

    if(gradeSchool == 1){
        student->ra->id[1] = contClass1 + 1;
        contClass1++;
    }else if(gradeSchool == 2){
        student->ra->id[1] = contClass2 + 1;
        contClass2++;
    }else if(gradeSchool == 3){
        student->ra->id[1] = contClass3 + 1;
        contClass3++;
    }

    printf("done!");

    return student;
}
CLASS *buildDiary(int gradeSchool)
{
    CLASS *class;

    class = (CLASS *) malloc(sizeof (CLASS));

    class->student= NULL;
    class->end = NULL;
    class->gradeSchool = gradeSchool;
    class->address = &class;

    return class;
}
void launchGradeSchool(RA *ra, double grade)
{
    printf("%f", grade);   
}
REPORT *approvedFailed(int gradeSchool)
{
    REPORT *report; 
    CLASS class;

    report = (REPORT *) malloc(sizeof (REPORT));

    report->porcent = 4;
    return report;
}
void launchGradeClass(CLASS *class)
{
    STUDENT *s = class->student;

    while (s != NULL){ 
                 
    launchGradeSchool(s->ra, randomGrade());
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

    while (countStudent <= 90)
    {
        s = schoolEnrollment(randomName(), randomGradeSchool());
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