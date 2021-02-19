/*******************************************************************
 *
 * COPYRIGHT (c) 2000 Matrox Electronic Systems Ltd.
 * All Rights Reserved
 *
 *******************************************************************/

/*******************************************************************
 *
 * Synopsis:      Prototypes for interrupt sources.
 *
 * Notes:
 *
 *******************************************************************/

#ifndef __INTLEVEL_H__
#define __INTLEVEL_H__

#if !defined(_IM_LOCAL_CODE) && defined(SHOW_INCLUDE_FILE)
#pragma message ("#include "__FILE__)
#endif

#include <linx_reg.h>

/* Each section use 32 semaphores */
#define _MP_MAX_SEMA_BY_SECTION    (64)
#define _MP_CONTROL_SEMA_OFFSET    (0)
#define _MP_SOF_SEMA_OFFSET        (_MP_CONTROL_SEMA_OFFSET  + _MP_MAX_SEMA_BY_SECTION)
#define _MP_LINE_INT_SEMA_OFFSET   (_MP_SOF_SEMA_OFFSET      + _MP_MAX_SEMA_BY_SECTION)
#define _MP_EOW_SEMA_OFFSET        (_MP_LINE_INT_SEMA_OFFSET + _MP_MAX_SEMA_BY_SECTION)
#define _MP_EOF_SEMA_OFFSET        (_MP_EOW_SEMA_OFFSET      + _MP_MAX_SEMA_BY_SECTION)
#define _MP_GPR_SEMA_OFFSET        (_MP_EOF_SEMA_OFFSET      + _MP_MAX_SEMA_BY_SECTION)

#define _MP_INTLVL_MASK            0x3f              /* Bit 0 to 63 */
#define _MP_SECTION_SHIFT          6

/* Interrupt status 0 */
#define MP_OASIS_INTLVL_HOST_NOT_EMPTY    (_MP_CONTROL_SEMA_OFFSET + 0)
#define MP_OASIS_INTFLG_HOST_NOT_EMPTY    ((REG_LLONG_TYPE)0x1)
#define MP_OASIS_INTLVL_HOST_THRESHOLD    (_MP_CONTROL_SEMA_OFFSET + 1)
#define MP_OASIS_INTFLG_HOST_THRESHOLD    ((REG_LLONG_TYPE)0x2)
#define MP_OASIS_INTLVL_HOST_FULL         (_MP_CONTROL_SEMA_OFFSET + 2)
#define MP_OASIS_INTFLG_HOST_FULL         ((REG_LLONG_TYPE)0x4)
#define MP_OASIS_INTLVL_NODE_NOT_EMPTY    (_MP_CONTROL_SEMA_OFFSET + 3)
#define MP_OASIS_INTFLG_NODE_NOT_EMPTY    ((REG_LLONG_TYPE)0x8)
#define MP_OASIS_INTLVL_NODE_THRESHOLD    (_MP_CONTROL_SEMA_OFFSET + 4)
#define MP_OASIS_INTFLG_NODE_THRESHOLD    ((REG_LLONG_TYPE)0x10)
#define MP_OASIS_INTLVL_NODE_FULL         (_MP_CONTROL_SEMA_OFFSET + 5)
#define MP_OASIS_INTFLG_NODE_FULL         ((REG_LLONG_TYPE)0x20)
#define MP_OASIS_INTLVL_DEBUG_NOT_EMPTY   (_MP_CONTROL_SEMA_OFFSET + 6)
#define MP_OASIS_INTFLG_DEBUG_NOT_EMPTY   ((REG_LLONG_TYPE)0x40)
#define MP_OASIS_INTLVL_DEBUG_THRESHOLD   (_MP_CONTROL_SEMA_OFFSET + 7)
#define MP_OASIS_INTFLG_DEBUG_THRESHOLD   ((REG_LLONG_TYPE)0x80)
#define MP_OASIS_INTLVL_MSG_OUT_SOF       (_MP_CONTROL_SEMA_OFFSET + 8)
#define MP_OASIS_INTFLG_MSG_OUT_SOF       ((REG_LLONG_TYPE)0x100)
#define MP_OASIS_INTLVL_MSG_OUT_EOF       (_MP_CONTROL_SEMA_OFFSET + 9)
#define MP_OASIS_INTFLG_MSG_OUT_EOF       ((REG_LLONG_TYPE)0x200)
#define MP_OASIS_INTLVL_LINK1_INT         (_MP_CONTROL_SEMA_OFFSET + 10)
#define MP_OASIS_INTFLG_LINK1_INT         ((REG_LLONG_TYPE)0x400)
#define MP_OASIS_INTLVL_PA_INT            (_MP_CONTROL_SEMA_OFFSET + 11)
#define MP_OASIS_INTFLG_PA_INT            ((REG_LLONG_TYPE)0x800)
#define MP_OASIS_INTLVL_PPC_FAULT         (_MP_CONTROL_SEMA_OFFSET + 12)
#define MP_OASIS_INTFLG_PPC_FAULT         ((REG_LLONG_TYPE)0x1000)
#define MP_OASIS_INTLVL_MSG0_EOF          (_MP_CONTROL_SEMA_OFFSET + 13)
#define MP_OASIS_INTFLG_MSG0_EOF          ((REG_LLONG_TYPE)0x2000)
#define MP_OASIS_INTLVL_LINK0_EOF         (_MP_CONTROL_SEMA_OFFSET + 14)
#define MP_OASIS_INTFLG_LINK0_EOF         ((REG_LLONG_TYPE)0x4000)
#define MP_OASIS_INTLVL_LINK1_EOF         (_MP_CONTROL_SEMA_OFFSET + 15)
#define MP_OASIS_INTFLG_LINK1_EOF         ((REG_LLONG_TYPE)0x8000)
#define MP_OASIS_INTLVL_MEM_FAULT         (_MP_CONTROL_SEMA_OFFSET + 16)
#define MP_OASIS_INTFLG_MEM_FAULT         ((REG_LLONG_TYPE)0x10000)
#define MP_OASIS_INTLVL_MEM_CALIB         (_MP_CONTROL_SEMA_OFFSET + 17)
#define MP_OASIS_INTFLG_MEM_CALIB         ((REG_LLONG_TYPE)0x20000)
#define MP_OASIS_INTLVL_CHANNEL0_BC_ERR   (_MP_CONTROL_SEMA_OFFSET + 18)
#define MP_OASIS_INTFLG_CHANNEL0_BC_ERR   ((REG_LLONG_TYPE)0x40000)
#define MP_OASIS_INTLVL_CHANNEL1_BC_ERR   (_MP_CONTROL_SEMA_OFFSET + 19)
#define MP_OASIS_INTFLG_CHANNEL1_BC_ERR   ((REG_LLONG_TYPE)0x80000)
#define MP_OASIS_INTLVL_VID_STR_OUT_CHAN0 (_MP_CONTROL_SEMA_OFFSET + 20)
#define MP_OASIS_INTFLG_VID_STR_OUT_CHAN0 ((REG_LLONG_TYPE)0x100000)
#define MP_OASIS_INTLVL_VID_STR_OUT_CHAN1 (_MP_CONTROL_SEMA_OFFSET + 21)
#define MP_OASIS_INTFLG_VID_STR_OUT_CHAN1 ((REG_LLONG_TYPE)0x200000)
#define MP_OASIS_INTLVL_MSG_STR_TIMER0    (_MP_CONTROL_SEMA_OFFSET + 22)
#define MP_OASIS_INTFLG_MSG_STR_TIMER0    ((REG_LLONG_TYPE)0x400000)
#define MP_OASIS_INTLVL_MSG_STR_TIMER1    (_MP_CONTROL_SEMA_OFFSET + 23)
#define MP_OASIS_INTFLG_MSG_STR_TIMER1    ((REG_LLONG_TYPE)0x800000)


/* Interrupt status 1 */
#define MP_OASIS_INTLVL_STREAM_SOF(X)        (_MP_SOF_SEMA_OFFSET + X)
#define MP_OASIS_INTFLG_STREAM_SOF(X)        ((REG_LLONG_TYPE)1 << (REG_LLONG_TYPE)X)

/* Interrupt status 2 */
#define MP_OASIS_INTLVL_STREAM_LINE_INT(X)   (_MP_LINE_INT_SEMA_OFFSET + X)
#define MP_OASIS_INTFLG_STREAM_LINE_INT(X)   ((REG_LLONG_TYPE)1 << (REG_LLONG_TYPE)X)

/* Interrupt status 3 */
#define MP_OASIS_INTLVL_STREAM_EOW(X)        (_MP_EOW_SEMA_OFFSET + X)
#define MP_OASIS_INTFLG_STREAM_EOW(X)        ((REG_LLONG_TYPE)1 << (REG_LLONG_TYPE)X)

/* Interrupt status 4 */
#define MP_OASIS_INTLVL_STREAM_EOF(X)        (_MP_EOF_SEMA_OFFSET + X)
#define MP_OASIS_INTFLG_STREAM_EOF(X)        ((REG_LLONG_TYPE)1 << (REG_LLONG_TYPE)X)

/* Interrupt request */
/* We define all 64 of them so it will be easier to modify the define name as well of a generic one */

/* the generic */
#define MP_OASIS_INTLVL_GPR(X)            (_MP_GPR_SEMA_OFFSET + X)
#define MP_OASIS_INTFLG_GPR(X)            ((REG_LLONG_TYPE)1 << (REG_LLONG_TYPE)X)

/* the specific */
#define MP_OASIS_INTLVL_REPLY       MP_OASIS_INTLVL_GPR(0)
#define MP_OASIS_INTFLG_REPLY       MP_OASIS_INTFLG_GPR(0)
#define MP_OASIS_INTLVL_HTR         MP_OASIS_INTLVL_GPR(1)  /* Host Transfer Ready im_buf put() & im_buf_get()*/
#define MP_OASIS_INTFLG_HTR         MP_OASIS_INTFLG_GPR(1)
#define MP_OASIS_INTLVL_LTR         MP_OASIS_INTLVL_GPR(2)  /* Local Transfer Ready im_buf put() & im_buf_get()*/
#define MP_OASIS_INTFLG_LTR         MP_OASIS_INTFLG_GPR(2)
#define MP_OASIS_INTLVL_DISPLAY     MP_OASIS_INTLVL_GPR(3)  /* Interrupt to handle the display requests */
#define MP_OASIS_INTFLG_DISPLAY     MP_OASIS_INTFLG_GPR(3)
#define MP_OASIS_INTLVL_UARTPPC     MP_OASIS_INTLVL_GPR(4)  /* Communication interrupt to the local */
#define MP_OASIS_INTFLG_UARTPPC     MP_OASIS_INTFLG_GPR(4)
#define MP_OASIS_INTLVL_UARTHOST    MP_OASIS_INTLVL_GPR(5)  /* Communication interrupt to the host */
#define MP_OASIS_INTFLG_UARTHOST    MP_OASIS_INTFLG_GPR(5)
#define MP_OASIS_INTLVL_GPR6        MP_OASIS_INTLVL_GPR(6)
#define MP_OASIS_INTFLG_GPR6        MP_OASIS_INTFLG_GPR(6)
#define MP_OASIS_INTLVL_GPR7        MP_OASIS_INTLVL_GPR(7)
#define MP_OASIS_INTFLG_GPR7        MP_OASIS_INTFLG_GPR(7)
#define MP_OASIS_INTLVL_GPR8        MP_OASIS_INTLVL_GPR(8)
#define MP_OASIS_INTFLG_GPR8        MP_OASIS_INTFLG_GPR(8)
#define MP_OASIS_INTLVL_GPR9        MP_OASIS_INTLVL_GPR(9)
#define MP_OASIS_INTFLG_GPR9        MP_OASIS_INTFLG_GPR(9)
#define MP_OASIS_INTLVL_GPR10       MP_OASIS_INTLVL_GPR(10)
#define MP_OASIS_INTFLG_GPR10       MP_OASIS_INTFLG_GPR(10)
#define MP_OASIS_INTLVL_GPR11       MP_OASIS_INTLVL_GPR(11)
#define MP_OASIS_INTFLG_GPR11       MP_OASIS_INTFLG_GPR(11)
#define MP_OASIS_INTLVL_GPR12       MP_OASIS_INTLVL_GPR(12)
#define MP_OASIS_INTFLG_GPR12       MP_OASIS_INTFLG_GPR(12)
#define MP_OASIS_INTLVL_GPR13       MP_OASIS_INTLVL_GPR(13)
#define MP_OASIS_INTFLG_GPR13       MP_OASIS_INTFLG_GPR(13)
#define MP_OASIS_INTLVL_GPR14       MP_OASIS_INTLVL_GPR(14)
#define MP_OASIS_INTFLG_GPR14       MP_OASIS_INTFLG_GPR(14)
#define MP_OASIS_INTLVL_GPR15       MP_OASIS_INTLVL_GPR(15)
#define MP_OASIS_INTFLG_GPR15       MP_OASIS_INTFLG_GPR(15)
#define MP_OASIS_INTLVL_GPR16       MP_OASIS_INTLVL_GPR(16)
#define MP_OASIS_INTFLG_GPR16       MP_OASIS_INTFLG_GPR(16)
#define MP_OASIS_INTLVL_GPR17       MP_OASIS_INTLVL_GPR(17)
#define MP_OASIS_INTFLG_GPR17       MP_OASIS_INTFLG_GPR(17)
#define MP_OASIS_INTLVL_GPR18       MP_OASIS_INTLVL_GPR(18)
#define MP_OASIS_INTFLG_GPR18       MP_OASIS_INTFLG_GPR(18)
#define MP_OASIS_INTLVL_GPR19       MP_OASIS_INTLVL_GPR(19)
#define MP_OASIS_INTFLG_GPR19       MP_OASIS_INTFLG_GPR(19)
#define MP_OASIS_INTLVL_GPR20       MP_OASIS_INTLVL_GPR(20)
#define MP_OASIS_INTFLG_GPR20       MP_OASIS_INTFLG_GPR(20)
#define MP_OASIS_INTLVL_GPR21       MP_OASIS_INTLVL_GPR(21)
#define MP_OASIS_INTFLG_GPR21       MP_OASIS_INTFLG_GPR(21)
#define MP_OASIS_INTLVL_GPR22       MP_OASIS_INTLVL_GPR(22)
#define MP_OASIS_INTFLG_GPR22       MP_OASIS_INTFLG_GPR(22)
#define MP_OASIS_INTLVL_GPR23       MP_OASIS_INTLVL_GPR(23)
#define MP_OASIS_INTFLG_GPR23       MP_OASIS_INTFLG_GPR(23)
#define MP_OASIS_INTLVL_GPR24       MP_OASIS_INTLVL_GPR(24)
#define MP_OASIS_INTFLG_GPR24       MP_OASIS_INTFLG_GPR(24)
#define MP_OASIS_INTLVL_GPR25       MP_OASIS_INTLVL_GPR(25)
#define MP_OASIS_INTFLG_GPR25       MP_OASIS_INTFLG_GPR(25)
#define MP_OASIS_INTLVL_GPR26       MP_OASIS_INTLVL_GPR(26)
#define MP_OASIS_INTFLG_GPR26       MP_OASIS_INTFLG_GPR(26)
#define MP_OASIS_INTLVL_GPR27       MP_OASIS_INTLVL_GPR(27)
#define MP_OASIS_INTFLG_GPR27       MP_OASIS_INTFLG_GPR(27)
#define MP_OASIS_INTLVL_GPR28       MP_OASIS_INTLVL_GPR(28)
#define MP_OASIS_INTFLG_GPR28       MP_OASIS_INTFLG_GPR(28)
#define MP_OASIS_INTLVL_GPR29       MP_OASIS_INTLVL_GPR(29)
#define MP_OASIS_INTFLG_GPR29       MP_OASIS_INTFLG_GPR(29)
#define MP_OASIS_INTLVL_GPR30       MP_OASIS_INTLVL_GPR(30)
#define MP_OASIS_INTFLG_GPR30       MP_OASIS_INTFLG_GPR(30)
#define MP_OASIS_INTLVL_GPR31       MP_OASIS_INTLVL_GPR(31)
#define MP_OASIS_INTFLG_GPR31       MP_OASIS_INTFLG_GPR(31)
#define MP_OASIS_INTLVL_GPR32       MP_OASIS_INTLVL_GPR(32)
#define MP_OASIS_INTFLG_GPR32       MP_OASIS_INTFLG_GPR(32)
#define MP_OASIS_INTLVL_GPR33       MP_OASIS_INTLVL_GPR(33)
#define MP_OASIS_INTFLG_GPR33       MP_OASIS_INTFLG_GPR(33)
#define MP_OASIS_INTLVL_GPR34       MP_OASIS_INTLVL_GPR(34)
#define MP_OASIS_INTFLG_GPR34       MP_OASIS_INTFLG_GPR(34)
#define MP_OASIS_INTLVL_GPR35       MP_OASIS_INTLVL_GPR(35)
#define MP_OASIS_INTFLG_GPR35       MP_OASIS_INTFLG_GPR(35)
#define MP_OASIS_INTLVL_GPR36       MP_OASIS_INTLVL_GPR(36)
#define MP_OASIS_INTFLG_GPR36       MP_OASIS_INTFLG_GPR(36)
#define MP_OASIS_INTLVL_GPR37       MP_OASIS_INTLVL_GPR(37)
#define MP_OASIS_INTFLG_GPR37       MP_OASIS_INTFLG_GPR(37)
#define MP_OASIS_INTLVL_GPR38       MP_OASIS_INTLVL_GPR(38)
#define MP_OASIS_INTFLG_GPR38       MP_OASIS_INTFLG_GPR(38)
#define MP_OASIS_INTLVL_GPR39       MP_OASIS_INTLVL_GPR(39)
#define MP_OASIS_INTFLG_GPR39       MP_OASIS_INTFLG_GPR(39)
#define MP_OASIS_INTLVL_GPR40       MP_OASIS_INTLVL_GPR(40)
#define MP_OASIS_INTFLG_GPR40       MP_OASIS_INTFLG_GPR(40)
#define MP_OASIS_INTLVL_GPR41       MP_OASIS_INTLVL_GPR(41)
#define MP_OASIS_INTFLG_GPR41       MP_OASIS_INTFLG_GPR(41)
#define MP_OASIS_INTLVL_GPR42       MP_OASIS_INTLVL_GPR(42)
#define MP_OASIS_INTFLG_GPR42       MP_OASIS_INTFLG_GPR(42)
#define MP_OASIS_INTLVL_GPR43       MP_OASIS_INTLVL_GPR(43)
#define MP_OASIS_INTFLG_GPR43       MP_OASIS_INTFLG_GPR(43)
#define MP_OASIS_INTLVL_GPR44       MP_OASIS_INTLVL_GPR(44)
#define MP_OASIS_INTFLG_GPR44       MP_OASIS_INTFLG_GPR(44)
#define MP_OASIS_INTLVL_GPR45       MP_OASIS_INTLVL_GPR(45)
#define MP_OASIS_INTFLG_GPR45       MP_OASIS_INTFLG_GPR(45)
#define MP_OASIS_INTLVL_GPR46       MP_OASIS_INTLVL_GPR(46)
#define MP_OASIS_INTFLG_GPR46       MP_OASIS_INTFLG_GPR(46)
#define MP_OASIS_INTLVL_GPR47       MP_OASIS_INTLVL_GPR(47)
#define MP_OASIS_INTFLG_GPR47       MP_OASIS_INTFLG_GPR(47)
#define MP_OASIS_INTLVL_GPR48       MP_OASIS_INTLVL_GPR(48)
#define MP_OASIS_INTFLG_GPR48       MP_OASIS_INTFLG_GPR(48)
#define MP_OASIS_INTLVL_GPR49       MP_OASIS_INTLVL_GPR(49)
#define MP_OASIS_INTFLG_GPR49       MP_OASIS_INTFLG_GPR(49)
#define MP_OASIS_INTLVL_GPR50       MP_OASIS_INTLVL_GPR(50)
#define MP_OASIS_INTFLG_GPR50       MP_OASIS_INTFLG_GPR(50)
#define MP_OASIS_INTLVL_GPR51       MP_OASIS_INTLVL_GPR(51)
#define MP_OASIS_INTFLG_GPR51       MP_OASIS_INTFLG_GPR(51)
#define MP_OASIS_INTLVL_GPR52       MP_OASIS_INTLVL_GPR(52)
#define MP_OASIS_INTFLG_GPR52       MP_OASIS_INTFLG_GPR(52)
#define MP_OASIS_INTLVL_GPR53       MP_OASIS_INTLVL_GPR(53)
#define MP_OASIS_INTFLG_GPR53       MP_OASIS_INTFLG_GPR(53)
#define MP_OASIS_INTLVL_GPR54       MP_OASIS_INTLVL_GPR(54)
#define MP_OASIS_INTFLG_GPR54       MP_OASIS_INTFLG_GPR(54)
#define MP_OASIS_INTLVL_GPR55       MP_OASIS_INTLVL_GPR(55)
#define MP_OASIS_INTFLG_GPR55       MP_OASIS_INTFLG_GPR(55)
#define MP_OASIS_INTLVL_GPR56       MP_OASIS_INTLVL_GPR(56)
#define MP_OASIS_INTFLG_GPR56       MP_OASIS_INTFLG_GPR(56)
#define MP_OASIS_INTLVL_GPR57       MP_OASIS_INTLVL_GPR(57)
#define MP_OASIS_INTFLG_GPR57       MP_OASIS_INTFLG_GPR(57)
#define MP_OASIS_INTLVL_LOGCTRL     MP_OASIS_INTLVL_GPR(58)
#define MP_OASIS_INTFLG_LOGCTRL     MP_OASIS_INTFLG_GPR(58)
#define MP_OASIS_INTLVL_TRACEDATA   MP_OASIS_INTLVL_GPR(59)
#define MP_OASIS_INTFLG_TRACEDATA   MP_OASIS_INTFLG_GPR(59)
#define MP_OASIS_INTLVL_CONIO       MP_OASIS_INTLVL_GPR(60)
#define MP_OASIS_INTFLG_CONIO       MP_OASIS_INTFLG_GPR(60)
#define MP_OASIS_INTLVL_FIO         MP_OASIS_INTLVL_GPR(61)
#define MP_OASIS_INTFLG_FIO         MP_OASIS_INTFLG_GPR(61)
#define MP_OASIS_INTLVL_TRK         MP_OASIS_INTLVL_GPR(62)
#define MP_OASIS_INTFLG_TRK         MP_OASIS_INTFLG_GPR(62)
#define MP_OASIS_INTLVL_TCPIP       MP_OASIS_INTLVL_GPR(63)
#define MP_OASIS_INTFLG_TCPIP       MP_OASIS_INTFLG_GPR(63)


#endif /* __INTLEVEL_H__ */
