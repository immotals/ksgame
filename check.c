#include <stdio.h>
#include <string.h>
void check(char A[])
{
	int len, k;
	len=strlen(A);
	for(k=0; k < len/2; k++)
	{
		if( A[k] != A[len-k-1] )
		{
			printf("회문이 아님니다.\n");
			break;
		}
		else if( k+1 == len/2 )
		{
			printf("회문입니다.\n");
		}
	}
}
int main(void)
{
	check("abcdedcba");
	check("abcddcba");
	check("rest");
	check("apple");
}
