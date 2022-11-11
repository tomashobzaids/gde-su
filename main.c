#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* dividers[] = {
	"Boro",
	"Dra",
	"Km",
	"Mrazek",
	"Plu",
	"Ser",
	"Sku",
	"Z"
};

char* mistnosti[] = {
	"A112",
	"A113",
	"D105",
	"D0206",
	"D0207",
	"E104",
	"E105",
	"E112"
};

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Invalid arguments.\n");
		printf("Usage: %s [surname]\n", argv[0]);
		return 0;
	}

	int skupina=0;
	while (dividers[skupina][0] < argv[1][0]) {
		skupina++;
	}

	if (dividers[skupina][0] == argv[1][0]) {
		int posun = 1;
		while (dividers[skupina][posun] == argv[1][posun]) {
			posun++;

			if (posun >= strlen(dividers[skupina]) || posun >= strlen(argv[1])) {
				break;
			}
	   	}

		if (dividers[skupina][posun] < argv[1][posun]) {
			skupina++;
		}
		
	}

	printf("Skupina %i [1-8] v mistnosti %s\n", skupina+1, mistnosti[skupina]);

	return 0;
}
