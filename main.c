#include <stdlib.h>
#include <stdio.h>

void encoder (const char* fi_name, const int offset, const int flag)
{
	const int ENG = 26; // number of letters in the English alphabet 
	// Open source file, for read
	FILE* fi = fopen(fi_name, "r");
	if(fi == 0) { perror(fi_name); exit(1); }
	// Open result file, for write
	char* fo_name = (flag) ? "decrypted.txt" : "encrypted.txt";
	FILE* fo = fopen(fo_name, "w");
	if(fo == 0) { perror(fo_name); exit(1); }

	// encrypt or decrypt files and save results
	char c = getc(fi);
	int is_char;
	int current_offset;
	while(!feof(fi))
	{
		current_offset = (flag) ? (offset%ENG)*-1 : offset%ENG;
		is_char = 0;
		if(c >= 'A' && c <= 'Z')
		{
			if((c+current_offset) > 'Z') current_offset-=ENG;
			if((c+current_offset) < 'A') current_offset+=ENG;
			c+=current_offset;
			fprintf(fo,"%c",c);
			is_char = 1;
		}
		if(c >= 'a' && c <= 'z')
		{
			if((c+current_offset) > 'z') current_offset-=ENG;
			if((c+current_offset) < 'a') current_offset+=ENG;
			c+=current_offset;
			fprintf(fo,"%c",c);
			is_char = 1;
		}
		if(!is_char) fprintf(fo,"%c",c);
		c = getc(fi);
	}
	fclose(fo);
	fclose(fi);
	if(flag) printf("File %s decrypted, saved to %s. Decryption key = %i\n",fi_name, fo_name, offset);
	else printf("File %s encrypted, saved to %s. Decryption key = %i\n",fi_name, fo_name, offset);
}

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
