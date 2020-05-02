#include"ALL.h"
#ifdef TEST_SET
void Print_Route_info_FIXED(int(*ap)[END])
{
	int row, col, i;
	int size = 4;

	printf("  ");
	for (i = 0; i < size; i++)
		printf("%c ", 'A' + i);
	puts("");
	for (row = 0; row < size; row++)
	{
		printf("%c ", 'A' + row);
		for (col = 0; col < size; col++)
		{
			printf("%d ", ap[row][col]);
		}
		puts("");
	}

}

Graph** Make_Node_FIXED()
{
	int i,j;
	int size = END;
	Graph** node;

	node = (Graph**)malloc(size * sizeof(Graph*));
	for (i = 0; i < size; i++)
	{
		node[i] = (Graph*)malloc(sizeof(Graph));
		node[i]->ch = 'A' + i;
		node[i]->link = (Graph**)malloc(size * sizeof(Graph*));//size-1
		for (j = 0; j < size; j++)
			node[i]->link[j] = NULL;
		node[i]->length = (int*)calloc(size, sizeof(int));
	}

	return node;
}

void Input_Route_FIXED(Graph** node, int(*ap)[END])
{
	int row, col;
	int size = END;
	//0:A, 1:B, ....
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (ap[row][col] == 1)
				node[row]->link[col] = node[col];
		}
	}
}

void Input_Length_TEST(Graph** node)
{
	int i, j;
	int idx = 0;
	int length[8] = { 6,2,3,3,8,1,5,4 };
	int size = _msize(node) / sizeof(Graph*);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (node[i]->link[j])
			{
				node[i]->length[j] = length[idx];
				idx++;
			}
			/*
	if (node[i]->link[j])
		node[i]->length[j] = rand() % (LEN_END - LEN_START + 1) + LEN_START;
	*/
		}
	}
}
int** Make_Route()
{
	int** ap;
	//int size = rand() % (END - START + 1) + START;
	int size = 4;
	int row, col;


	ap = (int**)malloc(size * sizeof(int*));
	for (row = 0; row < size; row++)
		ap[row] = (int*)calloc(size, sizeof(int));

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (row != col)
				ap[row][col] = rand() % 2;
		}
	}

	return ap;
}

void Print_Route_info(int** ap)
{
	int row, col, i;
	int size = _msize(ap) / sizeof(int*);

	printf("  ");
	for (i = 0; i < size; i++)
		printf("%c ", 'A' + i);
	puts("");
	for (row = 0; row < size; row++)
	{
		printf("%c ", 'A' + row);
		for (col = 0; col < size; col++)
		{
			printf("%d ", ap[row][col]);
		}
		puts("");
	}

}

Graph** Make_Node(int** ap)
{
	int i;
	int size = _msize(ap) / sizeof(int*);
	Graph** node;

	node = (Graph**)malloc(size * sizeof(Graph*));
	for (i = 0; i < size; i++)
	{
		node[i] = (Graph*)malloc(sizeof(Graph));
		node[i]->ch = 'A' + i;
		node[i]->link = (Graph**)malloc(size * sizeof(Graph*));//size-1
		memset(node[i]->link, 0, size * sizeof(Graph*));
	}

	return node;
}

void Input_Route(Graph** node, int** ap)
{
	int row, col;
	int size = _msize(ap) / sizeof(int*);
	//0:A, 1:B, ....
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (ap[row][col] == 1)
				node[row]->link[col] = node[col];
		}
	}
}
void Visit_all_TEST(Graph* node, char* ch_ary, int idx)
{
	int i;
	int cnt_ary[4] = { 0 };
	int target_idx = 0;
	if (node)
	{
		ch_ary[idx] = node->ch;
		idx++;
		for (i = 0; i < 5; i++)
		{
			if (ch_ary[i] == 0)//방문한 노드 저장하는 배열
				break;
			else
			{
				cnt_ary[ch_ary[i] - 'A']++;
				if (cnt_ary[ch_ary[i] - 'A'] == 2)
				{
					target_idx = ch_ary[i] - 'A';
					if (target_idx + 'A' != ch_ary[0])//제일 처음에 들어간 문자와 다르면
						return;
					else if (target_idx + 'A' == ch_ary[0])//제일 처음에 들어간 문자와 같으면
					{

						for (i = 0; i < 5; i++)
						{
							if (ch_ary[i] != 0)
								printf("%c", ch_ary[i]);
						}
						puts("");
						return;
					}
				}

			}
		}
		Visit_all_TEST(node->link[0], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[1], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[2], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[3], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
	}
}
//해당 노드가 2번이 되면 종료
//다른 노드는 2번 방문 불가
void Visit_all_MIN_MAX_TEST(Graph* node, char* ch_ary, int idx, int** length_table, int* min, int* max, char* min_ary, char* max_ary)
{
	int i;
	int cnt_ary[4] = { 0 };
	int target_idx = 0;
	if (node)
	{
		ch_ary[idx] = node->ch;
		idx++;
		for (i = 0; i < 5; i++)
		{
			if (ch_ary[i] == 0)//방문한 노드 저장하는 배열
				break;
			else
			{
				cnt_ary[ch_ary[i] - 'A']++;
				if (cnt_ary[ch_ary[i] - 'A'] == 2)
				{
					target_idx = ch_ary[i] - 'A';
					if (target_idx + 'A' != ch_ary[0])//제일 처음에 들어간 문자와 다르면
						return;
					else if (target_idx + 'A' == ch_ary[0])//제일 처음에 들어간 문자와 같으면
					{

						for (i = 0; i < 5; i++)
						{
							if (ch_ary[i] != 0)
								Search_MIN_MAX(length_table, ch_ary, min, max, min_ary, max_ary);
								//printf("%c", ch_ary[i]);
						}
						puts("");
						return;
					}
				}

			}
		}
		Visit_all_MIN_MAX_TEST(node->link[0], ch_ary, idx, length_table, min, max, min_ary, max_ary);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_MIN_MAX_TEST(node->link[1], ch_ary, idx, length_table, min, max, min_ary, max_ary);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_MIN_MAX_TEST(node->link[2], ch_ary, idx, length_table, min, max, min_ary, max_ary);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_MIN_MAX_TEST(node->link[3], ch_ary, idx, length_table, min, max, min_ary, max_ary);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
	}
}
int** Make_Length_Table_TEST(Graph** node)
{
	int row, col;
	int size = _msize(node) / sizeof(Graph*);
	int** length_table;

	length_table = (int**)malloc(size * sizeof(int*));
	for (row = 0; row < size; row++)
		length_table[row] = (int*)calloc(size, sizeof(int));

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (node[row]->link[col])
				length_table[row][col] = node[row]->length[col];
		}
	}
	return length_table;
}
void Search_MIN_MAX_TEST(int** length_table, char* ch_ary, int* min, int* max, char* min_ary, char* max_ary)
{
	int idx = 0;
	int size = _msize(length_table) / sizeof(int*);
	int sum = 0;

	for (idx = 0; idx < size; idx++)
	{
		if (ch_ary[idx + 1] != 0)
			sum += length_table[ch_ary[idx] - 'A'][ch_ary[idx + 1] - 'A'];
	}

	if (*min == 0 && *max == 0)
	{
		*min = sum;
		*max = sum;
		memcpy(min_ary, ch_ary, size + 1);
		memcpy(max_ary, ch_ary, size + 1);
	}
	else
	{
		if (sum > * max)
		{
			*max = sum;
			memcpy(max_ary, ch_ary, size + 1);
		}
		if (sum < *min)
		{
			*min = sum;
			memcpy(min_ary, ch_ary, size + 1);
		}
	}
}

void Print_ary_ptr(Graph* node)
{
	int idx = 0;
	//int size = _msize(node->link) / _msize(node->link[0]);
	printf("%c\n", node->ch);

	while (1)
	{
		if (node->link[idx])
			printf("%c\n", node->link[idx]->ch);

		idx++;
	}
}
#endif

/*
void Visit_all_TEST(Graph* node, char* ch_ary, int idx)
{
	int i;
	int cnt_ary[4] = { 0 };
	int target_idx = 0;
	if (node)
	{
		ch_ary[idx] = node->ch;
		idx++;
		for (i = 0; i < 5; i++)
		{
			if (ch_ary[i] == 0)//방문한 노드 저장하는 배열
				break;
			else
			{
				cnt_ary[ch_ary[i] - 'A']++;
				if (cnt_ary[ch_ary[i] - 'A'] == 2)
				{
					target_idx = ch_ary[i] - 'A';
					if (target_idx + 'A' != ch_ary[0])//제일 처음에 들어간 문자와 다르면
						return;
					else if (target_idx + 'A' == ch_ary[0])//제일 처음에 들어간 문자와 같으면
					{

						for (i = 0; i < 5; i++)
						{
							if (ch_ary[i] != 0)
								printf("%c", ch_ary[i]);
						}
						puts("");
						return;
					}
				}

			}
		}
		Visit_all_TEST(node->link[0], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[1], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[2], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
		Visit_all_TEST(node->link[3], ch_ary, idx);
		for (i = idx; i < 5; i++)
			ch_ary[idx] = 0;
	}
}
*/