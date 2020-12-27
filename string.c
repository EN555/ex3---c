#include<stdio.h>
#include<string.h>

#define LINE 256
#define WORD 30


int getLine(char ch[]){
	
	int count=0;
	char c; 
	while((c = getchar()) != '\n' && c != EOF && c != '\r'){ 	
		ch[count++] = c;
	}
	getchar();
	ch[count]= '\0';
	return count;
}




int word_substring(const char * str1, const char *str2){
		
		int counter = 0; 
		int size = strlen(str2);
		

		while(*str1 && *str2){
			
			if(*str1 == *str2){
				counter++;
				str2++;
			}
			str1++;
			
        }
			if(counter == size){
				return 1;
			}
		return 0;		//return 0 or 1 
	
}

int line_substring(const char * str1, const char *str2){	//get line and word
	
	char word[WORD];	//sentd word word to word_substring function
		
		int i=0;
		int num=0;
		
		while(*str1){
			
			if(*str1 == ' ' || *str1 == '\t' || *str1 == '\r' || *str1 == '\n' || *str1 == '\0'){
		
			word[i] = '\0'; 
			num =word_substring(&word[0] , str2);
			str1++;
			if(num == 1){
				return 1;
			}
			
			i=0;
			}
			
			word[i++] = *str1;
			str1++;
			
			
		}
			//chek the final word
			
			num =word_substring(&word[0] , str2);
			if(num== strlen(str2))
				num=1;
		
	return num; 
}

int A(char *word){
	
char line[LINE];

int i=0;
	while(getLine(line)){
		

		if(line_substring(line, word)){
			
			while(line[i]){

				printf("%c" , line[i]);
				i++;
			}			
			i=0;
			printf("\n");
		}
	}
	return 0;	
}	



int word_similiar(const char * str1, const char *str2){
		
		int counter = 0; 
		int size = strlen(str2);
		

		while(*str1 && *str2){
			
			if(*str1 == *str2){
				counter++;
				str2++;
			}
			str1++;
			
        }
			if(counter == size || counter-1 == size){
				return 1;
			}
		return 0;		//return 0 or 1 
	
}

int line_similiar(const char * str1, const char *str2){	//get line and word
	
	char word[WORD];	//sentd word word to word_substring function
		
		int i=0;
		int num=0;
		
		while(*str1){
			
			if(*str1 == ' ' || *str1 == '\t' || *str1 == '\r' || *str1 == '\n' || *str1 == '\0'){
		
			word[i] = '\0'; 
			num =word_similiar(&word[0] , str2);
			str1++;
			if(num == 1){
				i=0;
				while(word[i]){
						
					printf("%c" , word[i]);
					i++;
				}
					printf("\n");
			}
			
			i=0;
			}
			
			word[i++] = *str1;
			str1++;
			
			
		}
			//chek the final word
			
			num =word_similiar(&word[0] , str2);
			if(num== 1){
				i=0;
				while(word[i]){	
					printf("%c" , word[i]);
					i++;
				}
					printf("\n");
			}
		
	return num; 
}

int B(char *word){
	
char line[LINE];

	while(getLine(line)){
		line_similiar(line , word);
	}
	return 0;	
}
int main()
{	

char word[WORD];
char ques[2];
char c;
int i=0;
while((c = getchar()) != ' ' && c != '\t'){
	word[i++] = c;
}
word[i] = '\0';
ques[0] = getchar();
ques[1] ='\0';

getchar() ; getchar() ; getchar() ; getchar() ; 

if(ques[0] == 'a'){
	A(word);	
}
else{
	B(word);
}

    return 0;
}