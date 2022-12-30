#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

enum {
		TK_NOTYPE = 0, TK_LB, TK_RB, TK_PLUS, TK_SUBTR, TK_MUL, TK_DIV, TK_EQ, TK_INTD
};

typedef struct token {
		int type;
		char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};

static bool check_parentheses(int p, int q){
		int i;
		int pa_counter = 0;
		//int nr_token;
		//snr_token = q + 1;
		if((tokens[p].type != TK_LB)||(tokens[q].type != TK_RB)){
			printf("the first step is false.\n");
			return false;
		}
		for(i = p + 1; i < q; i = i+1){
			if(tokens[i].type == TK_LB){
				pa_counter = pa_counter + 1;
		}
			else if(tokens[i].type == TK_RB){
				pa_counter = pa_counter - 1;
			}
			else if(pa_counter < 0){
			printf("the second step is false.\n");
				return false;
			}
		}
		if(pa_counter != 0){
			printf("the last step is false,pa_counter=%d\n",pa_counter);
			return false; 
		}
		return true;
}

static int op_expr(int p, int q){
	int position;
	int i = 0;
	int j = 0;
	int pa_counter = 0;  //count parenthesis
	int f_counter = 0;   //count plus and subtraction 
	for(j = p; j <= q; j = j + 1){ 
		if((tokens[j].type == TK_PLUS)||(tokens[j].type == TK_SUBTR))
				f_counter = f_counter + 1;
	}
	printf("f_counter=%d\n",f_counter);
	for(i = p; i <= q; i = i + 1){
		if(tokens[i].type == TK_LB)
			pa_counter = pa_counter + 1;
		else if(tokens[i].type == TK_RB)
			pa_counter = pa_counter - 1;
		printf("pa_counter[%d]=%d\n",i,pa_counter);
		if((tokens[i].type==TK_PLUS)||(tokens[i].type==TK_SUBTR)||(tokens[i].type==TK_MUL)||(tokens[i].type==TK_DIV)){
			if (pa_counter == 0){
				if(f_counter > 0){       //exist + -
					if((tokens[i].type == TK_PLUS)||(tokens[i].type ==TK_SUBTR))
						position = i;
						printf("+positin[%d]=%d\n",i,position);
				}
				else if(f_counter == 0){ //only * /
					if((tokens[i].type == TK_MUL)||(tokens[i].type ==TK_DIV))
						position = i;
						printf("*positin[%d]=%d\n",i,position);
				}		
			}
		}			
	}
	return position;
}

int main(void){
		
	//input	expr = "4+3*(2-1)-1"; "4*3*4"
		int p = 0;
		int q = 4;
		/*tokens[0].type = TK_INTD;
  		strcpy(tokens[0].str, "4");
		tokens[1].type = TK_PLUS;
		tokens[2].type = TK_INTD;
		strcpy(tokens[2].str, "3");
		tokens[3].type = TK_MUL;
		tokens[4].type = TK_LB;
		tokens[5].type = TK_INTD;
  		strcpy(tokens[5].str, "2");
  		tokens[6].type = TK_SUBTR;
  		tokens[7].type = TK_INTD;
  		strcpy(tokens[7].str, "1");
  		tokens[8].type = TK_RB;
		tokens[9].type = TK_SUBTR;
		tokens[10].type = TK_INTD;
  		strcpy(tokens[10].str, "1");
  		*/
  		tokens[0].type = TK_INTD;
  		strcpy(tokens[0].str, "4");
  		tokens[1].type = TK_MUL;
  		tokens[2].type = TK_INTD;
  		strcpy(tokens[2].str, "3");
  		tokens[3].type = TK_MUL;
  		tokens[4].type = TK_INTD;
  		strcpy(tokens[4].str, "4");
  		
  		
		//printf("tokens[0].str = %s\n", tokens[0].str);
		//printf("tokens[2].str = %s\n", tokens[2].str);
		int i ;
		for (i = 0; i <= q; i = i+1){
			printf("tokens[%d].type = %d\n",i,tokens[i].type);
		}

		if (check_parentheses(p, q) == true){
			printf("correct!\n");
		}

		else{
			printf("uncorrect!\n");
		}
		
		//find the position of the Primary operator
		int op;
		op = op_expr(p, q);
		printf("op:%d\n",op);
		printf("op_type:%d\n",tokens[op].type);
		
	return 0;
}
