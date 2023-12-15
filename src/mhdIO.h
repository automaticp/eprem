/* The Earth-Moon-Mars Radiation Environment Module (EMMREM) software is */
/* free software; you can redistribute and/or modify the EMMREM sotware */
/* or any part of the EMMREM software under the terms of the GNU General */
/* Public License (GPL) as published by the Free Software Foundation; */
/* either version 2 of the License, or (at your option) any later */
/* version. Software that uses any portion of the EMMREM software must */
/* also be released under the GNU GPL license (version 2 of the GNU GPL */
/* license or a later version). A copy of this GNU General Public License */
/* may be obtained by writing to the Free Software Foundation, Inc., 59 */
/* Temple Place, Suite 330, Boston MA 02111-1307 USA or by viewing the */
/* license online at http://www.gnu.org/copyleft/gpl.html. */

#ifndef MHDIO_H
#define MHDIO_H
#include <hdf5.h>
#include <hdf5_hl.h>

#ifdef HAVE_HDF4
#include <mfhdf.h>
#endif

#include <unistd.h>
#include "cubeShellStruct.h"


void mhdReadMeshDimensions( char *fname , char *dsetname, int dsetnumber, int32_t *DimMax );
void mhdReadMesh( char *fname , char *dsetname, int dsetnumber, float *Dim[] );
void mhdReadDatafromFile(char *fname, float *buf[] );
void mhdDatafile_type();
#endif
