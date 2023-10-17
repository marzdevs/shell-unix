#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>



int main(){


	char command[600];
	
	printf("$ "); // prompt

	fgets(command, sizeof(command), stdin); // takes the users input and stores it in command

	
	

	// echo command
	if(strncmp(command,"echo\n", 4) == 0)
	{
        char* token = command; 
		
		command[strcspn(command, "\n")] = 0;  	

 		token = strtok(command, " \" ");
		
		token = strtok(NULL, " \" ");

		while ((token = strtok(NULL, " \" ")) != NULL)
		printf("%s ", token);
		
 		
		fflush(stdout);

	}
	// PSI command
	else if(strncmp(command,"PSI\n", 4) == 0)
	{

	printf("The PSI command works.\n");
	
	}
	// cat command prints out the contents of the file chosen
	else if(strncmp(command,"cat\n", 4) == 0 )
	{

		FILE *file;

		char filename[200];
		int outptFile;
		scanf("%s", filename);

		file = fopen(filename, "r"); 
    	
		if (file == NULL) 
    	{ 
        printf("Unable to open the file, please check if it does exist.\n"); 
        exit(1); 
   		} 
		else
		{
			printf("File was opened!\n");
		}

		
	if(file)
	{
		//gets the file character by character until it reaches the end of file
		// when reached eof it prints the contents of the file
		while((outptFile =getc(file))!= EOF)
		putchar(outptFile);
		fscanf(file, "%[^\n]", filename);
    	printf("%s\n", filename);


		fclose(file);
	
	}

	}
	// cp copies content of a file ot another file
	else if(strncmp(command,"cp\n", 2) == 0)
	{

		FILE *firstFile, *secondFile;
		char fileCopy[200];
		char copied;

		scanf("%s", fileCopy);

		// reads and writes the content of the file
		firstFile = fopen(fileCopy, "w+");
		secondFile = fopen(fileCopy, "w+");

		//copied = fgetc(firstFile);

		if(copied == NULL)
		{
			printf("Failed to open file.");
			return 1;
		}
		else
		{
		while (copied != EOF)
		{
			fputc(copied, secondFile);
			copied = fgetc(firstFile);
		}
		}

		printf("File copied to %s", fileCopy);

		fclose(firstFile);
		fclose(secondFile);
	
	}
	// removes a chosen file from directorys
	else if(strncmp(command,"rm\n", 2) == 0 )
	{
		FILE *file;
		char filename[100];
		scanf("%s", filename);

		file = fopen(filename, "w");

		fclose(file);

		if(remove(filename) == 0)
		{

			printf("file was deleted successfully!\n");
		
		}
		else
		{
			printf("File can not be deleted.\n");
		}
		
	}
	// creats a directory
	else if(strncmp(command,"mkdir\n", 4) == 0 )
	{
	
		char directoryName[50];
		char *token = command;
		command[strcspn(command, "\n")] = 0;  	

		token = strtok(command, " ");
		
		token = strtok(NULL, " ");
		
		mkdir(token, 0777);
		printf("$ ls\n");
		printf("$ %s \n", token);

		
	}	
	
	// removes the chosen directory
	else if(strncmp(command,"rmdir\n", 4) == 0 )
	{
		char *directoryName = command;
		command[strcspn(command, "\n")] = 0;  	

		directoryName = strtok(command, " ");
		
		directoryName = strtok(NULL, " ");

		if(remove(directoryName) == 0)
		{
			printf("directory was deleted successfully\n");

		}
		else
		{
			printf("Directory can not be deleted.\n");
		}
	
	
	}
	else if(strncmp(command, "exit\n", 4) == 0)
	{
		
		printf("You have quit the shell.\n");
		

	}
	
	else
	{
		printf("Did not input a valid command.\n");
	}

	return 0;
}

		




















