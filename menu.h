int MainMenu()												/*一级菜单显示界面*/
{
	int m,k;
	system("cls");											/*清屏*/
	while(1)
	{
		system("cls");										/*清屏*/
		printf("\t\t\t\t\t           主 菜 单\n");
		printf("\t\t\t\t\t     -----------------\n");
		printf("\t\t\t\t\t      1 - 考生信息管理系统\n");
		printf("\t\t\t\t\t      2 - 考生信息查询系统\n");
		printf("\t\t\t\t\t      0 - 退出系统\n");
		printf("\t\t\t\t\t请选择(0-2):");
		k=scanf("%d",&m);
		flushall();											/*清除键盘缓冲区的内容*/
		if(m>=0 && m<=2 && k==1)
			break;
		else
			printf("\t\t\t\t\t选择错误，请在0-2之间选择\n");
			system("pause");
	}
	return m;
}
int Menu2_1()												/*二级菜单  信息管理 显示界面*/
{
	int m,k;
	system("cls");											/*清屏*/
	while(1)
	{
		printf("\t\t\t\t\t         考生信息管理系统\n");
		printf("\t\t\t\t\t     ------------------\n");
		printf("\t\t\t\t\t      1 - 新增考生信息\n");
	//	printf("\t\t\t\t\t      2 - 删除考生信息\n");
		printf("\t\t\t\t\t      0 - 返回上一级菜单\n");
		printf("\t\t\t\t\t请选择(0-1):");
		k=scanf("%d",&m);
		flushall();											/*清除键盘缓冲区的内容*/
		if(m>=0 && m<=1 && k==1)
			break;
		else
			printf("\t\t\t\t\t选择错误，请在0-1之间选择\n");
	}
	return m;
}
int Menu2_2()												/*二级菜单  信息查询 显示界面*/
{
	int m,k;
	system("cls");											/*清屏*/
	while(1)
	{
		printf("\t\t\t\t\t         考生信息查询系统\n");
		printf("\t\t\t\t\t     ------------------\n");
		printf("\t\t\t\t\t      1 - 查询考生姓名\n");
		printf("\t\t\t\t\t      2 - 查询考生身份证\n");
		printf("\t\t\t\t\t      3 - 查询考生联系电话\n");
		printf("\t\t\t\t\t      4 - 查询所有考生信息\n");
		printf("\t\t\t\t\t      0 - 返回上一级菜单\n");
		printf("\t\t\t\t\t请选择(0-4):");
		k=scanf("%d",&m);
		flushall();											/*清除键盘缓冲区的内容*/
		if(m>=0 && m<=4 && k==1)
			break;
		else
			printf("\t\t\t\t\t选择错误，请在0-4之间选择\n");
	}
	return m;
}
