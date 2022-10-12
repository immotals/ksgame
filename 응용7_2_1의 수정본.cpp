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
	printf("정방행렬에 나타난 숫자 중에서\n");
	printf("가장 많이 출현한 숫자를 찾아라!\n");
	printf("가장 적게 출현한 숫자를 찾아라!\n"); 
	printf("제한시간은 5초입니다.\n\n");
	printf("아무키나 누르면 시작합니다. \n");
	getch();
}

void game_control(void)
{
	int s, k;
	printf("크기와 난수 최댓값 입력:");
	scanf("%d %d", &s, &k);
	printf("\n");
	int cnt[k], answer, user;
	clock_t start, end;
	double pst;
	system("cls");
	print_number(s, cnt, k);
	answer=find_nummost(cnt, k);
	printf("\n\n");
	printf("출현횟수가 가장 많은 숫자 입력>");
	start=clock();
	while(!kbhit())
	{
		end=clock();
		pst=(double)(end-start)/CLK_TCK;
		if (TIME_LIMIT<pst)
		{
			printf("\n제한시간을 넘었습니다. \n");
			exit(0);
		}
	}
	user=getch()-'0';
	printf("%d", user);
	check_result(user, answer, cnt);
	answer=find_numleast(cnt, k);
	printf("\n\n");
	printf("출현횟수가 가장 적은 숫자 입력>");
	start=clock();
	while(!kbhit())
	{
		end=clock();
		pst=(double)(end-start)/CLK_TCK;
		if (TIME_LIMIT<pst)
		{
			printf("\n제한시간을 넘었습니다. \n");
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
		printf("\n맞았습니다. \n");
	else
		printf("\n틀렸습니다. \n");
	printf("번호: %d, 횟수 : %d\n", answer, cnt[answer]);
}
