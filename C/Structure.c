#include <stdio.h>

/* struct student
{
    int roll_no;
    int sem;
    char name[10];
};

int main()
{
    struct student s1;           // struct student s1, s2, s3.................;
    printf("Enter Roll Number, Semester and name of student\n");
    scanf("%d %d %s", &s1.roll_no, &s1.sem, s1.name);

    printf("Roll No.: %d\nSem: %d\nName: %s", s1.roll_no, s1.sem, s1.name);

    return 0;
} */

/* typedef struct
{
    int roll_no;
    int sem;
    char name[10];
}stu;


int main()
{
    stu s1;                 // stu s1, s2, s3............;
    printf("Enter Roll Number, Semester and name of student\n");
    scanf("%d %d %s", &s1.roll_no, &s1.sem, s1.name);

    printf("Roll No.: %d\nSem: %d\nName: %s", s1.roll_no, s1.sem, s1.name);

    return 0;
}*/

/* struct student
{
    int roll_no;
    int sem;
    char name[10];
};

struct student s1;           // struct student s1, s2, s3..............;


int main()
{
    printf("Enter Roll Number, Semester and name of student\n");
    scanf("%d %d %s", &s1.roll_no, &s1.sem, s1.name);

    printf("Roll No.: %d\nSem: %d\nName: %s", s1.roll_no, s1.sem, s1.name);

    return 0;
} */

/*struct
{
    int roll_no;
    int sem;
    char name[10];
}s1;                       // }s1, s2, s3...........;

int main()
{
    printf("Enter Roll Number, Semester and name of student\n");
    scanf("%d %d %s", &s1.roll_no, &s1.sem, s1.name);

    printf("Roll No.: %d\nSem: %d\nName: %s", s1.roll_no, s1.sem, s1.name);

    return 0;
}*/

/* typedef struct
{
    int roll_no;
    int sem;
    char name[10];
}stu;              // }stu s1, s2, s3.......;         --->   this will gave error

stu s1;           // stu s1, s2, s3........;

int main()
{
    printf("Enter Roll Number, Semester and name of student\n");
    scanf("%d %d %s", &s1.roll_no, &s1.sem, s1.name);

    printf("Roll No.: %d\nSem: %d\nName: %s", s1.roll_no, s1.sem, s1.name);

    return 0;
} */

/* int main()
{
    struct student
    {
        int roll_no;
        int sem;
        char name[10];
    };

    struct student s1; // struct student s1, s2, s3.................;
    printf("Enter Roll Number, Semester and name of student\n");
    scanf("%d %d %s", &s1.roll_no, &s1.sem, s1.name);

    printf("Roll No.: %d\nSem: %d\nName: %s", s1.roll_no, s1.sem, s1.name);

    return 0;
}

struct student s2;     // we cannot create variale outside main function because struct student declared in      
                       // main function

*/