#ifndef __COMMEMT_CONVERT_H__  //防止头文件被重复包含和编译
#define __COMMEMT_CONVERT_H__
#define _CRT_SECURE_NO_WARNINGS 1
#define INPUTFILENAME "D://1//input.c"
#define OUTPUTFILENAME "D://1//output.c"
#include<stdio.h>
#include<stdlib.h>

void CommentCon();
void ConvertWork(FILE*read,FILE*write);
void NULL_state(FILE*read, FILE*write);//空状态
void C_state(FILE*read, FILE*write);//c状态
void CPP_state(FILE*read, FILE*write);//c++状态
typedef enum STATE_CONVERT
{
	NULL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
}State_type;

#endif//__COMMEMT_CONVERT_H__