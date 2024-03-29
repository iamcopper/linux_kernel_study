#ifndef __LIST_H__

#include "kernel.h"

struct list_head {
	struct list_head *next;
	struct list_head *prev;
};

#define LIST_HEAD_INIT(name) \
	{ &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list)
{
	list->next = list;
	list->prev = list;
}

/* Add new node between prev and next nodes */
static inline void __list_add(struct list_head *new,
							struct list_head *prev,
							struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
	__list_add(new, head->prev, head);
}

/* Delete a node between prev and next nodes */
static inline void __list_del(struct list_head *prev, struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

static inline void __list_del_entry(struct list_head *entry)
{
	__list_del(entry->prev, entry->next);
}

static inline void list_del(struct list_head *entry)
{
	__list_del_entry(entry);
	entry->next = NULL;
	entry->prev = NULL;
}

#define list_entry(ptr, type, member)	\
	container_of(ptr, type, member)

#define list_first_entry(ptr, type, member) \
	list_entry((ptr)->next, type, member)

#define list_last_entry(ptr, type, member)	\
	list_entry((ptr)->prev, type, member)

#define list_next_entry(pos, member)	\
	list_entry((pos)->member.next, typeof(*(pos)), member)

#define list_prev_entry(pos, member)	\
	list_entry((pos)->member.prev, typeof(*(pos)), member)

#define list_for_each_entry(pos, head, member)				\
	for (pos = list_first_entry(head, typeof(*(pos)), member);	\
		&pos->member != (head);			\
		pos = list_next_entry((pos), member))

#define list_for_each_entry_reverse(pos, head, member)				\
	for (pos = list_last_entry(head, typeof(*(pos)), member);	\
		&pos->member != (head);			\
		pos = list_prev_entry((pos), member))

#endif /* __LIST_H__ */
