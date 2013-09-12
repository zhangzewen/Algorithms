#include "AVL.H"

void R_Rotate(BSTree &p)
{
	lc = p->lchild;
	p->lchild = lc->rchild;
	lc->rchild = p;
	p = lc;
}

void L_Rotate(BSTree &p)
{
	rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
	
}

#define LH	1
#define EH	0
#define RH	-1

int InsertAVL(BSTree &T, char e, Boolean &taller) {
	if(!T){
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = TRUE;
	}else{
		if(EQ(e.key, T->data.key)){
			taller = FALSE;
			return 0;
		}

		if(LT(e.key, T->data.key)) {
			if(!InsertAVL(T->lchild, e, taller)) {
				return 0;
			}
			
			if(taller) {
				switch(T->bf) {
					case LH:
						LeftBalance(T);
						taller = FALSE;
						break;
					case EH:
						T->bf = LH;
						taller = TRUE;
						break;
					case RH:
						T->bf = EH;
						taller = FALSE;
						break;
				}
			}else{
				if(!InsertAVL(T->rchild, e, taller)) {
					return 0;
				}
		
				if(taller) {
					switch(T->bf) {
						case LH:
							T->bf = EH;
							taller = FALSE;
							break;
						case EH:
							T->bf = RH;
							taller = TRUE;
							break;
						case RH：
							RightBlance(T);
							taller = FALSE;
							break;
					}
				}
			}
		}
	}
}


void LeftBalance(BSTree & T){
	lc = T->lchild;
	switch(lc->bf) {
		case LH:
			T->bf = lc->bf = EH;
			R_Rotate(T);
			break;
		case RH:
			rd = lc->rchild;
			switch(rd->bf) {
				case LH:
					T->bf = RH;
					lc->bf = EH;
					break;
				case EH:
					T->bf = lc->bf = EH;
					break;
				case RH:
					T->bf = EH;
					lc->bf = LH;
			}
			
			rd->bf = EH;
			L.rotate(T->lchild);
			R.Rotate(T);
	}
}
