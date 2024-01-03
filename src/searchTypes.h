/*-----------------------------------------------
-- EMMREM: searchTypes.h
--
-- Grid searching utilities: types, functions.
--
-- ______________CHANGE HISTORY__________________
-- ______________END CHANGE HISTORY______________
------------------------------------------------*/

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

#ifndef SEARCHTYPES_H
#define SEARCHTYPES_H

#include "baseTypes.h"

/*-- Exported Vars. -------------------------*/

/*----------------------------------------------------------*/
/*---*/         void                                   /*---*/
/*---*/   initMPI_searchTypes(void )                   /*---*/;
/*----------------------------------------------------------*/

Scalar_t                                                          /*--*/
findIntersection( Vec_t x0,
		  Vec_t x1,
		  Scalar_t r);

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/  void                                                    /*--*/
/*--*/  getPointObsProjections( void );                          /*--*/
/*--*/                                                          /*--*/
/*--    get all projections on the point observer spheres         --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/  void                                                    /*--*/
/*--*/  pointObsProjectedStreamData( Index_t face,              /*--*/
/*--*/                               Index_t row,               /*--*/
/*--*/                               Index_t col );             /*--*/
/*--*/                                                          /*--*/
/*--                                                              --*/
/*--    distribution values and radius of projection              --*/
/*--                                                              --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/




#endif
