//https://blog.csdn.net/li_l_il/article/details/88677927

#include <stdlib.h>
//BST节点 
struct node{
//	值 
	int val;
//	指向左右子树的指针 
	node *lch,*rch;
};
 
//	插入数值x 
node *insert(node *p,int x){ 
	if(p==nullptr){
//		如果p为空指针，则申请一个节点的空间并将左右子树设为空，返回该节点 
		node *q = new node;
		q->val = x;
		q->lch = q->rch = nullptr;
		return q;
	}else{
//		如果p不为空，将x与p的值进行比较， 如果x小于val，则将x插入左子树，否则插入右子树 
		 if(x<p->val)	p->lch=insert(p->lch,x);
		 else p->rch = insert(p->rch,x);
		 return p;
	}
}
 
//	查找数值x,p为根节点 
bool find(node *p,int x){
	if(p==nullptr)	return false;
	else if(x==p->val)	return true;
	else if(x < (p->lch))	return find(p->lch,x);
	else return find(p->rch,x); 
} 
 
//	删除数值x
node *remove(node *p,int x){
	if(p==nullptr)	return nullptr;
//	找到要删除的节点 
	else if(x<p->val)	p->lch=remove(p->lch,x);
	else if(x>p->val)	p->rch=remove(p->rch,x);
//	如果要删除的节点没有左儿子，那么就把右儿子提上去 
	else if(p->lch==nullptr){
		node *q=p->rch;
		delete p;
		return q;
//	如果要删除的节点的左儿子没有右儿子，就把左儿子提上去 
	}else if(p->lch->rch==nullptr){
		node *q = p->lch;
		q->rch = p->rch;
		delete p;
		return q;
//	如果以上情况都不满足，就把左儿子的子孙中最大的节点（右儿子的右儿子的。。。右儿子）提到需要删除的节点上 
	}else{
		node *q;
//		用for循环进行遍历，这一招妙啊 
		for(q=p->lch;q->rch->rch!=nullptr;q=q->rch);
		node *r=q->rch;
		q->rch = r->lch;
		r->lch=p->lch;
		r->rch=p->rch;
		delete p;
		return r;
	}
	return p;
}

//

typedef struct Node_ {
    int data;
    Node_ *pLeft;
    Node_ *pRight;
} Node;

Node_ *insert(Node_ *root, int data) {
    if (nullptr == root) {
        root = (Node_*)malloc(sizeof(Node_));
        if(nullptr == root) {
            return nullptr;
        }
        root ->
    } 
}

Node_ *remove(Node_ *root, int data) {
    
}

Node_ *modify(Node_ *root, int data) {
    
}

Node_ *search(Node_ *root, int data) {
    
}
















