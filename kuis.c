#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <pthread.h>

typedef struct 
{
	char file[MAXSIZE];
	char panjang[MAXSIZE];
	char tampung[MAXSIZE];
	int n;
	FILE *fsumber
	struct dirent *dir;
}bungkusan;

int main()
{
	bungkusan *data;
	data = (bungkusan*) malloc (sizeof(bungkusan));

	struct dirent *dir;
	DIR *directory;
	int stat = 1;
	char masukan[MAXSIZE];
	int status;
	int pid;

	while(stat == 1)
	{
		printf("Silahkan masukan direktori yang ingin di cek (ketik 'end' keluar):	");
		scanf("%s", masukan);

		if (strcmp(masukan, "end") == 0)
		{
			stat = 0;
		}
		else
		{
			directory = opendir(masukan);

			if ((directory) && (data->dir = readdir(directory)) != NULL)
			{
				if (data->dir != NULL)
				{
					if((pid = fork()) < 0)
					{
                        perror("error fork");
                        exit(-1);
                    }
                    else if(pid == 0)
                    {
                        proses(data);
                        exit(0);
                    }

                    data->dir = readdir(directory);
				}

				while(wait(&status) > 0);
			}

			else
			{
				printf("Direktori tidak valid.\n");
			}

			closedir(directory);
		}
	}
	
	return 0;
}

void proses(bungkusan *data)
{
	char ch;	

	strcpy(data->file, data->dir->d_name);
	int len = strlen(data->file);

    	if((len > 4) && (data->file[len - 1] == 't') && (data->file[len - 2] == 'x') && (data->file[len - 3] == 't') && (data->file[len - 4] == '.')){

		data->fsumber = fopen(data->file, "r");

		if(data->fsumber == NULL)
		{
		    printf("File %s tidak dapat dibuka.\n\n", data->file);
		}

		pthread_t thread;

		do 
		{
			fscanf(data->fsumber, "%s", data->panjang);

			strcpy(data->tampung, data->panjang);

		    	ch = fgetc(fsumber);
		
			while(ch != EOF)
			{
				if(ch == ' ' || ch == '\n')
				{
					data->m++;
				}
			
				ch = fgetc(fsumber);
			}
		}
		
		while(fgetc(var->fsumber) != EOF);

		pthread_create(&thread, NULL, print, (void*) data);
		pthread_join(thread, NULL);

		fclose(data->fsumber);
	}
}

void *print(void* data)
{
	bungkusan *dat
	dat = (bungkusan*) data;

	printf("Jumlah kata dalam file %s sebanyak:	%d\n", dat->file, dat->n);
	printf("\n');

	return NULL;

}


