#include <stdio.h>
#include <stdlib.h>

#define STACK_EMPTY (0)


struct elt{
	struct elt* next;
	void* data;
};

typedef struct elt* stack;


void
stackPush(stack *s, void* data)
{
	stack e;
	e=malloc(sizeof(struct elt));
	if(e==0) return;

	e->data = data;
	e->next = *s;
	*s=e;
}

int
stackEmpty(const stack *s)
{
	return (*s == STACK_EMPTY);
}

void*
stackPop(stack *s){
	void* ret=NULL;
	stack e;

	if(stackEmpty(s))
		return ret;

	ret = (*s)->data;
	e=*s;

	*s=e->next;
	free(e);

	return ret;
}

int
main(int argc, char** argv)
{
	int num = -1;
	int itr = 0;
	int des_seq[1000]={0};
	stack s;
	int *m;
	//int ret;
	int j;
	while(num != 0)
	{
exit_infi:
		scanf("%d",&num);  /* Take single number of coaches */
		if(num == 0)
			break;
		while(1)		   /* check any number of combinations */
		{
			for(itr =0 ;itr < 1000; itr++)
				des_seq[itr]=0;
			for(itr = 0; itr < num; itr++)
			{
				scanf("%d",&des_seq[itr]);
				if(des_seq[itr] == 0){		/* if no combination provided exit */
					printf("\n");
					goto exit_infi;
				}
			}
			/* Taking input done, time to process */
			s = NULL;
			j=0;
			for(itr = 1; itr <= num ; itr++)
			{
				if(itr <= des_seq[j])
				{
					m = malloc(sizeof(int));
					*m = itr;
					stackPush(&s,m);
				}
				while((s != NULL || !stackEmpty(&s)) && des_seq[j] == *((int*)s->data))
				{
					stackPop(&s);
					j++;
				}
			}
			if(stackEmpty(&s))
				printf("Yes\n");
			else
				printf("No\n");
			/* processing ends */
		}
	}
	return 0;
}
