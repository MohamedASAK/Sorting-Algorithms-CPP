#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* previous;
};

node* head = NULL;
node* current = NULL;
node* tail = NULL;
node* index = NULL;
node* Nindex = NULL;
int listsize = 0;
int MX = 0;
// Linked List Operations
void insert(int newdata)
{
	current = new node;
	current->data = newdata;
	current->next = NULL;

	if (head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		current->previous = tail;
		tail->next = current;
		tail = tail->next;
	}
	listsize++;
}
void AddToHead(int newdata)
{
	current = new node;
	current->data = newdata;
	current->next = NULL;
	if (head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		current->next = head;
		head = current;
	}
}
void deleteNode(int Deldata) {
	if (head != NULL)
	{
		current = head;
		if (current->data == Deldata)
		{
			head = head->next;
			delete current;
		}
		else
		{
			while (current != NULL)
			{
				if ((current->next)->data == Deldata)
				{
					(current->next) = (current->next)->next;
					break;
				}
				else { current = current->next; }
			}
		}
	}
	else { cout << "No Data Found" << endl; }
}
void destoryList()
{
	if (head != NULL)
	{
		current = head;
		while (current != NULL)
		{
			head = head->next;
			delete current;
			current = head;
		}
		head = NULL;
		tail = NULL;
		cout << "The list is Destroyed Successfully" << endl;
	}
	else
	{
		cout << "There is no list to be destroyed" << endl;
	}
}
void display()
{
	if (head != NULL)
	{
		current = head;
		cout << "Data:" << endl;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	else
	{
		cout << "No Data Found" << endl;
	}
}
/* **************************** */
// Insertion Sort
void insertion_sort() {
	if (head != NULL) {
		current = head->next;
		while (current != NULL)
			index = current;
			Nindex = current;
			do {
				if (index->previous != NULL) {
					if (Nindex->data < (index->previous)->data)
					{
						int temp = Nindex->data;
						Nindex->data = (index-> previous)->data;
						(index->previous)->data = temp;
					}
					else {
						break;
					}
					Nindex = Nindex-> previous;
					index = index-> previous;
				}
				else {
					break;
				}
			} while (index != NULL);
			current = current->next;
		}
	else {
		cout << "No data founded to sort it\n";
	}
}
// Selection Sort
void selection_sort() {
	if (head != NULL) {
		current = head->next;
		while (current != NULL)
			index = current;
			Nindex = current->next;
		do {
			if (index->previous != NULL) {
				if (index->data > Nindex->data)
				{
					int temp = index->data;
					index->data = Nindex->data;
					Nindex->data = temp;
				}
				else {
					break;
				}
				Nindex = Nindex->previous;
				index = index->previous;
			}
			else {
				break;
			}
		} while (index != NULL);
		current = current->next;
	}
	else {
		cout << "No data founded to sort it\n";
	}
}
// Bubble Sort
void bubble_sort() {
	if (head != NULL) {
		current = head->next;
		while (current != NULL)
			index = current;
			Nindex = current->next;
		do {
			if (index->previous != NULL) {
				if (index->data > Nindex->data)
				{
					int temp = index->data;
					index->data = Nindex->data;
					Nindex->data = temp;
				}
				else {
					break;
				}
				Nindex = Nindex->previous;
				index = index->previous;
			}
			else {
				break;
			}
		} while (index != NULL);
		current = current->next;
	}
	else {
		cout << "No data founded to sort it\n";
	}
}

int Max_Number()
{
	int Max_Num = head->data;
	for (current = head; current != NULL; current = current->next)
	{
		if (Max_Num < current->data)
			Max_Num = current->data;
		else
			return 0;
	}
	return Max_Num;
}
// Count Sort
void count_sort()
{
	int ind = 0, i, list = 0;
	ind = Max_Number() + 1;
	list = listsize + 1;
	int* arr_index = new int[ind];
	int* output = new int[list];

	for (i = 0; i <= ind; i++)
		arr_index[i] = 0;

	for (current = head; current != NULL; current = current->next)
		arr_index[current->data]++;

	for (i = 1; i <= ind; ++i)
		arr_index[i] += arr_index[i - 1];

	for (current = tail; current != NULL; current = current->previous) {
		output[arr_index[current->data]] = current->data;
		arr_index[current->data]--;
	}

	current = head;
	for (i = 1; i <= listsize; i++) {
		current->data = output[i];
		current = current->next;
	}

}
// Redix Sort
void CountSortRedix(int exp)
{
	int ind = 0, i, list = 0;
	ind = Max_Number() + 1;
	list = listsize + 1;
	int* arr_index = new int[ind];
	int* output = new int[list];

	for (i = 0; i <= ind; ++i) arr_index[i] = 0;
	for (current = head; current != NULL; current = current->next)
		arr_index[(current->data / exp) % 10]++;

	for (i = 1; i <= ind; ++i)
		arr_index[i] += arr_index[i - 1];

	for (current = tail; current != NULL; current = current->previous) {
		output[arr_index[(current->data / exp) % 10]] = current->data;
		arr_index[(current->data / exp) % 10]--;
	}
	current = head;

	for (i = 1; i <= listsize; i++) {
		current->data = output[i];
		current = current->next;
	}
	for (i = 0; i <= ind; i++)
		arr_index[i] = 0;

	for (current = head; current != NULL; current = current->next)
		arr_index[current->data]++;

	for (i = 1; i <= ind; ++i)
		arr_index[i] += arr_index[i - 1];

	for (current = tail; current != NULL; current = current->previous) {
		output[arr_index[(current->data / exp) % 10]] = current->data;
		arr_index[(current->data / exp) % 10]--;

	}

	current = head;
	for (i = 1; i <= listsize; i++) {
		current->data = output[i];
		current = current->next;
	}

}
void radix_sort() {
	for (int Exp = 1; MX / Exp > 0; Exp *= 10)
		CountSortRedix(Exp);
}
// Merge Sort
node* indexOfList(node* head, int pos) {
	node* tmp = head;
	for (int i = 0; i < pos; ++i)
		tmp = tmp->next;
	return tmp;
}
void Merge(int*, int, int, int);
void Merge(node* head, int low, int high, int mid) {
	int i = low, j = mid + 1, ind = 0;
	int* tmp = new int[high - low + 1];
	while (i <= mid && j <= high) {
		if (indexOfList(head, i)->data < indexOfList(head, j)->data) {
			tmp[ind] = indexOfList(head, i)->data;
			ind++;
			i++;
		}
		else {
			tmp[ind] = indexOfList(head, j)->data;
			ind++;
			j++;
		}
	}
	while (i <= mid) {
		tmp[ind] = indexOfList(head, i)->data;
		ind++;
		i++;
	}
	while (j <= high) {
		tmp[ind] = indexOfList(head, j)->data;
		ind++;
		j++;
	}
	for (i = low; i <= high; i++)
		indexOfList(head, i)->data = tmp[i - low];
}
void merge_sort(node* head, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		merge_sort(head, low, mid);
		merge_sort(head, mid + 1, high);
		Merge(head, low, high, mid);
	}
}


void app() {
	/*
		op -> operation
		ins -> insert
		ath -> add to head
		dn -> deleted node
		c -> confirm
		ao -> another operation
		s -> starter app
	*/
	
	int op, ins, ath, dn, c, ao, s;
	cout << "---* Welcome to linked list implementation with sorting algorithms *---\n";
	do {
		cout << "Choise what do you want\n";
		cout << "Insert -> (1)\n";
		cout << "Add to head -> (2)\n";
		cout << "Delete node -> (3)\n";
		cout << "Display -> (4)\n";
		cout << "Destory list -> (5)\n";
		cout << "Sorting List -> (6)\n";
		cout << "Exit -> (7)\n";
		cin >> op;
		if (op == 1) {
			cout << "Enter value do you want to add to head\n";
			cin >> ins;
			insert(ins);
			display();
		}
		else if (op == 2) {
			cout << "Enter value do you want to add to head\n";
			cin >> ath;
			AddToHead(ath);
			display();
		}
		else if (op == 3) {
			display();
			cout << "Choise the node \n";
			cin >> dn;
			cout << "Are you sure to delete this node\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				deleteNode(dn);
				cout << "\nCheck data of list after deleting node : \n ";
				display();
			}
			else
			{
				cout << "Delete is canceled\n";
			}
		}
		else if (op == 4) {
			cout << "\nThe Nodes of the Linked List are: \n";
			display();
		}
		else if (op == 5) {
			display();
			cout << "\nIF Destroyed the whole list\n \t The result will be: \n";
			cout << "Are you sure to destroy the whole list\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				destoryList();
				cout << "\nCheck data of list after destroying : \n ";
				display();
			}
			else
			{
				cout << "Destroy is canceled\n";
			}
		}
		else if (op == 6)
		{
			cout << "--------Sorting--------\n";
			cout << "Choise what do you want\n";
			cout << "Insertion Sort -> (1)\n";
			cout << "Selection Sort -> (2)\n";
			cout << "Bubble Sort -> (3)\n";
			cout << "Count Sort -> (4)\n";
			cout << "Redix Sort -> (5)\n";
			cout << "Merge Sort -> (6)\n";
			cout << "Exit -> (7)\n";
			cin >> op;
			if (op == 1) 
			{
				insertion_sort();
			}
			else if (op == 2)
			{
				selection_sort();
			}
			else if (op == 3)
			{
				bubble_sort();
			}
			else if (op == 4)
			{
				count_sort();
			}
			else if (op == 5)
			{
				radix_sort();
			}
			else if (op == 6)
			{
				merge_sort(head, 0, tail->data);
			}
			else if (op == 7)
			{
				return;
			}

		}
		else if (op == 7)
		{
			return;
		}
		else { cout << "Error in entry\n"; }

		cout << "\n";
	
		cout << "Do you want another opration\n";
		cout << "Yes -> 1 \n";
		cout << "NO -> any key \n";
		cin >> ao;

	} while (ao == 1);
}
int main()
{
	app();
	return 0;
}