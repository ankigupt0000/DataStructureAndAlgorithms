#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"


int
main(int argc, char** argv)
{
	int num = -1;
	int itr = 0;
	int des_seq[1000]={0};
	stack s;
	int *m;
	int ret;
	int j;
	while(num != 0)
	{
exit_infi:
		scanf("%d",&num);  /* Take single number of coaches */
		if(num == 0)       /* if number of coaches is 0 exit */
			break;
		while(1)		   /* check any number of combinations */
		{
			for(itr = 0; itr < num; itr++)
			{
				scanf("%d",&des_seq[itr]);
				if(des_seq[itr] == 0) /* if no combination provided exit */
					goto exit_infi;
			}
			/* Taking input done, time to process */
			s = NULL;
			j = 0;
			for(itr = 1; itr <= num; itr++)
			{
				if(des_seq[j] > itr)
				{
					m=malloc(sizeof(int));
					*m = itr;
					stackPush(&s,m);
					//printf("pushed %d \n",*m);
				}
				else
				{
					do
					{
						if(!stackEmpty(&s))
							ret=*((int*)stackPop(&s));
							//printf("popped %d \n",ret);
					}while(ret == des_seq[++j]);
				}
			}
			if(stackEmpty(&s))
				printf("Yes\n");
			else
				printf("No\n");
			/* processing ends */
		}
		printf("\n");
	}
	return 0;
}
