#include<stdio.h>
#define EXIT_SUCCESS 0

void Incrypt(char *str)
{
int i;
char EncryptTable[26] = {'q','w','e','r','t',
			 'a','s','d','f','g',
			 'z','x','c','v','b',
			 'y','u','i','o','p',
			 'h','j','k','l','n','m'};

	for(i = 0 ; str[i] ; ++i)
		str[i] = EncryptTable[str[i]-97];
}

void Decrypt(char *str)
{
int i;
char DecryptTable[26] = {'f','o','m','h','c',
			 'i','j','u','r','v',
			 'w','x','z','y','s',
			 't','a','d','g','e',
			 'q','n','b','l','p','k'};

	for(i = 0 ; str[i] ; ++i)
		str[i] = DecryptTable[str[i]-97];
}

int main()
{
char str[30];

	printf("Enter string..\n");
	scanf("%s",str);

	Incrypt(str);
	printf("String = %s\n",str);
	Decrypt(str);
	printf("String = %s\n",str);

	return EXIT_SUCCESS;
}
