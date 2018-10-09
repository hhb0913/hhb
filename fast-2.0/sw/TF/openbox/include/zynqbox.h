/***************************************************************************
 *            zynqbox.h
 *
 *  五 八月 17 11:51:35 2018
 *  Copyright  2018  xzp
 *  <user@host>
 ****************************************************************************/
/*
 * zynqbox.h
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

#define FAST_ACTION_REG_ADDR 0x0
#define FAST_DEFAULT_RULE_ADDR 0x1f8

#define FAST_PORT_OFT	0x2000

#define FAST_COUNTS_RECV_BYTE_D0_OK 0x200
#define FAST_COUNTS_RECV_BYTE_D1_OK 0x204

#define FAST_COUNTS_SEND_BYTE_D0_OK 0x208
#define FAST_COUNTS_SEND_BYTE_D1_OK 0x20c

#define FAST_COUNTS_SNDSPKT_D0		0x208
#define FAST_COUNTS_SNDSPKT_D1		0x20C

#define FAST_COUNTS_RECV_PKT_D1_OK 0x294
#define FAST_COUNTS_RECV_PKT_D0_OK 0x290

#define FAST_COUNTS_SEND_PKT_D1_OK 0x2dc
#define FAST_COUNTS_SEND_PKT_D0_OK 0x2d8

#define FAST_COUNTS_SEND_OK_D0		0x2D8
#define FAST_COUNTS_SEND_OK_D1 		0x2DC