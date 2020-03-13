
#include <iostream>
using namespace std;

struct Node
{
	int x;
	Node *l, *r;
};
//обход
void show(Node *&Tree)
{
	if (Tree != NULL)            
	{
		show(Tree->l);               
		cout << Tree->x << '\t';               
		show(Tree->r);             
	}
}

//удаление
void del(Node *&Tree) {
	if (Tree != NULL)        
	{
		del(Tree->l);            
		del(Tree->r);             
		delete Tree;               
		Tree = NULL;               
	}

}

void add_node(int x, Node *&MyTree) //Фукция добавления звена в дерево
{
	if (NULL == MyTree)    //Если дерева нет
	{
		MyTree = new Node;          
		MyTree->x = x;             
		MyTree->l = MyTree->r = NULL; 
	}

	if (x < MyTree->x)   //Если нововведенный элемент x меньше чем элемент x сверху, уходим влево
	{
		if (MyTree->l != NULL) add_node(x, MyTree->l); //При помощи рекурсии заталкиваем элемент на свободный участок
		else          
		{
			MyTree->l = new Node;                
			MyTree->l->l = MyTree->l->r = NULL;  
			MyTree->l->x = x;                   
		}
	}

	if (x > MyTree->x)              //Если нововведенный элемент x больше чем элемент x сверху, уходим вправо
	{
		if (MyTree->r != NULL) add_node(x, MyTree->r);
		{
			MyTree->r = new Node;                 
			MyTree->r->l = MyTree->r->r = NULL;  
			MyTree->r->x = x;                    
		}
	}
}

int main()
{
	Node *Tree = NULL;                   
	int a;
	do
	{
		cin >> a;
		add_node(a, Tree);
	}
	while (a != 0);
	show(Tree);                        //Вывод на экран дерева. или просто обход дерева
	cout << '\n';
	del(Tree);                      

	system("pause");
}