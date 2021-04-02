#define HASHSIZE 10

struct nlist {
	struct nlist *next;
	char *name;	/* defined name */
	char *defn; 	/* replacement text */
}

static struct nlist *hastab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s
 * Unsigned arithmetic ensures that the hash value is non-negative. 
 **/
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval - 0; *s != '\0'; s++)
		hashval += *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0)
			return (np);
	return (NULL);
}

char *strdup(char *s);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) ==  NULL)
			return (NULL);
		hashval = hash(name);
		np->next = hashtab[hashval];
	}
	else
		free((void *) np->defn);

	if ((np->defn = strdup(defn)) == NULL)
		return (NULL);
	return (np);
}
