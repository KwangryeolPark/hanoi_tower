/*
		
	*재귀함수를 이용한 하노이탑의 해법 보여주기
	*박광렬
	*2019.05.15	23:56 

*/
/*
	2개일 때	원판 1을 B에 옮긴 후 
				원판 2를 C에 옮긴 후
				원판 1을 C에 옮김 
				
	3개일 때 	원판 1~2를 B에 옮긴 후	-> 2개를 A -> C로 옮기는 방식으로 A -> B 수행 (원판 3는 어차피 밑에 깔려 있기 때문에 없는 것처럼 취급 가능) 
				원판 3을 C에 옮긴 후
				원판 1~2를 C에 옮김 	-> 같은 방법으로 B -> C로 옮김
				
	4개일 때	원판 1~3을 B에 옮긴 후	-> 3개를 A -> C로 옮기는 방식으로 A -> B 수행 (원판 4는 어차피 밑에 깔려 있기 때문에 없는(바닥)처럼 취급 가능)
				원판 4를 C에 옮긴 후
				원판 1~3을 C에 옮김		-> 같은 방법으로 B -> C로 옮김  
				
	n개일 때	원판 1~n-1을 B에 옮긴 후
				원판 n을 C에 옮긴 후
				원판 1~n-1을 C에 옮김 
*/
#include <stdio.h>

void show(int, char, char, char);	//하노이 탑의 결과를 보여 주는 함수
 


int main(void) {
	int i;							//원판의 수가 저장될 변수 
	printf("몇개가 있나요?");		//
	scanf("%d", &i); 		
	show(i, 'A', 'B', 'C');			//첫 번째 기둥을 A, 두 번째 기둥을 B, 세 번째 기둥을 C라고 둠 
}

//원판의 수, 옮길 원판이 있는 기둥, 안 쓰는 기둥(다른 원판이 사용), 옮길 원판이 옮겨 갈 기둥 
void show(int n, char from, char tmp, char to) {
	if(n == 1) {	// 원판의 수가 1개면  
		printf("Move 1 from %c to %c\n", from, to); 	//from에서 to를 출력 
	} else {
		show(n - 1, from, to, tmp);		//1 ~ n - 1를 from(=A)에서 tmp(=B)로 옮기기 
		printf("Move %d from %c to %c\n", n, from, to);// 
		show(n - 1, tmp, from, to); 	//1 ~ n - 1를 tmp(=B)에서 to(=C)로 옮기기 
	}
}

