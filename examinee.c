#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include"myhead.h"
#include"menu.h"

void main()
{
	int menuid;									/*定义将主菜单的返回值存储的变量*/
	system("mode con cols=125 lines=40");		/*设置窗口宽度高度*/					
	welcome();									/*调用运行封面函数*/
	while(1)
	{
		menuid=MainMenu();						/*一级菜单选项选择*/
		if(menuid==0)
		{
			printf("\n程序结束\n");
			break;
		}
		switch(menuid)
		{
			case 1:SubMenu2_1();break;
			case 2:SubMenu2_2();break;
		}
	}
}
void welcome()								/*进入系统界面*/
{
	system("cls");							/*清屏*/
	system("color 0A");
	printf("\t\t\t\t\t  ╔═════════════╗\n");
	printf("\t\t\t\t\t  ║  **********************  ║\n");
	printf("\t\t\t\t\t  ║  **********************  ║\n");
	printf("\t\t\t\t\t  ║  **   考生信息系统   **  ║\n");
	printf("\t\t\t\t\t  ║  **********************  ║\n");
	printf("\t\t\t\t\t  ║  **********************  ║\n");
	printf("\t\t\t\t\t  ╚═════════════╝\n");
	system("pause");
}

void SubMenu2_1()							/*二级菜单 信息管理 选项选择*/
{
	int menuid;
	while(1)
	{
		menuid=Menu2_1();					/*调用二级菜单显示界面*/
		if(menuid==0)
			break;
		switch(menuid)
		{
			case 1:AddExaminee();break;
			//case 2:shanchu();break;
		}
	}
}
void SubMenu2_2()							/*二级菜单 信息查询 选项选择*/
{
	int menuid;
	while(1)
	{
		menuid=Menu2_2();					/*调用二级菜单显示界面*/
		if(menuid==0)
			break;
		switch(menuid)
		{
			case 1:SearchName();break;
			case 2:SearchID();break;
			case 3:SearchPhone();break;
			case 4:ShowExaminee();break;
		}
	}
}
int CountExaminee()							/*统计考生人数*/
{
	struct student examtemp;				/*定义结构体变量*/
	FILE *fp;								/*定义文件指针*/
	int count=0;
	if((fp=fopen(".\\examinee.txt","r"))==NULL)	/*打开文件*/
		return 0;
	else
	{
		while((fscanf(fp,"%s%s%s",examtemp.name,examtemp.phone,examtemp.ID))!=EOF)		/*考生数量累加统计*/
			count++;
	}
	fclose(fp);
	return count;
}
void AddExaminee()							/*新增考生信息*/
{
	FILE *fp;
	struct student myexaminee;				/*定义结构体变量*/
	printf("\n新增考生信息（按提示输入信息）\n");
	printf("考生姓名：\n");					
	gets(myexaminee.name);					/*输入数据*/
	printf("考生联系电话：\n");
	gets(myexaminee.phone);					/*输入数据*/
	printf("考生身份证号码：\n");
	gets(myexaminee.ID);					/*输入数据*/
	while(IsIDExist(myexaminee.ID))			/*对输入的数据进行判断并重新输入*/
	{
		printf("新增考生身份证号码%s已存在，重新输入!\n",myexaminee.ID);
		printf("考生身份证号码：\n");
		gets(myexaminee.ID);				/*重新输入正确数据*/
	}
	
	fp=fopen(".\\examinee.txt","a+");
	if((fp=fopen(".\\examinee.txt","a+"))==NULL)
	{
		printf("打开文件错误!\n");
		exit(0);
	}
	fprintf(fp,"%s\t%s\t%s\n",myexaminee.name,myexaminee.phone,myexaminee.ID);	/*向文本文件存入新增考生信息*/
	fclose(fp);
	printf("新增考生信息成功!\n");
	system("pause");
	flushall();
}
int IsIDExist(char *p)								/*判断身份证号码存在*/
{
	int i;
	struct student myexaminee;						/*定义结构体变量*/
	FILE *fp;
	fp=fopen(".\\examinee.txt","r");
	while((fscanf(fp,"%s%s%s",myexaminee.name,myexaminee.phone,myexaminee.ID))!=EOF)	
	{
		if(strcmp(myexaminee.ID,p)!=0 )				/*在文件中寻找是否有该身份证号码*/
		{
			i=0;
			continue;
		}
		else 
		{
			i=1;
			break;
		}
	}
	fclose(fp);
	return i;
}
void SearchName()							/*查询姓名*/
{
	char name[10];
	printf("输入查询考生姓名：\n");
	gets(name);
	ShowAExaminee(name);					/*调用个人信息显示函数*/
}
void SearchID()								/*查询身份证号码*/
{
	char ID[19];
	printf("输入查询考生身份证号码：\n");
	gets(ID);
	ShowAExaminee(ID);						/*调用个人信息显示函数*/
}

void SearchPhone()							/*查询联系电话*/
{
	char phone[10];
	printf("输入查询考生联系电话：\n");
	gets(phone);
	ShowAExaminee(phone);					/*调用个人信息显示函数*/
}
void ShowAExaminee(char *x)					/*显示指定考生个人信息*/
{	
	int k;
	struct student myexaminee;				/*定义结构体变量*/
	FILE *fp;
	fp=fopen(".\\examinee.txt","r");
	if((fp=fopen(".\\examinee.txt","r"))==NULL)
	{
		printf("打开文件错误!");
		exit(0);
	}											
	//while((feof(fp))!=EOF)
	while((fscanf(fp,"%s%s%s",myexaminee.name,myexaminee.phone,myexaminee.ID))!=EOF)
	{
		if(strcmp(myexaminee.name,x)==0 || strcmp(myexaminee.phone,x)==0 || strcmp(myexaminee.ID,x)==0 )
			k=1;
		if(k==1)
		{
			IDTr(&myexaminee.sex,&myexaminee.year,&myexaminee.month,&myexaminee.day,myexaminee.ID);
			IDTrB(myexaminee.bithplace,myexaminee.ID);			
			Randomexnum(&myexaminee.exnum);
			printf("考生姓名：%s\n考生性别：%c\n考生考号：%d\n考生联系电话：%s\n考生身份证号码：%s\n考生出生年月日：%d.%d.%d\n考生籍贯：%s\n",myexaminee.name,myexaminee.sex,myexaminee.exnum,myexaminee.phone,myexaminee.ID,myexaminee.year,myexaminee.month,myexaminee.day,myexaminee.bithplace);
			system("pause");
			break;
		}
		else
			k=0;
	}
			if(k==0)
			{
				printf("无该考生个人信息，请重新查询!!\n");
				system("pause");
			}
	fclose(fp);
}
void ShowExaminee()					/*显示所有考生信息*/ 
{
	int i=0,j=0;
	int sum=CountExaminee();
	struct student myexaminee;
	FILE *fp;
	fp=fopen(".\\examinee.txt","r");
	if(sum==0)
		printf("无考生信息");
	if((fp=fopen(".\\examinee.txt","r"))==NULL)
	{
		printf("打开文件错误!\n");
		exit(0);
	}
	
	for(j=1;j<=(sum/30)+1;j++)
	{
		printf("考号            考生姓名       考生性别        考生籍贯        考生出生年月日        联系电话         身份证\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		for(i=1;i<=30;i++)
		{
			if((fscanf(fp,"%s%s%s",myexaminee.name,myexaminee.phone,myexaminee.ID))==EOF)
				break;
			else
			{
				IDTr(&myexaminee.sex,&myexaminee.year,&myexaminee.month,&myexaminee.day,myexaminee.ID);	/*将结构体中的性别，年月日，身份证地址传给身份证转换函数*/
				IDTrB(myexaminee.bithplace,myexaminee.ID);												/*将结构体中的籍贯，身份证地址传给籍贯转换函数*/
				Randomexnum(&myexaminee.exnum);															/*将结构体中的考号地址传给考号生成函数*/
				printf("%d\t%s\t\t%c\t\t%s\t\t%d.%d.%d\t    %s\t\t%s\n",myexaminee.exnum,myexaminee.name,myexaminee.sex,myexaminee.bithplace,myexaminee.year,myexaminee.month,myexaminee.day,myexaminee.phone,myexaminee.ID);
			}
		}
		system("pause");
		system("cls");
	}
	fclose(fp);
}
void Randomexnum(int *num)											/*产生随机考号*/
{
	int exam=N/30+1,k,j;											/*exam为考场个数*/
	k=1+rand()%(exam);												/*产生随机考场数*/
	j=10+rand()%(21);												/*产生随机考生编码数*/
	*num=4301*100000+k*100+j;
}
void IDTr(char *s,int *y,int *m,int *d,char id[19])					/*身份证号码转换为性别,出生年月日*/
{
		if((id[16]-'0')%2==0)										/*对身份证号码的第17位数进行判断*/
			*s='F';
		else
			*s='M';
		*y=(id[6]-'0')*1000+(id[7]-'0')*100+(id[8]-'0')*10+id[9]-'0';	/*对身份证号码的第7,8,9位数进行判断*/
		*m=(id[10]-'0')*10+id[11]-'0';									/*对身份证号码的第11,12位数进行判断*/
		*d=(id[12]-'0')*10+id[13]-'0';									/*对身份证号码的第13,14位数进行判断*/
}
void IDTrB(char *b,char i[19])			/*身份证转换籍贯*/
{
	int x,y,z;			
	x=i[0]-'0';			/*将身份证号码的第一位数存储到变量*/
	y=i[1]-'0';			/*将身份证号码的第二位数存储到变量*/
	z=x*10+y;
	switch(z)
	{
		case 11:strcpy(b,"北京");break;
		case 12:strcpy(b,"天津");break;
		case 13:strcpy(b,"河北");break;
		case 14:strcpy(b,"山西");break;
		case 15:strcpy(b,"内蒙");break;
		case 21:strcpy(b,"辽宁");break;
		case 22:strcpy(b,"吉林");break;
		case 23:strcpy(b,"黑龙江");break;
		case 31:strcpy(b,"上海");break;
		case 32:strcpy(b,"江苏");break;
		case 33:strcpy(b,"浙江");break;
		case 34:strcpy(b,"安徽");break;
		case 35:strcpy(b,"福建");break;
		case 36:strcpy(b,"江西");break;
		case 37:strcpy(b,"山东");break;
		case 41:strcpy(b,"河南");break;
		case 42:strcpy(b,"湖北");break;
		case 43:strcpy(b,"湖南");break;
		case 44:strcpy(b,"广东");break;
		case 45:strcpy(b,"广西");break;
		case 46:strcpy(b,"海南");break;
		case 51:strcpy(b,"四川");break;
		case 52:strcpy(b,"贵州");break;
		case 53:strcpy(b,"云南");break;
		case 54:strcpy(b,"西藏");break;
		case 61:strcpy(b,"陕西");break;
		case 62:strcpy(b,"甘肃");break;
		case 63:strcpy(b,"青海");break;
		case 64:strcpy(b,"宁夏");break;
		case 65:strcpy(b,"新疆");break;
		case 50:strcpy(b,"重庆");break;
	}
}

