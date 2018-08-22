/*官方头文件*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <sys/types.h> 
/*自己的头文件*/
#include"print.h"
#include"myfile.h"
#include"mysrcfile.h"

#define STR_MAX 500
#define FILE_MAX 2000
#define OPTION_H "m"

char str[10];
char buf1[STR_MAX];
char buf2[STR_MAX];
char *mypath;

void print_option(char str_num);
int replace_src(char num);
int src_backup(char file_num);
int my_copy(char *in,char *out);
int weite_file(char *write_path,char *write_file_buf);
int cp_reset_src(char file_num);

int main(int argc,char *argv[])
{
	mypath = argv[0];			//获取可执行文件的地址
	*strrchr(mypath,'/')='\0';	//去掉文件名
	puts(mypath);					//命令行输出当前位置
	while(1)
	{
       print_option(1);
		while(strcmp(str,"a")<0 || strcmp(str,OPTION_H)>0)
		{
			scanf("%s",str);
		}
		if(replace_src(*str)!=0)exit(-1);
		else
		{
			printf(CLOSE"\r\n"NONE);
			system("sudo apt-get update");
			printf(GREEN HIGH"换源成功\r\n\r\n"NONE);
		}
		print_option(2);
		*str = '\0';
		puts(str);
		while(*str != 'y' && *str != 'n')
		{
			scanf("%s",str);
		}
		if(*str == 'n')
		{
			exit(-1);
        }
	}
	return 0; 
	exit(-1);
}

void print_option(char str_num)
{
	if(str_num == 1)
	{
		printf(GREEN HIGH"[a]"NONE);
		printf(RED HIGH"恢复出厂设置\r\n"NONE);
		printf(GREEN HIGH"[b]"NONE);
		printf(HIGH"备份还原\r\n"NONE);
		printf(GREEN HIGH"[c]"NONE);
		printf(HIGH"电子科大\r\n"NONE);
		printf(GREEN HIGH"[d]"NONE);
		printf(HIGH"阿里巴巴\r\n"NONE);
		printf(GREEN HIGH"[e]"NONE);
		printf(HIGH"清华大学\r\n"NONE);
		printf(GREEN HIGH"[f]"NONE);
		printf(HIGH"华中科技大学\r\n"NONE);
		printf(GREEN HIGH"[g]"NONE);
		printf(HIGH"华南农业大学(华南用户)\r\n"NONE);
		printf(GREEN HIGH"[h]"NONE);
		printf(HIGH"大连东软信息学院源(北方用户)\r\n"NONE);
		printf(GREEN HIGH"[i]"NONE);
		printf(HIGH"重庆大学源(中西部用户)\r\n"NONE);
		printf(GREEN HIGH"[j]"NONE);
		printf(HIGH"新加坡国立大学\r\n"NONE);
		printf(GREEN HIGH"[k]"NONE);
		printf(HIGH"牛津大学\r\n"NONE);
		printf(GREEN HIGH"[l]"NONE);
		printf(HIGH"韩国KAIST大学\r\n"NONE);
		printf(GREEN HIGH"[m]"NONE);
		printf(RED HIGH"退出\r\n"NONE);
	}
	else if(str_num == 2)
	{
		printf(HIGH"是否继续操作?"NONE);
		printf(GREEN HIGH"[y/n]\r\n"NONE);
    }
}

int replace_src(char num)
{
	char* my_src1;
	char* my_src2;
	switch(num)
	{
		case 'a'://恢复出厂设置
			my_src1=factory_file1;
			my_src2=factory_file2;
		break;
		case 'b'://备份还原
			printf(GREEN HIGH">>>还原备份文件<<<\r\n"NONE);
			if(cp_reset_src(1)!=0 && cp_reset_src(2)!=0)
			{
				printf(RED HIGH"sources.list还原失败\r\n"NONE);
				return -1;
			}
			else
			{
				return 0;
			}
		break;
		case 'c'://电子科大
			my_src1=UESTC1;
			my_src2=UESTC2;
		break;
		case 'd'://阿里巴巴
			my_src1=ALIYUN1;
			my_src2=ALIYUN2;
		break;
		case 'e'://清华大学
			my_src1=THU1;
			my_src2=THU2;
		break;
		case 'f'://华中科技大学
			my_src1=HUST1;
			my_src2=HUST2;
		break;
		case 'g'://华南农业大学(华南用户)
			my_src1=SCAU1;
			my_src2=SCAU2;
		break;
		case 'h'://大连东软信息学院源(北方用户)
			my_src1=DNUI1;
			my_src2=DNUI2;
		break;
		case 'i'://重庆大学源(中西部用户)
			my_src1=CQU1;
			my_src2=CQU2;
		break;
		case 'j'://新加坡国立大学
			my_src1=NUS1;
			my_src2=NUS2;
		break;
		case 'k'://牛津大学
			my_src1=Oxford1;
			my_src2=Oxford2;
		break;
		case 'l'://韩国KAIST大学
			my_src1=KAIST1;
			my_src2=KAIST1;
		break;
		case 'm'://退出
			exit(-1);
		break;
		default:
		printf(RED HIGH"未知选项!\r\n"NONE);
		return -1;
		break;
	}
	if(num!='b')
	{
		printf(GREEN HIGH">>>备份sources.list<<<\r\n"NONE);
		src_backup(1);
	
		printf(GREEN HIGH">>>备份raspi.list<<<\r\n"NONE);
		src_backup(2);
	
		printf(GREEN HIGH">>>更换树莓派源<<<\r\n"NONE);
		if(weite_file(src_path1,my_src1)!=0)
		{
			printf(RED HIGH"换源失败,请尝试root权限运行\r\n"NONE);
			return -1;
		}
		else
		{
			if(chmod(src_path1,0644)==0)
			{
				printf(GREEN HIGH"sources.list权限修改完成\r\n"NONE);
			}
			else
			{
				printf(RED HIGH"sources.list权限修改失败！请用root权限\r\n"NONE);
				return -1;
			}
		}
		if(weite_file(src_path2,my_src2)!=0)
		{
			printf(RED HIGH"换源失败,请尝试root权限运行\r\n"NONE);
			return -1;
		}
		else
		{
			if(chmod(src_path2,0644)==0)
			{
				printf(GREEN HIGH"raspi.list权限修改完成\r\n"NONE);
			}
			else
			{
				printf(RED HIGH"raspi.list权限修改失败！请用root权限\r\n"NONE);
				return -1;
			}
		}
	}
	else
	{
		printf(RED HIGH"没有该选项！\r\n"NONE);
		return -1;
	}
	return 0;
}

int my_copy(char *in_path,char *out_path)
{
	char file_buf[FILE_MAX];		//设置缓冲区大小
	FILE *in,*out;					//定义两个文件流，分别用于文件的读取和写入int len;
	int len;						//len为fread读到的字节长

	if((in=fopen(in_path,"r"))==NULL)
	{	//打开源文件的文件流
		printf(RED HIGH"源文件不存在！\r\n"NONE);
		return -1;
	}
	if((out=fopen(out_path,"w"))==NULL)
	{	//打开目标文件的文件流
		printf(RED HIGH"创建目标文件失败！\r\n"NONE);
		return -1;
	}
	while((len=fread(file_buf,1,FILE_MAX,in))>0)
	{//从源文件中读取数据并放到缓冲区中，第二个参数1也可以写成sizeof(char)
		fwrite(file_buf,1,len,out);	//将缓冲区的数据写到目标文件中memset(buffer，0，1024);
	}
	fclose(out);
	fclose(in);
	return 0;
}

int weite_file(char *write_path,char *write_file_buf)
{
	FILE *out;	//定义文件流
	if((out=fopen(write_path,"w"))==NULL)
	{	//打开目标文件的文件流
		printf(RED HIGH"创建目标文件失败！\r\n"NONE);
		return -1;
	}
	fwrite(write_file_buf,1,strlen(write_file_buf)-1,out);	//将缓冲区的数据写到目标文件中memset(buffer，0，1024);
	fclose(out);
	return 0;
}

int src_backup(char file_num)
{
	char* backup_file;
	char* src_path;

	if(file_num==1)
	{
		backup_file = backup_file1;
		src_path = src_path1;
	}
	else if(file_num==2)
	{
		backup_file = backup_file2;
		src_path = src_path2;
	}
	else
	{
		printf(RED HIGH"未知文件!\r\n"NONE);
		return -1;
	}

	memset(buf1,0,sizeof(buf1));
	strcat(buf1,mypath);
	strcat(buf1,backup_file);
	if(access(buf1,F_OK) != 0)
	{
		if(my_copy(src_path,buf1)==0)
		{
			printf(GREEN HIGH"备份复制完成\r\n"NONE);
			if(chmod(buf1,0777)==0)
			{
				printf(GREEN HIGH"备份权限修改完成\r\n"NONE);
			}
			else
			{
				printf(RED HIGH"备份文件权限修改失败！请用root权限\r\n"NONE);
				return -1;
			}
		}
	}
	else
	{
		printf(RED HIGH"备份已存在!\r\n"NONE);
		return -1;
	}
	return 0;
}

int cp_reset_src(char file_num)
{
	char* backup_file;
	char* src_path;

	if(file_num==1)
	{
		backup_file = backup_file1;
		src_path = src_path1;
	}
	else if(file_num==2)
	{
		backup_file = backup_file2;
		src_path = src_path2;
	}
	else
	{
		printf(RED HIGH"未知文件!\r\n"NONE);
		return -1;
	}

	memset(buf1,0,sizeof(buf1));
	strcat(buf1,mypath);
	strcat(buf1,backup_file);
	if(access(buf1,F_OK) == 0)
	{
		if(my_copy(buf1,src_path)==0)
		{
			printf(GREEN HIGH"文件还原完成\r\n"NONE);
			if(chmod(src_path,0644)==0)
			{
				printf(GREEN HIGH"文件权限修改完成\r\n"NONE);
			}
			else
			{
				printf(RED HIGH"文件权限修改失败！请用root权限\r\n"NONE);
				return -1;
			}
		}
	}
	else
	{
		printf(RED HIGH"未找到备份文件，请将备份文件放到程序目录下!\r\n"NONE);
		return -1;
	}
	return 0;
}
