int MainMenu()			/*һ���˵�*/
{
	int m,k;
	while(1)
	{
		printf("\n         �� �� ��\n");
		printf("     ---------\n");
		printf("      1 - ������Ϣ����ϵͳ\n");
		printf("      2 - ������Ϣ��ѯϵͳ\n");
		printf("      0 - �˳�ϵͳ\n");
		printf("��ѡ��(0-2):");
		k=scanf("%d",&m);
		flushall();		/*������̻�����������*/
		if(m>=0 && m<=2 && k==1)
			break;
		else
			printf("\nѡ���������0-2֮��ѡ��\n");
	}
	return m;
}
int Menu2_1()			/*�����˵�  ��Ϣ����*/
{
	int m,k;
	while(1)
	{
		printf("\n         ������Ϣ����ϵͳ\n");
		printf("     ------------------\n");
		printf("      1 - ����������Ϣ\n");
		printf("      2 - �޸Ŀ�����Ϣ\n");
		printf("      3 - ɾ��������Ϣ\n");
		printf("      0 - ������һ���˵�\n");
		printf("��ѡ��(0-3):");
		k=scanf("%d",&m);
		flushall();		/*������̻�����������*/
		if(m>=0 && m<=3 && k==1)
			break;
		else
			printf("\nѡ���������0-3֮��ѡ��\n");
	}
	return m;
}
int Menu2_2()			/*�����˵�  ��Ϣ��ѯ*/
{
	int m,k;
	while(1)
	{
		printf("\n         ������Ϣ��ѯϵͳ\n");
		printf("     ------------------\n");
		printf("      1 - ��ѯ��������\n");
		printf("      2 - ��ѯ��������\n");
		printf("      3 - ��ѯ�������֤\n");
		printf("      4 - ��ѯ�����Ա�\n");
		printf("      5 - ��ѯ��������\n");
		printf("      6 - ��ѯ������ϵ�绰\n");
		printf("      7 - ��ѯ��������������\n");
		printf("      0 - ������һ���˵�\n");
		printf("��ѡ��(0-7):");
		k=scanf("%d",&m);
		flushall();		/*������̻�����������*/
		if(m>=0 && m<=7 && k==1)
			break;
		else
			printf("\nѡ���������0-7֮��ѡ��\n");
	}
	return m;
}