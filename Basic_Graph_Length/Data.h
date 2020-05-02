#ifndef __Data_H__
#define __Data_H__

typedef struct _Graph {
	char ch;
	int* length;
	struct _Graph **link;
}Graph;


#endif

#define START 6
#define END 6

#define LEN_START 1
#define LEN_END 9

#define TRUE 1
#define FALSE 0
#define FAIL -1
