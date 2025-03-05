#include <iostream>
#include <cstring>
#include <math.h>

bool isoperator(char c){
	if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^') return true;
	return false;
}

int prio(char c){
	if(c == '^') return 3;
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;
	
	return -1; //untuk handle buka kurung
}

char ans[1000];

void infixtopostfix(char s[]){
	int len = strlen(s);
	char stack[len];
	int top = -1;
	
	int idx = 0;
	
	for(int i=0;i<len;i++){
		if(s[i]=='('){
			//push ke stack
			stack[++top] = s[i];
		}
		else if(s[i]==')'){
			while(stack[top] != '('){
				ans[idx++] = stack[top--];
			}
			top--; //pop (
		}
		else if(isoperator(s[i])){
			// + - * / ^
			while(top != -1 && prio(s[i])<=prio(stack[top])){
				ans[idx++] = stack[top--];
			}
			stack[++top] = s[i];
		}
		else{
			ans[idx] = s[i];
			idx++;
		}
	}
	
	while(top != -1){
		ans[idx] = stack[top--];
	}
	printf("%s\n", ans);
	
	
}

int main(){
	
	char input[15] = "a+b*(c-d)/e";
	infixtopostfix(input);
	
	printf("%s\n", ans);
	
	int stack[100];
	int top = -1;
	
	for(int i=0;i<strlen(ans); i++){
		if(isoperator(ans[i])){
			int a = stack[top];
			top--;
			int b = stack[top];
			top--;
			
			int tmp;
			
			if(ans[i]=='+'){
				tmp = b+a;
			}
			else if(ans[i]=='-'){
				tmp = b-a;
			}
			else if(ans[i]=='*'){
				tmp = b*a;
			}
			else if(ans[i]=='/'){
				tmp = b/a;
			}
			else if(ans[i]=='^'){
				tmp = pow(b, a);
			}
			
			top++;
			stack[top] = tmp;
		}
		else{
			top++;
			int tmp = ans[i] - '0';
			stack[top] = ans[i];
		}
	}
	printf("%d\n", stack[top]);
}