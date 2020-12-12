#include <stdio.h>

void Hanoi(int disk, char source, char dest, char aux){
	if(disk == 0){
		//printf("Move disk from %c to %c.\n",source,dest);
		return;
	}
	else{
		Hanoi(disk-1, source,aux,dest);
		printf("Move disk from %c to %c.\n",source,dest);
		Hanoi(disk-1, aux,dest,source);
	}
}

void main(){
	Hanoi(3,'S','D','A');
}