/*-----------------------------------------------
-- EMMREM: energeticParticles.h
--
-- Functionality to update energetic particle distributions.
--
-- ______________CHANGE HISTORY______________
--
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

#ifndef ENERGETICPARTICLES_H
#define ENERGETICPARTICLES_H

#include "baseTypes.h"
#include "cubeShellStruct.h"

#ifdef __cplusplus
extern "C" {
#endif

/*-- Evaluate current particle distributions for all energy --*/
/*-- ranges, for all shells and every shell node in each.   --*/
/*-- NB-The INNER_SHELL does not need to be included in the --*/
/*-- update as its data will be overwritten when it is used --*/
/*-- as a template to spawn a new shell or used as a buffer --*/
/*-- for passing shells from proc to proc.                  --*/

extern Index_t streamlistSize;
extern Index_t maxsubcycles_energychange;
extern Index_t maxsubcycles_focusing;
extern Index_t maxsubcycles_energychangeGlobal;
extern Index_t maxsubcycles_focusingGlobal;
extern Scalar_t min_tau;
extern Scalar_t min_tau_global;

extern Scalar_t leaving_left;
extern Scalar_t leaving_right;
extern Scalar_t leaving_leftGlobal;
extern Scalar_t leaving_rightGlobal;

void updateEnergeticParticles( void );


/*---------------------------------------------------------------*/
/*---------------------------------------------------------------*/
/*--*/    Scalar_t                                           /*--*/
/*--*/    meanFreePath( Index_t species                      /*--*/
/*--*/                  , Index_t energy                     /*--*/
/*--*/                  , Scalar_t range);                   /*--*/
/*--*/                                                       /*--*/
/* -- Mean Free Path in AU ------------------------------------- */
/*---------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/  Vec_t                                                   /*--*/
/*--*/  driftVelocity( Index_t species,                         /*--*/
/*--*/                 Index_t energy,                          /*--*/
/*--*/                 SphVec_t curlBoverB2,                    /*--*/
/*--*/                 Vec_t r );                               /*--*/
/*--*/                                                          /*--*/
/*--*/                                                          /*--*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/    void                                                  /*--*/
/*--*/    ShellData( void );                                    /*--*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/     void                                                 /*--*/
/*--*/     DiffuseShellData(  Index_t shell,                    /*--*/
/*--*/                        Scalar_t dt );                    /*--*/
/*--                                                              --*/
/*-- Diffuse Data within a Shell                                  --*/
/*-- perp diffusion                                               --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/             void                                         /*--*/
/*--*/     DriftShellData(	Index_t shell,											/*--*/
/*--*/					  					Scalar_t dt	);                      /*--*/
/*--                                                              --*/
/*-- Move Data within a Shell                                     --*/
/*-- due to drift motion                                          --*/
/*------------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/    void                                                  /*--*/
/*--*/    AdiabaticChange_Operator_Upwind(Scalar_t *f1,         /*--*/
/*--*/                                    Scalar_t *f,          /*--*/
/*--*/                                    Scalar_t *v_avg,      /*--*/
/*--*/                                    Node_t node);         /*--*/
/*--*/                                                          /*--*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/    void                                                  /*--*/
/*--*/    AdiabaticChange_Operator_WENO3(Scalar_t *f1,          /*--*/
/*--*/                                   Scalar_t *f,           /*--*/
/*--*/                                   Scalar_t *v_avg,       /*--*/
/*--*/                                   Node_t node);          /*--*/
/*--*/                                                          /*--*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*--*/     void                                                 /*--*/
/*--*/     AdiabaticChange( Index_t face,                       /*--*/
/*--*/                      Index_t row,                        /*--*/
/*--*/                      Index_t col,                        /*--*/
/*--*/                      Index_t shell,                      /*--*/
/*--*/                      Scalar_t dt );                      /*--*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/             void                                         /*--*/
/*--*/     ShockSolution( Index_t face,                         /*--*/
/*--*/                    Index_t row,                          /*--*/
/*--*/                    Index_t col,                          /*--*/
/*--*/                    Index_t shell,                        /*--*/
/*--*/                    Index_t species,                      /*--*/
/*--*/                    Scalar_t dt);                         /*--*/
/*--                                                              --*/
/*-- Evaluate the adiabatic change                                --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/     void                                                 /*--*/
/*--*/     AdiabaticFocusing_old( Index_t face,                 /*--*/
/*--*/                            Index_t row,                  /*--*/
/*--*/                            Index_t col,                  /*--*/
/*--*/                            Index_t shell,                /*--*/
/*--*/                            Scalar_t dt );                /*--*/
/*--                                                              --*/
/*-- Calculate adiabatic focusing along a stream                  --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/     void                                                 /*--*/
/*--*/     AdiabaticFocusing( Index_t face,                     /*--*/
/*--*/                        Index_t row,                      /*--*/
/*--*/                        Index_t col,                      /*--*/
/*--*/                        Index_t shell,                    /*--*/
/*--*/                        Scalar_t dt );                    /*--*/
/*--                                                              --*/
/*-- Calculate adiabatic focusing along a stream                  --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/    void                                                  /*--*/
/*--*/    AdiabaticFocusing_Operator_Upwind(Scalar_t *f1,       /*--*/
/*--*/                                      Scalar_t *f,        /*--*/
/*--*/                                      Scalar_t *v_avg);   /*--*/
/*--*/                                                          /*--*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/    void                                                  /*--*/
/*--*/    AdiabaticFocusing_Operator_WENO3(Scalar_t *f1,        /*--*/
/*--*/                                     Scalar_t *f,         /*--*/
/*--*/                                     Scalar_t *v_avg);    /*--*/
/*--*/                                                          /*--*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/             int                                          /*--*/
/*--*/     DiffuseStreamData( Index_t iterIndex,                /*--*/
/*--*/                        Scalar_t dt);                     /*--*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/             void                                         /*--*/
/*--*/     isotropize(Scalar_t dt,
                      Index_t species,
                      Index_t energy,
                      Index_t shell );
/*--                                                              --*/
/*--  returns a relaxed distribution over the relaxation time     --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/             void                                         /*--*/
/*--*/     GetStreamList( Index_t iterIndex );                  /*--*/
/*--                                                              --*/
/*-- streamlist with removed duplicates                           --*/
/*-- gathers stream at [face][row][col+mpi_rank] onto this proc   --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*--*/             void                                         /*--*/
/*--*/     FindSegmentLengths( void );                          /*--*/
/*--                                                              --*/
/*-- find array of displacements between nodes                    --*/
/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif


#endif
