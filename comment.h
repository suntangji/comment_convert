#ifndef _COMMENT_H__
#define _COMMENT_H__
 
#include <stdio.h>
#include<stdlib.h>

enum Status
{
	NONE_STATUS,
	C_STATUS,
	CPP_STATUS,
	END_STATUS
};
void DoConvertWork();
void doCppStatus(FILE* fpr, FILE* fpw, enum Status *status);
void doCStatus(FILE* fpr, FILE* fpw, enum Status *status);
void doNoneStatus(FILE* fpr, FILE* fpw, enum Status *status);
void doEndStatus(FILE* fpr, FILE* fpw, enum Status *status);
void commentConvert();
#endif //_COMMENT_H__
