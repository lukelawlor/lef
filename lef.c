/*
 * lef.c
 *
 * 1/26/23
 *
 * Luke's equation formatter
 *
 * *
 * line
 * line
 * line
 * *
 *
 * becomes
 *
 * .EQ
 * line
 * .EN
 * .EQ
 * line
 * .EN
 * .EQ
 * line
 * .EN
 *
 * *
 * line
 * 
 * line
 * *
 *
 * becomes
 *
 * .EQ
 * line
 * .EN
 * .sp
 * .EQ
 * line
 * .EN
 *
 * *file
 *
 * will include file in the output
 *
 */
#include <stdio.h>
#include <stdlib.h>
#define	PERR(...)	perr_start();fprintf(stderr, __VA_ARGS__);perr_end()
#define	SIGNAL	'*'
#define	START	".EQ\n"
#define	END	".EN\n"
#define	SEP	".sp\n"
#define	BUF_LEN	100
char inc_buf[BUF_LEN];
void perr_start()
{
	fprintf(stderr, "lef: error: ");
}
void perr_end()
{
	fputc('\n', stderr);
}
int main(void)
{
	int c;
	// Read until the end of the file
	while ((c = getchar()) != EOF)
	{
		// Start of formatting found
		if (c == SIGNAL)
		{
			// Move to next line
			c = getchar();
			if (c != '\n')
			{
				// No newline found, get the name of file to include
				int i = 0;
				do
				{
					inc_buf[i] = c;
					i++;
					if (i == BUF_LEN - 1)
					{
						// File name exceeds BUF_LEN
						inc_buf[i] = '\0';
						PERR("included file name \"%s...\" was too long", inc_buf);
						abort();
					}
					c = getchar();
				} while (c != '\n');

				// Null terminate
				inc_buf[i] = '\0';

				// Try opening the file
				FILE *fp = fopen(inc_buf, "r");
				if (fp == NULL)
				{
					PERR("can't open file \"%s\"", inc_buf);
					abort();
				}

				// Cat the file
				while ((c = fgetc(fp)) != EOF)
					putchar(c);

				// Close the file
				if (fclose(fp) == EOF)
				{
					PERR("failed to close file \"%s\"", inc_buf);
					abort();
				}
			}
			else
			{
				// Continuously read lines to format
				for (;;)
				{
					// Read start of line
					c = getchar();
					if (c == SIGNAL)
					{
						// End of formatting found
						// Move past newline
						c = getchar();
						if (c != '\n' && c != EOF)
							abort();
						break;
					}
					else if (c == '\n')
					{
						// Print seperator
						printf(SEP);
					}
					else
					{
						// Print start text
						printf(START);
						for (;;)
						{
							// Print text in this line
							putchar(c);
							if (c == '\n')
								break;
							c = getchar();
						}
						// Print end text
						printf(END);
					}
				}
			}
		}
		else
		{
			for (;;)
			{
				// Print everything in this line
				putchar(c);
				if (c == '\n')
					break;
				c = getchar();
			}
		}
	}
	return 0;
}
