#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("leungjch");
MODULE_DESCRIPTION("bme280 sensor driver");

static int open_driver(struct inode *device_file, struct  file *instance) {
	pr_info("bme280: open was called");
	return 0;
}

static int close_driver(struct inode *device_file, struct file *instance) {
	pr_info("bme280: close was called");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = open_driver,
	.release = close_driver
};

#define DEVMAJOR 90

static int init_driver(void) {
	pr_info("Hello world!\n");
	int register_ret = register_chrdev(DEVMAJOR, "bme280_dev_nr", &fops);
	if (register_ret == 0) {
		pr_info("bme280: registered device");
	} else if (register_ret > 0) {
		pr_info("bme280: already registered device");
	} else {
		pr_err("bme280: could not register device number");
		return -1;
	}
	return 0;
}

static void exit_driver(void) {
	unregister_chrdev(DEVMAJOR, "bme280_dev_nr");
	pr_info("Goodbye world!\n");
	return;
}

module_init(init_driver);
module_exit(exit_driver);
