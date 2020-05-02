#pragma once

#ifndef __FUNC_H__
#define __FUNC_H__

int** Make_Route();
void Print_Route_info(int** ap);
Graph** Make_Node(int** ap);
void Input_Route(Graph** node, int** ap);
void Visit_all(Graph* node, char* ch_ary, int idx, int size);
void Print_ary_ptr(Graph* node);
void Input_Length(Graph** node);
int** Make_Length_Table(Graph** node);
void Search_MIN_MAX(int** length_table, char* ch_ary, int* min, int* max, char* min_ary, char* max_ary);
void Selected_Route(Graph* node, char end, char* ch_ary, int idx, int size, int** length_table, int* min, int* max, char* min_ary, char* max_ary);
void clear_buf();
/*TEST*/

void Print_Route_info_FIXED(int(*ap)[END]);
Graph** Make_Node_FIXED();
void Input_Route_FIXED(Graph** node, int(*ap)[END]);
void Visit_all_TEST(Graph* node, char* ch_ary, int idx);
void Input_Length_TEST(Graph** node);
int** Make_Length_Table_TEST(Graph** node);
void Search_MIN_MAX_TEST(int** length_table, char* ch_ary, int* min, int* max, char* min_ary, char* max_ary);
void Visit_all_MIN_MAX_TEST(Graph* node, char* ch_ary, int idx, int** length_table, int* min, int* max, char* min_ary, char* max_ary);

#endif
