#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 2 )
    {
	    printf("usage: %s <filename>\n", argv[0]);
	    return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
	    perror("Error opening file");
	    return 1;
    }

    int lines = 0, words = 0, characters = 0;

    char ch, prev = '\0' ;

    while((ch = fgetc(file)) != EOF)
    {
	    characters++;

	    if(ch == '\n' ) lines++;

	    if ((ch ==' ' || ch == '\n' || ch == '\t' ) && prev != ' ' && prev!= '\n' && prev!= '\t')
		    words++;
	    prev =ch;
    }

    fclose(file);

    printf("Lines: %d\nWords: %d\nCharacters: %d\n",lines, words, characters);
    return 0;
}

