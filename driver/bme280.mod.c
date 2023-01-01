#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xabab44ce, "module_layout" },
	{ 0x45b0d854, "cdev_del" },
	{ 0x4da180b4, "i2c_del_driver" },
	{ 0x4d450972, "i2c_unregister_device" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xfe146ed6, "class_destroy" },
	{ 0x5adbbca6, "i2c_smbus_write_byte_data" },
	{ 0x9146d475, "i2c_put_adapter" },
	{ 0xf404247d, "i2c_register_driver" },
	{ 0xef0b77f2, "i2c_new_client_device" },
	{ 0x1db86460, "i2c_get_adapter" },
	{ 0x4a1b0727, "device_destroy" },
	{ 0x1727426a, "cdev_add" },
	{ 0x8ab0a071, "cdev_init" },
	{ 0x29ea4f1c, "device_create" },
	{ 0x33c2febe, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x97255bdf, "strlen" },
	{ 0xe914e41e, "strcpy" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x3ea1b6e4, "__stack_chk_fail" },
	{ 0xe8b759d6, "i2c_smbus_read_word_data" },
	{ 0x59e5070d, "__do_div64" },
	{ 0x884e50c9, "i2c_smbus_read_byte_data" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x92997ed8, "_printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E68AF7624275F790559F990");
