/*
 * filter_jackrack.c -- filter audio through Jack and/or LADSPA plugins
 * Copyright (C) 2004 Ushodaya Enterprises Limited
 * Author: Dan Dennedy <dan@dennedy.org>
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

#include <framework/mlt.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include <pthread.h>
#include <jack/jack.h>
#include <jack/ringbuffer.h>
#include <string.h>


static void filter_close( mlt_filter this )
{
	this->parent.close = NULL;
	mlt_service_close( &this->parent );
}

/** Constructor for the filter.
*/

mlt_filter filter_jackprobe_init( mlt_profile profile, mlt_service_type type, const char *id, char *arg )
{
	mlt_filter this = mlt_filter_new( );
	if ( this != NULL )
	{
		jack_status_t status = 0;

		jack_client_t *jack_client = jack_client_open( "mltprobe", JackNoStartServer, &status, NULL );
		if ( status == 0 )
		{
			jack_client_close( jack_client );
		}
		else
		{
			mlt_log_error( NULL, "Failed to connect to JACK server\n" );
			mlt_filter_close( this );
			this = NULL;
		}
	}
	return this;
}
