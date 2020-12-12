#include <stdio.h>

void fun(char temp[],int index){
	int i=1,flag=0,lindex=0;
	static char last[50];

	for(i=0; i<index; i++){
		if(temp[i] == ' ' || temp[i] == '\t')
			temp[i] = '-';
	}
	

	for(i=0; i<index; i++){
		if(temp[i] == '-')
			break;
		else
			printf("%c", temp[i]);
	}
	printf(" ");
	
	//===================================================

	for(i=index-1;i>=0;i--){
		if(temp[i] == '-')
			break;
		else{
			last[lindex++] = temp[i];
			temp[i] = '*';
		}
	}
	last[lindex++] = '-';

	for(;i>=0;i--){
		if(temp[i] >= '0' && temp[i] <= '9')
			break;
		else
			temp[i] = '*';
	}
	for(;i>=0;i--){
		if(temp[i] == '-')
			break;
		else{
			last[lindex++] = temp[i];
			temp[i] = '*';
		}
	}

	// for(i=1;i<index;i++)
	// 	printf("%c",temp[i]);
	for(i=lindex-1; i>=0; i--){
		if(last[i] == '-')
			printf(" ");
		else
			printf("%c",last[i]);
	}
}

void main(){
	FILE  *fp;
	char ch,temp[100];
	int index=0;
	fp = fopen("input.txt","r");

	while(1){
		ch = fgetc(fp);
		if(ch == EOF){
			break;
		}
		//printf("%c",ch);
		if(ch == '\n'){
			fun(temp,index);
			index = 0;
		}
		temp[index++] = ch;
	}
	printf("\n");
	fclose(fp);
}