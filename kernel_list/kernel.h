#ifndef __KERNEL_H__

#ifndef offsetof
#define offsetof(TYPE, MEMBER)		\
	((size_t) &((TYPE *)0)->MEMBER)
#endif

#ifndef container_of
#define container_of(ptr, type, member) ({			\
	const typeof(((type *)0)->member) *__mptr = (ptr);	\
	(type *)((char *)__mptr - offsetof(type, member)); })
#endif

#endif /* __KERNEL_H__ */
