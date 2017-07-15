#define EXAMINEE sizeof(struct student)
void Welcome();			/*显示系统运行封面及考生人数*/
int MainMenu();			/*显示一级菜单,返回选择的菜单项值*/
int Menu2_1();			/*显示二级菜单,返回选择的菜单项值*/
int Menu2_2();			/*显示二级菜单,返回选择的菜单项值*/
void SubMenu2_1();		/*调用考生信息管理相关函数*/
void SubMenu2_2();		/*调用考生信息查询相关函数*/
void AddExaminee();		/*新增考生信息*/
void ModifyExaminee();	/*修改考生信息*/
void DelExaminee();		/*删除考生信息*/
void SearchID();		/*查询身份证*/
void SearchName();		/*查询姓名*/
void SearchSex();		/*查询性别*/
void SearchPhone();		/*查询联系电话*/
void SearchExnum();		/*查询考号*/
void SearchBithplace();	/*查询籍贯*/
void SearchYMD();		/*查询出生年月日*/
int IsIDExist();			/*判断是否已存在该身份证号码*/
int IsExnum();				/*判断是否已存在该考号*/
void ShowAExaminee(char*);	/*显示指定考号的考生信息*/
/*考生结构定义*/
struct student
{
	char ID[19];		/*考生身份证号码*/
	char name[8];		/*考生姓名*/
	char sex;			/*考生性别*/
	char phone[12];		/*考生联系电话*/
	char exnum[10];		/*考生考号*/
	char bithplace[10];	/*考生籍贯*/
	int year,month,day;	/*考生出生年月日*/
}；