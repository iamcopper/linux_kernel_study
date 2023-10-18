## 1 Introduction
Kernel List implementation and example.

## 2 Kernel Source Code
* list --- Simple doubly linked list implementation

| Structure / Function | Link |
| --- | --- |
| Define | |
| - | [linux-v4.19/include/linux/list.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/list.h) |
| `struct list_head` | [linux-v4.19/include/linux/types.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/types.h) |
| `offsetof/container_of` | [linux-v4.19/tools/include/linux/kernel.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/kernel.h) |
| Use | |
| - | [linux-v4.19/drivers/i2c/i2c-dev.c](https://gitee.com/iamcopper/linux/blob/branch-v4.19/drivers/i2c/i2c-dev.c) |
| - | [linux-v4.19/drivers/spi/spidev.c](https://gitee.com/iamcopper/linux/blob/branch-v4.19/drivers/spi/spidev.c) |

* klist --- Some generic list helpers, extending struct list_head a bit

| Link |
| --- |
| [linux-v4.19/include/linux/klist.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/klist.h) |
| [linux-v4.19/lib/klist.c](https://gitee.com/iamcopper/linux/blob/branch-v4.19/lib/klist.c) |

* llist --- Lock-less NULL terminated single linked list

| Link |
| --- |
| [linux-v4.19/include/linux/llist.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/llist.h) |

* plist --- Descending-priority-sorted double-linked list

| Link |
| --- |
| [linux-v4.19/include/linux/plist.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/plist.h) |
