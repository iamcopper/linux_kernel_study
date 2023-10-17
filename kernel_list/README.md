## 1 Introduction
Kernel List implementation and example.

## 2 Kernel Source Code
| Structure / Function | Link |
| --- | --- |
| Define | |
| - | [linux-v4.19/include/linux/list.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/list.h) |
| `struct list_head` | [linux-v4.19/include/linux/types.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/types.h) |
| `LIST_POISON1/2` | [linux-v4.19/include/linux/poison.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/poison.h) |
| `offsetof/container_of` | [linux-v4.19/tools/include/linux/kernel.h](https://gitee.com/iamcopper/linux/blob/branch-v4.19/include/linux/kernel.h) |
| Use | |
| - | [linux-v4.19/drivers/i2c/i2c-dev.c](https://gitee.com/iamcopper/linux/blob/branch-v4.19/drivers/i2c/i2c-dev.c) |
| - | [linux-v4.19/drivers/spi/spidev.c](https://gitee.com/iamcopper/linux/blob/branch-v4.19/drivers/spi/spidev.c) |
