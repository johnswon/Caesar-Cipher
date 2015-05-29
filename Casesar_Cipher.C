#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main()
{
	int protokey;
	int key;
	int counter[26] = {0};
	int fixer;
	int max = 0;
	FILE *translatedCC;
	
	translatedCC = fopen("translated_letter.txt", "w");
	


	FILE *ccletter;
	ccletter = fopen("letter.encrypt", "r");
	int ch = getc(ccletter); 
	char letters = ch;
	while(ch != EOF)
	{
		if((ch<=122 && ch>97))
		{	
			fixer = ch-97;
			counter[fixer] += 1;
		}
		
		
				    
		ch = getc(ccletter);
	}
			fclose(ccletter);
			

	for(int i = 0; i<26; i++)
		{	
			int current = counter[i];
			
			if(current > max)
			{
				max = current;
				protokey = i;
			}
		} 
		
		key = protokey - 4;
		if (key < 0)
		{key += 26;
			}
		
		
		
			FILE *ccletternew;
			ccletternew = fopen("letter.encrypt", "r");
			ch = getc(ccletternew);
		
	while(ch != EOF)		
	{
		if(ch <= 122 && ch >= 97)
				{
						ch-= key;
						if(ch < 97)
						{
						ch = ch + 26;
						}
				
					letters = ch;
					putc(letters, translatedCC);
				}
			else
			{
				letters = ch;
				putc(letters, translatedCC);

			}
					ch = getc(ccletternew);

		}
					fclose(ccletternew);

return(0);
}
