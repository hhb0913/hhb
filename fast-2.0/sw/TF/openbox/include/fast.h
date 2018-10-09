/** *************************************************************************
 *  @file          fast.h
 *  @brief		FAST架构平台所有相关头文件定义
 * 
 *   此头文件包含了其他FAST相关的所有定义文件，如虚拟地址空间定义、数据类型定义
 *   数据结构定义、枚举类型定义和错误信息定义
 * 
 *  @date		2017/01/05 12:14:24 星期四
 *  @author		XDL(Copyright  2017  XuDongLai)
 *  @email		<XuDongLai0923@163.com>
 *  @version	0.2.0
 ****************************************************************************/
/*
 * fast.h
 *
 * Copyright (C) 2017 - XuDongLai
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __FAST_H__
#define __FAST_H__
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>
#include <signal.h>
#include <memory.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <linux/if_ether.h>
#include <linux/netlink.h>
#include <netinet/in.h> /*IPv6 addr*/
#include <arpa/inet.h>
#include <sys/file.h>
#include <sys/mman.h>

#define REG_VERSION "1.1.3" /*Version of libreg*/
#define RULE_VERSION "1.0.3"	/*Version of librule*/
#define UA_VERSION "1.1.3"  /*Version of libua*/

/**Enable FAST_Remote_control mod**/
#define REMOTE_MOD 1
#undef REMOTE_MOD

#if REMOTE_MOD
#define REMOTE_PORT 1234
#define REMOTE_IP "192.168.1.108"
#endif

/** 是否启动软件调试模式，不启用对硬件操作，对硬件寄存器读写进行屏蔽，仅做打印输出 */
#define XDL_DEBUG 1   /**< 启用软件调试模式 */
#undef XDL_DEBUG	/**< 不启用软件调试模式 */


/** 硬件平台是否使用NetMagic 08设备，默认使用湖南新实OpenBox平台，支持其他平台，请使用如下宏定义 */
#define NetMagic08 1  /**< 硬件平台使用NetMagic08平台 */
#undef NetMagic08   /**< 硬件平台不使用NetMagic08平台 */

/** 硬件平台使用OpenBox-S28的定义*/
#define OpenBoxS28 1  /**< 硬件平台使用OpenBox-S28平台 */
#undef OpenBoxS28     /**< 硬件平台不使用OpenBox-S28平台 */

/** 硬件查表模式是否使用BV查表，默认为顺序匹配查表 */
#define LOOKUP_BV 1   /**< 硬件查表使用BV */
#undef LOOKUP_BV	/**< 硬件查表不使用BV */


#ifdef NetMagic08
/** NetMagic 08平台进行访问控制地IP协议类型定义，值为：253 */
#define NMAC_PROTO 253
#endif

#include "fast_type.h"
#include "fast_struct.h"
#include "fast_err.h"
#include "fast_vaddr.h"

/*---------------OFP------------------*/
int ofp_init(int argc,char *argv[]);/** 初始化OFP通道*/
void ofp_exit(void);/** 退出OFP通道*/



/*---------------REG------------------*/
int fast_init_hw(u64 addr,u64 len);/** 硬件资源初始，NetMagic08则进行连接操作*/
void fast_distroy_hw(void);/** 销毁硬件资源信息，NetMagic08则进行释放连接操作*/
u64 fast_reg_rd(u64 regaddr);/** 读硬件64位寄存器*/
void fast_reg_wr(u64 regaddr,u64 regvalue);/** 写硬件64位寄存器*/
u32 fast_GME_reg_rd(u32 regaddr);
void fast_GME_reg_wr(u32 regaddr,u32 regvalue);

/*---------------RULE------------------*/
#ifndef LOOKUP_BV
#define FAST_RULE_CNT 32
#else
#define FAST_RULE_CNT 32
#endif
void print_hw_rule(void);/** 打印硬件规则(通过寄存器读返回,并显示)*/
void print_sw_rule(void);/** 打印软件缓存的规则*/
void init_rule(u32 default_action);	   /** 初始化规则模块,需要输入默认动作2017/06/01修改*/
int fast_add_rule(struct fast_rule *rule);/** 添加一条规则*/
int fast_modify_rule(struct fast_rule *rule,int idx);/** 修改指定位置的规则,函数内部会同步到硬件*/
int fast_del_rule(int idx);/** 删除一条规则,函数内部会同步到硬件*/
int read_hw_rule(struct fast_rule *rule,int index);/** 从硬件读取一条指定的规则内容*/
int rule_exists(struct fast_rule *rule);/**/

/*---------------UA------------------*/
int fast_ua_init(int mid,fast_ua_recv_callback callback);/** UA模块初始化*/
void fast_ua_destroy(void);/** UA模块注销(销毁)*/
int fast_ua_send(struct fast_packet *pkt,int pkt_len);/** UA发送报文功能函数*/
void fast_ua_recv();/** UA启动报文接收线程(接收到报文后,回调用户注册函数)*/
void print_pkt(struct fast_packet *pkt,int pkt_len);/** 打印FAST结构报文*/

int fast_sw_init(int mid,fast_ua_recv_callback callback);
int fast_sw_send(struct fast_packet *pkt,int pkt_len);

/*--------------OpenFlow Channel----------------*/
u16 n2rule16(u16 n);/** */
u32 n2rule32(u32 n);/** */
u64 n2rule64(u64 n);/** */
void set_rule_mac64(char *mac,u64 value);/** */
void set_rule_mac_oxm(char *mac,char *oxm);/** OXM是网络序*/
void set_rule_ipv6_oxm(char *ipv6,char *oxm);/** */
void oxm2rule(char *dst,char *oxm,int len);/** */
void init_rule_sw(void);
u32 fast_match_rule(struct flow *key);
void print_sw_rule_by_idx(int idx);
void print_user_rule(struct fast_rule *rule);
/*--------------DEBUG----------------*/
#ifdef FAST_KERNEL
#define PFX "fastK->"
#define EPFX "KERR-fast->"
#define FAST_DBG(args...) printk(PFX args)
#define FAST_ERR(args...) printk(EPFX args)
#else
#define PFX "fastU->"
#define EPFX "UERR-fast->"
#define FAST_DBG(args...) do{printf(PFX);printf(args);}while(0)
#define FAST_ERR(args...) do{printf(EPFX);printf(args);exit(0);}while(0)
#endif
#endif//__FAST_H__
