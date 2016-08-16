#define _CRT_SECURE_NO_WARNINGS 1
#include "CommentConvert.h"

State_type state;

void NULL_state(FILE*read, FILE*write)
{
	int first = fgetc(read);
	int second = 0;
	switch (first)
	{
	case '/':
		second = fgetc(read);
		if (second == '*')
		{
			fputc(first,write);
			fputc('/',write);
			state = C_STATE;
		}
		else if (second == '/')
		{
			fputc(first, write);
			/*�޸ĵ�*/
			fputc('/', write);
			state = CPP_STATE;
		}
		else
		{
			fputc(first, write);
			fputc(second, write);
		}	
		break;
	case EOF:
		/*�����eof�Ͳ����������ʲô������*/
		/*fputc(first,write);*/    
		state = END_STATE;
		break;
	default:
		fputc(first, write);
		break;
	}
}

void C_state(FILE*read, FILE*write)
{
	int first = fgetc(read);
	int second = 0;
	int third = 0;
	switch (first)
	{
	case '*':
		second = fgetc(read);
		if (second == '/')
		{  
			third = fgetc(read);
			if (third == '\n')
				fputc(third, write);
			else
			{
				fputc(third, write);
				fputc('\n', write);
			}
			/*���ڶ�һ���е�����*/
		    /*fputc('\n', write);*/
			state = NULL_STATE;
		}
		else if (second == '*')
		{
			third = fgetc(read);
			if (third == '/')
			{
				putc(first, write);
				putc('\n',write);
				state = NULL_STATE;
			}
			else
			{
				putc(first,write);
				putc(second,write);
				putc(third,write);
			}
		}
		else
		{
			fputc(first, write);
			fputc(second, write);
		}
		break;
	case '\n':fputc(first, write);
		fputc('/',write);
		fputc('/',write);
		break;
		/*c�в�Ӧ����eof*/
	/*case EOF:
		state = END_STATE;
		break;*/
	default:
		fputc(first, write);
		break;
	}
}

void CPP_state(FILE*read, FILE*write)
{
	int first = fgetc(read);
	/*int second = 0;*/
	switch (first)
	{
	case '\n':
		/*�޸ĵ�*/
		/*fputc('*', write);
		fputc('/', write);*/
		fputc(first,write);
		state = NULL_STATE;
		break;
	//case '/':
	//	/*c++ע������*/
	//	second = getc(read);
	//	if (second == '/')
	//	{
	//		;
	//	}
	//	else if (second == '*')
	//	{
	//		;
	//	}
	//	else
	//	{
	//		fputc(first, write);
	//		fputc(second,write);
	//	}
	//	break;
	//case '*':
	//	/*c++ע������*/
	//	second = getc(read);
	//	if (second == '/')
	//	{
	//		;
	//	}
	//	else
	//	{
	//		fputc(first, write);
	//		fputc(second, write);
	//	}
	//	break;
	case EOF:
		/*�޸ĵ�*/
		/*fputc('*', write);
		fputc('/', write);*/
		state = END_STATE;
		break;
	default:
		fputc(first, write);
		break;
	}

}

void ConvertWork(FILE*fRead, FILE*fWrite)
{
	state = NULL_STATE;
	while (state != END_STATE)
	{
		switch (state)
		{
		case NULL_STATE:NULL_state(fRead,fWrite);
			break;
		case C_STATE:C_state(fRead, fWrite);
			break;
		case CPP_STATE:CPP_state(fRead, fWrite);
			break;
		default:
			break;
		}
	}

}
void CommentCon()
{
	FILE*fWrite = NULL;
	FILE*fRead = fopen(INPUTFILENAME, "r");
	if (fRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	fWrite = fopen(OUTPUTFILENAME, "w");
	if (fWrite == NULL)
	{
		fclose(fRead);
		perror("open file for write");
		exit(EXIT_FAILURE);	
	}
	ConvertWork(fRead,fWrite);
		fclose(fRead);
		fclose(fWrite);
}