/** *************************************************************************
 *  @file          fast_vaddr.h
 *  @brief		FAST平台硬件虚拟地址空间定义
 * 
 *  FAST平台硬件的所有地址有一套规范的地址空间定义，根据功能需求进行地址分区管理
 *  其地址分区如下：\n
 *  
 *  @date		2017/01/05 13:31:40 星期四
 *  @author		XDL(Copyright  2017  XuDongLai)
 *  @email		<XuDongLai0923@163.com>
 *  @version	0.2.0
 ****************************************************************************/
/*
 * fast_vaddr.h
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

#define FAST_DMID_PROTO_STACK 0x80  /**< 协议栈的MID值的定义,目的MID为0x80表示送到内核协议栈,大于0x80为软件模块，否则为硬件模块 */

#if OpenBoxS28
#include "OpenBox-S28.h"
#elif NetMagic08
#include "NetMagic08.h"
#else
#include "zynqbox.h"
#endif
