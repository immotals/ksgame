#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#define MATRIX_SIZE 5
#define MAX_NUMBER 5
#define TIME_LIMIT 5

void intro_game(void);
void game_control(void);
void print_number(int n, int cnt[], int v);
int find_nummost(int cnt[], int v);
int find_numleast(int cnt[], int v);
void check_result(int user, int answer, int cnt[]);
int main(void)
{
	srand(time(NULL));
	intro_game();
    game_control();
	return 0;
}


void intro_game(void)
{
	printf("������Ŀ� ��Ÿ�� ���� �߿���\n");
	printf("���� ���� ������ ���ڸ� ã�ƶ�!\n");
	printf("���� ���� ������ ���ڸ� ã�ƶ�!\n"); 
	printf("���ѽð��� 5���Դϴ�.\n\n");
	printf("�ƹ�Ű�� ������ �����մϴ�. \n");
	getch();
}

void game_control(void)
{
	int s, k;
	printf("ũ��� ���� �ִ� �Է�:");
	scanf("%d %d", &s, &k);
	printf("\n");
	int cnt[k], answer, user;
	clock_t start, end;
	double pst;
	system("cls");
	print_number(s, cnt, k);
	answer=find_nummost(cnt, k);
	printf("\n\n");
	printf("����Ƚ���� ���� ���� ���� �Է�>");
	start=clock();
	while(!kbhit())
	{
		end=clock();
		pst=(double)(end-start)/CLK_TCK;
		if (TIME_LIMIT<pst)
		{
			printf("\n���ѽð��� �Ѿ����ϴ�. \n");
			exit(0);
		}
	}
	user=getch()-'0';
	printf("%d", user);
	check_result(user, answer, cnt);
	answer=find_numleast(cnt, k);
	printf("\n\n");
	printf("����Ƚ���� ���� ���� ���� �Է�>");
	start=clock();
	while(!kbhit())
	{
		end=clock();
		pst=(double)(end-start)/CLK_TCK;
		if (TIME_LIMIT<pst)
		{
			printf("\n���ѽð��� �Ѿ����ϴ�. \n");
			exit(0);
		}
	}
	user=getch()-'0';
	printf("%d", user);
	check_result(user, answer, cnt);
}

void print_number(int n, int cnt[], int v)
{
	int i, j, r_num;
	int same;
	do
	{
		same=0;
		for(i=0;i<v;i+=1)
		{
			cnt[i]=0;		
		}
		system("cls");
		for(i=1;i<=n;i+=1)
		{
			for(j=1;j<=n;j+=1)
			{
				r_num=rand()%v;
				cnt[r_num]+=1;
				printf("%d ", r_num);
			}
			printf("\n");
		}
		for(int i = 0; i < v; i++)
		{
			for(int j = i+1; j < v; j++)
			{
				if(cnt[i] == cnt[j])
				{
					same++;
				}
			}
		}
	}while(same);
}

int find_nummost(int cnt[], int v)
{
	int i, check, max_num=0;
	for(i=0;i<v;i+=1)
	{
		if (max_num<=cnt[i])
		{
			max_num=cnt[i];
			check=i;
		}
	}
	return check;
}

int find_numleast(int cnt[], int v)
{
	int i, check, min_num=v-1;
	for(i=0;i<v;i+=1)
	{
		if (min_num>=cnt[i])
		{
			min_num=cnt[i];
			check=i;
		}
	}
	return check;
}

void check_result(int user, int answer, int cnt[])
{
	if (user==answer)
		printf("\n�¾ҽ��ϴ�. \n");
	else
		printf("\nƲ�Ƚ��ϴ�. \n");
	printf("��ȣ: %d, Ƚ�� : %d\n", answer, cnt[answer]);
}
