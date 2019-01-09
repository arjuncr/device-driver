//sample driver
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

static int __init hello_world_init(void)
{
	printk(KERN_INFO "Welcome to test driver\n");
        printk(KERN_INFO "This is a sample driver\n");
	return 0;
}

void __exit hello_world_exit(void)
{
	printk(KERN_INFO "Driver Removed Successfully\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("test");
MODULE_DESCRIPTION("simple test driver");
