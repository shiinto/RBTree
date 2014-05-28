#pragma once
#include "RBTree.h"
#include <vector>
#include <windows.h>
#include <iostream>

using namespace std;

HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);


RBnode::RBnode(){
	data = 0;
	red = 1;
	left = 0;
	right = 0;
}

RBnode::RBnode(int item, RBnode*node){
	data = item;
	red = 1;
	left = node;
	right = node;
}


RBtree::RBtree(){
	head = new RBnode();
	nullnode = new RBnode();
	nullnode->red = 0;
	head->red = 0;
	head->left = nullnode;
	head->right = nullnode;
	nullnode->left = nullnode;
	nullnode->right = nullnode;
}


void RBtree::rightrotation(RBnode*&k2){
	RBnode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2 = k1;
}

void RBtree::leftrotation(RBnode*&k2){
	RBnode *k1 = k2->right;
	RBnode *k3 = k1->left;
	k1->left = k2;
	k2->right = k3;
	
	k2 = k1;
}


void RBtree::insert(int item){

	if (head->right == nullnode){
		head->right = new RBnode(item,nullnode);
		head->right->red = 0;
	}
	else
		insert(head, item);
}

bool RBtree::insert(RBnode*node, int item){

		RBnode*newnode = new RBnode(item, nullnode);
		bool ok = 0;

		//umfärben
		if (node->left->red == 1 && node->right->red == 1){
			node->red = 1;
			node->left->red = 0;
			node->right->red = 0;
		}

		//einfügen
		if (item < node->data && node != head){
			if (item < node->left->data){
				if (node->left->left == nullnode){
					node->left->left = newnode;
					if (node->left->red){
						rightrotation(node);
						node->red = 0;
						node->right->red = 1;
					}
					ok = 1;
				}
				else
					ok = insert(node->left, item);
			}
			else{
				if (node->left->right == nullnode){
					node->left->right = newnode;
					if (node->left->red){
						//doppelrotation - links-rechts
						leftrotation(node->left);
						rightrotation(node);
						node->red = 0;
						node->right->red = 1;
					}
					ok = 1;
				}
				else
					ok = insert(node->left, item);
			}
		}

		else{ // (item > node->data){
			if (item > node->right->data){
				if (node->right->right == nullnode){
					node->right->right = newnode;
					if (node->right->red){
						leftrotation(node);
						node->red = 0;
						node->left->red = 1;
					}
					ok = 1;
				}
				else
					ok = insert(node->right, item);
			}
			else{
				if (node->right->left == nullnode){
					node->right->left = newnode;
					if (node->right->red){
						//doppelrotation - rechts-links
						rightrotation(node->right);
						leftrotation(node);
						node->red = 0;
						node->left->red = 1;
					}
					ok = 1;
				}
				else
					ok = insert(node->right, item);
			}
		}
		return ok;
}

int potenz(int a, int b)  // gibt die b Potenz von a aus
{
	return(b<1 ? 1 : (potenz(a, b - 1)*a));
}

void space(int n)
{
	for (int spc = 0; spc<n; spc++)
		cout << " ";
	return;
}

void rot(void)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void weiss(void)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}


void RBtree::baum_malen()
{
	vector< RBnode*> niv;
	int i = 0, max, spc = 0;
	niv.push_back(head->right);
	cout << "\n\n";
	for (int n = 0; n < 5; n++)
	{
		max = (potenz(2, n + 1) - 1);
		spc = 64 / potenz(2, n + 1) - 1;
		while (i< max)
		{

			niv.push_back(niv.at(i)->left);
			niv.push_back(niv.at(i)->right);
			space(spc);
			if (niv.at(i) != nullnode)
			{
				(niv.at(i)->red) ? rot() : weiss();
				cout << niv.at(i)->data;
				weiss();
			}
			else
				cout << "  ";
			space(spc);
			i++;
		}
		cout << endl << endl << endl;
	}
}
