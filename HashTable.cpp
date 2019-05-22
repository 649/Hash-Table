#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Node {
	int data;
	struct Node *next;
}HashChain;
typedef struct HashT {
	HashChain *first;
}HashTable;
int f(int x, int k) {
	return x % k;
}

int main() {
	int m = 0, key = 0; char c[1000];
	cin >> m;
	HashTable* Sequence = new HashTable[m];
	for (int i = 0; i < m; i++)
		Sequence[i].first = NULL;
	while (c[0] != 'e') {
		cin >> c;
		key = atoi(c + 1);
		int i = f(key, m);
		if (c[0] == 'i') {
			HashChain* n = new HashChain;
			n->data = key;
			if (Sequence[i].first != NULL) 
				n->next = Sequence[i].first;
			else
				n->next = NULL;
			Sequence[i].first = n;
		}
		if (c[0] == 'd') {
			HashChain* n;
			HashChain* t;
			HashChain* p;
			int del = 0;
			n = Sequence[i].first;
			t = n;
			while (n != NULL) {
				if (n->data == key) {
					if (Sequence[i].first == n)
						Sequence[i].first = n->next;
					else {
						while (t->data != key && t != NULL) {
							p = t;
							t = t->next;
						}if (t == NULL)
							break;
						p->next = t->next;
					}
					delete n;
					del = 1;
					cout << key << ":DELETED;" << endl;
					break;
				} else
					n = n->next;
			} if (del == 0)
				cout << key << ":DELETE_FAILED;" << endl;
		}
		if (c[0] == 's') {
			HashChain* n;
			int search = 0, j = 0;
			n = Sequence[i].first;
			while (n != NULL) {
				if (n->data == key) {
					search = 1;
					cout << key << ":FOUND_AT" << i << "," << j << ";" << endl;
					break;
				} else {
					j++;
					n = n->next;
				}
			}
			if (search == 0)
				cout << key << ":NOT_FOUND;" << endl;
		}
		if (c[0] == 'o') {
			HashChain* n;
			for (int i = 0; i < m; i++) {
				cout << i << ":";
				n = Sequence[i].first;
				while (n != NULL) {
					printf("%d->", n->data);
					n = n->next;
				}
				cout << ";" << endl;
			}
		}
	}
	HashChain* n;
	HashChain* t;
	for (int i = 0; i < m; i++) {
		n = Sequence[i].first;
		t = n;
		while (n != NULL) {
			n = n->next;
			delete t;
			t = n;
		}
	}
	delete Sequence;
	return 0;
}