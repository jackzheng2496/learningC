typedef struct student {
    int age;
    char *name;
    char *school;
    
    void (*set_name)(struct student* , char *);
    void (*set_school)(struct student* , char *);
    void (*set_age)(struct student*, int);
} student_t;

void student_t_set_name(student_t *student, char *name)
{
    assert(student != NULL);
    student->name = strdup(name);
}

void student_t_set_school(student_t *student, char *school)
{
    assert(student != NULL);
    student->school = strdup(school);
}

void student_t_set_age(student_t *student, int age)
{
    assert(student != NULL);
    student->age = age;
}

student_t *make_student()
{
    student_t *student = malloc(sizeof(student_t));
    memset(student, 0, sizeof(student_t));
    
    student->set_name = student_t_set_name;
    student->set_school = student_t_set_school;
    student->set_age = student_t_set_age;
    
    return student;
}

int main(void)
{
    student_t *student = make_student();
    
    student->set_name(student, "Jack Zheng");
    student->set_school(student, "SBU");
    student->set_age(student, 20);
    
    return 0;
}
