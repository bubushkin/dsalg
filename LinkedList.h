
typedef struct ListElement_ {
	int data;
	ListElement *pnext;
}ListElement;

void displayElement(ListElement *);

int countElements(ListElement *);

void searchElement(ListElement *, int, int *);

ListElement *insertAtBeginning(ListElement *, int);

void insertAtEnd(ListElement *, int);

