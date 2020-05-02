#include"ALL.h"


#ifdef ACTUAL
int main()
{
	srand((unsigned int)time(NULL));
	Graph** node;
	int** ap = Make_Route();
	int size = _msize(ap) / sizeof(int*);
	char* ch_ary = (char*)calloc(size + 1, sizeof(char));
	int i = 0;
	int j = 0;
	int row, col;

	int** length_table;
	int sum = 0, min = 0, max = 0;

	char* max_ary = (char*)malloc(size + 1);
	char* min_ary = (char*)malloc(size + 1);
	char start, end;

	memset(max_ary, 0, size + 1);
	memset(min_ary, 0, size + 1);

	Print_Route_info(ap);
	puts("");
	node = Make_Node(ap);
	Input_Route(node, ap);
	Input_Length(node);
	length_table = Make_Length_Table(node);

	
	for (i = 0; i < size; i++)
	{
		printf("%c: ", node[i]->ch);
		for (j = 0; j < size; j++)
		{
			if (node[i]->link[j])
				printf("%d ", node[i]->length[j]);
		}
		puts("");
	}
	puts("");

	
	printf("시작점과 끝점을 입력해주세요.\n");
	printf("시작점:"); scanf("%c", &start); clear_buf(); puts("");
	printf("끝점:"); scanf("%c", &end); clear_buf(); puts("");

	Selected_Route(node[start - 'A'], end, ch_ary, 0, size + 1, length_table, &min, &max, min_ary, max_ary);

	printf("MAX: %d\n", max);
	for (i = 0; i < size + 1; i++)
		printf("%c ", max_ary[i]);
	puts("");

	printf("MIN: %d\n", min);
	for (i = 0; i < size + 1; i++)
		printf("%c ", min_ary[i]);
	puts("");

}
#endif
#ifdef TEST_SET

int main()
{
	srand((unsigned int)time(NULL));
	Graph** node;
	int ap[4][4] = { {0,1,0,1},{1,0,0,1},{1,0,0,0},{1,1,1,0} };
	//int ap[4][4] = { {0,1,0,0},{0,0,1,0},{1,0,0,1},{0,1,0,0} };
	int** length_table;
	int sum = 0, min = 0, max = 0;
	char max_ary[5] = { 0 };
	char min_ary[5] = { 0 };
	char ch_ary[5] = { 0 };
	int cnt_ary[4] = { 0 };
	int size = 4;
	int i, j;



	Print_Route_info_FIXED(ap);
	puts("");

	node = Make_Node_FIXED(ap);
	Input_Route_FIXED(node, ap);

	Input_Length_TEST(node);
	for (i = 0; i < size; i++)
	{
		printf("%c: ", node[i]->ch);
		for (j = 0; j < size; j++)
		{
			if (node[i]->link[j])
				printf("%d ", node[i]->length[j]);
		}
		puts("");
		puts("");
	}

	for (i = 0; i < size; i++)
	{
		printf("%c: ", node[i]->ch);
		for (j = 0; j < size; j++)
		{
			if (node[i]->link[j])
				printf("%d ", node[i]->length[j]);
		}
		puts("");
		puts("");
	}
	Visit_all_TEST(node[0], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[1], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[2], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[3], ch_ary, 0);



	length_table = Make_Length_Table_TEST(node);

	for (i = 0; i < size; i++)
	{	
		for (j = 0; j < size; j++)
		{
			printf("%d ", length_table[i][j]);
		}
		puts("");
	}
	
	
	Visit_all_MIN_MAX_TEST(node[0], ch_ary, 0, length_table, &min, &max, min_ary, max_ary);
	Visit_all_MIN_MAX_TEST(node[1], ch_ary, 0, length_table, &min, &max, min_ary, max_ary);
	Visit_all_MIN_MAX_TEST(node[2], ch_ary, 0, length_table, &min, &max, min_ary, max_ary);
	Visit_all_MIN_MAX_TEST(node[3], ch_ary, 0, length_table, &min, &max, min_ary, max_ary);
	puts("");
	puts("");

	printf("MAX: %d\n", max);
	for (i = 0; i < size + 1; i++)
		printf("%c ", max_ary[i]);
	puts("");

	printf("MIN: %d\n", min);
	for (i = 0; i < size + 1; i++)
		printf("%c ", min_ary[i]);
	puts("");
	

	/*

	Visit_all_TEST(node[0], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[1], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[2], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[3], ch_ary, 0);

	for (i = 0; i < size; i++)
	{
		printf("%c: ", node[i]->ch);
		for (j = 0; j < size; j++)
		{
			if (node[i]->link[j])
				printf("%d ", node[i]->length[j]);
		}
		puts("");
		puts("");
	}
		Visit_all_TEST(node[0], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[1], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[2], ch_ary, 0);
	puts("");
	Visit_all_TEST(node[3], ch_ary, 0);
	*/



}

#endif

#ifdef TEST
for (row = 0; row < size; row++)
{
	printf("%c:", node[row]->ch);
	for (col = 0; col < size; col++)
	{
		if (node[row]->link[col])
			printf("%c ", node[row]->link[col]->ch);
	}
	puts("");
}



int row, col;
int size = _msize(ap) / sizeof(int*);
//0:A, 1:B, ....
for (row = 0; row < size; row++)
{
	printf("%c:", node[row]->ch);
	for (col = 0; col < size; col++)
	{
		if (node[row]->link[col])
			printf("%c ", node[row]->link[col]->ch);
		}
	puts("");
	}

while (1)
{
	ap = Make_Route();
	Print_Route_info(ap);
	system("pause");
	}

#endif

#ifdef BASIC_SET

srand((unsigned int)time(NULL));
Graph** node;
int** ap = Make_Route();
char ch_ary[5] = { 0 };



Print_Route_info(ap);
puts("");
node = Make_Node(ap);
Input_Route(node, ap);

Visit_every_node(node[0]);



#endif
