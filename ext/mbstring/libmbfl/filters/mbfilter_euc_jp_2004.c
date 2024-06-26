/*
 * "streamable kanji code filter and converter"
 * Copyright (c) 1998-2002 HappySize, Inc. All rights reserved.
 *
 * LICENSE NOTICES
 *
 * This file is part of "streamable kanji code filter and converter",
 * which is distributed under the terms of GNU Lesser General Public
 * License (version 2) as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with "streamable kanji code filter and converter";
 * if not, write to the Free Software Foundation, Inc., 59 Temple Place,
 * Suite 330, Boston, MA  02111-1307  USA
 *
 * The author of this file:
 *
 */
/*
 * The source code included in this files was separated from mbfilter_ja.c
 * by rui hirokawa <hirokawa@php.net> on 16 aug 2011.
 *
 */

#include "mbfilter.h"
#include "mbfilter_euc_jp_2004.h"
#include "mbfilter_sjis_2004.h"

extern const unsigned char mblen_table_eucjp[];

static const char *mbfl_encoding_eucjp2004_aliases[] = {"EUC_JP-2004", NULL};

const mbfl_encoding mbfl_encoding_eucjp2004 = {
	mbfl_no_encoding_eucjp2004,
	"EUC-JP-2004",
	"EUC-JP",
	mbfl_encoding_eucjp2004_aliases,
	mblen_table_eucjp,
	0,
	&vtbl_eucjp2004_wchar,
	&vtbl_wchar_eucjp2004,
	NULL
};

const struct mbfl_convert_vtbl vtbl_eucjp2004_wchar = {
	mbfl_no_encoding_eucjp2004,
	mbfl_no_encoding_wchar,
	mbfl_filt_conv_common_ctor,
	NULL,
	mbfl_filt_conv_jis2004_wchar,
	mbfl_filt_conv_jis2004_wchar_flush,
	NULL,
};

const struct mbfl_convert_vtbl vtbl_wchar_eucjp2004 = {
	mbfl_no_encoding_wchar,
	mbfl_no_encoding_eucjp2004,
	mbfl_filt_conv_common_ctor,
	NULL,
	mbfl_filt_conv_wchar_jis2004,
	mbfl_filt_conv_wchar_jis2004_flush,
	NULL,
};
