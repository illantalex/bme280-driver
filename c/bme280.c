#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("leungjch");
MODULE_DESCRIPTION("bme280 sensor driver");

static int init(void) {
	printk("Hello world");
	return 0;
}

static void exit(void) {
	return;
}

module_init(init);
module_exit(exit);


