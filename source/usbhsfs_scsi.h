/*
 * usbhsfs_scsi.h
 *
 * Copyright (c) 2020, DarkMatterCore <pabloacurielz@gmail.com>.
 * Copyright (c) 2020, XorTroll.
 *
 * This file is part of libusbhsfs (https://github.com/DarkMatterCore/libusbhsfs).
 *
 * libusbhsfs is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * libusbhsfs is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifndef __USBHSFS_SCSI_H__
#define __USBHSFS_SCSI_H__

#include "usbhsfs_manager.h"

bool usbHsFsScsiReadDriveSectors(UsbHsFsDriveContext *ctx, u8 lun, u64 sector_offset, u32 sector_count, void *out_buf);
bool usbHsFsScsiWriteDriveSectors(UsbHsFsDriveContext *ctx, u8 lun, u64 sector_offset, u32 sector_count, const void *buf);
/// Prepares a LUN from the provided drive context using SCSI commands and initializes an output LUN context.
bool usbHsFsScsiInitializeDriveLogicalUnitContext(UsbHsFsDriveContext *drive_ctx, u8 lun, UsbHsFsDriveLogicalUnitContext *lun_ctx);

/// Reads logical blocks from a drive LUN using the provided LUN context.
/// Takes care of thread-synchronization lock mechanisms on its own. Suitable for filesystem libraries.
bool usbHsFsScsiReadLogicalUnitBlocks(UsbHsFsDriveLogicalUnitContext *lun_ctx, void *buf, u64 block_addr, u32 block_count);

/// Writes logical blocks to a drive LUN using the provided LUN context.
/// Takes care of thread-synchronization lock mechanisms on its own. Suitable for filesystem libraries.
bool usbHsFsScsiWriteLogicalUnitBlocks(UsbHsFsDriveLogicalUnitContext *lun_ctx, void *buf, u64 block_addr, u32 block_count);

#endif  /* __USBHSFS_SCSI_H__ */
