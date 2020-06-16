
#ifndef _PTLSER_H




#if (LINUX_VERSION_CODE < VERSION_CODE(2,6,9))
#define PTLSER_READ_REG	    readb
#define PTLSER_WRITE_REG	writeb
#else
#define PTLSER_READ_REG	    ioread8
#define PTLSER_WRITE_REG	iowrite8
#endif

#include <asm/uaccess.h>
#define put_to_user(arg1, arg2) put_user(arg1, (unsigned long *)arg2)
#define get_from_user(arg1, arg2) get_user(arg1, (unsigned int *)arg2)

#define	PTLSER_EVENT_TXLOW	    1
#define	PTLSER_EVENT_HANGUP	2

#define SERIAL_DO_RESTART
#define PTLSER_BOARDS		    4	/* Max. boards */
#define PTLSER_PORTS		    32	/* Max. ports */
#define PTLSER_PORTS_PER_BOARD	8	/* Max. ports per board*/
#define PTLSER_ISR_PASS_LIMIT	99999L	

#define	PTLSER_ERR_IOADDR	-1
#define	PTLSER_ERR_IRQ		-2
#define	PTLSER_ERR_IRQ_CONFLIT	-3
#define	PTLSER_ERR_VECTOR	-4

#define SERIAL_TYPE_NORMAL	1
#define SERIAL_TYPE_CALLOUT	2

#define WAKEUP_CHARS		256

#define UART_MCR_AFE		0x20
#define UART_LSR_SPECIAL	0x1E

#define PTLSER_LOCK_INIT()		unsigned long sp_flags=0
#if 0

#define PTLSER_LOCK(lock)		{\
				printk("in %s %d\n", __FUNCTION__,  smp_processor_id());\
				spin_lock_irqsave(lock, sp_flags);\
				}
#define PTLSER_UNLOCK(lock)		{\
				printk("out %s\n", __FUNCTION__);\
				spin_unlock_irqrestore(lock, sp_flags);\
				}
#else
#define PTLSER_LOCK(lock)		{\
				if(!in_interrupt())\
					spin_lock_irqsave(lock, sp_flags);\
				}
#define PTLSER_UNLOCK(lock)		{\
				if(!in_interrupt())\
					spin_unlock_irqrestore(lock, sp_flags);\
				}
#endif

#if (LINUX_VERSION_CODE < VERSION_CODE(2,6,0))
#define PORTNO(x)	(MINOR((x)->device) - (x)->driver.minor_start)
#else
#define PORTNO(x)	((x)->index)
#endif

#define RELEVANT_IFLAG(iflag)	(iflag & (IGNBRK|BRKINT|IGNPAR|PARMRK|INPCK|IXON|IXOFF))

// #if (LINUX_VERSION_CODE < VERSION_CODE(2,6,23))
// #define IRQ_T(info) ((info->flags & ASYNC_SHARE_IRQ) ? SA_SHIRQ : SA_INTERRUPT)
// #else
// #define IRQ_T(info) ((info->flags & ASYNC_SHARE_IRQ) ? IRQF_SHARED : IRQF_DISABLED)
// #endif

#ifndef MIN
#define MIN(a,b)	((a) < (b) ? (a) : (b))
#endif



#ifdef CONFIG_PCI

#ifndef PCI_ANY_ID
#define PCI_ANY_ID (~0)
#endif

#endif



#define	PTLSER_VENDOR_ID	    0x12D8
#define PTLSER_DEVICE_7958		0x7958
#define PTLSER_DEVICE_7954		0x7954
#define PTLSER_DEVICE_7952		0x7952
#define PTLSER_DEVICE_7951		0x7951
#define PTLSER_DEVICE_8958		0x8958
#define PTLSER_DEVICE_8954		0x8954
#define PTLSER_DEVICE_8952		0x8952
#define PTLSER_DEVICE_8951		0x8951

#define PCI_VENDOR_ID_ACCESIO			0x494f
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM_2SDB	0x1051
#define PCI_DEVICE_ID_ACCESIO_MPCIE_COM_2S	0x1053
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM_4SDB	0x105C
#define PCI_DEVICE_ID_ACCESIO_MPCIE_COM_4S	0x105E
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM232_2DB	0x1091
#define PCI_DEVICE_ID_ACCESIO_MPCIE_COM232_2	0x1093
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM232_4DB	0x1099
#define PCI_DEVICE_ID_ACCESIO_MPCIE_COM232_4	0x109B
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM_2SMDB	0x10D1
#define PCI_DEVICE_ID_ACCESIO_MPCIE_COM_2SM	0x10D3
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM_4SMDB	0x10DA
#define PCI_DEVICE_ID_ACCESIO_MPCIE_COM_4SM	0x10DC
#define PCI_DEVICE_ID_ACCESIO_MPCIE_ICM485_1	0x1108
#define PCI_DEVICE_ID_ACCESIO_MPCIE_ICM422_2	0x1110
#define PCI_DEVICE_ID_ACCESIO_MPCIE_ICM485_2	0x1111
#define PCI_DEVICE_ID_ACCESIO_MPCIE_ICM422_4	0x1118
#define PCI_DEVICE_ID_ACCESIO_MPCIE_ICM485_4	0x1119
#define PCI_DEVICE_ID_ACCESIO_PCIE_ICM_2S	0x1152
#define PCI_DEVICE_ID_ACCESIO_PCIE_ICM_4S	0x115A
#define PCI_DEVICE_ID_ACCESIO_PCIE_ICM232_2	0x1190
#define PCI_DEVICE_ID_ACCESIO_MPCIE_ICM232_2	0x1191
#define PCI_DEVICE_ID_ACCESIO_PCIE_ICM232_4	0x1198
#define PCI_DEVICE_ID_ACCESIO_MPCIE_ICM232_4	0x1199
#define PCI_DEVICE_ID_ACCESIO_PCIE_ICM_2SM	0x11D0
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM422_4	0x105A
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM485_4	0x105B
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM422_8	0x106A
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM485_8	0x106B
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM232_4	0x1098
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM232_8	0x10A9
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM_4SM	0x10D9
#define PCI_DEVICE_ID_ACCESIO_PCIE_COM_8SM	0x10E9
#define PCI_DEVICE_ID_ACCESIO_PCIE_ICM_4SM	0x11D8


#define PTLSER_PORT8		7



#if (LINUX_VERSION_CODE < VERSION_CODE(2,6,0))
#define DRV_VAR		    (&ptlser_var_sdriver)
#define DRV_VAR_P(x)	ptlser_var_sdriver.x
#else
#define DRV_VAR		    (ptlser_var_sdriver)
#define DRV_VAR_P(x)	ptlser_var_sdriver->x
#endif

#ifndef INIT_WORK
#define INIT_WORK(_work, _func, _data){	\
	_data->tqueue.routine = _func;\
	_data->tqueue.data = _data;\
	}
#endif

#ifndef set_current_state
#define	set_current_state(x) 		current->state = x
#endif


#if (LINUX_VERSION_CODE < VERSION_CODE(2,6,0))
#define IRQ_RET void
#define IRQ_RETVAL(x)
#else
#define IRQ_RET irqreturn_t
#endif


#if (LINUX_VERSION_CODE < VERSION_CODE(2,6,0))
#define PTLSER_MOD_INC	MOD_INC_USE_COUNT
#define PTLSER_MOD_DEC	MOD_DEC_USE_COUNT
#else
#define PTLSER_MOD_INC	try_module_get(THIS_MODULE)
#define PTLSER_MOD_DEC	module_put(THIS_MODULE)	
#endif

#if (LINUX_VERSION_CODE >= VERSION_CODE(2,6,0))
#ifndef ASYNC_CALLOUT_ACTIVE
#define ASYNC_CALLOUT_ACTIVE 0
#endif
#endif


#if (LINUX_VERSION_CODE >= VERSION_CODE(2,6,0))
#define PTLSER_TTY_DRV(x)	tty->driver->x
#else
#define PTLSER_TTY_DRV(x)	tty->driver.x
#endif

#if (LINUX_VERSION_CODE >= VERSION_CODE(5, 0, 0))
#define PTLSER_ACCESS_CHK(type, addr, size)	access_ok(addr, size)
#elif (LINUX_VERSION_CODE >= VERSION_CODE(2,6,0))
#define PTLSER_ACCESS_CHK(type, addr, size)	access_ok(type, addr, size)	
#else
#define PTLSER_ACCESS_CHK(type, addr, size)	verify_area(type, addr, size)	
#endif

#if (LINUX_VERSION_CODE >= VERSION_CODE(2,6,0))
#define PTLSER_ERR(x)	!(x)	
#else
#define PTLSER_ERR(x)	x	
#endif

#if (LINUX_VERSION_CODE >= VERSION_CODE(2,6,0))
#define GET_FPAGE	__get_free_page	
#else
#define GET_FPAGE	get_free_page
#endif

#ifndef atomic_read
#define atomic_read(v)	v
#endif


#ifndef UCHAR
typedef unsigned char	UCHAR;
#endif


#endif
