typedef struct dict *Dict;

/* Provides operations for working with keys or values */
struct dictContentsOperations {
	/* hash function */
	unsigned long (*hash) (const void *datum, void *arg);

	/* returns nonzero if *datum1 == *datum 2 */
	int (*equal)(const void *datum1, const void *datum2, void *args);

	/* make a copy of datum that will survive changes to original */
	void *(*copy)(const void *datum, void *args);

	/* free a copy */
	void (*delete) (void *datum, void *args);

	/* extra argument, to allow further specialization */
	void *arg;
};

/* create a new dictionary with given key and value operations */
/* Note: valueOps.hash and valueOps.equal are not used. */

Dict
dictCreate(struct dictContentsOperations keyOps,
			struct dictContentsOperations valueOps);

/* free a dictionary and all the space it contains */
/* This will call the appropriate delete function for all keys and */
/* values */
void dictDestroy(Dict d);

/* set dict[key] = value. */
/* Both key and value are copied internally. */
/* if data is the null pointer, remove dict[key]. */

void dictSet(Dict d, const void *key, const void *value);

/* Return dict[key], r null if dict[key] has not been set  */

const void *dictGet(Dict d, const void *key);

/* some predefined dictContentsOperations structures */

/*
 * DictIntOps support int's that have been cast to (void *), e.g.:
 * 		d = dictCreate(DictIntOps, DictIntOps);
 * 		dictSet(d,(void*) 1, (void *) 2));
 * 		x = (int) dictGet(d, (void*) 1);
 */
struct dictContentsOperations DictIntOps;

/*
 * Supports null-terminated strings, e.g.:
 * 		d = dictCreate(DictStringOps, DictStringOps);
 * 		dictSet(d, "foo", "bar");
 * 		s = dictGet(d,"foo");
 * Note: no cast are needed since C automatically converts
 * between (void *) and other pointer types.
 */
struct dictContentsOperations DictStringOps;

/* Supports fixed-sixe block of memory, e.g.:
 * 		int x = 1;
 * 		int y = 2;
 * 		d = dictCreate(dictMemOps(sizeof(int)), dictMemOps(sizeof(int));
 * 		dictSet(d,&x,&y);
 * 		printf("%d", *dictGet(d,&x);
 */
struct dictContentsOperations dictMemOps(int size);
