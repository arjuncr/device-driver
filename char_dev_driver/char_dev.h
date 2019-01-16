#ifndef CHAR_DEV_HEADER_FILE
#define CHAR_DEV_HEADER_FILE

#define 	SUCCESS 	0

extern int 	char_dev_init_module(void);
extern void 	char_dev_cleanup_module(void);
extern int 	char_dev_open(struct inode *, struct file *);
extern int 	char_dev_release(struct inode *, struct file *);
extern ssize_t  char_dev_read(struct file *, char *, size_t, loff_t *);
extern ssize_t  char_dev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops = {
  .owner   =    THIS_MODULE,
  .read    = 	char_dev_read,
  .write   = 	char_dev_write,
  .open    = 	char_dev_open,
  .release = 	char_dev_release
};

MODULE_LICENSE("GPL");
MODULE_AUTHOR("arjun");
MODULE_DESCRIPTION("simple char_dev driver");

module_init(char_dev_init_module);
module_exit(char_dev_cleanup_module);

#endif
