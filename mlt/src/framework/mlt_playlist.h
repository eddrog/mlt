/*
 * mlt_playlist.h -- playlist service class
 * Copyright (C) 2003-2004 Ushodaya Enterprises Limited
 * Author: Charles Yates <charles.yates@pandora.be>
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
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _MLT_PLAYLIST_H_
#define _MLT_PLAYLIST_H_

#include "mlt_producer.h"

/** Structure for returning clip information.
*/

typedef struct
{
	mlt_producer producer;
	mlt_timecode start;
	char *resource;
	mlt_timecode in;
	int64_t frame_in;
	mlt_timecode out;
	int64_t frame_out;
	mlt_timecode playtime;
	mlt_timecode length;
	float fps;
}
mlt_playlist_clip_info;

/** Public final methods
*/

extern mlt_playlist mlt_playlist_init( );
extern mlt_producer mlt_playlist_producer( mlt_playlist this );
extern mlt_service mlt_playlist_service( mlt_playlist this );
extern mlt_properties mlt_playlist_properties( mlt_playlist this );
extern int mlt_playlist_count( mlt_playlist this );
extern int mlt_playlist_clear( mlt_playlist this );
extern int mlt_playlist_append( mlt_playlist this, mlt_producer producer );
extern int mlt_playlist_append_io( mlt_playlist this, mlt_producer producer, double in, double out );
extern int mlt_playlist_blank( mlt_playlist this, mlt_timecode length );
extern mlt_timecode mlt_playlist_clip( mlt_playlist this, mlt_whence whence, int index );
extern int mlt_playlist_current_clip( mlt_playlist this );
extern mlt_producer mlt_playlist_current( mlt_playlist this );
extern int mlt_playlist_get_clip_info( mlt_playlist this, mlt_playlist_clip_info *info, int index );
extern int mlt_playlist_insert( mlt_playlist this, mlt_producer producer, int where, mlt_timecode in, mlt_timecode out );
extern int mlt_playlist_remove( mlt_playlist this, int where );
extern int mlt_playlist_move( mlt_playlist this, int from, int to );
extern int mlt_playlist_resize_clip( mlt_playlist this, int clip, mlt_timecode in, mlt_timecode out );
extern void mlt_playlist_close( mlt_playlist this );

#endif

