/***************************************************************************
 *            OpenBox-s28.h
 *
 *  五 八月 17 09:34:49 2018
 *  Copyright  2018  xzp
 *  <xiaozhipeng@xperis.com.cn>
 ****************************************************************************/
/*
 * OpenBox-s28.h
 *
 * Copyright (C) 2018 - xzp
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

//硬件版本号虚拟地址空间地址定义

#define FAST_HW_REG_VERSION 0x38	/**< 硬件版本寄存器地址 NetMagic08为：0x0,OpenBox为：0x38 */



//规则寄存器虚拟地址空间地址定义
#define FAST_RULE_REG_WADDR 0x200	   /**< 规则写寄存器*/
#define FAST_RULE_REG_RADDR 0x208	   /**< 规则读寄存器*/
#define FAST_RULE_REG_VADDR 0x210	   /**< 读规则返回值寄存器*/


//规则动作寄存器
#define FAST_ACTION_REG_ADDR 0x20000	/**< 写动作寄存器*/
#define FAST_DEFAULT_RULE_ADDR 0x1F8	/**< 默认动作(匹配不到规则时执行默认动作)地址*/

//端口寄存器
//PORT BASE INFO
/** 
 * 端口计数寄存器的访问由3部分组成：\n
 * 基地址|端口偏移地址*端口序号|计数寄存器地址\n
 * @par 示例说明
 * REG=FAST_PORT_BASE|FAST_PORT_OFT*port_idx|XX_REG;
 * 
 * XX_REG可以是计数寄存器、状态寄存器和端口的其他配置寄存器的地址
 */
#define FAST_PORT_BASE			0x40000 /**< 此为端口寄存器起始地址*/
/** 
 * 端口计数寄存器的访问由3部分组成：\n
 * 基地址|端口偏移地址*端口序号|计数寄存器地址\n
 * @par 示例说明
 * REG=FAST_PORT_BASE|FAST_PORT_OFT*port_idx|XX_REG;
 * 
 * XX_REG可以是计数寄存器、状态寄存器和端口的其他配置寄存器的地址
 */
#define FAST_PORT_OFT			0x2000  /**< 此为端口寄存器端口的偏移量（即每个端口拥有的地址空间）*/
//PORT COUNTS
#define FAST_COUNTS_SEND_OK		0x1A	/**< 计数寄存器：发送成功的计数*/
#define FAST_COUNTS_RECV_OK		0x1B	/**< 计数寄存器：接收成功的计数*/
#define FAST_COUNTS_CRC_ERR		0x1C	/**< 计数寄存器：CRC错误的计算*/
#define FAST_COUNTS_ALIGNER		0x1D	/**< 计数寄存器：帧对齐错误*/
#define FAST_COUNTS_SEND_D0_OK  0x1E	/**< 计数寄存器：成功发送字节数低位计数*/
#define FAST_COUNTS_SEND_D1_OK  0x0F	/**< 计数寄存器：成功发送字节数高位计数*/
#define FAST_COUNTS_RECV_D0_OK  0x1F	/**< 计数寄存器：成功发送字节数低位计数*/
#define FAST_COUNTS_RECV_D1_OK  0x3D	/**< 计数寄存器：成功发送字节数高位计数*/

#define FAST_COUNTS_RCVFERR		0x22	/**< 计数寄存器：接收的错误帧数*/
#define FAST_COUNTS_SNDFERR		0x23	/**< 计数寄存器：发送的错误帧数*/
#define FAST_COUNTS_RCVSPKT		0x24	/**< 计数寄存器：接收到的单播报文数*/
#define FAST_COUNTS_RCVMPKT		0x25	/**< 计数寄存器：接收到的多播报文数*/
#define FAST_COUNTS_RCVBPKT		0x26	/**< 计数寄存器：接收到的广播报文数*/
#define FAST_COUNTS_SNDSPKT		0x28	/**< 计数寄存器：发送的单播报文数*/
#define FAST_COUNTS_SNDMPKT		0x29	/**< 计数寄存器：发送的多播报文数*/
#define FAST_COUNTS_SNDBPKT		0x2A	/**< 计数寄存器：发送的广播报文数*/
//PORT and STATUS

#define FAST_PORT_MAC_CORE_CONFIG		0x2		/**< 配置寄存器：MAC核配置地址*/
#define FAST_PORT_MAC_0					0x3		/**< 配置寄存器：MAC0地址寄存器*/
#define FAST_PORT_MAC_1					0x4		/**< 配置寄存器：MAC1地址寄存器*/
#define FAST_PORT_FRAME_MAX_LEN			0x5		/**< 配置寄存器：支持最大帧长度*/
#define FAST_PORT_BUF_LEVEL				0xE		/**< 配置寄存器：BUF LEVEL*/
#define FAST_PORT_FRAME_SPACE			0x17	/**< 配置寄存器：帧间隔*/
#define FAST_PORT_PCS_MODE				0x94	/**< 状态寄存器：PCS模式*/
#define FAST_PORT_PCS_STATUS			0x81	/**< 状态寄存器：PCS状态*/
#define FAST_PORT_PCS_STATUS_LINK_OK	(0x1<<2)/**< 状态寄存器：LINK OK状态*/
#define FAST_PORT_PCS_STATUS_AUTONEG_EN	(0x1<<3)/**< 状态寄存器：自协商使能状态*/
#define FAST_PORT_PCS_STATUS_AUTONEG_OK	(0x1<<5)/**< 状态寄存器：自协商成功状态*/
#define FAST_PORT_NEG_STATUS			(0x85)  /**< 状态寄存器：自协商状态*/
#define FAST_PORT_NEG_STATUS_10M		(0x0<<10)/**< 状态寄存器：链路协商为10M*/
#define FAST_PORT_NEG_STATUS_100M		(0x1<<10)/**< 状态寄存器：链路协商为100M*/
#define FAST_PORT_NEG_STATUS_1G			(0x2<<10)/**< 状态寄存器：链路协商为1000M*/
#define FAST_PORT_NEG_STATUS_HALF		(0x0<<12)/**< 状态寄存器：链路为半双工状态*/
#define FAST_PORT_NEG_STATUS_FULL		(0x1<<12)/**< 状态寄存器：链路为全双工状态*/
#define FAST_PORT_NEG_STATUS_UP			(0x1<<15)/**< 状态寄存器：端口UP状态*/
#define FAST_PORT_NEG_STATUS_DOWN		(0x0<<15)/**< 状态寄存器：端口DOWN状态*/
//__FAST_VADDR_H__