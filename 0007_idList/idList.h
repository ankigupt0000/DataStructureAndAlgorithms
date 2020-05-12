typedef struct idList *IDList;

#define MIN_ID (0)
#define MAX_ID (999999999)

/* build on IDLIST out of an unsorted array of n good ids */
/* return 0 on allocation failure */

IDList
IDListCreate(int n, int unsortedIdList[]);

/* destroy on IDList */
void
IDListDestroy(IDList list);

/* check an id against the list */
/* returns nonzero if id is in the list */

int
IDListContains(IDList list, int id);
