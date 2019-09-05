#include <stdio.h>
#include <stdlib.h>

struct Cell{
	int val;
	struct Cell *next;
};

struct List{
	int len;
	struct Cell *head;
};

void print_list(struct List *list){
	struct Cell *temp = list->head;
	while(temp!=NULL){
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

//insert element at the end of the list
void insert_node(struct Cell *cell, struct List *list){
	struct Cell *temp = list->head;
	if (list->head == NULL){
		list->head = cell;
		list->len = 1;
	}
	else{
		while(temp->next!=NULL){
			temp = temp->next;
		}
		cell->next = NULL;
		temp->next = cell;
		list->len += 1; 
	}
}

//delete element by value
void delete_node(struct List *list, int v){
	struct Cell *temp = list->head;
	if(list->head == NULL){
		printf("Impossible to delete, list is empty\n");
		return;
	}
	else if (list->head->val == v){
		list->head == NULL;
		list->len -=1;
		return;
	}
	else{
		while(temp->next!=NULL){
			if(temp->next->val == v){
				temp->next = temp->next->next;
				list->len -=1;
				return;
			}
			else{
				temp=temp->next;
			}		
		}
		printf("There is no element with value '%d' in the list\n", v);
	}
}


int main(){
	struct List *list = (struct List*)malloc(sizeof(struct List));
	list->len = 0;
	list->head = NULL;

	struct Cell* cell1 = (struct Cell*)malloc(sizeof(struct Cell));
	cell1->val = 6;
	cell1->next = NULL;
	struct Cell* cell2 = (struct Cell*)malloc(sizeof(struct Cell));
	cell2->val = 7;
	cell2->next = NULL;
	struct Cell* cell3 = (struct Cell*)malloc(sizeof(struct Cell));
	cell3->val = 34;
	cell3->next = NULL;


	insert_node(cell1, list);
	insert_node(cell2, list);
	insert_node(cell3, list);

	print_list(list);

	delete_node(list, 7);
	delete_node(list, 8);

	print_list(list);


	
		

}





















