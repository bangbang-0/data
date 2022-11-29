
//1.������

#include<iostream>

using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data;          //����������
    LNode *next;     //����ָ����
} LNode, *LinkList;
void ListDisplay(LinkList &L);
//��1����ʼ���������޲κ��вΣ���
LinkList CreateList(int i = 0) { //����Ĭ��Ϊ0 ,���в�������,��������������,Ĭ��β�巨
    LinkList head = new LNode, p;//����ͷ���head �Ͳ���ָ��
    p = head; //��ֵ������ָ��
    head->next = nullptr; //�ÿ�
    if (i != 0) { //�вι���
        for (int j = 0; j < i; j++) {
            auto s = new LNode;  //�����½��
            cout << "�����" << j + 1 << "����" << endl;
            cin >> s->data; //�����������
            p->next = s;  //���½��ĵ�ַ��������ָ���next,��������
            p = s;   //�൱�� p=p->next �ƶ�����ָ�뵽���һ�����
        }
        p->next = nullptr;//β����ÿ�
    } else { //�޲ι��캯�� ,Ĭ�Ϲ���1-10
        for (int j = 0; j < 10; j++) {
            auto s = new LNode;
            s->data = j + 1; //��ֵ
            p->next = s; //����
            p = s; //�ƶ�ָ��
        }
        p->next = nullptr;//�ÿ�
//        cout << "�����뵥�����е�����Ԫ�أ�����-1ʱ�������������������" << endl;
//        int x;
//        cin >> x;
//        while (x != -1) {
//            auto s = new LNode;
//            s->data = x;
//            p->next = s;
//            p = s;
//            cin >> x;
//        }
//        p->next = nullptr;
    }
    return head;
}

//��2���������ȣ�
void Listlenth(LinkList L) {
    int i = 0;//��¼����
    LinkList p = L->next;
    while (p) {//����ֱ�� p==nullptr
        p = p->next;
        i++;//������++
    }
    cout << "length:" << i << endl;//��ӡ����
}

//��3����λ�ò��ң�
ElemType GetElem(LinkList &L, int i) {//��λ�ò���,˳����ң�ƽ��ʱ�临�Ӷ�ΪO��n��
    LinkList p = L->next;
    int j = 1;//������
    while (p && j < i) {//����ֱ��pָ��ָ���i��Ԫ�صĽ��
        p = p->next;
        ++j;
    }
    if (p == nullptr) { //��ֹ�����λ�������ڽ����
        cout << "λ�ò��Ϸ�,��������:" << endl;
        int x;
        cin >> x;
        GetElem(L, x);//���µ��ú���
    }
    else {
        cout<<"��"<<i<<"��Ԫ��Ϊ"<<p->data<<endl;
        return p->data;
    }
}

//��4����ֵ���ң�
LinkList LocateElem(LinkList &L, ElemType e) {//��ֵ����,˳����ң�ƽ��ʱ�临�Ӷ�ΪO��n��
    LinkList p = L->next;
    int x = 1;
    while (p && p->data != e) {//����ֱ��pָ���ֵ���ڵĽ��
        p = p->next;//�ƶ�
        ++x;
    }
    if (!p) {
        cout << "�������޴�Ԫ��" << endl;
        return nullptr;//���ؿ�ָ��
    } else {
        cout << "��Ԫ���������" << x<< "��" << endl;
        return p;
    }
}

//��5����λ��i����һ������Ԫ�أ�
void ListInsert(LinkList &L, int i, ElemType e) {//��λ��i����һ������Ԫ�أ������Ϊi-1�Ľ�������㣬ƽ��ʱ�临�Ӷ�ΪO��n��
    LinkList p = L;//ָ��ֱ��ָ��ͷ���,�Ա���λ��0������
    int j = 0;
    while (p && j < i) {//ָ���ƶ���iλ��ǰ
        ++j;
        p = p->next;
    }
    if (p) {
        auto s = new LNode;//�½����
        s->next = p->next; //�ýڵ㱣�� p��next��ָ��ĵ�ַ
        p->next = s; //ˢ��p->next ��s�ĵ�ַ��ֵ��p
        s->data = e; //s����ɹ� ,��ֵ
        cout << "����ɹ�" << endl;
        ListDisplay(L);
    } else
        cout << "����ʧ��" << endl;
}

//��6��ɾ��λ��i������Ԫ�أ�
void ListDelete(LinkList &L, int i) {//ɾ��λ��i��һ������Ԫ��,ƽ��ʱ�临�Ӷ�ΪO��n��
    LinkList p = L->next;
    int j = 1;//������
    while (p && j < i - 1) {//�ƶ�ָ�뵽Ҫɾ���Ľ�����һ�����
        ++j;
        p = p->next;
    }
    if (p) {//�жϸý���Ƿ����
        LinkList s;
        s = p->next; //��Ҫɾ���Ľ��
        p->next = s->next;//��Ҫɾ���Ľ���nextָ�뱣��ĵ�ַת��
        delete s;//ɾ�����
        cout << "ɾ���ɹ�" << endl;
        ListDisplay(L);
    } else cout << "ɾ��ʧ��" << endl;
}

//��7������������
void ListDisplay(LinkList &L) {//����
    LinkList p = L->next;
    while (p) {
        cout << p->data << "->";
        p = p->next;//�ƶ�ָ��
    }
    cout << "null" << endl;
}

//��8���ϲ�����
LinkList MergeList(LinkList &LA, LinkList &LB) {
    LinkList p = LA;//��������ָ��
    while (p->next) {
        p = p->next;
    }//�ƶ�����ָ�뵽β���
    p->next = LB->next;//β����nextָ�� LBͷָ��ĵ�һ�����
    delete LB;//ɾ������ͷ���
    return LA;
}

//��9�����ٵ�����
void del(LinkList &L) {
    LinkList tmp;
    while (L->next != nullptr) {
        tmp = L->next;
        delete L; // �����ͷŽ�㡣
        L = tmp;
    }
    L = nullptr; // ������ָ���ÿա�
    cout << "������ɾ��";
}

int main() {
    LinkList s = CreateList();//�޲ι���
    ListDisplay(s);//����չʾ����
    Listlenth(s);//�������ĳ���
    int i, e;
    i = 5;
    GetElem(s, i);//��λ�ò��ҵ�5��Ԫ��
    i = 7;
    LocateElem(s, i);//��ֵ����Ԫ��7
    i =0,e=0;
    cout<<"��0λ�ò���ֵ0"<<"......";
    ListInsert(s, i, e);//��0λ�ò���ֵ0
    i=11;
    cout<<"ɾ����11λ�õĽ��"<<"......";
    ListDelete(s, i);//ɾ����11λ�õĽ��
    cout<<"����������"<<endl;
    LinkList b = CreateList(3);//�вι���
    MergeList(s, b); //�ϲ�����
    cout<<"�ϲ���:"<<endl;
    ListDisplay(s);
    del(s); //ɾ������
    return 0;
}