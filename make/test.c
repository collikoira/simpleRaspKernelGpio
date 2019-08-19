#include<linux/init.h>
#include<linux/module.h>
#include<linux/gpio.h>

#define DRIVER_NAME "leds"
#define PDEBUG(fmt,args...) printk(KERN_DEBUG"%s:"fmt,DRIVER_NAME, ##args)
#define PERR(fmt,args...) printk(KERN_ERR"%s:"fmt,DRIVER_NAME,##args)
#define PINFO(fmt,args...) printk(KERN_INFO"%s:"fmt,DRIVER_NAME, ##args)
#define A1 14 // kelt
#define A2 15 // pun

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ANTTI JAAKOLA");
MODULE_DESCRIPTION("A simple Linux char driver for the BBB");  ///< The description -- see modinfo
MODULE_VERSION("0.1");            ///< A version number to inform users

static int __init leds_init(void)
{
	/*  Open gpio-pins A1 & A2 */
	gpio_request(A1,"A1");
	gpio_request(A2,"A2");
	
	gpio_direction_output(A1, 1);
	gpio_direction_output(A2, 2);

	PINFO("INIT, Gpio pins activated\n");

	return 0;
}

static void __exit leds_exit(void)
{	
	/* Close gpio-pins A1 & A2 */
	gpio_direction_output(A1, 0);
	gpio_direction_output(A2, 0);


	gpio_free(A1);
	gpio_free(A2);	

	PINFO("EXIT, gpio pins freed\n");

}

module_init(leds_init);
module_exit(leds_exit);



