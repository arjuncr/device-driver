//simple char dev driver

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include "char_dev.h"

static int major = 250;

int char_dev_init_module(void)
{

  major = register_chrdev(0, "simple_driver", &fops);

  if (major < 0) 
  {
    printk(KERN_ALERT "Registering char device failed with %d\n",major);
    return major;
  }

   printk(KERN_INFO "simple char dirver:init major %d\n",major);

  return SUCCESS;
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

