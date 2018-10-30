#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


const int buffer = 3000;
int WordsNo;
int linesOfText;
void usage();
void scan(int myfid);

int main(int argc, char* argv[])
{
	//Checks to see if arguments are specified
	if(argc < 2)
	{
		usage();	
		printf("%s\n", argv[0]);
		return -1;
	}
	//Reserve vaiables to hold temporary buffer and two integers to count for lines of text
	
	ssize_t stringFile;
	size_t length = 0;
	WordsNo = 0;
	linesOfText = 0;
	char *line = NULL;
	int i;
	
	//create file and open it based on user input, O_RDONLY becuase we want to read it
	for(i = 1; i < argc; i++)
	{
		//goes through argument list and counts each file
		int fid = open(argv[i], O_RDONLY);
		//checks whether there is a file to open
		if(fid < 0)
		{
			perror("Error");
			return(-1);
		}
		else
		{
			//scans the file
			scan(fid);
		}
		//closes the file when it is done
		close(fid);
	}
	//prints out each line of text and words
	printf("Lines of Text: ");
	printf("%d\n", linesOfText);
	printf("Words        : ");
	printf("%d\n", WordsNo);
	printf("ccountln terminates\n");
	return 0;
}

void usage()
{
	printf("Usage: ");
}

void scan(int myfid)
{
	//creates temporary word count and line count
	int tempWordCount = 0;
	int tempLineCount = 0;
	//creates temporary buffer for words
	char fileBuf[buffer];
	enum states {SPACE, WORD};
	int state = SPACE;
	int i = 0;
	//while it is not at the end of the file
	while(read(myfid, fileBuf,1) == 1)
	{
		//checks for words
		if(fileBuf[0] == ' ' || fileBuf[0] == '\t')
		{
			state = SPACE;
		}
		//checks for lines
		else if(fileBuf[0] == '\n')
		{
			tempLineCount++;
			state = SPACE;
		}
		else
		{
			//adds to the word count
			if(state == SPACE)
			{		
				tempWordCount++;
			}
			state = WORD;
		}
	}
	//adds to the actual word and line count
	WordsNo += tempWordCount;
	linesOfText += tempLineCount;
	

}
