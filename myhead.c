#define EXAMINEE sizeof(struct student)
void Welcome();			/*��ʾϵͳ���з��漰��������*/
int MainMenu();			/*��ʾһ���˵�,����ѡ��Ĳ˵���ֵ*/
int Menu2_1();			/*��ʾ�����˵�,����ѡ��Ĳ˵���ֵ*/
int Menu2_2();			/*��ʾ�����˵�,����ѡ��Ĳ˵���ֵ*/
void SubMenu2_1();		/*���ÿ�����Ϣ������غ���*/
void SubMenu2_2();		/*���ÿ�����Ϣ��ѯ��غ���*/
void AddExaminee();		/*����������Ϣ*/
void ModifyExaminee();	/*�޸Ŀ�����Ϣ*/
void DelExaminee();		/*ɾ��������Ϣ*/
void SearchID();		/*��ѯ���֤*/
void SearchName();		/*��ѯ����*/
void SearchSex();		/*��ѯ�Ա�*/
void SearchPhone();		/*��ѯ��ϵ�绰*/
void SearchExnum();		/*��ѯ����*/
void SearchBithplace();	/*��ѯ����*/
void SearchYMD();		/*��ѯ����������*/
int IsIDExist();			/*�ж��Ƿ��Ѵ��ڸ����֤����*/
int IsExnum();				/*�ж��Ƿ��Ѵ��ڸÿ���*/
void ShowAExaminee(char*);	/*��ʾָ�����ŵĿ�����Ϣ*/
/*�����ṹ����*/
struct student
{
	char ID[19];		/*�������֤����*/
	char name[8];		/*��������*/
	char sex;			/*�����Ա�*/
	char phone[12];		/*������ϵ�绰*/
	char exnum[10];		/*��������*/
	char bithplace[10];	/*��������*/
	int year,month,day;	/*��������������*/
}��