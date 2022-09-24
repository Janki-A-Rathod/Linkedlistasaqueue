#gcc -lm -o LLAQExecutable FunctionsOfLLAQ.c LinkedlistAsaQueue.c -pthread
        
INCLUDES += -I./inc/
CC = gcc
CFLAGS = -lm -o 
CFLAG2= -pthread
EXECUTABLE =out/LLAQExecutable
SRC1=src/LinkedlistAsaQueue.c
SRC2=src/FunctionsOfLLAQ.c
all:
	 $(CC) $(INCLUDES) $(CFLAGS) $(EXECUTABLE)  $(SRC1) $(SRC2) $(CFLAG2) 
install:
	$(EXECUTABLE)
clean:
	rm -rf LLAQExecutable
