#include <stdio.h>
#include <string.h>

void read_stdin(void);
void read_file(char *);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		read_stdin();
		return 0;
	}

	for (int i = 1; i < argc; i++) {
		if (strncmp(argv[i], "-", 1) == 0) {
			read_stdin();
			continue;
		}

		read_file(argv[i]);
	}
}

void read_stdin(void)
{
	int buffer_size = 128;
	char buffer[128];

	while (fgets(buffer, buffer_size, stdin)) {
		printf("%s", buffer);
	}
}

void read_file(char *filename)
{
	int buffer_size = 128;
	char buffer[128];

	FILE *fp = fopen(filename, "r");

	while (fgets(buffer, buffer_size, fp)) {
		printf("%s", buffer);
	}

	fclose(fp);
}
