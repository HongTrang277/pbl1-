#include <bits/stdc++.h>

using namespace std;

struct ElementType {
    unsigned long CCCD; // CCCD của cổ đông
    char *shareHolder; // cổ đông
    char *StockSymbol; // Mã cổ phiếu
    unsigned long share; // số cổ phiếu
};

struct Node
{
    struct ElementType value;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node *List;
typedef struct Node *Position;


List createList()
{
    List headerNode = (Node*)malloc(sizeof (struct Node));
    headerNode->next = NULL;
    return headerNode;
}

Position insert(List *pL, struct ElementType e, Position p) {
    // vì phần tử trong list là kiểu Node*, nên nếu lấy struct Node làm kiểu biến thì phải thêm "*"
    struct Node *newItem = (Node*)malloc(sizeof(struct Node));

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

void listByStockSymbol(List pL, char *MaCoPhieu)
{
    int dontexist=0;
    cout << "Những người sở hữu cổ phiếu " << MaCoPhieu <<" !" << endl;
    while (pL!=NULL && pL->value.StockSymbol != MaCoPhieu )
    {
        if (pL!=NULL)
        {  
            cout << "*** " << " Tên | " <<  pL->value.shareHolder <<  " | - Mã số CCCD" << pL->value.CCCD << endl ;
            cout << "*** " << " Mã chứng khoán | " << pL->value.StockSymbol << " | - Số cổ phiếu : " << pL->value.share <<" ***" << endl;
        }
        if (dontexist)
            cout << "Không có dữ liệu !";

        pL = pL->next;
    }
}

Position findGreatestShare(List pL)
{
    Position MaxSharePos;
    MaxSharePos->value.share = pL->value.share;
    while (pL!=NULL)
        {
            if (pL->value.share > MaxSharePos->value.share)
                MaxSharePos =pL;  
            pL = pL->next;
        }
    return MaxSharePos;
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
    int count =1;
    while (pL!= NULL)
    {
        cout << endl;
        cout << "*** " << count << " Tên | " <<  pL->value.shareHolder <<  " | - Mã số CCCD" << pL->value.CCCD << endl ;
        cout << "*** " << " Mã chứng khoán | " << pL->value.StockSymbol << " | - Số cổ phiếu : " << pL->value.share <<" ***" << endl;
        count++;
        pL = pL->next;
    }
}
int main()
{
    List pL;

    struct ElementType item1 , item2, item3 ,item4, item5;
    item1.CCCD = 1603; item1.shareHolder = "Lê Ngọc Lâm Na"; item1.StockSymbol = "PNJ" ; item1.share = 4000;
    item2.CCCD = 2710; item2.shareHolder = "Nguyễn Thị Hồng Trang"; item2.StockSymbol = "KHDL" ; item2.share = 3000;
    item3.CCCD = 1234; item3.shareHolder = "Đoàn Hoàng Thiên Phú"; item3.StockSymbol = "PNJ" ; item3.share = 3999;
    item4.CCCD = 1235; item4.shareHolder = "Nguyễn Đỗ Thắng"; item4.StockSymbol = "Lo?" ; item4.share = 9999;
    item5.CCCD = 1236; item5.shareHolder = "Nguyễn Thái Ngọc Thảo"; item5.StockSymbol = "Nhat" ; item1.share = 1234;

    Position p;
    p= insert(&pL, item1, p);
    p= insert(&pL, item2, p);
    p= insert(&pL, item3, p);
    p= insert(&pL, item4, p);
    p= insert(&pL, item5, p);

    display(pL);

    p = findWithCCCD(pL,1235);

    if (p!=NULL)
    {  
        cout << "Found !" << endl;
        cout << "*** " << " Tên | " <<  pL->value.shareHolder <<  " | - Mã số CCCD" << pL->value.CCCD << endl ;
        cout << "*** " << " Mã chứng khoán | " << pL->value.StockSymbol << " | - Số cổ phiếu : " << pL->value.share <<" ***" << endl;
    }
    else 
        cout << "Not found !";

    listByStockSymbol(pL, "PNJ");

    p = findWithCCCD(pL,1235);
    
    Delete(p);
    cout << "The list after deletion" << endl;
    display(pL);
    return 0;
}