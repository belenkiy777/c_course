#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct town { // создание двунаправленного списка
	struct town* pNext;
	struct town* pPrev;
	char Name[];
};

typedef struct town Town;
Town* pFirst = 0, * pLast = 0;

Town* Create(const char* name) { // выделение памяти под город и копирование его в список
	size_t len = strlen(name);
	Town* po = (Town*)malloc(sizeof(Town) + sizeof(char) * len + 1); // размер структуры + длина города + 0
	if (po == 0) return 0;
	strncpy_s(po->Name, len + 1, name, len + 1);
	return po;
}

void Destroy(Town* po) { // освобождение памяти
	if (po) free(po);
}

void AddToList(Town* po) { // добавление города в список
	if (pLast) pLast->pNext = po; // ставим новый город в конец
	po->pPrev = pLast; // отодвигаем предыдущий город 
	pLast = po;
	po->pNext = 0;
	if (pFirst == 0) pFirst = po; // если список был пуст, новый элемент первый

}

void DelFromList(Town* po) { // удаление города из списка
	if (po->pPrev)
		po->pPrev->pNext = po->pNext; // ставим следующий элемент на место удаляемого
	else
		pFirst = po->pNext; // если удаляемый элемент был первым

	if (po->pNext)
		po->pNext->pPrev = po->pPrev; // связываем следующий элемент с предыщущим
	else
		pLast = po->pPrev;  // если удаляемый элемент был последним

}

Town* Search4(const char* home) { // найти город и вернуть адрес структуры, иначе 0
	Town* po = pFirst;
	while (po) {
		if (strcmp(po->Name, home) == 0) return po;
		po = po->pNext;
	}
	return 0;
};

void PrintAllTowns(void) { // вывод списка
	printf("\nAll town list:");
	Town* po = pFirst;
	while (po) {
		printf("\n %s", po->Name);
		po = po->pNext;
	}
}

void SortTowns(void) { // сортировка списка по алфавиту
	if (pFirst == 0 || pFirst->pNext == 0) return;

	int swapped = 1; // флаг успешного прохода (если что-то поменялось, идем еще раз)
	while (swapped) {
		swapped = 0;
		Town* po = pFirst;
		while (po && po->pNext) {
			if (strcmp(po->Name, po->pNext->Name) > 0) { //????? если два элемента стоят не по алфавиту
				// po - указатель на структуру Town, Name - массив с названием города
				// оператор -> нужен для обращения к элементам структуры
				// доступ к элементам структуры осуществляется по адресу структуры + смещению к ячейке элемента
				Town* a = po;
				Town* b = po->pNext;

				// пузырьковая сортировка
				a->pNext = b->pNext; // a теперь указывает на следующий элемент после b
				if (b->pNext) b->pNext->pPrev = a; // следующий элемент теперь указывает на a 

				b->pPrev = a->pPrev; // b теперь указывает на элемент до a
				if (a->pPrev) a->pPrev->pNext = b; // предыдущий элемент теперь указывает на b

				b->pNext = a; // b теперь указывает на a
				a->pPrev = b; // a теперь указывает на b

				if (pFirst == a) pFirst = b; // обновляем указатели pFirst и pLast
				if (!(a->pNext)) pLast = a;
				swapped = 1;
			}
			else {
				po = po->pNext; // если пара в правильном порядке, то идем дальше
			}
		}
	}
}


int main(void) {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	Town* po;

	po = Create("Saint-Petersburg");
	if (po == 0) return -1; // если не удалось выделить память, возвращаем ошибку
	AddToList(po);

	po = Create("Saratov");
	if (po == 0) return -1;
	AddToList(po);

	po = Create("Chelyabinsk");
	if (po == 0) return -1;
	AddToList(po);

	po = Create("Khimki");
	if (po == 0) return -1;
	AddToList(po);

	po = Create("Tosno");
	if (po == 0) return -1;
	AddToList(po);

	po = Create("Minsk");
	if (po == 0) return -1;
	AddToList(po);

	po = Search4("Tosno");
	DelFromList(po);
	Destroy(po);

	po = Create("Istanbul");
	if (po == 0) return -1;
	AddToList(po);

	SortTowns();
	PrintAllTowns();

	// очистка списка
	while (pFirst) {
		po = pFirst;
		pFirst = po->pNext;
		Destroy(po);
	}
	return 0;

}




