/*Let us create a few structures suitable for graphics. The basic object is a point, which we will
assume has an x coordinate and a y coordinate, both integers.*/

struct point {
	int x;
	int y;
};

struct rect {
	struct point pt1;
	struct point pt2;
};
/*The only legal operations on a structure are copying it or assigning to it as a unit, taking its
address with &, and accessing its members. Copy and assignment include passing arguments to
functions and returning values from functions as well. Structures may not be compared. A
structure may be initialized by a list of constant member values; an automatic structure may
also be initialized by an assignment. */

 /* makepoint: make a point from x and y components, return a struct 
  * of specific type (point) */
struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return (temp);
}

struct rect screen;
struct point middle;

screen.pt1 = makepoint(0, 0);
screen.pt2 = makepoint(4, 6);
middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
		(screen.pt1.y + screen.pt2.y) / 2);

/* The next step is a set of functions to do arithmetic on points. For instance */

/* addpoints: add two points - returns an struct*/
struct addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += ps.y;
	return (p1);
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
	return (p.x >= r.pt1.x && p.y < r.pt2.x
		&& p.y >= r.pt1.y && p.y < r.pt2.y);
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = min(r.pt1.x, r.pt2.x);
	temp.pt1.y = min(r.pt1.y, r.pt2.y);
	temp.pt2.x = max(r.pt1.x, r.pt2.x);
	temp.pt2.y = max(r.pt1.y, r.pt2.y);
	return (temp);
}

/*
 * If a large structure is to be passed to a function, it is generally more efficient to pass a pointer
 * than to copy the whole structure. Structure pointers are just like pointers to ordinary variables.
 * The declaration
 */

/*
 * *pp is the structure
 * (*pp).x and (*pp).y are the members
 */
struct point origin, *pp;

pp = &origin;
printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
printf("origin is (%d,%d)\n", pp->x, pp->y);

struct rect r, *rp = &r;
/* then these four expressions are equivalent: */
r.pt1.x;
r->pt1->x;
(r.pt1).x;
(r->pt1).x;

struct {
	int len;
	char *str;
} *p;

/* increments len, not p before accesing len */
++p->len;

/* increments p before and after accessing len */
(++p)->len;
(p++)->len;

/* r fetches whatever str points to; */
*p->str;

/* increments str after accessing whatever it points to (just like *s++)*/
*p->str++;

/* + increments whatever str points to*/
(*p->str)++;

/* increments p after accessing whatever str points to. */
*p++->str;
