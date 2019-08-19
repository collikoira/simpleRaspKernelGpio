obj-m += test.o

all: 
	make ARCH=arm CROSS_COMPILE=${CCPREFIX}	-C /home/antti/rasp/linux M=$(PWD) modules	



clean: 
	make -C /home/antti/rasp/linux M=$(PWD) clean
