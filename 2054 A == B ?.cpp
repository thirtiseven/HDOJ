#include <cstdio>
#include <cstring>
#define maxn 10000000
char s1[maxn];
char s2[maxn];
char *str(char *s)
{
	int len=strlen(s);
	if(strchr(s,'.')!=NULL)
	{ 
		while(s[--len]=='0');
			if(s[len]=='.')
				len--;
			s[len+1]='\0';
	} 
	return s;
}
int main()
{
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		if(!strcmp(str(s1),str(s2)))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}