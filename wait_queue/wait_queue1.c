#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static int condition;
static struct task_struct *task_1;
static struct task_struct *task_2;
static struct task_struct *task_3;

DECLARE_WAIT_QUEUE_HEAD(wq);

static int thread_func_1(void *data)
{
	int i = 0;
	while (i++ < 100) {
		wait_event(wq, condition == 1);
		msleep(1000);
		printk(">>>>>this task 1\n");
	}
	return 0;
}

static int thread_func_2(void *data)
{
	int i = 0;
	while (i++ < 100) {
		wait_event(wq, condition == 1);
		msleep(1000);
		printk(">>>>>this task 2\n");
	}
	return 0;
}

static int thread_func_3(void *data)
{
	int i = 0;
	while (i++ < 10) {
		condition = 0;
		msleep(2000);
		printk(">>>>>this task 3\n");
		condition = 1;
		wake_up(&wq);
		msleep(2000);
	}
	return 0;
}

static int __init wait_queue1_init(void)
{
	printk("%s\n", __func__);
	condition = 0;

	task_1 = kthread_run(thread_func_1, NULL, "thread%d", 1);
	if (IS_ERR(task_1))
		printk("**********create thread 1 failed\n");
	else
		printk("======success create thread 1\n");

	task_2 = kthread_run(thread_func_2, NULL, "thread%d", 2);
	if (IS_ERR(task_2))
		printk("**********create thread 2 failed\n");
	else
		printk("======success create thread 2\n");

	task_3 = kthread_run(thread_func_3, NULL, "thread%d", 3);
	if (IS_ERR(task_3))
		printk("**********create thread 3 failed\n");
	else
		printk("======success create thread 3\n");
	return 0;
}

static void __exit wait_queue1_exit(void)
{
	int ret = 0;

	printk("%s\n", __func__);

	if (!IS_ERR(task_1)) {
		ret = kthread_stop(task_1);
		if (ret > 0)
			printk("<<<<<<<<%d\n", ret);
	}

	if (!IS_ERR(task_2)) {
		ret = kthread_stop(task_2);
		if (ret > 0)
			printk("<<<<<<<<%d\n", ret);
	}

	if (!IS_ERR(task_3)) {
		ret = kthread_stop(task_3);
		if (ret > 0)
			printk("<<<<<<<<%d\n", ret);
	}
}

module_init(wait_queue1_init);
module_exit(wait_queue1_exit);
MODULE_AUTHOR("iamcopper<kangpan519@gmail.com>");
MODULE_LICENSE("GPL v2");

