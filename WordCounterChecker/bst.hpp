#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include<math.h>
using namespace std;

class doublyLinkedList{
  private:
	class node
	{
	public:
		string data;
		node* next;
		node* prev;
    int track;
		node(string x, int y)
		{
			data = x;
      track = y;
			next = nullptr;
			prev = nullptr;
		}
	};

	node* head;
	node* tail;

  public:
  doublyLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

  
	void addBack(string x, int y)
	{
		node* baby = new node(x, y);
    
		if (head == nullptr)
		{
			tail = baby;
			head = baby;
		}
		else
		{
		tail->next = baby;
    baby->prev = tail;
    tail = baby;
		}
	}

  void printList()
	{
		node* p = head;
		while (p != nullptr)
		{
			cout << p->data << " " << p->track <<endl;
			p = p->next;
		}
	}

  void mergeSort(){
    if(head->next == nullptr){
    }
    else{
      doublyLinkedList L;
      doublyLinkedList R;
      split(L,R);
      L.mergeSort();
      R.mergeSort();
      merge(L,R);
    }
  }

  void merge(doublyLinkedList& L1, doublyLinkedList& L2){
    while(L1.head!=nullptr && L2.head!=nullptr){
      if(L1.head->track > L2.head->track){
        addBack(L1.head->data, L1.head->track);
        L1.head=L1.head->next;
      }
      else{
        addBack(L2.head->data, L2.head->track);
        L2.head=L2.head->next;
      }
    }
    while(L1.head!=nullptr){
      addBack(L1.head->data, L1.head->track);
      L1.head = L1.head->next;
    }

   while(L2.head!=nullptr){
      addBack(L2.head->data, L2.head->track);
      L2.head = L2.head->next;
    }
  }

  void split(doublyLinkedList& L1, doublyLinkedList& L2){
    node* a = head;
    int c = 0; //counter
    int midpoint = 0;
    if(a==nullptr){
    }
    else{
      //count numbers in list
      while(a != nullptr){
        c++;
        a = a->next;
      }
      a = head;
      midpoint = round(c/2.0);
      while(midpoint>1){
        a = a->next;
        midpoint--;
      }
    while(head!= a->next){
      L1.addBack(head->data, head->track);
      head = head->next;
    }
    while(head!= nullptr){
      L2.addBack(head->data, head->track);
      head = head->next;
    }
   }
  }

  void openFile(string name){
    mergeSort();
    ofstream file;
    file.open(name);
    int limit = 0;
    for(node* iptr = head; limit < 100;iptr = iptr->next){
      file << iptr->data << " " << iptr->track << endl;
      limit++;
    }
    file.close();
  }
};

class binarySearchTree{
  private:
	class node
	{
	public:
		string data;
		node * left;
		node * right;
    int track;

		node(string x)
		{
			data = x;
      track = 1;
			left = nullptr;
			right = nullptr;
		}
	};
  node * root;
  node * head;

  void recInsert(string x, node* &p)
	{
		if (p == nullptr)
		{
			p = new node(x); 
		}
		else
		{
      if(x == p->data){
        p->track++;
      }
			else if (x < p->data)
				recInsert(x, p->left);
			else
				recInsert(x, p->right);}
	}

  void recDisplay(node* p)
	{
		if (p == nullptr) 
		{}
		else
		{
			recDisplay(p->left);
			cout << p->data << " " << p->track << endl;
			recDisplay(p->right);
		}
	}

  bool bSearch(string* y, int start, int e, string word){
    int m = (start + e)/2;
    if(start<=e){
      if(y[m]==word){
        return true;
      }
      else if(y[m]>word){
        return bSearch(y, start, m-1, word);
      }
      else{
        return bSearch(y, m+1, e, word);
      }
    }
    else{
      return false;
    }
  }
//this function puts misspelled words in linked list
  void misSpell(doublyLinkedList &x, string* y, node*p){
    if(p==nullptr){}
    else{
      bool a = bSearch(y, 0, 202412,p->data);
      misSpell(x,y,p->left);
      if(a == true){
      }
      else{
        x.addBack(p->data, p->track);
      }
      misSpell(x,y,p->right);
    }
  }
  
  public:
  binarySearchTree()
	{
		root = nullptr;
	}
	void insert(string x)
	{
		recInsert(x, root);
	}
	void display()
	{
		recDisplay(root);
	}
  void loadFromFile(string file){
    ifstream read;
    read.open(file);
    string a ;
    while(read.good()){
      read >> a;
      insert(a);
    }
    read.close();
  }
  void writeToFile(string newfile, doublyLinkedList& x){
    x.mergeSort();
    x.printList();
  }
  void findMisSpell(doublyLinkedList &x, string* y, string name){
    this->misSpell(x, y, root);
    x.openFile(name);
  }
};

