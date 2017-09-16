//print all combos of n brackets
// For 3: ()()(), (())(), ()(()), ((()))

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void print_b(int *b, int size) {
	int i=0, j;

	while(i<size){
		for(j=0; j<b[i]; j++)
			printf("(");
		for(j=0; j<b[i]; j++)
			printf(")");
		i += b[i];
	}
	printf("\n");
}

//In the current position p, go through 1, 2, 3 ...combinations
void bracket_combo(int p, int size, int *b) {
	
	int i, j=1;
	if(p == size){
		print_b(b, size);
		return;
	}

	for(i=p; i<size; i++){
		b[p] = j;
		bracket_combo(p+j, size, b);
		j++;
	}
}

/*The above solution doesn't work. For 3 it doesn't print (()()) */

//another way to look at this problem is, one bracket has to be opened first,
//then there are two choices, close it or open another until max are opened.
//If max are open then there is only one choice after that, close all.

void print_paren(int n, vector<char> &v, int *open, int*close) {

	if(n==0) {
		int count=0;
		for(int i=0; i<v.size(); i++) {
			if(v[i] == '(')
				count++;
			else	
				count--;
			cout << v[i];
		}
		while(count){
			count--;
			cout << ')';
		}
		cout << endl;
		return;
	}

	/*first open a bracket */
	v.push_back('(');
	(*open)++; //be very carful with operator precedence.
	print_paren(n-1, v, open, close);
	(*open)--;
	v.pop_back();

	/*try to close a brack */
	if(*open > *close) {
		v.push_back(')');
		(*close)++;
		print_paren(n, v, open, close); //pass n, not n-1 since ( was popped before.
		(*close)--;
		v.pop_back();
	}
	return;
}



			

int main() {
	
	int b[10];
	
	bracket_combo(0, 3, b);

	printf("\n\n");
	vector<char> v;
	int open=0, close=0;
	print_paren(3,v,&open, &close);
}

