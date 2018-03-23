#define _CRT_SECURE_NO_WARNINGS 
#include"comment.h"

void doCppStatus(FILE* fpr, FILE* fpw, enum Status *status)
{
	int first = 0;
	first = fgetc(fpr);
	switch (first)
	{
	case '\n':
		fputc(first, fpw);
		*status = NONE_STATUS;
		break;
	case EOF:
		*status = END_STATUS;
		break;
	default:
		fputc(first, fpw);
		break;
	}
}

void doCStatus(FILE* fpr, FILE* fpw, enum Status *status)
{
	int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(fpr);

		switch (first)
		{
		case '*':
			second = fgetc(fpr);
			switch (second)
			{
			case'/':
				*status = NONE_STATUS;
				third = fgetc(fpr);
				while ((third != '\n') || (third == EOF))
				{
					if (third == ' ')
					{
						fputc(third, fpw);
					}
					else
					{
						fputc('\n', fpw);
						break;
					}
				}
				ungetc(third, fpr);
				break;
			case '*':
				fputc(first, fpw);
				ungetc(second, fpr);
				break;
			case EOF:
				*status = END_STATUS;
				break;
			default:
				fputc(first, fpw);
				fputc(second, fpw);
				break;
			}
			break;
		case '\n':
			fputc(first, fpw);
			fputc('/', fpw);
			fputc('/', fpw);
			//	*status = C_STATUS;
			//	//doCStatus(fpr, fpw, status);
			break;
		default:
			fputc(first, fpw);
			break;
		}
}
	
void doNoneStatus(FILE* fpr, FILE* fpw, enum Status *status)
{
	int first = 0;
	int second = 0;
	first = fgetc(fpr);
	
		switch (first)
		{
		case '/':
			second = fgetc(fpr);
			switch (second)
			{
			case'/':
				fputc(first, fpw);
				fputc(second, fpw);
				*status = CPP_STATUS;
				break;
			case '*':
				fputc(first, fpw);
				fputc(first, fpw);
				*status = C_STATUS;
				break;
			case EOF:
				fputc(first, fpw);
				*status = END_STATUS;
				break;
			default:
				fputc(first, fpw);
				fputc(second, fpw);
				break;
			}

			break;
		case EOF:
			*status = END_STATUS;
			break;
		default:
			fputc(first, fpw);
			break;
		}
}
void doEndStatus(FILE* fpr, FILE* fpw, enum Status *status)
{
	fclose(fpr);
	fclose(fpw);
	exit(EXIT_SUCCESS);
}