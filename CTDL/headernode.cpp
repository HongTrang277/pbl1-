#include <bits/stdc++.h>

using namespace std;

struct ElementType {
    unsigned long ID;
    char *name;
};

struct Node
{
    struct ElementType value;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node *List;
typedef struct Node *Position;

Position find(List pL, unsigned long ID)
{
    while (pL!=NULL && pL->value.ID != ID)
        {
            pL = pL->next;
        }
    return pL;
}

void Delete(Position p)
{
    if (p==NULL) return;

    p->prev->next = p->next;
    if (p->next!= NULL)
        p->next->prev = p->prev;
}
Position insert(List *pL, struct ElementType e, Position p) {
    struct Node *newItem = (Node*)malloc(sizeof(struct Node));
    newItem->value = e;

    newItem->next = p->next;
    newItem->prev=p;
    p->next = newItem;
    newItem->next->prev = newItem;

    if (*pL==NULL || p==NULL){
        // Empty list, so insert to the first position
        newItem->next = NULL;
        *pL = newItem;
    } else {
        newItem->next = p->next;
        p->next = newItem;
    }
    return newItem;
}

List createList()
{
    List headerNode = (Node*)malloc(sizeof (struct Node));
    headerNode->next = NULL;
    return headerNode;
}

void display(List pL)
{
    int count =1;
    while (pL!= NULL)
    {
        cout << "*** " << count << " | " <<  pL->value.ID <<  " | " << pL->value.name << " ***\n";
        count++;
        pL = pL->next;
    }
}
int main()
{
    List pL;

// This is a normal struct, not a pointer struct
    struct ElementType item1 , item2, item3;
    item1.ID = 123;item1.name = "Nguyen Van A";
    item2.ID = 124;item2.name = "Nguyen Van B";
    item3.ID = 125;item3.name = "Nguyen Van C";

    Position p;
    p= insert(&pL, item1, p);
    p= insert(&pL, item2, p);
    p= insert(&pL, item3, p);

    display(pL);
    p = find(pL,124);
    if (p!=NULL)
        cout << "Found ! ID: " << p->value.ID << "  |  Name: " << p->value.name;
    else 
        cout << "Not found!";

Delete(p);
cout << "The list after deletion" << endl;
display(pL);
    return 0;
}