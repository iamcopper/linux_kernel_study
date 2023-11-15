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
	printk(">>>>>task 1 enter and wait_event\n");
	wait_event(wq, condition == 1);
	printk(">>>>>task 1 is woke up, start while\n");
	while(1)
	{
		if (kthread_should_stop())
		{
			printk(">>>>>task 1 stop and exit\n");
			return 0;
		}
		msleep(3000);
		printk(">>>>>task 1 in while\n");
	}
	printk(">>>>>task 1 exit\n");
	return 0;
}

static int thread_func_2(void *data)
{
	printk(">>>>>task 2 enter and wait_event\n");
	wait_event(wq, condition == 1);
	printk(">>>>>task 2 is woke up, start while\n");
	while(1)
	{
		if (kthread_should_stop())
		{
			printk(">>>>>task 2 stop and exit\n");
			return 0;
		}
		msleep(3000);
		printk(">>>>>task 2 in while\n");
	}
	printk(">>>>>task 2 exit\n");
	return 0;
}

static int thread_func_3(void *data)
{
	printk(">>>>>task 3 enter\n");
	printk(">>>>>task 3 sleep 2s\n");
	msleep(2000);
	printk(">>>>>task 3 set condition and wait_up\n");
	condition = 1;
	wake_up(&wq);
	printk(">>>>>task 3 start while\n");
	while(1)
	{
		if (kthread_should_stop())
		{
			printk(">>>>>task 3 stop and exit\n");
			return 0;
		}
		msleep(3000);
		printk(">>>>>task 3 in while\n");
	}
	printk(">>>>>task 3 exit\n");
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
		printk("task_1 ret=%d\n", ret);
	}

	if (!IS_ERR(task_2)) {
		ret = kthread_stop(task_2);
		printk("task_2 ret=%d\n", ret);
	}

	if (!IS_ERR(task_3)) {
		ret = kthread_stop(task_3);
		printk("task_3 ret=%d\n", ret);
	}
}

module_init(wait_queue1_init);
module_exit(wait_queue1_exit);
MODULE_AUTHOR("iamcopper<kangpan519@gmail.com>");
MODULE_LICENSE("GPL v2");

