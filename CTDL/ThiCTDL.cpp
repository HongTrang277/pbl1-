#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

using namespace std;

struct ElementType {
    unsigned long CCCD; // CCCD của cổ đông
    string shareHolder; // cổ đông
    string StockSymbol; // Mã cổ phiếu
    unsigned long share; // số cổ phiếu
};

struct Node
{
    struct ElementType value;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node* List;
typedef struct Node* Position;


List createList()
{
    List headerNode = new Node;
    headerNode->next = NULL;
    return headerNode;
}

Position insert(ElementType e, Position p) {
    // vì phần tử trong list là kiểu Node*, nên nếu lấy struct Node làm kiểu biến thì phải thêm "*"
    Position newItem = new Node;
    newItem->value = e;
    // Nếu insert số 5 vào vị trí thứ 2 trong 3 số 1,2,3 thì p ở vị trí thứ nhất, dãy sau khi insert: 1,5,2,3
    
    // Để Cắt liên kết giữa 1 và 2
    newItem->next = p->next; // nối liên kết 5->2 trước
    newItem->prev=p; // nối liên két 1<-5 
    p->next = newItem; // nối liên kết 1->5
    
    if (newItem->next!=NULL) // Nếu là phần tử cuối thì NULL không truy cập prev đến phần tử cuối danh sách
    {
        newItem->next->prev = newItem; // nối liên kết 5<-2 , do là ở vị trí p không còn gì trỏ vào 2, nên lấy newItem->next 
    }
    return newItem;
}

void listByStockSymbol(List pL, string MaCoPhieu)
{
    bool exist = false;
    cout << "Owners of " << MaCoPhieu <<" :" << endl;
    while (pL!=NULL)
    {
        if (pL!=NULL  && pL->value.StockSymbol == MaCoPhieu )
        {  
            exist = true;
            cout << "*** " << " Name | " <<  pL->value.shareHolder <<  " | - ID : " << pL->value.CCCD << endl ;
            cout << "*** " << " Stock Symbol | " << pL->value.StockSymbol << " | - Number of share : " << pL->value.share <<" ***" << endl;
        }
        pL = pL->next;
    }
    if (!exist)
        cout << "Không có dữ liệu !";
}

void findGreatestShare(List pL)
{
    Position MaxSharePos = new Node;
    Position temp = new Node;
    temp = pL->next;
    MaxSharePos->value.share = temp->value.share;
    while (temp!=NULL)
        {
            if (temp->value.share > MaxSharePos->value.share)
                MaxSharePos =temp;  
            temp = temp->next;
        }
    int count=1;
    while (pL!=NULL)
        {
            if (pL->value.share == MaxSharePos->value.share)
            {
                cout << "*** " << count << " Name | " <<  pL->value.shareHolder <<  " | - ID : " << pL->value.CCCD << endl ;
                cout << "*** " << " Stock Symbol | " << pL->value.StockSymbol << " | - Number of share : " << pL->value.share <<" ***" << endl;
                count++; 
            }
            pL = pL->next;
        }
}

Position findWithCCCD(List pL, unsigned long ID)
{
    while (pL!=NULL && pL->value.CCCD != ID)
        {
            pL = pL->next;
        }
    return pL;
}

void Delete(Position p)
{
    if (p==NULL) return; // danh sách trống

    p->prev->next = p->next; // gắn vị trí phía sau p, thành vị trí tiếp theo của vị trí trước p
    if (p->next!= NULL) // tại vì NULL không truy cập prev đến phần tử cuối danh sách, nên chỉ thực hiện khi phần tử sau p != NULL
        p->next->prev = p->prev;
}

void display(List pL)
{
    pL = pL->next;
    if (pL==NULL)
    {
        cout << "List is empty!";
        return;
    }
    int count =1;
    while (pL!= NULL)
    {
        cout << endl;
        cout << "*** " << count << " Name | " <<  pL->value.shareHolder <<  " | - ID : " << pL->value.CCCD << endl ;
        cout << "*** " << " Stock Symbol | " << pL->value.StockSymbol << " | - Number of share : " << pL->value.share <<" ***" << endl;
        count++;
        pL = pL->next;
    }
}
int main()
{
    List pL  = new Node;
    pL = createList();
    struct ElementType item1 , item2, item3 ,item4,item5;
    item1.CCCD = 1603; item1.shareHolder = "Lam Na"; item1.StockSymbol = "PNJ" ; item1.share = 4000;
    item2.CCCD = 2710; item2.shareHolder = "Hchang"; item2.StockSymbol = "KHDL" ; item2.share = 3000;
    item3.CCCD = 1234; item3.shareHolder = "Thu phien"; item3.StockSymbol = "PNJ" ; item3.share = 3999;
    item4.CCCD = 1235; item4.shareHolder = "Do Thang"; item4.StockSymbol = "Lo?" ; item4.share = 9999;
    item5.CCCD = 1235; item5.shareHolder = "Nguyễn Thái Ngọc Thảo"; item5.StockSymbol = "Nhat" ; item5.share = 9999;

    Position p ;
    p= insert(item1, pL);
    p= insert(item2, p);
    p= insert(item3, p);
    p= insert(item4, p);
    p= insert(item5, p);

    display(pL);

    listByStockSymbol(pL, "PNJ");

    cout << endl;

    findGreatestShare(pL);

    p = findWithCCCD(pL,1235);

    if (p!=NULL)
    {  
        cout << "Found !" << endl;
        cout << "*** " << " Name | " <<  p->value.shareHolder <<  " | - ID :" << p->value.CCCD << endl ;
        cout << "*** " << " Stock Symbol | " << p->value.StockSymbol << " | - Number of share : " << p->value.share <<" ***" << endl;
    }
    else 
        cout << "Not found !";
    
    Delete(p);
    cout << "The list after deletion" << endl;
    display(pL);
    delete(pL);
    return 0;
}