#include<stdio.h>
#include<stdlib.h>
struct BST
{
 int key;
 struct BST* ptroleftchild;
 struct BST* ptrtorightchild;
};
struct BST* maketree(nwkey)
{
 struct BST* prtonwnode;
 prtonwnode=(struct BST*)malloc(sizeof(struct BST));
 prtonwnode->key=nwkey;
 prtonwnode->ptroleftchild=NULL;
 prtonwnode->ptrtorightchild=NULL;
 return prtonwnode;
}
struct BST* insert(struct BST* nodeoriginal, int key)
{
 if (nodeoriginal==NULL) return maketree(key);
 if (key < nodeoriginal->key)
 nodeoriginal->ptroleftchild = insert(nodeoriginal->ptroleftchild, key);
 else if (key > nodeoriginal->key)
 nodeoriginal->ptrtorightchild = insert(nodeoriginal->ptrtorightchild, key);
 return nodeoriginal;
}
void inordertrav(struct BST* nodeoriginal)
{
 if(nodeoriginal==NULL) return;
 inordertrav(nodeoriginal->ptroleftchild);
 printf("%d->",nodeoriginal->key);
 inordertrav(nodeoriginal->ptrtorightchild);
}
int main(){
 struct BST* nodeoriginal=NULL;
 nodeoriginal=insert(nodeoriginal,8);
 insert(nodeoriginal,3);
 insert(nodeoriginal,1);
 insert(nodeoriginal,6);
 insert(nodeoriginal,7);
 insert(nodeoriginal,10);
 insert(nodeoriginal,14);
 insert(nodeoriginal,4);
 inordertrav(nodeoriginal);
}
