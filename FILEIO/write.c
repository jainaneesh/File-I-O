#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define FILE "write.txt"

int main(int argc, char *argv[]){

	// Checking if enough arguments were passed in
	if ( argc < 2 )
	{
		printf("\n\nAuthor: Aneesh Jain\n");
		printf("========== write usage ===========\n");
		printf("Usage: ./write <string_to_write>\n");
		exit(EXIT_FAILURE);
	} 
	
	if ( argc > 2 ){
		printf("\n\nAuthor: Aneesh Jain\n");
		printf("========== write usage ===========\n");
		printf("Usage: ./write <string_to_write>\n");
		printf("More than required number of arguments were passed\n");
		exit(EXIT_FAILURE);
	}

	// Variable to store user data
	char user_input[10];
	
	// Storing the input data in the user_input
	// This assumes that the user data is only 10 characters long
	strcpy(user_input, argv[1]);

	// Storing the number of bytes written to the file
	ssize_t bytes_written;

	// Variable to store file descriptor
	int fd = 0;

	// Open the file and create if it doesn't exist
	fd = open(FILE, O_RDONLY | O_WRONLY | O_CREAT, 0600);

	if ( fd < 0 ){
		perror("File could not be opened");
	} else {
		printf("File successfully opened with file descriptor %d", fd);
	}

	bytes_written = write(fd, &user_input, sizeof(user_input));

	if ( bytes_written < 0 ){
		perror("Write failed");
	}
	
	// Closing the file descriptor to free it
	close(fd);

}
