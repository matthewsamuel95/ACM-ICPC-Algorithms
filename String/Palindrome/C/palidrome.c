#include <stdio.h>
#include <string.h>


int chkpal(char word[]){
	int i, j;
	j = strlen(word) - 1;
	for(i = 0; i < strlen(word); i++){
		if(word[i] != word[j])
			return 0;
		j--;
	}
	return 1;
}

int main(){
	char palv[50];
	int i = 0;
	while(i < 3){
	  scanf("%s", palv);
	  if(chkpal(palv))
	    printf("palindroma");
	  else
	    printf("n palindroma");
	  printf("\n");
	  i++;
	}	
}
