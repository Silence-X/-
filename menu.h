int MainMenu()												/*һ���˵���ʾ����*/
{
	int m,k;
	system("cls");											/*����*/
	while(1)
	{
		system("cls");										/*����*/
		printf("\t\t\t\t\t           �� �� ��\n");
		printf("\t\t\t\t\t     -----------------\n");
		printf("\t\t\t\t\t      1 - ������Ϣ����ϵͳ\n");
		printf("\t\t\t\t\t      2 - ������Ϣ��ѯϵͳ\n");
		printf("\t\t\t\t\t      0 - �˳�ϵͳ\n");
		printf("\t\t\t\t\t��ѡ��(0-2):");
		k=scanf("%d",&m);
		flushall();											/*������̻�����������*/
		if(m>=0 && m<=2 && k==1)
			break;
		else
			printf("\t\t\t\t\tѡ���������0-2֮��ѡ��\n");
			system("pause");
	}
	return m;
}
int Menu2_1()												/*�����˵�  ��Ϣ���� ��ʾ����*/
{
	int m,k;
	system("cls");											/*����*/
	while(1)
	{
		printf("\t\t\t\t\t         ������Ϣ����ϵͳ\n");
		printf("\t\t\t\t\t     ------------------\n");
		printf("\t\t\t\t\t      1 - ����������Ϣ\n");
	//	printf("\t\t\t\t\t      2 - ɾ��������Ϣ\n");
		printf("\t\t\t\t\t      0 - ������һ���˵�\n");
		printf("\t\t\t\t\t��ѡ��(0-1):");
		k=scanf("%d",&m);
		flushall();											/*������̻�����������*/
		if(m>=0 && m<=1 && k==1)
			break;
		else
			printf("\t\t\t\t\tѡ���������0-1֮��ѡ��\n");
	}
	return m;
}
int Menu2_2()												/*�����˵�  ��Ϣ��ѯ ��ʾ����*/
{
	int m,k;
	system("cls");											/*����*/
	while(1)
	{
		printf("\t\t\t\t\t         ������Ϣ��ѯϵͳ\n");
		printf("\t\t\t\t\t     ------------------\n");
		printf("\t\t\t\t\t      1 - ��ѯ��������\n");
		printf("\t\t\t\t\t      2 - ��ѯ�������֤\n");
		printf("\t\t\t\t\t      3 - ��ѯ������ϵ�绰\n");
		printf("\t\t\t\t\t      4 - ��ѯ���п�����Ϣ\n");
		printf("\t\t\t\t\t      0 - ������һ���˵�\n");
		printf("\t\t\t\t\t��ѡ��(0-4):");
		k=scanf("%d",&m);
		flushall();											/*������̻�����������*/
		if(m>=0 && m<=4 && k==1)
			break;
		else
			printf("\t\t\t\t\tѡ���������0-4֮��ѡ��\n");
	}
	return m;
}
