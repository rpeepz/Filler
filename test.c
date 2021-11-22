#include "libbignum.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

int main(void) {

/*
	Testing bignum_init and bignum_del
	
	t_bignum*	a;
	char* number;

	number = "-987";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "123";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "42";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "0";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "-0";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "-0a";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "--";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "a";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "-a0";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "-041a4";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);

	number = "00000414a";
	a = bignum_init(number);
	printf("number %s -> %s, length %ld -> %ld, sign %d\n", number, a->number, ft_strlen(number), a->len, a->sign);
	bignum_del(&a);
*/

/*
	Testing bignum_eq

	t_bignum	*a;
	t_bignum	*b;
	char		*num1;
	char		*num2;
	
	num1 = "123";
	num2 = "123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "123";
	num2 = "124";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "123";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-123";
	num2 = "123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "A";
	num2 = "0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "A";
	num2 = "-0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s\nnum2: %s ", a->number, b->number);
	printf("equal?: %s\n", bignum_eq(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);
*/

/*
	Testing bignum_gt

	t_bignum	*a;
	t_bignum	*b;
	char		*num1;
	char		*num2;
	
	num1 = "041";
	num2 = "141";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s (false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "441";
	num2 = "442";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s (false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "124";
	num2 = "12";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "100";
	num2 = "123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "123";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124444";
	num2 = "-124445";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-041";
	num2 = "-141";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124";
	num2 = "-12";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 greater?: %s\n", bignum_gt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);
*/

/*
	Testing bignum_lt

	t_bignum	*a;
	t_bignum	*b;
	char		*num1;
	char		*num2;
	
	num1 = "-2147483648.                 3";
	num2 = "141";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s (true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "441";
	num2 = "442";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s (true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "124";
	num2 = "12";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "100";
	num2 = "123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "123";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(flase)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124444";
	num2 = "-124445";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(flase)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124";
	num2 = "-123";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-041";
	num2 = "-141";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);

	num1 = "-124";
	num2 = "-12";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(true)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);
	
	num1 = "0";
	num2 = "0";
	a = bignum_init(num1);
	b = bignum_init(num2);
	printf("num1: %s(false)\nnum2: %s ", a->number, b->number);
	printf("N1 less?: %s\n", bignum_lt(a, b)? "false" : "true");
	bignum_del(&a);
	bignum_del(&b);
*/

/*
	Testing bignum_add

	t_bignum	*a;
	t_bignum	*b;
	t_bignum	*c;
	char		*num1;
	char		*num2;
	
	num1 = "191111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	num2 = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "14";
	num2 = "155";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "1";
	num2 = "420420420420420420420420420420420420420420420420420420420420420420420420420420420420";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "1000000050";
	num2 = "7000000050";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "40000040";
	num2 = "40000059";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "5000000009";
	num2 = "4000000001";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "57";
	num2 = "41";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "150";
	num2 = "50";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "999";
	num2 = "1";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "75";
	num2 = "25";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "1175";
	num2 = "1125";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "65555555555555";
	num2 = "25555555555555";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
 
 */

/*
	Testing bignum_add with negatives
*/
	t_bignum	*a;
	t_bignum	*b;
	t_bignum	*c;
	char		*num1;
	char		*num2;
	
	// num1 = "191111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	// num2 = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111115111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	// a = bignum_init(num1);
	// b = bignum_init(num2);
	// c = bignum_add(a, b);
	// printf("%s + %s = %s\n", a->number, b->number, c->number);
	// bignum_del(&a);
	// bignum_del(&b);
	// bignum_del(&c);

	
	num1 = "100000";
	num2 = "-100001";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-100000";
	num2 = "100001";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "179";
	num2 = "-100169";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-169";
	num2 = "100179";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "179";
	num2 = "-169";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-169";
	num2 = "179";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);
	
	num1 = "-169";
	num2 = "169";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "0";
	num2 = "14";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-169";
	num2 = "14";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "169";
	num2 = "-14";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "-14";
	num2 = "-155";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	
	num1 = "1";
	num2 = "420420420420420420420420420420420420420420420420420420420420420420420420420420420420";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "1000000050";
	num2 = "7000000050";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	num1 = "40000040";
	num2 = "40000059";
	a = bignum_init(num1);
	b = bignum_init(num2);
	c = bignum_add(a, b);
	printf("%s + %s = %s\n", a->number, b->number, c->number);
	bignum_del(&a);
	bignum_del(&b);
	bignum_del(&c);

	


	return (0);
}
