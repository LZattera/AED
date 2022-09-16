struct person{
    char name[30];
    int age;
};
typedef struct element* Person;

Person* RESET();
void CLEAR (Person *pe);
int EMPTY(Person *pe);
int PUSH(Person* pe, struct person al);
int POP(Person* pe);