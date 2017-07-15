#define N CountExaminee()
void welcome();							/*显示系统运行封面及考生人数*/
int MainMenu();							/*显示一级菜单,返回选择的菜单项值*/
int Menu2_1();							/*显示二级菜单,返回选择的菜单项值*/
int Menu2_2();							/*显示二级菜单,返回选择的菜单项值*/
int CountExaminee();					/*统计考生人数*/ 
void SubMenu2_1();						/*调用考生信息管理相关函数*/
void SubMenu2_2();						/*调用考生信息查询相关函数*/
void AddExaminee();						/*新增考生信息*/
//void shanchu();							/*删除考生信息*/
void SearchID();						/*查询身份证*/
void SearchName();						/*查询姓名*/
void SearchPhone();						/*查询联系电话*/
void Randomexnum(int *num);				/*产生随机考号*/
int IsIDExist(char *p);					/*判断是否已存在该身份证号码*/
int IsExnum(char *t);					/*判断是否已存在该考号*/
void IDTr(char *s,int *y,int *m,int *d,char id[19]);	/*身份证号码转换为性别出生年月日*/	
void IDTrB(char *b,char i[19]);							/*身份证号码转换为籍贯*/
void ShowAExaminee(char *x);							/*显示指定考生个人信息*/
void ShowExaminee();									/*显示所有考生信息*/ 
/*考生结构定义*/
struct student
{
	char ID[19];			/*考生身份证号码*/
	char name[8];			/*考生姓名*/
	char sex;				/*考生性别*/
	char phone[12];			/*考生联系电话*/
	int exnum;				/*考生考号*/
	char bithplace[20];		/*考生籍贯*/
	int year, month,day;	/*考生出生年月日*/
}; 
