#include "encoder.h"

int main()
{
	printf("Program to encrypt and decrypt files, using Caesar encryption.\n");	

	printf("Enter offset: ");
	int offset = 0;
	scanf("%i",&offset);
	getchar();

	if(offset == 0) { perror("offset = 0, nothing to change!"); return 1; }

	printf("Enter file name: ");
	char fi_name[20];
	scanf("%19s",fi_name);
	getchar();

	printf("Enter 'e' - for encrypt file or 'd' - for decrypt: ");
	char c = 0;
	scanf("%c",&c);
	getchar();
	const int encrypt = 0;
	const int decrypt = 1;
	switch(c)
	{
		case 'e': encoder(fi_name,offset,encrypt);
			break;
		case 'd': encoder(fi_name,offset,decrypt);
			break;
		default: perror("Error: enter 'e' for encrypt or 'd' for decrypt!");
			return 1;
	}
	return 0;
}
