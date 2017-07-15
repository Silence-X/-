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
	int menuid;									/*���彫���˵��ķ���ֵ�洢�ı���*/
	system("mode con cols=125 lines=40");		/*���ô��ڿ�ȸ߶�*/					
	welcome();									/*�������з��溯��*/
	while(1)
	{
		menuid=MainMenu();						/*һ���˵�ѡ��ѡ��*/
		if(menuid==0)
		{
			printf("\n�������\n");
			break;
		}
		switch(menuid)
		{
			case 1:SubMenu2_1();break;
			case 2:SubMenu2_2();break;
		}
	}
}
void welcome()								/*����ϵͳ����*/
{
	system("cls");							/*����*/
	system("color 0A");
	printf("\t\t\t\t\t  �X�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t\t  �U  **********************  �U\n");
	printf("\t\t\t\t\t  �U  **********************  �U\n");
	printf("\t\t\t\t\t  �U  **   ������Ϣϵͳ   **  �U\n");
	printf("\t\t\t\t\t  �U  **********************  �U\n");
	printf("\t\t\t\t\t  �U  **********************  �U\n");
	printf("\t\t\t\t\t  �^�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	system("pause");
}

void SubMenu2_1()							/*�����˵� ��Ϣ���� ѡ��ѡ��*/
{
	int menuid;
	while(1)
	{
		menuid=Menu2_1();					/*���ö����˵���ʾ����*/
		if(menuid==0)
			break;
		switch(menuid)
		{
			case 1:AddExaminee();break;
			//case 2:shanchu();break;
		}
	}
}
void SubMenu2_2()							/*�����˵� ��Ϣ��ѯ ѡ��ѡ��*/
{
	int menuid;
	while(1)
	{
		menuid=Menu2_2();					/*���ö����˵���ʾ����*/
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
int CountExaminee()							/*ͳ�ƿ�������*/
{
	struct student examtemp;				/*����ṹ�����*/
	FILE *fp;								/*�����ļ�ָ��*/
	int count=0;
	if((fp=fopen(".\\examinee.txt","r"))==NULL)	/*���ļ�*/
		return 0;
	else
	{
		while((fscanf(fp,"%s%s%s",examtemp.name,examtemp.phone,examtemp.ID))!=EOF)		/*���������ۼ�ͳ��*/
			count++;
	}
	fclose(fp);
	return count;
}
void AddExaminee()							/*����������Ϣ*/
{
	FILE *fp;
	struct student myexaminee;				/*����ṹ�����*/
	printf("\n����������Ϣ������ʾ������Ϣ��\n");
	printf("����������\n");					
	gets(myexaminee.name);					/*��������*/
	printf("������ϵ�绰��\n");
	gets(myexaminee.phone);					/*��������*/
	printf("�������֤���룺\n");
	gets(myexaminee.ID);					/*��������*/
	while(IsIDExist(myexaminee.ID))			/*����������ݽ����жϲ���������*/
	{
		printf("�����������֤����%s�Ѵ��ڣ���������!\n",myexaminee.ID);
		printf("�������֤���룺\n");
		gets(myexaminee.ID);				/*����������ȷ����*/
	}
	
	fp=fopen(".\\examinee.txt","a+");
	if((fp=fopen(".\\examinee.txt","a+"))==NULL)
	{
		printf("���ļ�����!\n");
		exit(0);
	}
	fprintf(fp,"%s\t%s\t%s\n",myexaminee.name,myexaminee.phone,myexaminee.ID);	/*���ı��ļ���������������Ϣ*/
	fclose(fp);
	printf("����������Ϣ�ɹ�!\n");
	system("pause");
	flushall();
}
int IsIDExist(char *p)								/*�ж����֤�������*/
{
	int i;
	struct student myexaminee;						/*����ṹ�����*/
	FILE *fp;
	fp=fopen(".\\examinee.txt","r");
	while((fscanf(fp,"%s%s%s",myexaminee.name,myexaminee.phone,myexaminee.ID))!=EOF)	
	{
		if(strcmp(myexaminee.ID,p)!=0 )				/*���ļ���Ѱ���Ƿ��и����֤����*/
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
void SearchName()							/*��ѯ����*/
{
	char name[10];
	printf("�����ѯ����������\n");
	gets(name);
	ShowAExaminee(name);					/*���ø�����Ϣ��ʾ����*/
}
void SearchID()								/*��ѯ���֤����*/
{
	char ID[19];
	printf("�����ѯ�������֤���룺\n");
	gets(ID);
	ShowAExaminee(ID);						/*���ø�����Ϣ��ʾ����*/
}

void SearchPhone()							/*��ѯ��ϵ�绰*/
{
	char phone[10];
	printf("�����ѯ������ϵ�绰��\n");
	gets(phone);
	ShowAExaminee(phone);					/*���ø�����Ϣ��ʾ����*/
}
void ShowAExaminee(char *x)					/*��ʾָ������������Ϣ*/
{	
	int k;
	struct student myexaminee;				/*����ṹ�����*/
	FILE *fp;
	fp=fopen(".\\examinee.txt","r");
	if((fp=fopen(".\\examinee.txt","r"))==NULL)
	{
		printf("���ļ�����!");
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
			printf("����������%s\n�����Ա�%c\n�������ţ�%d\n������ϵ�绰��%s\n�������֤���룺%s\n�������������գ�%d.%d.%d\n�������᣺%s\n",myexaminee.name,myexaminee.sex,myexaminee.exnum,myexaminee.phone,myexaminee.ID,myexaminee.year,myexaminee.month,myexaminee.day,myexaminee.bithplace);
			system("pause");
			break;
		}
		else
			k=0;
	}
			if(k==0)
			{
				printf("�޸ÿ���������Ϣ�������²�ѯ!!\n");
				system("pause");
			}
	fclose(fp);
}
void ShowExaminee()					/*��ʾ���п�����Ϣ*/ 
{
	int i=0,j=0;
	int sum=CountExaminee();
	struct student myexaminee;
	FILE *fp;
	fp=fopen(".\\examinee.txt","r");
	if(sum==0)
		printf("�޿�����Ϣ");
	if((fp=fopen(".\\examinee.txt","r"))==NULL)
	{
		printf("���ļ�����!\n");
		exit(0);
	}
	
	for(j=1;j<=(sum/30)+1;j++)
	{
		printf("����            ��������       �����Ա�        ��������        ��������������        ��ϵ�绰         ���֤\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		for(i=1;i<=30;i++)
		{
			if((fscanf(fp,"%s%s%s",myexaminee.name,myexaminee.phone,myexaminee.ID))==EOF)
				break;
			else
			{
				IDTr(&myexaminee.sex,&myexaminee.year,&myexaminee.month,&myexaminee.day,myexaminee.ID);	/*���ṹ���е��Ա������գ����֤��ַ�������֤ת������*/
				IDTrB(myexaminee.bithplace,myexaminee.ID);												/*���ṹ���еļ��ᣬ���֤��ַ��������ת������*/
				Randomexnum(&myexaminee.exnum);															/*���ṹ���еĿ��ŵ�ַ�����������ɺ���*/
				printf("%d\t%s\t\t%c\t\t%s\t\t%d.%d.%d\t    %s\t\t%s\n",myexaminee.exnum,myexaminee.name,myexaminee.sex,myexaminee.bithplace,myexaminee.year,myexaminee.month,myexaminee.day,myexaminee.phone,myexaminee.ID);
			}
		}
		system("pause");
		system("cls");
	}
	fclose(fp);
}
void Randomexnum(int *num)											/*�����������*/
{
	int exam=N/30+1,k,j;											/*examΪ��������*/
	k=1+rand()%(exam);												/*�������������*/
	j=10+rand()%(21);												/*�����������������*/
	*num=4301*100000+k*100+j;
}
void IDTr(char *s,int *y,int *m,int *d,char id[19])					/*���֤����ת��Ϊ�Ա�,����������*/
{
		if((id[16]-'0')%2==0)										/*�����֤����ĵ�17λ�������ж�*/
			*s='F';
		else
			*s='M';
		*y=(id[6]-'0')*1000+(id[7]-'0')*100+(id[8]-'0')*10+id[9]-'0';	/*�����֤����ĵ�7,8,9λ�������ж�*/
		*m=(id[10]-'0')*10+id[11]-'0';									/*�����֤����ĵ�11,12λ�������ж�*/
		*d=(id[12]-'0')*10+id[13]-'0';									/*�����֤����ĵ�13,14λ�������ж�*/
}
void IDTrB(char *b,char i[19])			/*���֤ת������*/
{
	int x,y,z;			
	x=i[0]-'0';			/*�����֤����ĵ�һλ���洢������*/
	y=i[1]-'0';			/*�����֤����ĵڶ�λ���洢������*/
	z=x*10+y;
	switch(z)
	{
		case 11:strcpy(b,"����");break;
		case 12:strcpy(b,"���");break;
		case 13:strcpy(b,"�ӱ�");break;
		case 14:strcpy(b,"ɽ��");break;
		case 15:strcpy(b,"����");break;
		case 21:strcpy(b,"����");break;
		case 22:strcpy(b,"����");break;
		case 23:strcpy(b,"������");break;
		case 31:strcpy(b,"�Ϻ�");break;
		case 32:strcpy(b,"����");break;
		case 33:strcpy(b,"�㽭");break;
		case 34:strcpy(b,"����");break;
		case 35:strcpy(b,"����");break;
		case 36:strcpy(b,"����");break;
		case 37:strcpy(b,"ɽ��");break;
		case 41:strcpy(b,"����");break;
		case 42:strcpy(b,"����");break;
		case 43:strcpy(b,"����");break;
		case 44:strcpy(b,"�㶫");break;
		case 45:strcpy(b,"����");break;
		case 46:strcpy(b,"����");break;
		case 51:strcpy(b,"�Ĵ�");break;
		case 52:strcpy(b,"����");break;
		case 53:strcpy(b,"����");break;
		case 54:strcpy(b,"����");break;
		case 61:strcpy(b,"����");break;
		case 62:strcpy(b,"����");break;
		case 63:strcpy(b,"�ຣ");break;
		case 64:strcpy(b,"����");break;
		case 65:strcpy(b,"�½�");break;
		case 50:strcpy(b,"����");break;
	}
}

