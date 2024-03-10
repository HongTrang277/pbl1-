#include <bits/stdc++.h>

const int MAX_SIZE = 100;
using namespace std;

struct ElementType{
    unsigned long ID;
    char *name;
};

typedef struct ElementType *Student;
typedef int Position;
struct ListInfo{
    int maxsize;
    int count;
    Student list;
};

typedef struct ListInfo *StudentList;

StudentList create(int maxsize)
{
    StudentList L = (StudentList)malloc(sizeof( struct ListInfo));
    L->count = 0;
    L->maxsize = maxsize;
    L->list = (Student)malloc(maxsize*sizeof(struct ElementType));
    return L;
}

void insert(StudentList L, Student s, Position p = 0)
{
    
    Position current;
    if (p > L->count  || L->count == L->maxsize) exit(1);
        current = L ->count;
    while (current != p)
    {
        L->list[current] = L->list[current-1];
        current--;
    }
    L->list[current] = *s;
    L->count++;
}

void display(StudentList L)
{
    for (Position p= 0; p<L->count;p++)
        cout << "*** " << p+1 << " | " << L->list[p].ID << "     | " << L->list[p].name << " ***" <<endl ;
}

Student find(StudentList L, unsigned long ID)
{
    for (Position p = 0; p < L->count; p++)
        if(L->list[p].ID == ID)
            return &L->list[p];
    return NULL;
}


// int Empty_List(StudentList L)
// {
//     return (L->Next==NULL);
// }


int main()
{
    StudentList Class13;
    Class13 = create(MAX_SIZE);

    Student std1 = (Student)malloc(sizeof(struct ElementType));
    Student std2 = (Student)malloc(sizeof(struct ElementType));
    Student std3 = (Student)malloc(sizeof(struct ElementType));

    std1->ID = 200301;
    std1->name = "Phan Thanh Trường";
    std2->ID = 200302;
    std2->name = "Nhue";
    std3->ID = 200303;
    std3->name = "sbd";

    insert(Class13,std1);
    insert(Class13,std2);
    insert(Class13,std3);

    display(Class13);

    std3 = find(Class13, 200303);
    if (std3 !=NULL)
        {
        cout << "*** Found! ***" << endl;
        cout << std3->name;
        }
    else 
        cout << "*** Error 404 ***";
    free(Class13);
    return 0;
}