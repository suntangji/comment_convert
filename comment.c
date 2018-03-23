#define _CRT_SECURE_NO_WARNINGS 
#include"comment.h"

void DoConvertWork()
{
	enum Status status = NONE_STATUS;
	FILE* fpread = NULL;
	FILE* fpwrite = NULL;
	int first = 0;
	int second = 0;
	//enum Status status;

	fpread = fopen("input.c", "r");
	if (fpread == NULL)
	{
		perror("open file error for read");
		getchar();
		exit(EXIT_FAILURE);
	}
	fpwrite = fopen("output.c", "w");
	if (fpwrite == NULL)
	{
		fclose(fpread);
		perror("opne file error for write");
		getchar();
		exit(EXIT_FAILURE);
	}
	while (status != END_STATUS)
	{

		switch (status)
		{
		case NONE_STATUS:
			doNoneStatus(fpread, fpwrite, &status);
			break;
		case C_STATUS:
			doCStatus(fpread, fpwrite, &status);
			break;
		case CPP_STATUS:
			doCppStatus(fpread, fpwrite, &status);
			break;
		}
	}
	doEndStatus(fpread, fpwrite, &status);
}
//void commentConvert()
//{
//	FILE* fpread = NULL;
//	FILE* fpwrite = NULL;
//	int first = 0;
//	int second = 0;
//	enum Status status;
//
//	fpread = fopen("input.c", "r");
//	if (fpread ==NULL)
//	{
//		perror("open file error for read");
//		getchar();
//		exit(EXIT_FAILURE);
//	}
//	fpwrite = fopen("output.c", "w");
//	if (fpwrite==NULL)
//	{
//		fclose(fpread);
//		perror("opne file error for write");
//		getchar();
//		exit(EXIT_FAILURE);
//	}
//	first = fgetc(fpread);
//	if(first != EOF)
//	{
//		switch (first)
//		{
//		case '/':
//			second = fgetc(fpread);
//			switch (second)
//			{
//			case '/':
//				fputc(first, fpwrite);
//				fputc(second, fpwrite);
//				status = CPP_STATUS;
//				doCppStatus(fpread,fpwrite,&status);
//				break;
//			case '*':
//				fputc(first, fpwrite);
//				fputc(first, fpwrite);
//				status = C_STATUS;
//				doCStatus(fpread, fpwrite, &status);
//				break;
//			default:
//				fputc(first, fpwrite);
//				fputc(second, fpwrite);
//				doNoneStatus(fpread, fpwrite, &status);
//				break;
//			}
//			break;
//		default:
//			fputc(first, fpwrite);
//			doNoneStatus(fpread, fpwrite, &status);
//			break;
//		}
//		//printf("%c", first);
//		//fputc(first, fpwrite);
//		//first = fgetc(fpread);
//
//	}
//	doEndStatus(fpread, fpwrite, &status);
//}
