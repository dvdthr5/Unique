#include "tree.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(void) {
    printf("Usage:  unique NUM NUM NUM ...       (normal output)\n");
    printf("        unique -d NUM NUM NUM ...    (debugging output)\n");
    exit(0);
}

/*
* Confirm that all characters of the string s are digits.
* If any character is NOT a digit, then call print_usage().
*/
void check_number(const char *s) {
	for (int x = 0;s[x] != '\0'; x++){
		if (!isdigit(s[x])){
			print_usage();
			return;
		}
	}
}

/*
* Usage:    unique 4 8 1 4 ...          call tree_print()
*           unique -d 4 8 1 4 ...       call tree_dump()
*/
int main(int argc, char **argv) {
    if (argc < 2) {
	print_usage();
    }
    int start_index = 1;
    Tree *tree = tree_alloc();
    if (strcmp(argv[1], "-d") == 0){
	start_index = 2;
    }
	
    for (int i = start_index; i < argc; i++){
	check_number(argv[i]);
	int num = atoi(argv[i]);
	tree_add(tree, num);
    }

    if (strcmp(argv[1], "-d") == 0){
	tree_dump(tree);
	  }
else{
	tree_print(tree);
}
	tree_free(&tree);
	return 0;
}
