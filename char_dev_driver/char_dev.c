//simple char dev driver
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/unistd.h>
#include <linux/fcntl.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include "char_dev.h"

int __init char_dev_init_module(void)
{

  if (alloc_chrdev_region(&first, 0, 1, NAME) < 0)
  {
    return -1;
  }

  if ((cl = class_create(THIS_MODULE, NAME)) == NULL)
  {
    unregister_chrdev_region(first, 1);
    return -1;
  }

  if (device_create(cl, NULL, first, NULL, NAME) == NULL)
  {
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
    return -1;
  }

    cdev_init(&c_dev, &fops);

  if (cdev_add(&c_dev, first, 1) == -1)
  {
    device_destroy(cl, first);
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
    return -1;
  }

  printk(KERN_INFO "simple char dirver:init simple_driver\n");

  return 0;
}
void char_dev_cleanup_module(void)
{
  printk(KERN_INFO "simple char dirver:cleanup module\n");

  unregister_chrdev(major,"simple_driver");
}

int char_dev_open(struct inode *inode, struct file *filp)
{
  printk(KERN_INFO "simple char dirver:open\n");
   
  return SUCCESS;
}

int char_dev_release(struct inode *inode, struct file *filp)
{  
  printk(KERN_INFO "simple char dirver:release\n");

  return SUCCESS;
}

ssize_t char_dev_read(struct file *filp,char *buffer,size_t length,loff_t *offset)
{
  printk(KERN_INFO "simple char dirver:read\n");

  return SUCCESS;
}

ssize_t char_dev_write(struct file *filp, const char *buf, size_t len, loff_t *off)
{
  printk(KERN_INFO "simple char dirver:write\n");

  return  SUCCESS;
}

void __exit char_dev_exit(void)
{
  cdev_del(&c_dev);
  device_destroy(cl, first);
  class_destroy(cl);
  unregister_chrdev_region(first, 1);
  printk(KERN_INFO "simple char dirver:exit\n");
}

