#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct car {
	int doornum;
	char *color;
	char *model;
	struct list_head list;
};

static LIST_HEAD(carlist);

int main(int argc, char *argv[])
{
	struct car *redcar = malloc(sizeof(struct car));
	redcar->doornum = 3;
	redcar->color = "RED";
	redcar->model = "V3";
	INIT_LIST_HEAD(&redcar->list);

	struct car *bluecar = malloc(sizeof(struct car));
	bluecar->doornum = 4;
	bluecar->color = "BLUE";
	bluecar->model = "V4";
	INIT_LIST_HEAD(&bluecar->list);

	struct car yellowcar = {
		.doornum = 8,
		.color = "YELLOW",
		.model = "V8",
		.list = LIST_HEAD_INIT(yellowcar.list),
	};

#if 1
	/* insert from list head */
	list_add(&redcar->list, &carlist);
	list_add(&bluecar->list, &carlist);
	list_add(&yellowcar.list, &carlist);
#else
	/* insert from list tail */
	list_add_tail(&redcar->list, &carlist);
	list_add_tail(&bluecar->list, &carlist);
	list_add_tail(&yellowcar.list, &carlist);
#endif

	printf(">>> Before list_del(), run list_for_each_entry()\n");
	struct car *acar;
	int i = 0, bluecar_num = 0;
	list_for_each_entry(acar, &carlist, list)
	{
		printf("[i=%d] acar->doornum=%d, acar->color=%s, acar->model=%s\n",
				i++, acar->doornum, acar->color, acar->model);
		if (strcmp(acar->color, "BLUE") == 0)
			bluecar_num++;
	}
	printf("Found %d blue car(s)\n\n", bluecar_num);

	list_del(&bluecar->list);

	printf(">>> After list_del(), run list_for_each_entry()\n");
	i = 0;
	bluecar_num = 0;
	list_for_each_entry(acar, &carlist, list)
	{
		printf("[i=%d] acar->doornum=%d, acar->color=%s, acar->model=%s\n",
				i++, acar->doornum, acar->color, acar->model);
		if (strcmp(acar->color, "BLUE") == 0)
			bluecar_num++;
	}
	printf("Found %d blue car(s)\n\n", bluecar_num);

	printf(">>> After list_del(), run list_for_each_entry_reverse()\n");
	i = 0;
	list_for_each_entry_reverse(acar, &carlist, list)
	{
		printf("[i=%d] acar->doornum=%d, acar->color=%s, acar->model=%s\n",
				i++, acar->doornum, acar->color, acar->model);
		if (strcmp(acar->color, "BLUE") == 0)
			bluecar_num++;
	}
	printf("Found %d blue car(s)\n\n", bluecar_num);

	free(redcar);
	free(bluecar);

	return 0;
}
