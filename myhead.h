#define N CountExaminee()
void welcome();							/*��ʾϵͳ���з��漰��������*/
int MainMenu();							/*��ʾһ���˵�,����ѡ��Ĳ˵���ֵ*/
int Menu2_1();							/*��ʾ�����˵�,����ѡ��Ĳ˵���ֵ*/
int Menu2_2();							/*��ʾ�����˵�,����ѡ��Ĳ˵���ֵ*/
int CountExaminee();					/*ͳ�ƿ�������*/ 
void SubMenu2_1();						/*���ÿ�����Ϣ������غ���*/
void SubMenu2_2();						/*���ÿ�����Ϣ��ѯ��غ���*/
void AddExaminee();						/*����������Ϣ*/
//void shanchu();							/*ɾ��������Ϣ*/
void SearchID();						/*��ѯ���֤*/
void SearchName();						/*��ѯ����*/
void SearchPhone();						/*��ѯ��ϵ�绰*/
void Randomexnum(int *num);				/*�����������*/
int IsIDExist(char *p);					/*�ж��Ƿ��Ѵ��ڸ����֤����*/
int IsExnum(char *t);					/*�ж��Ƿ��Ѵ��ڸÿ���*/
void IDTr(char *s,int *y,int *m,int *d,char id[19]);	/*���֤����ת��Ϊ�Ա����������*/	
void IDTrB(char *b,char i[19]);							/*���֤����ת��Ϊ����*/
void ShowAExaminee(char *x);							/*��ʾָ������������Ϣ*/
void ShowExaminee();									/*��ʾ���п�����Ϣ*/ 
/*�����ṹ����*/
struct student
{
	char ID[19];			/*�������֤����*/
	char name[8];			/*��������*/
	char sex;				/*�����Ա�*/
	char phone[12];			/*������ϵ�绰*/
	int exnum;				/*��������*/
	char bithplace[20];		/*��������*/
	int year, month,day;	/*��������������*/
}; 
