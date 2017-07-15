int MainMenu()			/*一级菜单*/
{
	int m,k;
	while(1)
	{
		printf("\n         主 菜 单\n");
		printf("     ---------\n");
		printf("      1 - 考生信息管理系统\n");
		printf("      2 - 考生信息查询系统\n");
		printf("      0 - 退出系统\n");
		printf("请选择(0-2):");
		k=scanf("%d",&m);
		flushall();		/*清除键盘缓冲区的内容*/
		if(m>=0 && m<=2 && k==1)
			break;
		else
			printf("\n选择错误，请在0-2之间选择\n");
	}
	return m;
}
int Menu2_1()			/*二级菜单  信息管理*/
{
	int m,k;
	while(1)
	{
		printf("\n         考生信息管理系统\n");
		printf("     ------------------\n");
		printf("      1 - 新增考生信息\n");
		printf("      2 - 修改考生信息\n");
		printf("      3 - 删除考生信息\n");
		printf("      0 - 返回上一级菜单\n");
		printf("请选择(0-3):");
		k=scanf("%d",&m);
		flushall();		/*清除键盘缓冲区的内容*/
		if(m>=0 && m<=3 && k==1)
			break;
		else
			printf("\n选择错误，请在0-3之间选择\n");
	}
	return m;
}
int Menu2_2()			/*二级菜单  信息查询*/
{
	int m,k;
	while(1)
	{
		printf("\n         考生信息查询系统\n");
		printf("     ------------------\n");
		printf("      1 - 查询考生考号\n");
		printf("      2 - 查询考生姓名\n");
		printf("      3 - 查询考生身份证\n");
		printf("      4 - 查询考生性别\n");
		printf("      5 - 查询考生籍贯\n");
		printf("      6 - 查询考生联系电话\n");
		printf("      7 - 查询考生出生年月日\n");
		printf("      0 - 返回上一级菜单\n");
		printf("请选择(0-7):");
		k=scanf("%d",&m);
		flushall();		/*清除键盘缓冲区的内容*/
		if(m>=0 && m<=7 && k==1)
			break;
		else
			printf("\n选择错误，请在0-7之间选择\n");
	}
	return m;
}