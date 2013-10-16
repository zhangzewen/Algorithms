#include "RBTree.h"
#include <stdio.h>
#include <stdlib.h>
/*
红黑树的性质
1.节点非黑即红
2.节点是红，其左右子节点为黑
3.空节点(NULL)是黑色的
4.根节点是黑色的
5.对每个结点，从该结点到其子孙结点的所有路径上包含相同数目的黑结点
*/
static rb_node_t *rb_new_node(key_t key, data_t data)
{
	rb_node_t *node = (rb_node_t *)malloc(sizeof(struct rb_node_t));
	
	if (!node) {
		printf("malloc error!\n");
		exit(-1);
	}
	
	node->key = key;
	node->data = data;
	return node;
}

static rb_node_t *rb_insert_rebalance(rb_node_t *node, rb_node_t *root);
static rb_node_t *rb_erase_rebalance(rb_node_t *node, rb_node_t *parent, rb_node_t *root);
static rb_node_t *rb_rotate_left(rb_node_t *node, rb_node_t *root)
{
	rb_node_t *right = node->right;

	if ((node->right = right->left)) { //这个分两步走：1.先赋值，2.在判断赋值时候为空
		right->left->parent = node;
	}
	
	right->left = node;
	
	if ((right->parent = node->parent)) {
		if (node == node->parent->right) {
			node->parent->right = right;
		}else {
			node->parent->left = right;	
		}
	}else {
		root = right;
	}
	
	node->parent = right;
	
	return root;
}


static rb_node_t *rb_rotate_right(rb_node_t *node, rb_node_t *root)
{
	rb_node_t *left = node->left;
	
	if ((node->left = left->right)) {
		left->right->parent = node;
	}

	left->right = node;
	
	if ((left->parent = node->parent)) {
		if (node == node->parent->right) {
			node->parent->right = left;
		}else {
			node->parent->left = left;
		}
	}else {
		root = left;
	}

	node->parent = left;
	
	return root;
}


static rb_node_t *rb_search_auxiliary(key_t key, rb_node_t *root, rb_node_t **save)
{
	rb_node_t *node = root;
	rb_node_t *parent = NULL;
	int ret = 0;
	
	while(node) {
		parent = node;
		ret = node->key - key;
		
		if(0 < ret) {
			node = node->left;
		} else if (0 > ret) {
			node = node->right;
		}else {
			return node;
		}
	}

	if (save) {
		*save = parent;
	}

	return NULL;
}

rb_node_t *rb_search(key_t key, rb_node_t *root)
{
	return rb_search_auxiliary(key, root, NULL);
}

rb_node_t *rb_insert(key_t key, data_t data, rb_node_t *root)
{
	rb_node_t *parent = NULL;
	rb_node_t *node = NULL;

	parent = NULL;

	if ((node = rb_search_auxiliary(key, root, &parent))) {
		return root;
	}

	node = rb_new_node(key, data);
	node->parent = parent;
	node->left = node->right = NULL;
	node->color = RED;

	if(parent) {
		if (parent->key > key) {
			parent->left = node;
		}else {
			parent->right = node;
		}
	}else {
		root = node;
	}
	return rb_insert_rebalance(node, root);
}

/*
	用z表示当前节点，p[z]表示父节点，p[p[z]]表示祖父节点,y表示叔叔
*/
static rb_node_t *rb_insert_rebalance(rb_node_t *node, rb_node_t *root)
{
	rb_node_t *parent;//父节点p[z]
	rb_node_t *gparent;//祖父节点p[p[z]]
	rb_node_t *uncle;//叔叔节点y
	rb_node_t *tmp;//临时节点
	
	while ((parent = node->parent) && parent->color == RED) {
		//parent 为node的父节点，且当父节点颜色为红 ?不该判断父节点是否为空（根节点）
		gparent = parent->parent;
		
		if (parent == gparent->left) { //当祖父的左孩子即为父母时
			uncle = gparent->right;//定义叔叔的概念 ,叔叔就是父母的右孩子

			if (uncle && uncle->color == RED) {//情况1:z的叔叔y是红色的
				uncle->color = BLACK;//将叔叔节点y染黑
				parent->color = BLACK;//z的父母p[z]染黑，解决z,p[z]都是红色的问题
				gparent->color = RED;

				node = gparent; //将祖父当作新增节点z，指针z上移两层，且染红
			//上述情况1中，只考虑了z作为父母的右孩子的情况
			}else { //情况2：z的叔叔y是黑色的
				if (parent->right == node) { //且z为右孩子
					root = rb_rotate_left(parent, root); // 左旋[节点z，与父母节点]
					tmp = parent;
					parent = node;
					node = tmp; //parent与node互换角色
				}
				//情况3：z的叔叔y是黑色的，此时z成了左孩子
				//注意：1.情况3是由上述情况2变化而来的
				//2：z的叔叔总是黑色的，否则就是情况1了
				//z的父母p[z]染黑
				//原祖父节点染红
				//
				parent->color = BLACK;
				gparent->color = RED;
				root = rb_rotate_right(gparent, root);//右旋[节点z，与祖父节点]
			}
		}else { //当祖父的右孩子是父母时
			uncle = gparent->left;//祖父的左孩子作为叔叔的几点
			if (uncle && uncle->color == RED) {//情况1：z的叔叔y是红色的 
				uncle->color = BLACK;	
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;//同上
			}else {//情况2：z的叔叔y是黑色的
				if (parent->left == node) { //且z为左孩子
					root = rb_rotate_right(parent, root);//以节点parent，root右旋
					tmp = parent;
					parent = node;
					node = tmp;//parent与node互换角色
				}
				//经过情况2的变化，成了情况3
				parent->color = BLACK;
				gparent->color = RED;
				root = rb_rotate_left(gparent, root); //以节点gparent和root右旋
			}
		}
	}
	//当父亲节点为黑色的时候，红黑树的性质不变
	root->color = BLACK;//根节点，不论怎样，都得置为黑色
	return root; //返回根节点
}
/*
如果需要删除的节点有两个儿子，那么问题可以被转化成删除另一个只有一个儿子的节点的问题（为了表述方便，这里所指的儿子，为非叶子节点的儿子）。对于二叉查找树，在删除带有两个非叶子儿子的节点的时候，我们找到要么在它的左子树中的最大元素、要么在它的右子树中的最小元素，并把它的值转移到要删除的节点中(如在这里所展示的那样)。我们接着删除我们从中复制出值的那个节点，它必定有少于两个非叶子的儿子。因为只是复制了一个值而不违反任何属性，这就把问题简化为如何删除最多有一个儿子的节点的问题。它不关心这个节点是最初要删除的节点还是我们从中复制出值的那个节点。
在本文余下的部分中，我们只需要讨论删除只有一个儿子的节点(如果它两个儿子都为空，即均为叶子，我们任意将其中一个看作它的儿子)。如果我们删除一个红色节点（此时该节点的儿子将都为叶子节点），它的父亲和儿子一定是黑色的。所以我们可以简单的用它的黑色儿子替换它，并不会破坏属性3和4。通过被删除节点的所有路径只是少了一个红色节点，这样可以继续保证属性5。另一种简单情况是在被删除节点是黑色而它的儿子是红色的时候。如果只是去除这个黑色节点，用它的红色儿子顶替上来的话，会破坏属性5，但是如果我们重绘它的儿子为黑色，则曾经通过它的所有路径将通过它的黑色儿子，这样可以继续保持属性5。
需要进一步讨论的是在要删除的节点和它的儿子二者都是黑色的时候，这是一种复杂的情况。我们首先把要删除的节点替换为它的儿子。出于方便，称呼这个儿子为N(在新的位置上)，称呼它的兄弟(它父亲的另一个儿子)为S
*/
rb_node_t *rb_erase(key_t key, rb_node_t *root)
{
	rb_node_t *child;	
	rb_node_t *parent;
	rb_node_t *old; //要删除的节点的copy
	rb_node_t *left;
	rb_node_t *node;//要删除的节点

	color_t color;

	if (!(node = rb_search_auxiliary(key, root, NULL))) {
		printf("key %d is not exist !/n");
		return root;
	}		

	old = node; 
	
	if (node->left && node->right) { //当要删除的节点的左右子节点都不为NULL时
		node = node->right;//本规则是取药删除节点的右子树中最小的节点
		while ((left = node->left) != NULL) {
			node = left;
		}
//找到右子树中的最小节点，并取其右孩子赋值给child
		child = node->right;
		parent = node->parent;//获取最小节点的父节点
		color = node->color; //获取最小节点的color

		if (child) {
			child->parent = parent;
		}

		if (parent) {
			if (parent->left == node) {
				parent->left = child;
			}else {
				parent->right = child;
			}
		}else {
			root = child;
		}

		if (node->parent == old) {
			parent = node;
		}

		node->parent = old->parent;
		node->color = old->color;
		node->right = old->right;
		node->left = old->left;

		if (old->parent) {
			if (old->parent->left == old) {
				old->parent->left = node;
			}else {
				old->parent->right = node;
			}
		}else {
			root = node;
		}
		
		old->left->parent = node;

		if (old->right) {
			old->right->parent = node;
		}
	}else {
		if (!node->left) {
			child = node->right;
		}else if (!node->right) {
			child = node->left;
		}

		parent = node->parent;
		color = node->color;

		if (child) {
			child->parent = parent;
		}
	
		if (parent) {
			if (parent->left == node) {
				parent->left = child;
			}else {
				parent->right = child;
			}
		}else {
			root = child;
		}
	}
	free(old);
	
	if (color == BLACK) {
		root = rb_erase_rebalance(child, parent, root);
	}

	return root;
}
//红黑树修复删除的4中情况
//x表示要删除的节点，*other， w表示兄弟节点
static rb_node_t *rb_erase_rebalance(rb_node_t *node, rb_node_t *parent, rb_node_t *root)
{
	rb_node_t *other; //x的兄弟other
	rb_node_t *o_left; //兄弟的左孩子
	rb_node_t *o_right; //兄弟的右孩子
	while ((!node || node->color == BLACK) && node != root) {
		if (parent->left == node) {
			other = parent->right;
			if (other->color == RED) { //情况1：x的兄弟w是红色的
				other->color = BLACK;
				parent->color = RED;//改变颜色 w->黑色 , x的父节点染红
				root = rb_rotate_left(parent, root);//在以x的父节点做一次左旋
				other = parent->right;
			}

			if ((!other->left || other->left->color == BLACK) &&
						(!other->right || other->right->color == BLACK)) { // 情况2：x的兄弟w是黑色的，且w的两个孩子都是黑色的
				other->color = RED;// 兄弟w变成为红色
				node = parent; //父节点为新节点node
				parent = node->parent; // 
			}else {
				if (!other->right ||  other->right->color == BLACK) {
					if ((o_left = other->left)) {
						o_left->color = BLACK;
					}

					other->color = RED;
					root = rb_rotate_right(other, root);
					other = parent->right;
				}
				
				other->color = parent->color;
				parent->color = BLACK;
				if (other->right) {
					other->right->color = BLACK;
				}

				root = rb_rotate_left(parent, root);
				node = root;
				break;
			}
		}else {
			other = parent->left;
			if (other->color == RED) {
				other->color = BLACK;
				parent->color = RED;
				root = rb_rotate_right(parent, root);
				other = parent->left;
			}
			
			if ((!other->left || other->left->color == BLACK) && 
					(!other->right || other->right->color == BLACK)) {
				other->color = RED;
				node = parent;
				parent = node->parent;
			}else {
				if (!other->left || other->left->color == BLACK) {
					if ((o_right = other->right)) {
						o_right->color = BLACK;
					}
					other->color = RED;
					root = rb_rotate_left(other, root);
					other = parent->left;
				}
			
				other->color = parent->color;
				parent->color = BLACK;

				if (other->left) {
					other->left->color = BLACK;
				}

				root = rb_rotate_right(parent, root);
				node = root;
				break;
			}
		}
	}
	
	if (node) {
		node->color = BLACK;
	}
	return root;
}
