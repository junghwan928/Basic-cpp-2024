#include <iostream>

int main(int argc, char* argv[]) {

	printf("argc: %d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] : %s\n", i, argv[i]);
	}

	printf("End of Program!!\n");
	return 0;


}